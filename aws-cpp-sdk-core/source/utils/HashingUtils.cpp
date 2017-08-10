/*
  * Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
  * 
  * Licensed under the Apache License, Version 2.0 (the "License").
  * You may not use this file except in compliance with the License.
  * A copy of the License is located at
  * 
  *  http://aws.amazon.com/apache2.0
  * 
  * or in the "license" file accompanying this file. This file is distributed
  * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
  * express or implied. See the License for the specific language governing
  * permissions and limitations under the License.
  */

#include <aws/core/utils/logging/LogMacros.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/utils/base64/Base64.h>
#include <aws/core/utils/crypto/Sha256.h>
#include <aws/core/utils/crypto/Sha256HMAC.h>
#include <aws/core/utils/crypto/MD5.h>
#include <aws/core/utils/Outcome.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>
#include <aws/core/utils/memory/stl/AWSList.h>

#include <iomanip>

using namespace Aws::Utils;
using namespace Aws::Utils::Base64;
using namespace Aws::Utils::Crypto;

// internal buffers are fixed-size arrays, so this is harmless memory-management wise
static Aws::Utils::Base64::Base64 s_base64;

// Aws Glacier Tree Hash calculates hash value for each 1MB data
const static uint64_t TREE_HASH_ONE_MB = 1024 * 1024;

Aws::String HashingUtils::Base64Encode(const ByteBuffer& message)
{
    return s_base64.Encode(message);
}

ByteBuffer HashingUtils::Base64Decode(const Aws::String& encodedMessage)
{
    return s_base64.Decode(encodedMessage);
}

ByteBuffer HashingUtils::CalculateSHA256HMAC(const ByteBuffer& toSign, const ByteBuffer& secret)
{
    Sha256HMAC hash;
    return hash.Calculate(toSign, secret).GetResult();
}

ByteBuffer HashingUtils::CalculateSHA256(const Aws::String& str)
{
    Sha256 hash;
    return hash.Calculate(str).GetResult();
}

ByteBuffer HashingUtils::CalculateSHA256(Aws::IOStream& stream)
{
    Sha256 hash;
    return hash.Calculate(stream).GetResult();
}

/**
 * This function is only used by HashingUtils::CalculateSHA256TreeHash() in this cpp file
 * It's a helper function be used to compute the TreeHash defined at:
 * http://docs.aws.amazon.com/amazonglacier/latest/dev/checksum-calculations.html
 */
static ByteBuffer TreeHashFinalCompute(Aws::List<ByteBuffer>& input)
{
    Sha256 hash;
    assert(input.size() != 0);

    // O(n) time complexity of merging (n + n/2 + n/4 + n/8 +...+ 1)
    while (input.size() > 1)
    {
        auto iter = input.begin();
        // if only one element left, just left it there
        while (std::next(iter) != input.end())
        {
            // if >= two elements
            Aws::String str(reinterpret_cast<char*>(iter->GetUnderlyingData()), iter->GetLength());
            // list erase returns iterator of next element next to the erased element or end() if erased the last one
            // list insert inserts element before pos, here we erase two elements, and insert a new element
            iter = input.erase(iter);
            str.append(reinterpret_cast<char*>(iter->GetUnderlyingData()), iter->GetLength());
            iter = input.erase(iter);
            input.insert(iter, hash.Calculate(str).GetResult());

            if (iter == input.end()) break;
        } // while process to the last element
    } // while the list has only one element left

    return *(input.begin());
}

ByteBuffer HashingUtils::CalculateSHA256TreeHash(const Aws::String& str)
{
    Sha256 hash;
    if (str.size() == 0)
    {
        return hash.Calculate(str).GetResult();
    }

    Aws::List<ByteBuffer> input;
    uint64_t pos = 0;
    while (pos < (uint64_t)str.size())
    {
        input.push_back(hash.Calculate(Aws::String(str, pos, TREE_HASH_ONE_MB)).GetResult());
        pos += TREE_HASH_ONE_MB;
    }

    return TreeHashFinalCompute(input);
}

ByteBuffer HashingUtils::CalculateSHA256TreeHash(Aws::IOStream& stream)
{
    Sha256 hash;
    Aws::List<ByteBuffer> input;
    auto currentPos = stream.tellg();
    if (currentPos == std::ios::pos_type(-1))
    {
        currentPos = 0;
        stream.clear();
    }
    stream.seekg(0, stream.beg);
    Array<char> streamBuffer(TREE_HASH_ONE_MB);
    while (stream.good())
    {
        stream.read(streamBuffer.GetUnderlyingData(), TREE_HASH_ONE_MB);
        auto bytesRead = stream.gcount();
        if (bytesRead > 0)
        {
            input.push_back(hash.Calculate(Aws::String(reinterpret_cast<char*>(streamBuffer.GetUnderlyingData()), bytesRead)).GetResult());
        }
    }
    stream.clear();
    stream.seekg(currentPos, stream.beg);

    if (input.size() == 0)
    {
        return hash.Calculate("").GetResult();
    }
    return TreeHashFinalCompute(input);
}

Aws::String HashingUtils::HexEncode(const ByteBuffer& message)
{
    Aws::StringStream ss;

    for (unsigned i = 0; i < message.GetLength(); ++i)
    {
        ss << std::hex << std::setw(2) << std::setfill('0')
            << (unsigned int) message[i];
    }

    return ss.str();
}

ByteBuffer HashingUtils::HexDecode(const Aws::String& str)
{
    //number of characters should be even
    assert(str.length() % 2 == 0);
    assert(str.length() >= 2);

    if(str.length() < 2 || str.length() % 2 != 0)
    {
        return ByteBuffer();
    }

    size_t strLength = str.length();
    size_t readIndex = 0;

    if(str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
    {
        strLength -= 2;
        readIndex = 2;
    }

    ByteBuffer hexBuffer(strLength / 2);
    size_t bufferIndex = 0;

    for (size_t i = readIndex; i < str.length(); i += 2)
    {
        if(!isalnum(str[i]) || !isalnum(str[i + 1]))
        {
            //contains non-hex characters
            assert(0);
        }

        char firstChar = str[i];
        uint8_t distance = firstChar - '0';

        if(isalpha(firstChar))
        {
            firstChar = static_cast<char>(toupper(firstChar));
            distance = firstChar - 'A' + 10;
        }

        unsigned char val = distance * 16;

        char secondChar = str[i + 1];
        distance = secondChar - '0';

        if(isalpha(secondChar))
        {
            secondChar = static_cast<char>(toupper(secondChar));
            distance = secondChar - 'A' + 10;
        }

        val += distance;
        hexBuffer[bufferIndex++] = val;
    }

    return hexBuffer;
}

ByteBuffer HashingUtils::CalculateMD5(const Aws::String& str)
{
    MD5 hash;
    return hash.Calculate(str).GetResult();
}

ByteBuffer HashingUtils::CalculateMD5(Aws::IOStream& stream)
{
    MD5 hash;
    return hash.Calculate(stream).GetResult();
}

int HashingUtils::HashString(const char* strToHash)
{
    if (!strToHash)
        return 0;

    int hash = 0;
    while (char charValue = *strToHash++)
    {
        hash = charValue + 31 * hash;    
    }

    return hash;
}

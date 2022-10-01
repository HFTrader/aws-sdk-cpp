﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/awstransfer/model/ListHostKeysResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::Transfer::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

ListHostKeysResult::ListHostKeysResult()
{
}

ListHostKeysResult::ListHostKeysResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

ListHostKeysResult& ListHostKeysResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("NextToken"))
  {
    m_nextToken = jsonValue.GetString("NextToken");

  }

  if(jsonValue.ValueExists("ServerId"))
  {
    m_serverId = jsonValue.GetString("ServerId");

  }

  if(jsonValue.ValueExists("HostKeys"))
  {
    Array<JsonView> hostKeysJsonList = jsonValue.GetArray("HostKeys");
    for(unsigned hostKeysIndex = 0; hostKeysIndex < hostKeysJsonList.GetLength(); ++hostKeysIndex)
    {
      m_hostKeys.push_back(hostKeysJsonList[hostKeysIndex].AsObject());
    }
  }



  return *this;
}

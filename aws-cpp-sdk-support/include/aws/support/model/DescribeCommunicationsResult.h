﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/support/Support_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/support/model/Communication.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace Support
{
namespace Model
{
  /**
   * <p>The communications returned by the <a>DescribeCommunications</a>
   * operation.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/support-2013-04-15/DescribeCommunicationsResponse">AWS
   * API Reference</a></p>
   */
  class DescribeCommunicationsResult
  {
  public:
    AWS_SUPPORT_API DescribeCommunicationsResult();
    AWS_SUPPORT_API DescribeCommunicationsResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    AWS_SUPPORT_API DescribeCommunicationsResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    /**
     * <p>The communications for the case.</p>
     */
    inline const Aws::Vector<Communication>& GetCommunications() const{ return m_communications; }

    /**
     * <p>The communications for the case.</p>
     */
    inline void SetCommunications(const Aws::Vector<Communication>& value) { m_communications = value; }

    /**
     * <p>The communications for the case.</p>
     */
    inline void SetCommunications(Aws::Vector<Communication>&& value) { m_communications = std::move(value); }

    /**
     * <p>The communications for the case.</p>
     */
    inline DescribeCommunicationsResult& WithCommunications(const Aws::Vector<Communication>& value) { SetCommunications(value); return *this;}

    /**
     * <p>The communications for the case.</p>
     */
    inline DescribeCommunicationsResult& WithCommunications(Aws::Vector<Communication>&& value) { SetCommunications(std::move(value)); return *this;}

    /**
     * <p>The communications for the case.</p>
     */
    inline DescribeCommunicationsResult& AddCommunications(const Communication& value) { m_communications.push_back(value); return *this; }

    /**
     * <p>The communications for the case.</p>
     */
    inline DescribeCommunicationsResult& AddCommunications(Communication&& value) { m_communications.push_back(std::move(value)); return *this; }


    /**
     * <p>A resumption point for pagination.</p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>A resumption point for pagination.</p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextToken = value; }

    /**
     * <p>A resumption point for pagination.</p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextToken = std::move(value); }

    /**
     * <p>A resumption point for pagination.</p>
     */
    inline void SetNextToken(const char* value) { m_nextToken.assign(value); }

    /**
     * <p>A resumption point for pagination.</p>
     */
    inline DescribeCommunicationsResult& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>A resumption point for pagination.</p>
     */
    inline DescribeCommunicationsResult& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p>A resumption point for pagination.</p>
     */
    inline DescribeCommunicationsResult& WithNextToken(const char* value) { SetNextToken(value); return *this;}

  private:

    Aws::Vector<Communication> m_communications;

    Aws::String m_nextToken;
  };

} // namespace Model
} // namespace Support
} // namespace Aws

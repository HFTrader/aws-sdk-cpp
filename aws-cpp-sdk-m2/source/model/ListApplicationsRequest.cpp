﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/m2/model/ListApplicationsRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/http/URI.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::MainframeModernization::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws::Http;

ListApplicationsRequest::ListApplicationsRequest() : 
    m_environmentIdHasBeenSet(false),
    m_maxResults(0),
    m_maxResultsHasBeenSet(false),
    m_namesHasBeenSet(false),
    m_nextTokenHasBeenSet(false)
{
}

Aws::String ListApplicationsRequest::SerializePayload() const
{
  return {};
}

void ListApplicationsRequest::AddQueryStringParameters(URI& uri) const
{
    Aws::StringStream ss;
    if(m_environmentIdHasBeenSet)
    {
      ss << m_environmentId;
      uri.AddQueryStringParameter("environmentId", ss.str());
      ss.str("");
    }

    if(m_maxResultsHasBeenSet)
    {
      ss << m_maxResults;
      uri.AddQueryStringParameter("maxResults", ss.str());
      ss.str("");
    }

    if(m_namesHasBeenSet)
    {
      for(const auto& item : m_names)
      {
        ss << item;
        uri.AddQueryStringParameter("names", ss.str());
        ss.str("");
      }
    }

    if(m_nextTokenHasBeenSet)
    {
      ss << m_nextToken;
      uri.AddQueryStringParameter("nextToken", ss.str());
      ss.str("");
    }

}




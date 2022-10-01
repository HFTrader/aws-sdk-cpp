﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/outposts/model/GetConnectionRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Outposts::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

GetConnectionRequest::GetConnectionRequest() : 
    m_connectionIdHasBeenSet(false)
{
}

Aws::String GetConnectionRequest::SerializePayload() const
{
  return {};
}





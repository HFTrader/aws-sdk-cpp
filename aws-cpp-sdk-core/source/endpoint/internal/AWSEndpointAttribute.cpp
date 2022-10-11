/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/core/endpoint/internal/AWSEndpointAttribute.h>
#include <aws/core/utils/logging/LogMacros.h>

static const char ENDPOINT_AUTH_SCHEME_TAG[] = "EndpointAuthScheme::BuildEndpointAuthSchemeFromJson";

Aws::Internal::Endpoint::EndpointAttributes
Aws::Internal::Endpoint::EndpointAttributes::BuildEndpointAttributesFromJson(const Aws::String& iJsonStr)
{
    Aws::Internal::Endpoint::EndpointAttributes attributes;
    Aws::Internal::Endpoint::EndpointAuthScheme& authScheme = attributes.authScheme;

    Utils::Json::JsonValue jsonObject(iJsonStr);
    if (jsonObject.WasParseSuccessful())
    {
        Aws::Map<Aws::String, Utils::Json::JsonView> jsonMap = jsonObject.View().GetAllObjects();
        for (const auto& mapItemAttribute : jsonMap)
        {
            if (mapItemAttribute.first == "authSchemes" && mapItemAttribute.second.IsListType()) {
                Aws::Utils::Array<Utils::Json::JsonView> jsonAuthSchemeArray = mapItemAttribute.second.AsArray();

                for (size_t arrayIdx = 0; arrayIdx < jsonAuthSchemeArray.GetLength(); ++arrayIdx)
                {
                    const Utils::Json::JsonView& property = jsonAuthSchemeArray.GetItem(arrayIdx);
                    for (const auto& mapItemProperty : property.GetAllObjects())
                    {
                        if (mapItemProperty.first == "name") {
                            authScheme.SetName(mapItemProperty.second.AsString());
                        } else if (mapItemProperty.first == "signingName") {
                            authScheme.SetSigningName(mapItemProperty.second.AsString());
                        } else if (mapItemProperty.first == "signingRegion") {
                            authScheme.SetSigningRegion(mapItemProperty.second.AsString());
                        } else if (mapItemProperty.first == "signingRegionSet") {
                            authScheme.SetSigningRegionSet(mapItemProperty.second.AsString());
                        } else if (mapItemProperty.first == "disableDoubleEncoding") {
                            authScheme.SetDisableDoubleEncoding(mapItemProperty.second.AsBool());
                        } else {
                            AWS_LOG_WARN(ENDPOINT_AUTH_SCHEME_TAG, Aws::String("Unknown Endpoint authSchemes attribute property: " + mapItemProperty.first).c_str());
                        }
                    }
                }
            } else {
                AWS_LOG_WARN(ENDPOINT_AUTH_SCHEME_TAG, Aws::String("Unknown Endpoint Attribute: " + mapItemAttribute.first).c_str());
            }
        }
    }
    else
    {
        AWS_LOGSTREAM_ERROR(ENDPOINT_AUTH_SCHEME_TAG, "Json Parse failed with message: " << jsonObject.GetErrorMessage());
    }

    return attributes;
}
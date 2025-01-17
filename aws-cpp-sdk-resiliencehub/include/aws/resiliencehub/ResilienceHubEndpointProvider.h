﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/resiliencehub/ResilienceHub_EXPORTS.h>
#include <aws/core/client/GenericClientConfiguration.h>
#include <aws/core/endpoint/DefaultEndpointProvider.h>
#include <aws/core/endpoint/EndpointParameter.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>

#include <aws/resiliencehub/ResilienceHubEndpointRules.h>


namespace Aws
{
namespace ResilienceHub
{
namespace Endpoint
{
using EndpointParameters = Aws::Endpoint::EndpointParameters;
using Aws::Endpoint::EndpointProviderBase;
using Aws::Endpoint::DefaultEndpointProvider;

using ResilienceHubClientContextParameters = Aws::Endpoint::ClientContextParameters;

using ResilienceHubClientConfiguration = Aws::Client::GenericClientConfiguration<false>;
using ResilienceHubBuiltInParameters = Aws::Endpoint::BuiltInParameters;

/**
 * The type for the ResilienceHub Client Endpoint Provider.
 * Inherit from this Base class / "Interface" should you want to provide a custom endpoint provider.
 * The SDK must use service-specific type for each service per specification.
 */
using ResilienceHubEndpointProviderBase =
    EndpointProviderBase<ResilienceHubClientConfiguration, ResilienceHubBuiltInParameters, ResilienceHubClientContextParameters>;

using ResilienceHubDefaultEpProviderBase =
    DefaultEndpointProvider<ResilienceHubClientConfiguration, ResilienceHubBuiltInParameters, ResilienceHubClientContextParameters>;

/**
 * Default endpoint provider used for this service
 */
class AWS_RESILIENCEHUB_API ResilienceHubEndpointProvider : public ResilienceHubDefaultEpProviderBase
{
public:
    using ResilienceHubResolveEndpointOutcome = Aws::Endpoint::ResolveEndpointOutcome;

    ResilienceHubEndpointProvider()
      : ResilienceHubDefaultEpProviderBase(Aws::ResilienceHub::ResilienceHubEndpointRules::Rules)
    {}

    ~ResilienceHubEndpointProvider()
    {
    }
};
} // namespace Endpoint
} // namespace ResilienceHub
} // namespace Aws

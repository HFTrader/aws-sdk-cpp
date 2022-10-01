﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/chime-sdk-media-pipelines/ChimeSDKMediaPipelines_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace ChimeSDKMediaPipelines
{
namespace Model
{
  enum class ArtifactsConcatenationState
  {
    NOT_SET,
    Enabled,
    Disabled
  };

namespace ArtifactsConcatenationStateMapper
{
AWS_CHIMESDKMEDIAPIPELINES_API ArtifactsConcatenationState GetArtifactsConcatenationStateForName(const Aws::String& name);

AWS_CHIMESDKMEDIAPIPELINES_API Aws::String GetNameForArtifactsConcatenationState(ArtifactsConcatenationState value);
} // namespace ArtifactsConcatenationStateMapper
} // namespace Model
} // namespace ChimeSDKMediaPipelines
} // namespace Aws

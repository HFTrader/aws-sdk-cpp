﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/states/SFN_EXPORTS.h>
#include <aws/states/SFNRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace SFN
{
namespace Model
{

  /**
   */
  class AWS_SFN_API SendTaskHeartbeatRequest : public SFNRequest
  {
  public:
    SendTaskHeartbeatRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "SendTaskHeartbeat"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>The token that represents this task. Task tokens are generated by Step
     * Functions when tasks are assigned to a worker, or in the <a
     * href="https://docs.aws.amazon.com/step-functions/latest/dg/input-output-contextobject.html">context
     * object</a> when a workflow enters a task state. See
     * <a>GetActivityTaskOutput$taskToken</a>.</p>
     */
    inline const Aws::String& GetTaskToken() const{ return m_taskToken; }

    /**
     * <p>The token that represents this task. Task tokens are generated by Step
     * Functions when tasks are assigned to a worker, or in the <a
     * href="https://docs.aws.amazon.com/step-functions/latest/dg/input-output-contextobject.html">context
     * object</a> when a workflow enters a task state. See
     * <a>GetActivityTaskOutput$taskToken</a>.</p>
     */
    inline bool TaskTokenHasBeenSet() const { return m_taskTokenHasBeenSet; }

    /**
     * <p>The token that represents this task. Task tokens are generated by Step
     * Functions when tasks are assigned to a worker, or in the <a
     * href="https://docs.aws.amazon.com/step-functions/latest/dg/input-output-contextobject.html">context
     * object</a> when a workflow enters a task state. See
     * <a>GetActivityTaskOutput$taskToken</a>.</p>
     */
    inline void SetTaskToken(const Aws::String& value) { m_taskTokenHasBeenSet = true; m_taskToken = value; }

    /**
     * <p>The token that represents this task. Task tokens are generated by Step
     * Functions when tasks are assigned to a worker, or in the <a
     * href="https://docs.aws.amazon.com/step-functions/latest/dg/input-output-contextobject.html">context
     * object</a> when a workflow enters a task state. See
     * <a>GetActivityTaskOutput$taskToken</a>.</p>
     */
    inline void SetTaskToken(Aws::String&& value) { m_taskTokenHasBeenSet = true; m_taskToken = std::move(value); }

    /**
     * <p>The token that represents this task. Task tokens are generated by Step
     * Functions when tasks are assigned to a worker, or in the <a
     * href="https://docs.aws.amazon.com/step-functions/latest/dg/input-output-contextobject.html">context
     * object</a> when a workflow enters a task state. See
     * <a>GetActivityTaskOutput$taskToken</a>.</p>
     */
    inline void SetTaskToken(const char* value) { m_taskTokenHasBeenSet = true; m_taskToken.assign(value); }

    /**
     * <p>The token that represents this task. Task tokens are generated by Step
     * Functions when tasks are assigned to a worker, or in the <a
     * href="https://docs.aws.amazon.com/step-functions/latest/dg/input-output-contextobject.html">context
     * object</a> when a workflow enters a task state. See
     * <a>GetActivityTaskOutput$taskToken</a>.</p>
     */
    inline SendTaskHeartbeatRequest& WithTaskToken(const Aws::String& value) { SetTaskToken(value); return *this;}

    /**
     * <p>The token that represents this task. Task tokens are generated by Step
     * Functions when tasks are assigned to a worker, or in the <a
     * href="https://docs.aws.amazon.com/step-functions/latest/dg/input-output-contextobject.html">context
     * object</a> when a workflow enters a task state. See
     * <a>GetActivityTaskOutput$taskToken</a>.</p>
     */
    inline SendTaskHeartbeatRequest& WithTaskToken(Aws::String&& value) { SetTaskToken(std::move(value)); return *this;}

    /**
     * <p>The token that represents this task. Task tokens are generated by Step
     * Functions when tasks are assigned to a worker, or in the <a
     * href="https://docs.aws.amazon.com/step-functions/latest/dg/input-output-contextobject.html">context
     * object</a> when a workflow enters a task state. See
     * <a>GetActivityTaskOutput$taskToken</a>.</p>
     */
    inline SendTaskHeartbeatRequest& WithTaskToken(const char* value) { SetTaskToken(value); return *this;}

  private:

    Aws::String m_taskToken;
    bool m_taskTokenHasBeenSet = false;
  };

} // namespace Model
} // namespace SFN
} // namespace Aws

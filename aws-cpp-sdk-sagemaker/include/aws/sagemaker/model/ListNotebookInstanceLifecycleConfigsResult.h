﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/sagemaker/SageMaker_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/sagemaker/model/NotebookInstanceLifecycleConfigSummary.h>
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
namespace SageMaker
{
namespace Model
{
  class ListNotebookInstanceLifecycleConfigsResult
  {
  public:
    AWS_SAGEMAKER_API ListNotebookInstanceLifecycleConfigsResult();
    AWS_SAGEMAKER_API ListNotebookInstanceLifecycleConfigsResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    AWS_SAGEMAKER_API ListNotebookInstanceLifecycleConfigsResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    /**
     * <p>If the response is truncated, SageMaker returns this token. To get the next
     * set of lifecycle configurations, use it in the next request. </p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>If the response is truncated, SageMaker returns this token. To get the next
     * set of lifecycle configurations, use it in the next request. </p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextToken = value; }

    /**
     * <p>If the response is truncated, SageMaker returns this token. To get the next
     * set of lifecycle configurations, use it in the next request. </p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextToken = std::move(value); }

    /**
     * <p>If the response is truncated, SageMaker returns this token. To get the next
     * set of lifecycle configurations, use it in the next request. </p>
     */
    inline void SetNextToken(const char* value) { m_nextToken.assign(value); }

    /**
     * <p>If the response is truncated, SageMaker returns this token. To get the next
     * set of lifecycle configurations, use it in the next request. </p>
     */
    inline ListNotebookInstanceLifecycleConfigsResult& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>If the response is truncated, SageMaker returns this token. To get the next
     * set of lifecycle configurations, use it in the next request. </p>
     */
    inline ListNotebookInstanceLifecycleConfigsResult& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p>If the response is truncated, SageMaker returns this token. To get the next
     * set of lifecycle configurations, use it in the next request. </p>
     */
    inline ListNotebookInstanceLifecycleConfigsResult& WithNextToken(const char* value) { SetNextToken(value); return *this;}


    /**
     * <p>An array of <code>NotebookInstanceLifecycleConfiguration</code> objects, each
     * listing a lifecycle configuration.</p>
     */
    inline const Aws::Vector<NotebookInstanceLifecycleConfigSummary>& GetNotebookInstanceLifecycleConfigs() const{ return m_notebookInstanceLifecycleConfigs; }

    /**
     * <p>An array of <code>NotebookInstanceLifecycleConfiguration</code> objects, each
     * listing a lifecycle configuration.</p>
     */
    inline void SetNotebookInstanceLifecycleConfigs(const Aws::Vector<NotebookInstanceLifecycleConfigSummary>& value) { m_notebookInstanceLifecycleConfigs = value; }

    /**
     * <p>An array of <code>NotebookInstanceLifecycleConfiguration</code> objects, each
     * listing a lifecycle configuration.</p>
     */
    inline void SetNotebookInstanceLifecycleConfigs(Aws::Vector<NotebookInstanceLifecycleConfigSummary>&& value) { m_notebookInstanceLifecycleConfigs = std::move(value); }

    /**
     * <p>An array of <code>NotebookInstanceLifecycleConfiguration</code> objects, each
     * listing a lifecycle configuration.</p>
     */
    inline ListNotebookInstanceLifecycleConfigsResult& WithNotebookInstanceLifecycleConfigs(const Aws::Vector<NotebookInstanceLifecycleConfigSummary>& value) { SetNotebookInstanceLifecycleConfigs(value); return *this;}

    /**
     * <p>An array of <code>NotebookInstanceLifecycleConfiguration</code> objects, each
     * listing a lifecycle configuration.</p>
     */
    inline ListNotebookInstanceLifecycleConfigsResult& WithNotebookInstanceLifecycleConfigs(Aws::Vector<NotebookInstanceLifecycleConfigSummary>&& value) { SetNotebookInstanceLifecycleConfigs(std::move(value)); return *this;}

    /**
     * <p>An array of <code>NotebookInstanceLifecycleConfiguration</code> objects, each
     * listing a lifecycle configuration.</p>
     */
    inline ListNotebookInstanceLifecycleConfigsResult& AddNotebookInstanceLifecycleConfigs(const NotebookInstanceLifecycleConfigSummary& value) { m_notebookInstanceLifecycleConfigs.push_back(value); return *this; }

    /**
     * <p>An array of <code>NotebookInstanceLifecycleConfiguration</code> objects, each
     * listing a lifecycle configuration.</p>
     */
    inline ListNotebookInstanceLifecycleConfigsResult& AddNotebookInstanceLifecycleConfigs(NotebookInstanceLifecycleConfigSummary&& value) { m_notebookInstanceLifecycleConfigs.push_back(std::move(value)); return *this; }

  private:

    Aws::String m_nextToken;

    Aws::Vector<NotebookInstanceLifecycleConfigSummary> m_notebookInstanceLifecycleConfigs;
  };

} // namespace Model
} // namespace SageMaker
} // namespace Aws

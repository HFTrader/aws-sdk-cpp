﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/ecr/ECR_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/ecr/model/ImageIdentifier.h>
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
namespace ECR
{
namespace Model
{
  class ListImagesResult
  {
  public:
    AWS_ECR_API ListImagesResult();
    AWS_ECR_API ListImagesResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    AWS_ECR_API ListImagesResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    /**
     * <p>The list of image IDs for the requested repository.</p>
     */
    inline const Aws::Vector<ImageIdentifier>& GetImageIds() const{ return m_imageIds; }

    /**
     * <p>The list of image IDs for the requested repository.</p>
     */
    inline void SetImageIds(const Aws::Vector<ImageIdentifier>& value) { m_imageIds = value; }

    /**
     * <p>The list of image IDs for the requested repository.</p>
     */
    inline void SetImageIds(Aws::Vector<ImageIdentifier>&& value) { m_imageIds = std::move(value); }

    /**
     * <p>The list of image IDs for the requested repository.</p>
     */
    inline ListImagesResult& WithImageIds(const Aws::Vector<ImageIdentifier>& value) { SetImageIds(value); return *this;}

    /**
     * <p>The list of image IDs for the requested repository.</p>
     */
    inline ListImagesResult& WithImageIds(Aws::Vector<ImageIdentifier>&& value) { SetImageIds(std::move(value)); return *this;}

    /**
     * <p>The list of image IDs for the requested repository.</p>
     */
    inline ListImagesResult& AddImageIds(const ImageIdentifier& value) { m_imageIds.push_back(value); return *this; }

    /**
     * <p>The list of image IDs for the requested repository.</p>
     */
    inline ListImagesResult& AddImageIds(ImageIdentifier&& value) { m_imageIds.push_back(std::move(value)); return *this; }


    /**
     * <p>The <code>nextToken</code> value to include in a future
     * <code>ListImages</code> request. When the results of a <code>ListImages</code>
     * request exceed <code>maxResults</code>, this value can be used to retrieve the
     * next page of results. This value is <code>null</code> when there are no more
     * results to return.</p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>The <code>nextToken</code> value to include in a future
     * <code>ListImages</code> request. When the results of a <code>ListImages</code>
     * request exceed <code>maxResults</code>, this value can be used to retrieve the
     * next page of results. This value is <code>null</code> when there are no more
     * results to return.</p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextToken = value; }

    /**
     * <p>The <code>nextToken</code> value to include in a future
     * <code>ListImages</code> request. When the results of a <code>ListImages</code>
     * request exceed <code>maxResults</code>, this value can be used to retrieve the
     * next page of results. This value is <code>null</code> when there are no more
     * results to return.</p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextToken = std::move(value); }

    /**
     * <p>The <code>nextToken</code> value to include in a future
     * <code>ListImages</code> request. When the results of a <code>ListImages</code>
     * request exceed <code>maxResults</code>, this value can be used to retrieve the
     * next page of results. This value is <code>null</code> when there are no more
     * results to return.</p>
     */
    inline void SetNextToken(const char* value) { m_nextToken.assign(value); }

    /**
     * <p>The <code>nextToken</code> value to include in a future
     * <code>ListImages</code> request. When the results of a <code>ListImages</code>
     * request exceed <code>maxResults</code>, this value can be used to retrieve the
     * next page of results. This value is <code>null</code> when there are no more
     * results to return.</p>
     */
    inline ListImagesResult& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>The <code>nextToken</code> value to include in a future
     * <code>ListImages</code> request. When the results of a <code>ListImages</code>
     * request exceed <code>maxResults</code>, this value can be used to retrieve the
     * next page of results. This value is <code>null</code> when there are no more
     * results to return.</p>
     */
    inline ListImagesResult& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p>The <code>nextToken</code> value to include in a future
     * <code>ListImages</code> request. When the results of a <code>ListImages</code>
     * request exceed <code>maxResults</code>, this value can be used to retrieve the
     * next page of results. This value is <code>null</code> when there are no more
     * results to return.</p>
     */
    inline ListImagesResult& WithNextToken(const char* value) { SetNextToken(value); return *this;}

  private:

    Aws::Vector<ImageIdentifier> m_imageIds;

    Aws::String m_nextToken;
  };

} // namespace Model
} // namespace ECR
} // namespace Aws

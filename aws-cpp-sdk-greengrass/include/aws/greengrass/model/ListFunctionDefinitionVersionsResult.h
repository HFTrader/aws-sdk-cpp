﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/greengrass/Greengrass_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/greengrass/model/VersionInformation.h>
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
namespace Greengrass
{
namespace Model
{
  class ListFunctionDefinitionVersionsResult
  {
  public:
    AWS_GREENGRASS_API ListFunctionDefinitionVersionsResult();
    AWS_GREENGRASS_API ListFunctionDefinitionVersionsResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    AWS_GREENGRASS_API ListFunctionDefinitionVersionsResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    /**
     * The token for the next set of results, or ''null'' if there are no additional
     * results.
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * The token for the next set of results, or ''null'' if there are no additional
     * results.
     */
    inline void SetNextToken(const Aws::String& value) { m_nextToken = value; }

    /**
     * The token for the next set of results, or ''null'' if there are no additional
     * results.
     */
    inline void SetNextToken(Aws::String&& value) { m_nextToken = std::move(value); }

    /**
     * The token for the next set of results, or ''null'' if there are no additional
     * results.
     */
    inline void SetNextToken(const char* value) { m_nextToken.assign(value); }

    /**
     * The token for the next set of results, or ''null'' if there are no additional
     * results.
     */
    inline ListFunctionDefinitionVersionsResult& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * The token for the next set of results, or ''null'' if there are no additional
     * results.
     */
    inline ListFunctionDefinitionVersionsResult& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * The token for the next set of results, or ''null'' if there are no additional
     * results.
     */
    inline ListFunctionDefinitionVersionsResult& WithNextToken(const char* value) { SetNextToken(value); return *this;}


    /**
     * Information about a version.
     */
    inline const Aws::Vector<VersionInformation>& GetVersions() const{ return m_versions; }

    /**
     * Information about a version.
     */
    inline void SetVersions(const Aws::Vector<VersionInformation>& value) { m_versions = value; }

    /**
     * Information about a version.
     */
    inline void SetVersions(Aws::Vector<VersionInformation>&& value) { m_versions = std::move(value); }

    /**
     * Information about a version.
     */
    inline ListFunctionDefinitionVersionsResult& WithVersions(const Aws::Vector<VersionInformation>& value) { SetVersions(value); return *this;}

    /**
     * Information about a version.
     */
    inline ListFunctionDefinitionVersionsResult& WithVersions(Aws::Vector<VersionInformation>&& value) { SetVersions(std::move(value)); return *this;}

    /**
     * Information about a version.
     */
    inline ListFunctionDefinitionVersionsResult& AddVersions(const VersionInformation& value) { m_versions.push_back(value); return *this; }

    /**
     * Information about a version.
     */
    inline ListFunctionDefinitionVersionsResult& AddVersions(VersionInformation&& value) { m_versions.push_back(std::move(value)); return *this; }

  private:

    Aws::String m_nextToken;

    Aws::Vector<VersionInformation> m_versions;
  };

} // namespace Model
} // namespace Greengrass
} // namespace Aws

﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/databrew/GlueDataBrew_EXPORTS.h>
#include <aws/databrew/GlueDataBrewRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Http
{
    class URI;
} //namespace Http
namespace GlueDataBrew
{
namespace Model
{

  /**
   */
  class AWS_GLUEDATABREW_API ListRulesetsRequest : public GlueDataBrewRequest
  {
  public:
    ListRulesetsRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "ListRulesets"; }

    Aws::String SerializePayload() const override;

    void AddQueryStringParameters(Aws::Http::URI& uri) const override;


    /**
     * <p>The Amazon Resource Name (ARN) of a resource (dataset). Using this parameter
     * indicates to return only those rulesets that are associated with the specified
     * resource.</p>
     */
    inline const Aws::String& GetTargetArn() const{ return m_targetArn; }

    /**
     * <p>The Amazon Resource Name (ARN) of a resource (dataset). Using this parameter
     * indicates to return only those rulesets that are associated with the specified
     * resource.</p>
     */
    inline bool TargetArnHasBeenSet() const { return m_targetArnHasBeenSet; }

    /**
     * <p>The Amazon Resource Name (ARN) of a resource (dataset). Using this parameter
     * indicates to return only those rulesets that are associated with the specified
     * resource.</p>
     */
    inline void SetTargetArn(const Aws::String& value) { m_targetArnHasBeenSet = true; m_targetArn = value; }

    /**
     * <p>The Amazon Resource Name (ARN) of a resource (dataset). Using this parameter
     * indicates to return only those rulesets that are associated with the specified
     * resource.</p>
     */
    inline void SetTargetArn(Aws::String&& value) { m_targetArnHasBeenSet = true; m_targetArn = std::move(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of a resource (dataset). Using this parameter
     * indicates to return only those rulesets that are associated with the specified
     * resource.</p>
     */
    inline void SetTargetArn(const char* value) { m_targetArnHasBeenSet = true; m_targetArn.assign(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of a resource (dataset). Using this parameter
     * indicates to return only those rulesets that are associated with the specified
     * resource.</p>
     */
    inline ListRulesetsRequest& WithTargetArn(const Aws::String& value) { SetTargetArn(value); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of a resource (dataset). Using this parameter
     * indicates to return only those rulesets that are associated with the specified
     * resource.</p>
     */
    inline ListRulesetsRequest& WithTargetArn(Aws::String&& value) { SetTargetArn(std::move(value)); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of a resource (dataset). Using this parameter
     * indicates to return only those rulesets that are associated with the specified
     * resource.</p>
     */
    inline ListRulesetsRequest& WithTargetArn(const char* value) { SetTargetArn(value); return *this;}


    /**
     * <p>The maximum number of results to return in this request.</p>
     */
    inline int GetMaxResults() const{ return m_maxResults; }

    /**
     * <p>The maximum number of results to return in this request.</p>
     */
    inline bool MaxResultsHasBeenSet() const { return m_maxResultsHasBeenSet; }

    /**
     * <p>The maximum number of results to return in this request.</p>
     */
    inline void SetMaxResults(int value) { m_maxResultsHasBeenSet = true; m_maxResults = value; }

    /**
     * <p>The maximum number of results to return in this request.</p>
     */
    inline ListRulesetsRequest& WithMaxResults(int value) { SetMaxResults(value); return *this;}


    /**
     * <p>A token generated by DataBrew that specifies where to continue pagination if
     * a previous request was truncated. To get the next set of pages, pass in the
     * NextToken value from the response object of the previous page call.</p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>A token generated by DataBrew that specifies where to continue pagination if
     * a previous request was truncated. To get the next set of pages, pass in the
     * NextToken value from the response object of the previous page call.</p>
     */
    inline bool NextTokenHasBeenSet() const { return m_nextTokenHasBeenSet; }

    /**
     * <p>A token generated by DataBrew that specifies where to continue pagination if
     * a previous request was truncated. To get the next set of pages, pass in the
     * NextToken value from the response object of the previous page call.</p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextTokenHasBeenSet = true; m_nextToken = value; }

    /**
     * <p>A token generated by DataBrew that specifies where to continue pagination if
     * a previous request was truncated. To get the next set of pages, pass in the
     * NextToken value from the response object of the previous page call.</p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::move(value); }

    /**
     * <p>A token generated by DataBrew that specifies where to continue pagination if
     * a previous request was truncated. To get the next set of pages, pass in the
     * NextToken value from the response object of the previous page call.</p>
     */
    inline void SetNextToken(const char* value) { m_nextTokenHasBeenSet = true; m_nextToken.assign(value); }

    /**
     * <p>A token generated by DataBrew that specifies where to continue pagination if
     * a previous request was truncated. To get the next set of pages, pass in the
     * NextToken value from the response object of the previous page call.</p>
     */
    inline ListRulesetsRequest& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>A token generated by DataBrew that specifies where to continue pagination if
     * a previous request was truncated. To get the next set of pages, pass in the
     * NextToken value from the response object of the previous page call.</p>
     */
    inline ListRulesetsRequest& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p>A token generated by DataBrew that specifies where to continue pagination if
     * a previous request was truncated. To get the next set of pages, pass in the
     * NextToken value from the response object of the previous page call.</p>
     */
    inline ListRulesetsRequest& WithNextToken(const char* value) { SetNextToken(value); return *this;}

  private:

    Aws::String m_targetArn;
    bool m_targetArnHasBeenSet = false;

    int m_maxResults;
    bool m_maxResultsHasBeenSet = false;

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet = false;
  };

} // namespace Model
} // namespace GlueDataBrew
} // namespace Aws

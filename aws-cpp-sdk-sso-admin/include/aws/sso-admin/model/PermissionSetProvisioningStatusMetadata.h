﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/sso-admin/SSOAdmin_EXPORTS.h>
#include <aws/sso-admin/model/StatusValues.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/DateTime.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace SSOAdmin
{
namespace Model
{

  /**
   * <p>Provides information about the permission set provisioning
   * status.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/sso-admin-2020-07-20/PermissionSetProvisioningStatusMetadata">AWS
   * API Reference</a></p>
   */
  class AWS_SSOADMIN_API PermissionSetProvisioningStatusMetadata
  {
  public:
    PermissionSetProvisioningStatusMetadata();
    PermissionSetProvisioningStatusMetadata(Aws::Utils::Json::JsonView jsonValue);
    PermissionSetProvisioningStatusMetadata& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The status of the permission set provisioning process.</p>
     */
    inline const StatusValues& GetStatus() const{ return m_status; }

    /**
     * <p>The status of the permission set provisioning process.</p>
     */
    inline bool StatusHasBeenSet() const { return m_statusHasBeenSet; }

    /**
     * <p>The status of the permission set provisioning process.</p>
     */
    inline void SetStatus(const StatusValues& value) { m_statusHasBeenSet = true; m_status = value; }

    /**
     * <p>The status of the permission set provisioning process.</p>
     */
    inline void SetStatus(StatusValues&& value) { m_statusHasBeenSet = true; m_status = std::move(value); }

    /**
     * <p>The status of the permission set provisioning process.</p>
     */
    inline PermissionSetProvisioningStatusMetadata& WithStatus(const StatusValues& value) { SetStatus(value); return *this;}

    /**
     * <p>The status of the permission set provisioning process.</p>
     */
    inline PermissionSetProvisioningStatusMetadata& WithStatus(StatusValues&& value) { SetStatus(std::move(value)); return *this;}


    /**
     * <p>The identifier for tracking the request operation that is generated by the
     * universally unique identifier (UUID) workflow.</p>
     */
    inline const Aws::String& GetRequestId() const{ return m_requestId; }

    /**
     * <p>The identifier for tracking the request operation that is generated by the
     * universally unique identifier (UUID) workflow.</p>
     */
    inline bool RequestIdHasBeenSet() const { return m_requestIdHasBeenSet; }

    /**
     * <p>The identifier for tracking the request operation that is generated by the
     * universally unique identifier (UUID) workflow.</p>
     */
    inline void SetRequestId(const Aws::String& value) { m_requestIdHasBeenSet = true; m_requestId = value; }

    /**
     * <p>The identifier for tracking the request operation that is generated by the
     * universally unique identifier (UUID) workflow.</p>
     */
    inline void SetRequestId(Aws::String&& value) { m_requestIdHasBeenSet = true; m_requestId = std::move(value); }

    /**
     * <p>The identifier for tracking the request operation that is generated by the
     * universally unique identifier (UUID) workflow.</p>
     */
    inline void SetRequestId(const char* value) { m_requestIdHasBeenSet = true; m_requestId.assign(value); }

    /**
     * <p>The identifier for tracking the request operation that is generated by the
     * universally unique identifier (UUID) workflow.</p>
     */
    inline PermissionSetProvisioningStatusMetadata& WithRequestId(const Aws::String& value) { SetRequestId(value); return *this;}

    /**
     * <p>The identifier for tracking the request operation that is generated by the
     * universally unique identifier (UUID) workflow.</p>
     */
    inline PermissionSetProvisioningStatusMetadata& WithRequestId(Aws::String&& value) { SetRequestId(std::move(value)); return *this;}

    /**
     * <p>The identifier for tracking the request operation that is generated by the
     * universally unique identifier (UUID) workflow.</p>
     */
    inline PermissionSetProvisioningStatusMetadata& WithRequestId(const char* value) { SetRequestId(value); return *this;}


    /**
     * <p>The date that the permission set was created.</p>
     */
    inline const Aws::Utils::DateTime& GetCreatedDate() const{ return m_createdDate; }

    /**
     * <p>The date that the permission set was created.</p>
     */
    inline bool CreatedDateHasBeenSet() const { return m_createdDateHasBeenSet; }

    /**
     * <p>The date that the permission set was created.</p>
     */
    inline void SetCreatedDate(const Aws::Utils::DateTime& value) { m_createdDateHasBeenSet = true; m_createdDate = value; }

    /**
     * <p>The date that the permission set was created.</p>
     */
    inline void SetCreatedDate(Aws::Utils::DateTime&& value) { m_createdDateHasBeenSet = true; m_createdDate = std::move(value); }

    /**
     * <p>The date that the permission set was created.</p>
     */
    inline PermissionSetProvisioningStatusMetadata& WithCreatedDate(const Aws::Utils::DateTime& value) { SetCreatedDate(value); return *this;}

    /**
     * <p>The date that the permission set was created.</p>
     */
    inline PermissionSetProvisioningStatusMetadata& WithCreatedDate(Aws::Utils::DateTime&& value) { SetCreatedDate(std::move(value)); return *this;}

  private:

    StatusValues m_status;
    bool m_statusHasBeenSet = false;

    Aws::String m_requestId;
    bool m_requestIdHasBeenSet = false;

    Aws::Utils::DateTime m_createdDate;
    bool m_createdDateHasBeenSet = false;
  };

} // namespace Model
} // namespace SSOAdmin
} // namespace Aws

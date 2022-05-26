﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/glue/model/RedshiftTarget.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace Glue
{
namespace Model
{

RedshiftTarget::RedshiftTarget() : 
    m_nameHasBeenSet(false),
    m_inputsHasBeenSet(false),
    m_databaseHasBeenSet(false),
    m_tableHasBeenSet(false),
    m_redshiftTmpDirHasBeenSet(false),
    m_tmpDirIAMRoleHasBeenSet(false),
    m_upsertRedshiftOptionsHasBeenSet(false)
{
}

RedshiftTarget::RedshiftTarget(JsonView jsonValue) : 
    m_nameHasBeenSet(false),
    m_inputsHasBeenSet(false),
    m_databaseHasBeenSet(false),
    m_tableHasBeenSet(false),
    m_redshiftTmpDirHasBeenSet(false),
    m_tmpDirIAMRoleHasBeenSet(false),
    m_upsertRedshiftOptionsHasBeenSet(false)
{
  *this = jsonValue;
}

RedshiftTarget& RedshiftTarget::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("Name"))
  {
    m_name = jsonValue.GetString("Name");

    m_nameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Inputs"))
  {
    Array<JsonView> inputsJsonList = jsonValue.GetArray("Inputs");
    for(unsigned inputsIndex = 0; inputsIndex < inputsJsonList.GetLength(); ++inputsIndex)
    {
      m_inputs.push_back(inputsJsonList[inputsIndex].AsString());
    }
    m_inputsHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Database"))
  {
    m_database = jsonValue.GetString("Database");

    m_databaseHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Table"))
  {
    m_table = jsonValue.GetString("Table");

    m_tableHasBeenSet = true;
  }

  if(jsonValue.ValueExists("RedshiftTmpDir"))
  {
    m_redshiftTmpDir = jsonValue.GetString("RedshiftTmpDir");

    m_redshiftTmpDirHasBeenSet = true;
  }

  if(jsonValue.ValueExists("TmpDirIAMRole"))
  {
    m_tmpDirIAMRole = jsonValue.GetString("TmpDirIAMRole");

    m_tmpDirIAMRoleHasBeenSet = true;
  }

  if(jsonValue.ValueExists("UpsertRedshiftOptions"))
  {
    m_upsertRedshiftOptions = jsonValue.GetObject("UpsertRedshiftOptions");

    m_upsertRedshiftOptionsHasBeenSet = true;
  }

  return *this;
}

JsonValue RedshiftTarget::Jsonize() const
{
  JsonValue payload;

  if(m_nameHasBeenSet)
  {
   payload.WithString("Name", m_name);

  }

  if(m_inputsHasBeenSet)
  {
   Array<JsonValue> inputsJsonList(m_inputs.size());
   for(unsigned inputsIndex = 0; inputsIndex < inputsJsonList.GetLength(); ++inputsIndex)
   {
     inputsJsonList[inputsIndex].AsString(m_inputs[inputsIndex]);
   }
   payload.WithArray("Inputs", std::move(inputsJsonList));

  }

  if(m_databaseHasBeenSet)
  {
   payload.WithString("Database", m_database);

  }

  if(m_tableHasBeenSet)
  {
   payload.WithString("Table", m_table);

  }

  if(m_redshiftTmpDirHasBeenSet)
  {
   payload.WithString("RedshiftTmpDir", m_redshiftTmpDir);

  }

  if(m_tmpDirIAMRoleHasBeenSet)
  {
   payload.WithString("TmpDirIAMRole", m_tmpDirIAMRole);

  }

  if(m_upsertRedshiftOptionsHasBeenSet)
  {
   payload.WithObject("UpsertRedshiftOptions", m_upsertRedshiftOptions.Jsonize());

  }

  return payload;
}

} // namespace Model
} // namespace Glue
} // namespace Aws

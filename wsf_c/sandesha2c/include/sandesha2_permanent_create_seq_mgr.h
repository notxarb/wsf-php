/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SANDESHA2_PERMANENT_CREATE_SEQ_MGR_H
#define SANDESHA2_PERMANENT_CREATE_SEQ_MGR_H

/**
 * @file sandesha2_permanent_create_seq_mgr.h
 * @brief Sandesha Permanat Create Sequence Manager Interface
 */

#include <axutil_allocator.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include <axutil_string.h>
#include <axutil_utils.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup sandesha2_permanent_create_seq_mgr Permanat Create Sequence Manager
  * @ingroup sandesha2
  * @{
  */

AXIS2_EXTERN struct sandesha2_create_seq_mgr * AXIS2_CALL
sandesha2_permanent_create_seq_mgr_create(
    const axutil_env_t *env,
    axis2_char_t *dbname);

/** @} */
#ifdef __cplusplus
}
#endif
#endif /* SANDESHA2_PERMANENT_CREATE_SEQ_MGR_H */

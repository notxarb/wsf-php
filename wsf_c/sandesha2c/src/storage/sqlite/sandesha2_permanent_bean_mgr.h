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

#ifndef SANDESHA2_PERMANENT_BEAN_MGR_H
#define SANDESHA2_PERMANENT_BEAN_MGR_H

/**
 * @file sandesha2_permanent_bean_mgr.h
 * @brief Sandesha In Memory Bean Manager Interface
 */

#include <axutil_allocator.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include <axutil_string.h>
#include <axutil_utils.h>
#include <axutil_array_list.h>
#include <sandesha2_msg_store_bean.h>
#include "sqlite3.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct sandesha2_bean_mgr_args sandesha2_bean_mgr_args_t;
typedef struct sandesha2_permanent_bean_mgr sandesha2_permanent_bean_mgr_t;
typedef struct sandesha2_permanent_bean_mgr_ops sandesha2_permanent_bean_mgr_ops_t;
struct sandesha2_response;

struct sandesha2_bean_mgr_args
{
    const axutil_env_t *env;
    void *data;
};

AXIS2_EXTERN sandesha2_permanent_bean_mgr_t * AXIS2_CALL
sandesha2_permanent_bean_mgr_create(
    const axutil_env_t *env,
    axis2_char_t *dbname,
    axis2_char_t *key);

void AXIS2_CALL
sandesha2_permanent_bean_mgr_free(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env);

/**
 * Database insert method. Storage managers use this function
 * to store data to the database
 * @param bean_mgr
 * @param env
 * @param bean
 * @param retrieve_func retrieve callback function
 * @param sql_stmt_retrieve
 * @param sql_stmt_update
 * @param sql_stmt_insert
 */
axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_insert(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *sql_stmt_insert);

axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_remove(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *sql_stmt_remove);

void *AXIS2_CALL
sandesha2_permanent_bean_mgr_retrieve(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    int (*retrieve_func)(void *, int, char **, char **),
    axis2_char_t *sql_stmt_retrieve);

axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_update(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *sql_stmt_update);

axutil_array_list_t *AXIS2_CALL
sandesha2_permanent_bean_mgr_find(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    int (*find_func)(void *, int, char **, char **),
    axis2_char_t *sql_stmt_find);

sandesha2_msg_store_bean_t *AXIS2_CALL
sandesha2_permanent_bean_mgr_retrieve_msg_store_bean(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *key);

axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_update_msg_store_bean(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_msg_store_bean_t *bean);

axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_insert_msg_store_bean(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_msg_store_bean_t *bean);

axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_remove_msg_store_bean(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *key);

axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_store_response(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    axis2_char_t *response,
    int msg_no,
    int soap_version);

axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_remove_response(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    int msg_no);

struct sandesha2_response *AXIS2_CALL
sandesha2_permanent_bean_mgr_retrieve_response(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    int msg_no);

int
sandesha2_permanent_bean_mgr_busy_handler(
    const axutil_env_t *env,
    sqlite3* dbconn,
    char *sql_stmt,
    int (*callback_func)(void *, int, char **, char **),
    void *args,
    char **error_msg,
    int rc);

sqlite3 *
sandesha2_permanent_bean_mgr_get_dbconn(
    const axutil_env_t *env,
    axis2_char_t *dbname);

/** @} */
#ifdef __cplusplus
}
#endif
#endif /* SANDESHA2_PERMANENT_BEAN_MGR_H */

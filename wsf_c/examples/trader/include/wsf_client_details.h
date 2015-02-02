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

#ifndef WSF_CLIENT_DETAILS_H
#define WSF_CLIENT_DETAILS_H

/** @defgroup wsf_client_details_h
 * @ingroup wsf_client_details_h
 * @{
 */

#include <axis2_util.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct wsf_client_details_t wsf_client_details_t;

    AXIS2_EXTERN wsf_client_details_t *AXIS2_CALL
    wsf_client_details_create(const axutil_env_t *env,
        axis2_char_t *ssn,
        axis2_char_t *name,
        axis2_char_t *password);

    AXIS2_EXTERN void AXIS2_CALL
    wsf_client_details_free(wsf_client_details_t *wsf_client_details,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    wsf_client_details_get_ssn(wsf_client_details_t *wsf_client_details,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    wsf_client_details_set_ssn(wsf_client_details_t *wsf_client_details,
            const axutil_env_t *env,
            axis2_char_t *ssn);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    wsf_client_details_get_name(wsf_client_details_t *wsf_client_details,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    wsf_client_details_set_name(wsf_client_details_t *wsf_client_details,
            const axutil_env_t *env,
            axis2_char_t *name);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    wsf_client_details_get_password(wsf_client_details_t *wsf_client_details,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    wsf_client_details_set_password(wsf_client_details_t *wsf_client_details,
            const axutil_env_t *env,
            axis2_char_t *password);

    AXIS2_EXTERN double AXIS2_CALL
    wsf_client_details_get_credit(wsf_client_details_t *wsf_client_details,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    wsf_client_details_set_credit(wsf_client_details_t *wsf_client_details,
            const axutil_env_t *env,
            double credit);

    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    wsf_client_details_get_stock_holdings(wsf_client_details_t *wsf_client_details,
            const axutil_env_t *env);



#ifdef __cplusplus
}
#endif
#endif

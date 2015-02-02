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
 
#ifndef SANDESHA2_ACKS_TO_H
#define SANDESHA2_ACKS_TO_H

/**
  * @file sandesha2_acks_to.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axiom_soap_envelope.h>
#include <sandesha2_address.h>


#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup sandesha2_acks_to
 * @ingroup sandesha2_wsrm
 * @{
 */
typedef struct sandesha2_acks_to_t sandesha2_acks_to_t;

/**
 * @brief sandesha2_acks_to
 *    sandesha2_acks_to
 */

AXIS2_EXTERN sandesha2_acks_to_t * AXIS2_CALL
sandesha2_acks_to_create(
    const axutil_env_t *env, 
    sandesha2_address_t *address,
    axis2_char_t *rm_ns_value, 
    axis2_char_t *addr_ns_value);

axis2_status_t AXIS2_CALL 
sandesha2_acks_to_free(
    sandesha2_acks_to_t *acks_to, 
    const axutil_env_t *env);								

sandesha2_address_t * AXIS2_CALL
sandesha2_acks_to_get_address(
    sandesha2_acks_to_t *acks_to,
    const axutil_env_t *env);
                    	
axis2_status_t AXIS2_CALL 
sandesha2_acks_to_set_address (
    sandesha2_acks_to_t *acks_to, 
    const axutil_env_t *env, 
    sandesha2_address_t *address);								
 
axis2_char_t* AXIS2_CALL 
sandesha2_acks_to_get_namespace_value(
    sandesha2_acks_to_t *acks_to,
	const axutil_env_t *env);

void* AXIS2_CALL 
sandesha2_acks_to_from_om_node(
    sandesha2_acks_to_t *acks_to,
    const axutil_env_t *env, 
    axiom_node_t *om_node);
    
axiom_node_t* AXIS2_CALL 
sandesha2_acks_to_to_om_node(
    sandesha2_acks_to_t *acks_to,
   	const axutil_env_t *env, 
    void *om_node);
 
axutil_array_list_t *AXIS2_CALL
sandesha2_acks_to_get_ref_param_list(
    sandesha2_acks_to_t * acks_to,
    const axutil_env_t * env);

axis2_status_t AXIS2_CALL
sandesha2_acks_to_add_ref_param(
    sandesha2_acks_to_t * acks_to,
    const axutil_env_t * env,
    axiom_node_t * ref_param_node);

/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* SANDESHA2_ACKS_TO_H */


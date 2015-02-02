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
 
#ifndef SANDESHA2_SEQ_OFFER_H
#define SANDESHA2_SEQ_OFFER_H

/**
  * @file sandesha2_seq_offer.h
  * @brief 
  */

#include <sandesha2_error.h>
#include <sandesha2_identifier.h>
#include <sandesha2_endpoint.h>
#include <sandesha2_expires.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup sandesha2_seq_offer
 * @ingroup sandesha2_wsrm
 * @{
 */
    
typedef struct sandesha2_seq_offer_t sandesha2_seq_offer_t;
 
/**
 * @brief sandesha2_seq_offer
 *    sandesha2_seq_offer
 */

AXIS2_EXTERN sandesha2_seq_offer_t* AXIS2_CALL
sandesha2_seq_offer_create(
    const axutil_env_t *env, 
    axis2_char_t *ns_value,
	axis2_char_t *addr_ns_val);

axis2_status_t AXIS2_CALL 
sandesha2_seq_offer_free(
    sandesha2_seq_offer_t *seq_offer, 
	const axutil_env_t *env);

sandesha2_identifier_t * AXIS2_CALL
sandesha2_seq_offer_get_identifier(
    sandesha2_seq_offer_t *seq_offer,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL                 
sandesha2_seq_offer_set_identifier(
    sandesha2_seq_offer_t *seq_offer,
    const axutil_env_t *env, 
    sandesha2_identifier_t *identifier);

sandesha2_endpoint_t * AXIS2_CALL
sandesha2_seq_offer_get_endpoint(
    sandesha2_seq_offer_t *seq_offer,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL                 
sandesha2_seq_offer_set_endpoint(
    sandesha2_seq_offer_t *seq_offer,
    const axutil_env_t *env, 
    sandesha2_endpoint_t *endpoint);

sandesha2_expires_t * AXIS2_CALL                    	
sandesha2_seq_offer_get_expires(
    sandesha2_seq_offer_t *seq_offer,
    const axutil_env_t *env);
                    	
axis2_status_t AXIS2_CALL
sandesha2_seq_offer_set_expires(
    sandesha2_seq_offer_t *seq_offer,
    const axutil_env_t *env, sandesha2_expires_t *expires);
 
axis2_char_t* AXIS2_CALL 
sandesha2_seq_offer_get_namespace_value(
    sandesha2_seq_offer_t *seq_offer,
	const axutil_env_t *env);

void* AXIS2_CALL 
sandesha2_seq_offer_from_om_node(
    sandesha2_seq_offer_t *seq_offer,
    const axutil_env_t *env, 
    axiom_node_t *om_node);

axiom_node_t* AXIS2_CALL 
sandesha2_seq_offer_to_om_node(
    sandesha2_seq_offer_t *seq_offer,
    const axutil_env_t *env, 
    void *om_node);
/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* SANDESHA2_SEQ_OFFER_H */


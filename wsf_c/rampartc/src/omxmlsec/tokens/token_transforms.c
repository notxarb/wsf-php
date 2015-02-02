/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <oxs_tokens.h>

/**
* Creates <ds:Transforms> element
*/
AXIS2_EXTERN axiom_node_t* AXIS2_CALL
oxs_token_build_transforms_element(
    const axutil_env_t *env,
    axiom_node_t *parent)
{
    axiom_node_t *transforms_node = NULL;
    axiom_element_t *transforms_ele = NULL;
    axiom_namespace_t *ns_obj = NULL;

    ns_obj = axiom_namespace_create(env, OXS_DSIG_NS, OXS_DS);
    transforms_ele = axiom_element_create(
        env, parent, OXS_NODE_TRANSFORMS, ns_obj, &transforms_node);
    if(!transforms_ele)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[rampart]Error creating Transforms element.");
        axiom_namespace_free(ns_obj, env);
        return NULL;
    }

    return transforms_node;
}



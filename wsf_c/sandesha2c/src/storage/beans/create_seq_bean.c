/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <sandesha2_create_seq_bean.h>
#include <axutil_env.h>
#include <axutil_utils.h>
#include <axutil_utils_defines.h>
#include <axutil_string.h>


/*create_seq_bean struct */

struct sandesha2_create_seq_bean
{
	/*  a unique identifier that can be used to identify the messages of a certain seq */
	axis2_char_t *internal_seq_id;

	/* This is the message ID of the create seq message. */
	axis2_char_t *create_seq_msg_id;

	/*  This is the actual Sequence ID of the seq.*/
	axis2_char_t *seq_id;
    /**
     * The key that is used to store the CreateSequence message in the Message 
     * Storage.This is stored here, so that the CreateSequence message can be 
     * used as a reference when Sandesha2 want to generate new messages. 
     * (e.g. MakeConnection)
     */
    axis2_char_t *create_seq_msg_store_key;

    /**
     * This is stored here, so that the message pointed by this can be used as a 
     * reference when Sandesha2 want to generate new messages. 
     * (e.g. MakeConnection). Create sequence message could not be used
     * here since it may be subjected to things like encryption.
     */
    axis2_char_t *ref_msg_store_key;
};

AXIS2_EXTERN sandesha2_create_seq_bean_t * AXIS2_CALL
sandesha2_create_seq_bean_create(
    const axutil_env_t *env )
{
	sandesha2_create_seq_bean_t *create_seq_bean = NULL;
	create_seq_bean = (sandesha2_create_seq_bean_t *) AXIS2_MALLOC(
        env->allocator, sizeof(sandesha2_create_seq_bean_t) );

	if (!create_seq_bean)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
		return NULL;
	}
	/* init the properties. */
	create_seq_bean->internal_seq_id = NULL;
	create_seq_bean->create_seq_msg_id = NULL;
	create_seq_bean->seq_id = NULL;
    create_seq_bean->create_seq_msg_store_key = NULL;
    create_seq_bean->ref_msg_store_key = NULL;

	return create_seq_bean;
}
	
AXIS2_EXTERN sandesha2_create_seq_bean_t* AXIS2_CALL 
sandesha2_create_seq_bean_create_with_data(
    const axutil_env_t *env,
    axis2_char_t *internal_seq_id,
    axis2_char_t *create_seq_msg_id,
    axis2_char_t *seq_id)
{
	sandesha2_create_seq_bean_t *create_seq_bean = NULL;
	create_seq_bean = (sandesha2_create_seq_bean_t*) AXIS2_MALLOC(
        env->allocator, sizeof(sandesha2_create_seq_bean_t));

	if (!create_seq_bean)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
		return NULL;
	}

	/* init the properties. */
	create_seq_bean->internal_seq_id = axutil_strdup(env, internal_seq_id);
	create_seq_bean->create_seq_msg_id = axutil_strdup(env, create_seq_msg_id);
	create_seq_bean->seq_id = axutil_strdup(env, seq_id);
    create_seq_bean->create_seq_msg_store_key = NULL;
    create_seq_bean->ref_msg_store_key = NULL;

	return create_seq_bean;
}

void AXIS2_CALL
sandesha2_create_seq_bean_free  (
    sandesha2_create_seq_bean_t *create_seq_bean,
    const axutil_env_t *env)
{
	if(create_seq_bean->internal_seq_id)
	{
		AXIS2_FREE(env->allocator, create_seq_bean->internal_seq_id);
		create_seq_bean->internal_seq_id = NULL;
	}
		
	if(create_seq_bean->create_seq_msg_id)
	{
		AXIS2_FREE(env->allocator, create_seq_bean->create_seq_msg_id);
		create_seq_bean->create_seq_msg_id= NULL;
	}

	if(create_seq_bean->seq_id)
	{
		AXIS2_FREE(env->allocator, create_seq_bean->seq_id);
		create_seq_bean->seq_id = NULL;
	}
	if(create_seq_bean->create_seq_msg_store_key)
	{
		AXIS2_FREE(env->allocator, create_seq_bean->create_seq_msg_store_key);
		create_seq_bean->create_seq_msg_store_key = NULL;
	}
	if(create_seq_bean->ref_msg_store_key)
	{
		AXIS2_FREE(env->allocator, create_seq_bean->ref_msg_store_key);
		create_seq_bean->ref_msg_store_key = NULL;
	}
    if(create_seq_bean)
    {
        AXIS2_FREE(env->allocator, create_seq_bean);
        create_seq_bean = NULL;
    }
}

axis2_char_t * AXIS2_CALL
sandesha2_create_seq_bean_get_create_seq_msg_id( 
    sandesha2_create_seq_bean_t* create_seq_bean,
    const axutil_env_t *env)
{
	return create_seq_bean->create_seq_msg_id;

}	

void AXIS2_CALL
sandesha2_create_seq_bean_set_create_seq_msg_id (
    sandesha2_create_seq_bean_t *create_seq_bean,
    const axutil_env_t *env, 
    axis2_char_t* seq_msg_id)

{
    if(create_seq_bean->create_seq_msg_id)
    {
        AXIS2_FREE(env->allocator, create_seq_bean->create_seq_msg_id);
    }

	create_seq_bean->create_seq_msg_id = axutil_strdup(env, seq_msg_id);
}

axis2_char_t * AXIS2_CALL
sandesha2_create_seq_bean_get_rms_sequence_id(
    sandesha2_create_seq_bean_t *create_seq_bean,
	const axutil_env_t *env)
{
	return create_seq_bean->seq_id;
}

void AXIS2_CALL
sandesha2_create_seq_bean_set_outgoing_sequence_id(
    sandesha2_create_seq_bean_t *create_seq_bean,
	const axutil_env_t *env, 
    axis2_char_t *seq_id)
{
    if(create_seq_bean->seq_id)
    {
        AXIS2_FREE(env->allocator, create_seq_bean->seq_id);
    }

	create_seq_bean->seq_id = axutil_strdup(env, seq_id);
}

axis2_char_t * AXIS2_CALL
sandesha2_create_seq_bean_get_internal_sequence_id( 
    sandesha2_create_seq_bean_t *create_seq_bean,
	const axutil_env_t *env)
{
	return create_seq_bean->internal_seq_id;
}

void AXIS2_CALL
sandesha2_create_seq_bean_set_internal_sequence_id( 
    sandesha2_create_seq_bean_t *create_seq_bean,
	const axutil_env_t *env, axis2_char_t *int_seq_id)
{
    if(create_seq_bean->internal_seq_id)
    {
        AXIS2_FREE(env->allocator, create_seq_bean->internal_seq_id);
    }

	create_seq_bean->internal_seq_id = axutil_strdup(env, int_seq_id);
}

axis2_char_t * AXIS2_CALL
sandesha2_create_seq_bean_get_create_seq_msg_store_key(
    sandesha2_create_seq_bean_t *create_seq_bean,
	const axutil_env_t *env)
{
	return create_seq_bean->create_seq_msg_store_key;
}

void AXIS2_CALL
sandesha2_create_seq_bean_set_create_seq_msg_store_key(
    sandesha2_create_seq_bean_t *create_seq_bean,
	const axutil_env_t *env, axis2_char_t *create_seq_msg_store_key)
{
    if(create_seq_bean->create_seq_msg_store_key)
    {
        AXIS2_FREE(env->allocator, create_seq_bean->create_seq_msg_store_key);
    }

    create_seq_bean->create_seq_msg_store_key = axutil_strdup(env, create_seq_msg_store_key);
}

axis2_char_t * AXIS2_CALL
sandesha2_create_seq_bean_get_ref_msg_store_key( 
    sandesha2_create_seq_bean_t *create_seq_bean,
	const axutil_env_t *env)
{
	return create_seq_bean->ref_msg_store_key;
}

void AXIS2_CALL
sandesha2_create_seq_bean_set_ref_msg_store_key( 
    sandesha2_create_seq_bean_t *create_seq_bean,
	const axutil_env_t *env, axis2_char_t *ref_msg_store_key)
{
    if(create_seq_bean->ref_msg_store_key)
    {
        AXIS2_FREE(env->allocator, create_seq_bean->ref_msg_store_key);
    }

    create_seq_bean->ref_msg_store_key = axutil_strdup(env, ref_msg_store_key);
}


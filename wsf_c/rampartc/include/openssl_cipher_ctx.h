/*
 *   Copyright 2003-2004 The Apache Software Foundation.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */
#include <axis2_defines.h>
#include <axutil_env.h>
#include <openssl/evp.h>
#include <oxs_key.h>
/**
  * @file openssl_cipher_ctx.h
  * @brief The cipher context in which the information regarding a cipher cycle is stored
  */
#ifndef OPENSSL_CIPHER_CTX_H
#define OPENSSL_CIPHER_CTX_H

/**
 * @defgroup openssl_cipher_ctx OpenSSL Cipher Context
 * @ingroup openssl
 * @{
 */



#ifdef __cplusplus
extern "C" {
#endif

    /** Type name for struct openssl_cipher_ctx */
    typedef struct openssl_cipher_ctx_t openssl_cipher_ctx_t;

    /**
     * Free function
     * @param ctx to the openssl cipher ctx struct
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t AXIS2_CALL
    openssl_cipher_ctx_free(
        openssl_cipher_ctx_t *ctx,
        const axutil_env_t *env);
    /**
     * Given the ctx return the CIPHER
     * @param ctx to the openssl cipher ctx struct
     * @param env pointer to environment struct
     * @return RVP_CIPHER the cipher 
     */
    const EVP_CIPHER* AXIS2_CALL
    openssl_cipher_ctx_get_cipher(
        openssl_cipher_ctx_t *ctx,
        const axutil_env_t *env);
    /**
     * Given the ctx return key
     * @param ctx to the openssl cipher ctx struct
     * @param env pointer to environment struct
     * @return key 
     */
    oxs_key_t *AXIS2_CALL
    openssl_cipher_ctx_get_key(
        openssl_cipher_ctx_t *ctx,
        const axutil_env_t *env);
    /**
     * Given the ctx return iv
     * @param ctx to the openssl cipher ctx struct
     * @param env pointer to environment struct
     * @return iv 
     */
    axis2_char_t *AXIS2_CALL
    openssl_cipher_ctx_get_iv(
        openssl_cipher_ctx_t *ctx,
        const axutil_env_t *env);
    /**
     * Given the ctx return the padding
     * @param ctx to the openssl cipher ctx struct
     * @param env pointer to environment struct
     * @return padding
     */
    axis2_char_t *AXIS2_CALL
    openssl_cipher_ctx_get_pad(
        openssl_cipher_ctx_t *ctx,
        const axutil_env_t *env);

    /**
     * Set the Cipher for the cipher context.
     * @param ctx to the openssl cipher ctx struct
     * @param env pointer to environment struct
     * @param EVP_CIPHER The pointer for the Cipher to be set in the cipher context
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t AXIS2_CALL
    openssl_cipher_ctx_set_cipher(
        openssl_cipher_ctx_t *ctx,
        const axutil_env_t *env,
        const EVP_CIPHER*);

    /**
     * Set the Key for the cipher context.
     * @param ctx to the openssl cipher ctx struct
     * @param env pointer to environment struct
     * @param key The key to be set in the cipher context 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t AXIS2_CALL
    openssl_cipher_ctx_set_key(
        openssl_cipher_ctx_t *ctx,
        const axutil_env_t *env,
        oxs_key_t *key);

    /**
     * Set the Initial Value for the cipher context.
     * @param ctx to the openssl cipher ctx struct
     * @param env pointer to environment struct
     * @param iv The Initial Value to be set in the cipher context
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t AXIS2_CALL
    openssl_cipher_ctx_set_iv(
        openssl_cipher_ctx_t *ctx,
        const axutil_env_t *env,
        axis2_char_t *iv);

    /**
     * Set the pad for the cipher context.
     * @param ctx to the openssl cipher ctx struct
     * @param env pointer to environment struct
     * @param pad the pad to be set in the cipher context 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t AXIS2_CALL
    openssl_cipher_ctx_set_pad(
        openssl_cipher_ctx_t *ctx,
        const axutil_env_t *env,
        axis2_char_t *pad);


    /**
     * Create a new cipher context. All the fields carry NULL values at the begining.
     * @param env pointer to environment struct
     * @return Fresh Cipher Context
     */
    AXIS2_EXTERN openssl_cipher_ctx_t *AXIS2_CALL
    openssl_cipher_ctx_create(const axutil_env_t *env);

    /* @} */
#ifdef __cplusplus
}
#endif

#endif    /* OPENSSL_CIPHER_CTX_H */

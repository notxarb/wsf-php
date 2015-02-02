
       /**
        * axis2_getPortfolioResponse.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/C version: #axisVersion# #today#
        *
        */

        #include <axis2_getPortfolioResponse.h>
          
              /**
               * implmentation of the getPortfolioResponse|http://www.wso2.org/types element
               */
             


        struct axis2_getPortfolioResponse
        {
            
                axutil_qname_t* qname;
            axis2_PortFolio_t* attrib_portFolio;
            
        };


       /************************* Function Implmentations ********************************/
        AXIS2_EXTERN axis2_getPortfolioResponse_t* AXIS2_CALL
        axis2_getPortfolioResponse_create(
            const axutil_env_t *env )
        {
            axis2_getPortfolioResponse_t *getPortfolioResponse = NULL;
            
              axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            getPortfolioResponse = (axis2_getPortfolioResponse_t *) AXIS2_MALLOC(env->
                allocator, sizeof(axis2_getPortfolioResponse_t));

            if(NULL == getPortfolioResponse)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            getPortfolioResponse->attrib_portFolio  = NULL;
                  
              qname =  axutil_qname_create (env,
                        "getPortfolioResponse",
                        "http://www.wso2.org/types",
                        "ns1");

              getPortfolioResponse->qname = qname;
            

            return getPortfolioResponse;
         }

        axis2_status_t AXIS2_CALL
        axis2_getPortfolioResponse_free (
                axis2_getPortfolioResponse_t* getPortfolioResponse,
                const axutil_env_t *env)
        {
            
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

            
              if( getPortfolioResponse->attrib_portFolio != NULL)
              {
                 
                 
                      axis2_PortFolio_free( getPortfolioResponse->attrib_portFolio, env);
                   getPortfolioResponse->attrib_portFolio = NULL;
              }

              
              if(getPortfolioResponse->qname )
              {
                  axutil_qname_free (getPortfolioResponse->qname, env);
                  getPortfolioResponse->qname = NULL;
              }
            

            if(getPortfolioResponse)
            {
                AXIS2_FREE( env->allocator, getPortfolioResponse);
                getPortfolioResponse = NULL;
            }
            return AXIS2_SUCCESS;
        }

          
           axutil_qname_t* AXIS2_CALL
           axis2_getPortfolioResponse_get_qname (
                   axis2_getPortfolioResponse_t* getPortfolioResponse,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

               return getPortfolioResponse-> qname;
           }
        

        axis2_status_t AXIS2_CALL
        axis2_getPortfolioResponse_deserialize(
                axis2_getPortfolioResponse_t* getPortfolioResponse,
                const axutil_env_t *env,
                axiom_node_t* parent)
        {

            axis2_status_t status = AXIS2_SUCCESS;
            axiom_namespace_t *ns1 = NULL;
            
               void *element = NULL;
            
             /*axis2_char_t* text_value = NULL;*/
             axutil_qname_t *qname = NULL;
            
            
               axiom_node_t *first_node = NULL;
               
             
               axiom_node_t *current_node = NULL;
               axiom_element_t *current_element = NULL;
            
            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

            ns1 = axiom_namespace_create (env,
                                         "http://www.wso2.org/types",
                                         "ns1");
            
              if ( NULL == parent )
              {
                /** This should be checked above */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL elemenet for getPortfolioResponse"
                                              " %d :: %s", env->error->error_number,
                                              AXIS2_ERROR_GET_MESSAGE(env->error));
                return AXIS2_FAILURE;
              }
            
                    current_element = axiom_node_get_data_element( parent, env);
                    qname = axiom_element_get_qname( current_element, env, parent);
                    if ( axutil_qname_equals( qname, env, getPortfolioResponse-> qname ) )
                    {
                        first_node = axiom_node_get_first_child( parent, env);
                    }
                    else
                    {
                        first_node = parent;
                    }
                 

                     
                     /**
                      * building portFolio element
                      */
                     
                     
                     
                                   current_node = first_node;
                                 
                           if ( current_node != NULL)
                           {
                              current_element = axiom_node_get_data_element( current_node, env);
                                      element = (void*)axis2_PortFolio_create( env);
                                      status =  axis2_PortFolio_deserialize( ( axis2_PortFolio_t*)element, env,
                                                                             axiom_node_get_first_child(current_node, env)==NULL?current_node:axiom_node_get_first_child(current_node, env));
                                      if( AXIS2_FAILURE ==  status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element portFolio "
                                                              " %d :: %s", env->error->error_number,
                                                              AXIS2_ERROR_GET_MESSAGE(env->error));
                                          return AXIS2_FAILURE;
                                      }
                                      status = axis2_getPortfolioResponse_set_portFolio( getPortfolioResponse, env,
                                                                   ( axis2_PortFolio_t*)element);
                                    
                                 if( AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for portFolio "
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                     return AXIS2_FAILURE;
                                 }
                           }
                           
                               else
                               {
                                   /** this is not a nillable element*/
                                   AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "non nillable or minOuccrs != 0 element portFolio missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                   return AXIS2_FAILURE;
                               }
                            

          return status;
       }

        axiom_node_t* AXIS2_CALL
        axis2_getPortfolioResponse_serialize(
                axis2_getPortfolioResponse_t* getPortfolioResponse,
                const axutil_env_t *env, axiom_node_t* parent, int has_parent)
        {
            
            axiom_namespace_t *ns1 = NULL;
            
                    /*axis2_char_t text_value_1[64];*/
                    
               axiom_node_t *current_node = NULL;
               axiom_element_t *current_element = NULL;
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            AXIS2_ENV_CHECK(env, NULL);

            ns1 = axiom_namespace_create (env,
                                         "http://www.wso2.org/types",
                                         "ns1");
            
                if( parent == NULL)
                {
                    current_element = axiom_element_create (env, parent, "getPortfolioResponse", ns1 , &current_node);
                    axiom_element_set_namespace( current_element, env, ns1, current_node);
                    parent = current_node;
                }
               
                if(has_parent)
                {
                    data_source = axiom_node_get_data_element(parent, env);
                    if (!data_source)
                        return NULL;
                    stream = axiom_data_source_get_stream(data_source, env); /* assume parent is of type data source */
                    if (!stream)
                        return NULL;
                    current_node = parent;
                }
                else
                {
                    data_source = axiom_data_source_create(env, parent, &current_node);
                    stream = axiom_data_source_get_stream(data_source, env);
                }
             
                     
                     /**
                      * parsing portFolio element
                      */
                     

                    
                    
                        start_input_str = "<ns1:portFolio xmlns:ns1=\"http://www.wso2.org/types\">";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:portFolio>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                            axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            axis2_PortFolio_serialize( getPortfolioResponse->attrib_portFolio, env, current_node, AXIS2_TRUE);
                            axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
            return parent;
        }

        

            /**
             * getter for portFolio.
             */
            axis2_PortFolio_t* AXIS2_CALL
            axis2_getPortfolioResponse_get_portFolio(
                    axis2_getPortfolioResponse_t* getPortfolioResponse,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return getPortfolioResponse-> attrib_portFolio;
             }

            /**
             * setter for portFolio
             */
            axis2_status_t AXIS2_CALL
            axis2_getPortfolioResponse_set_portFolio(
                    axis2_getPortfolioResponse_t* getPortfolioResponse,
                    const axutil_env_t *env,
                    axis2_PortFolio_t*  param_portFolio)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!getPortfolioResponse)
                {
                    return AXIS2_FAILURE;
                }

                
                  if( NULL == param_portFolio )
                  {
                      AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "portFolio is NULL, but not a nullable element"
                                                 " %d :: %s", env->error->error_number,
                                                 AXIS2_ERROR_GET_MESSAGE(env->error));
                      return AXIS2_FAILURE;
                  }
                getPortfolioResponse-> attrib_portFolio = param_portFolio;
                return AXIS2_SUCCESS;
             }

            


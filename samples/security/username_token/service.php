<?php
/*
 * Copyright 2005,2008 WSO2, Inc. http://wso2.com
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

// User defined function implementing service operation 
function echoFunction($inMessage) {
    $returnMessage = new WSMessage($inMessage->str);
    return $returnMessage;
}

$cert = ws_get_cert_from_file("../keys/bob_cert.cert");
$pvt_key = ws_get_key_from_file("../keys/bob_key.pem");

// Operations and associated options
$operations = array("echoString" => "echoFunction");
$actions = array("http://php.axis2.org/samples/echoString" => "echoString");

// Security options
$security_options = array("useUsernameToken" => TRUE);
$policy = new WSPolicy(array("security"=>$security_options));
$security_token = new WSSecurityToken(array("user" => "Raigama",
                                            "password" => "RaigamaPW",
                                            "passwordType" => "Digest",
											"privateKey" => $pvt_key,
                                       		"certificate" => $cert));

// Create service with options
$service = new WSService(array("operations" => $operations,
                               "actions" => $actions,
                               "policy" => $policy,
                               "securityToken" => $security_token));

// Reply to requests
$service->reply();

?>

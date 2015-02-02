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

$reqPayloadString = <<<XML
<ns1:echo xmlns:ns1="http://wso2.org/wsfphp/samples"><text>Hello World!</text></ns1:echo>
XML;

try {
    $rec_cert = ws_get_cert_from_file("../../keys/bob_cert.cert");
    $pvt_key = ws_get_key_from_file("../../keys/alice_key.pem");
    
    $reqMessage = new WSMessage($reqPayloadString,
                                array("to" => "http://localhost/samples/security/encryption/policy_file_based/service.php",
                                      "action" => "http://wso2.org/wsfphp/samples/echoString"));
    
    $policy_xml = file_get_contents("policy.xml"); 
    $policy = new WSPolicy($policy_xml);
    $sec_token = new WSSecurityToken(array("privateKey" => $pvt_key,
                                           "receiverCertificate" => $rec_cert));
    
    $client = new WSClient(array("useWSA" => TRUE,
                                 "policy" => $policy,
                                 "securityToken" => $sec_token));
				
    $resMessage = $client->request($reqMessage);
    
    printf("Response = %s \n", $resMessage->str);

} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Reason);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}

}
?>

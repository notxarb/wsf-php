--TEST--
Test for echo_signing_client sample
--FILE--
<?php

$reqPayloadString = <<<XML
<ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>
XML;

try {
    $my_cert = ws_get_cert_from_file("samples/keys/alice_cert.cert");
    $my_key = ws_get_key_from_file("samples/keys/alice_key.pem");
    $rec_cert = ws_get_cert_from_file("samples/keys/bob_cert.cert");
    
    $reqMessage = new WSMessage($reqPayloadString,
                                array("to"=>"http://localhost/samples/security/signing/service.php",
                                      "action" => "http://wso2.org/wsfphp/samples/echoString"));
    
    $sec_array = array("sign"=>TRUE,
                       "algorithmSuite" => "Basic256Rsa15",
                       "securityTokenRefernce" => "IssuerSerial");
    
    $policy = new WSPolicy(array("security"=>$sec_array));
    $sec_token = new WSSecurityToken(array("privateKey" => $my_key,
                                           "certificate" => $my_cert,
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

--EXPECT--
Response = <ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>



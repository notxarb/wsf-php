#!/bin/bash
#If your client repository is different, change the value.
CLIENT_REPO="$WSFC_HOME/client_repo"

#INSTALL MODULE to make sure that both server and client have the same module.
echo "Copying latest module to client_repo"
cp -r $WSFC_HOME/modules/rampart $CLIENT_REPO/modules

#RUN
./saml_protect http://localhost:9090/axis2/services/sec_echo/echoString $CLIENT_REPO


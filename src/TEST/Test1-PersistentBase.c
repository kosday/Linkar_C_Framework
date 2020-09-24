#include <malloc.h>
#include <stdio.h>

#include "LinkarStringsHelper.h"
#include "LinkarStrings.h"
#include "CredentialOptions.h"
#include "ConnectionInfo.h"

#include "Types.h"

#include "FunctionsPersistent.h"

void main(void)
{	
	char* credentialOptions = LkCreateCredentialOptions("192.168.100.101", "QMEP1", 11301, "ADMIN", "admin", "", "Test C Library");
	printf("LkCreateCredentialOptions: %s\n", credentialOptions);
	
	char* error;
	char* customVars = "";
	char* connectionInfo = Base_LkLogin(&error, credentialOptions, customVars, 30);
	
	if(error != NULL)
		printf("ERRORS: %s\n", error);
	
	printf("\nconnectionInfo: %s\n", connectionInfo);
	
	char* host = LkExtractDataFromConnectionInfo(connectionInfo, CONN_INFO_HOST);	
	char* entrypoint = LkExtractDataFromConnectionInfo(connectionInfo, CONN_INFO_ENTRYPOINT);
	char* port = LkExtractDataFromConnectionInfo(connectionInfo, CONN_INFO_PORT);	
	char* username = LkExtractDataFromConnectionInfo(connectionInfo, CONN_INFO_USERNAME);	
	char* password = LkExtractDataFromConnectionInfo(connectionInfo, CONN_INFO_PASSWORD);	
	char* language = LkExtractDataFromConnectionInfo(connectionInfo, CONN_INFO_LANGUAGE);	
	char* freetext = LkExtractDataFromConnectionInfo(connectionInfo, CONN_INFO_FREETEXT);	
	char* pluginId = LkExtractDataFromCredentialOptions(credentialOptions, CRD_OPTIONS_PLUGINID);	
	char* sessionId = LkExtractDataFromConnectionInfo(connectionInfo, CONN_INFO_SESSION_ID);	
	char* id = LkExtractDataFromConnectionInfo(connectionInfo, CONN_INFO_ID);	
	char* publicKey = LkExtractDataFromConnectionInfo(connectionInfo, CONN_INFO_PUBLIC_KEY);	
	char* receiveTimeoutStr = LkExtractDataFromConnectionInfo(connectionInfo, CONN_INFO_RECEIVE_TIMEOUT);
	
	printf("\nLkExtractDataFromConnectionInfo Examples:\n");
	printf("HOST: %s\n", host);
	printf("ENTRYPOINT: %s\n", entrypoint);
	printf("PORT: %s\n", port);
	printf("USERNAME: %s\n", username);
	printf("PASSWORD: %s\n", password);
	printf("LANGUAGE: %s\n", language);
	printf("FREETEXT: %s\n", freetext);
	printf("PLUGINID: %s\n", pluginId);
	printf("SESSION ID: %s\n", sessionId);
	printf("CONNECTION ID: %s\n", id);
	printf("PUBLIC KEY: %s\n", publicKey);
	printf("RECEIVE TIMEOUT: %s\n", receiveTimeoutStr);

	free(host);	
	free(entrypoint);
	free(port);
	free(username);
	free(password);
	free(language);
	free(freetext);
	free(sessionId);
	free(id);
	free(publicKey);
	free(receiveTimeoutStr);
	
	// Operation Base_LkRead example
	printf("\nOperation Base_LkRead example\n");
	char* filename = "LK.CUSTOMERS";
	char* recordIds = "1";
	char* dictionaries = "";
	char* readOptions = NULL;
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	DataFormatCruTYPE outputFormat = DataFormatCruTYPE_MV;
	uint32_t receiveTimeout = 10;
	
	char* result = Base_LkRead(&error, &connectionInfo, filename, recordIds, dictionaries, readOptions, inputFormat, outputFormat, customVars, receiveTimeout);
	if(error != NULL)
		printf("ERRORS: %s\n", error);
	printf("result (MV): %s\n", result);

	free(result);

	// Operation LkLogout example
	printf("\nOperation LkLogout example\n");
	printf("connectionInfo BEFORE Logout: %s\n", connectionInfo);
	
	Base_LkLogout(&error, &connectionInfo, customVars, 30);
	printf("Logout result: %s\n", result);
	
	printf("connectionInfo AFTER Logout: %s\n", connectionInfo);
	free(connectionInfo);	
}
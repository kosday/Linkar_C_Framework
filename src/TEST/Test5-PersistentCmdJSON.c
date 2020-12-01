#include <malloc.h>
#include <stdio.h>

#include "CredentialOptions.h"
#include "ConnectionInfo.h"
#include "CommandsPersistent.h"

static void mainProgram(char** connectionInfo)
{	
	// Operation LkSendCommand Read example
	printf("\nOperation LkSendCommand Read example. LK.ORDERS Id 1 and 2\n");

	char* commandTemplate1 = "\
{ \"NAME\" : \"READ\", \"COMMAND\" :\n\
	{\n\
		\"CALCULATED\" : \"False\" ,\n\
		\"CONVERSION\" : \"False\" ,\n\
		\"FORMAT_SPEC\" : \"False\" ,\n\
		\"ORIGINAL_RECORDS\" : \"False\" ,\n\
		\"CUSTOM_VARS\" : \"\" ,\n\
		\"OUTPUT_FORMAT\" : \"JSON\" ,\n\
		\"FILE_NAME\" : \"LK.ORDERS\" ,\n\
		\"DICT_CLAUSE\" : \"\",\n\
       \"RECORDS\" :\n\
       [\n\
           { \"LKITEMID\" : \"1\" },\n\
           { \"LKITEMID\" : \"2\" }\n\
       ]\n\
	}\n\
}\n";
	
	printf("Command Template:\n%s\n", commandTemplate1);
	char* error;
	uint32_t receiveTimeout = 10;
	char* result = LkSendJsonCommand(&error, connectionInfo, commandTemplate1, receiveTimeout);
	if(error != NULL)
		printf("ERRORS: %s\n", error);
	printf("result (JSON): \n%s\n", result);
	free(result);

	char* commandTemplate2 = "\
{ \"NAME\" : \"READ\", \"COMMAND\" :\n\
	{\n\
		\"CALCULATED\" : \"False\" ,\n\
		\"CONVERSION\" : \"False\" ,\n\
		\"FORMAT_SPEC\" : \"False\" ,\n\
		\"ORIGINAL_RECORDS\" : \"False\" ,\n\
		\"CUSTOM_VARS\" : \"\" ,\n\
		\"OUTPUT_FORMAT\" : \"JSON_DICT\" ,\n\
		\"FILE_NAME\" : \"LK.ORDERS\" ,\n\
		\"DICT_CLAUSE\" : \"\",\n\
       \"RECORDS\" :\n\
       [\n\
           { \"LKITEMID\" : \"1\" },\n\
           { \"LKITEMID\" : \"2\" }\n\
       ]\n\
	}\n\
}\n";	
	printf("\n\nCommand Template:\n%s\n", commandTemplate2);
	result = LkSendJsonCommand(&error, connectionInfo, commandTemplate2, receiveTimeout);
	if(error != NULL)
		printf("ERRORS: %s\n", error);
	printf("result (JSON_DICT): \n%s\n", result);
	free(result);
	
	char* commandTemplate3 = "\
{ \"NAME\" : \"READ\", \"COMMAND\" :\n\
	{\n\
		\"CALCULATED\" : \"False\" ,\n\
		\"CONVERSION\" : \"False\" ,\n\
		\"FORMAT_SPEC\" : \"False\" ,\n\
		\"ORIGINAL_RECORDS\" : \"False\" ,\n\
		\"CUSTOM_VARS\" : \"\" ,\n\
		\"OUTPUT_FORMAT\" : \"JSON_SCH\" ,\n\
		\"FILE_NAME\" : \"LK.ORDERS\" ,\n\
		\"DICT_CLAUSE\" : \"\",\n\
       \"RECORDS\" :\n\
       [\n\
           { \"LKITEMID\" : \"1\" },\n\
           { \"LKITEMID\" : \"2\" }\n\
       ]\n\
	}\n\
}\n";
	
	printf("\n\nCommand Template:\n%s\n", commandTemplate3);
	result = LkSendJsonCommand(&error, connectionInfo, commandTemplate3, receiveTimeout);
	if(error != NULL)
		printf("ERRORS: %s\n", error);
	printf("result (JSON_SCH): \n%s\n", result);
	free(result);
}

void main(void)
{	
	char* credentialOptions = LkCreateCredentialOptions("192.168.100.101", "QMEP1", 11301, "ADMIN", "admin", "", "Test C Library");	
	char* error;
	char* customVars = "";
	uint32_t receiveTimeout = 30;
	char* connectionInfo = LkLogin(&error, credentialOptions, customVars, receiveTimeout);
	free(credentialOptions);
	if(error != NULL)
	{
		printf("ERRORS: %s\n", error);
		free(error);
	}
	else
	{
		if(connectionInfo != NULL)
		{
			char* sessionId = LkExtractDataFromConnectionInfo(connectionInfo, CONN_INFO_SESSION_ID);
			if(sessionId != NULL)
			{
				printf("Login successfull with Session Id: %s\n", sessionId);
				free(sessionId);
				
				mainProgram(&connectionInfo);
		
				LkLogout(&error, &connectionInfo, customVars, receiveTimeout);
				free(connectionInfo);
				if(error != NULL)
				{
					printf("ERRORS: %s\n", error);
					free(error);
				}
				printf("\nLogout\n");
			}
		}		
	}
}

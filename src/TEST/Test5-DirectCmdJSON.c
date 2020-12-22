#include <malloc.h>
#include <stdio.h>

#include "CredentialOptions.h"
#include "CommandsDirect.h"

void main(void)
{	
	char* credentialOptions = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "ADMIN", "admin", "", "Test C Library");	
	
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
	char* result = LkSendJsonCommand(&error, credentialOptions, commandTemplate1, receiveTimeout);
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
	result = LkSendJsonCommand(&error, credentialOptions, commandTemplate2, receiveTimeout);
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
	result = LkSendJsonCommand(&error, credentialOptions, commandTemplate3, receiveTimeout);
	if(error != NULL)
		printf("ERRORS: %s\n", error);
	printf("result (JSON_SCH): \n%s\n", result);
	free(result);
	
	free(credentialOptions);
}
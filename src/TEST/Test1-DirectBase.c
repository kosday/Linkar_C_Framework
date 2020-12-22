#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "LinkarStringsHelper.h"
#include "LinkarStrings.h"
#include "CredentialOptions.h"

#include "Types.h"

#include "FunctionsDirect.h"

void main(void)
{	
	char* credentialOptions = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "ADMIN", "admin", "", "Test C Library");
	printf("LkCreateCredentialOptions: %s\n", credentialOptions);

	char* host = LkExtractDataFromCredentialOptions(credentialOptions, CRD_OPTIONS_HOST);	
	char* entrypoint = LkExtractDataFromCredentialOptions(credentialOptions, CRD_OPTIONS_ENTRYPOINT);
	char* port = LkExtractDataFromCredentialOptions(credentialOptions, CRD_OPTIONS_PORT);	
	char* username = LkExtractDataFromCredentialOptions(credentialOptions, CRD_OPTIONS_USERNAME);	
	char* password = LkExtractDataFromCredentialOptions(credentialOptions, CRD_OPTIONS_PASSWORD);	
	char* language = LkExtractDataFromCredentialOptions(credentialOptions, CRD_OPTIONS_LANGUAGE);	
	char* freetext = LkExtractDataFromCredentialOptions(credentialOptions, CRD_OPTIONS_FREETEXT);	
	char* pluginId = LkExtractDataFromCredentialOptions(credentialOptions, CRD_OPTIONS_PLUGINID);	

	printf("\nLkExtractDataFromCredentialOptions Examples:\n");
	printf("HOST: %s\n", host);
	printf("ENTRYPOINT: %s\n", entrypoint);
	printf("PORT: %s\n", port);
	printf("USERNAME: %s\n", username);
	printf("PASSWORD: %s\n", password);
	printf("LANGUAGE: %s\n", language);
	printf("FREETEXT: %s\n", freetext);
	printf("PLUGINID: %s\n", pluginId);

	free(host);	
	free(entrypoint);
	free(port);
	free(username);
	free(password);
	free(language);
	free(freetext);
	free(pluginId);	
	
	printf("\nExtractFromSplit Example:\n");
	printf("char* ep = ExtractFromSplit(credentialOptions, ASCII_FS, CRD_OPTIONS_ENTRYPOINT);\n");
	char* ep = LkExtractFromSplit(credentialOptions, ASCII_FS, CRD_OPTIONS_ENTRYPOINT);
	printf("ep = %s\n", ep);
	free(ep);
	
	// Operation Base_LkRead example
	printf("\nOperation Base_LkRead example\n");
	char* error;
	char* filename = "LK.CUSTOMERS";
	char* recordIds = "1";
	char* dictionaries = "";
	char* readOptions = NULL;
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	DataFormatCruTYPE outputFormat = DataFormatCruTYPE_MV;
	char* customVars = "";
	uint32_t receiveTimeout = 10;
	char* result = Base_LkRead(&error, credentialOptions, filename, recordIds, dictionaries, readOptions, inputFormat, outputFormat, customVars, receiveTimeout);
	if(error != NULL)
	{
		printf("ERRORS: %s\n", error);
		free(error);
	}
	printf("Base_LkRead Result (MV): %s\n", result);
	free(result);
/*
	char *error;
		
	char *lstExp [3] = { "12", "123", "1234" };
	char* expression = LkComposeExpressions((const char** const)lstExp, 3);
	//char* template = "12%c123%c1234";
	//char expression[12];
	//sprintf(expression, template, 254, 254, 254);

	printf("Expression: %s (len: %zd)\n", expression, strlen(expression));
	printf("Expression: ");
	int i;
	for(i=0; i<strlen(expression); i++)
		printf("%02x ", expression[i]);

	free(expression);

	printf("\nBase_LkFormat\n");
	char* result = Base_LkFormat(&error, credentialOptions, expression, "R#10", 1, "", 60);
	if(error)
	{
		printf("Base_LkFormat Error: %s\n", error);
		free(error);
	}
	else
	{
		printf("Base_LkFormat Result %s\n", result);
		char* formatResult = LkExtractFormat(result);
		printf("formatResult Result %s (len: %zd)\n", formatResult, strlen(formatResult));
	
		uint32_t count;
		char** lstFormatResult = LkStrSplit(formatResult, DBMV_Mark_AM, &count);
		//char** lstFormatResult = LkStrSplit(formatResult, 254, &count);
		printf("count: %d\n", count);
		printf("FormatResult [0]: %s\n", lstFormatResult[0]);
		printf("FormatResult [1]: %s\n", lstFormatResult[1]);
		printf("FormatResult [2]: %s\n", lstFormatResult[2]);
		free(formatResult);
				
		free(result);
	}
	
*/
	free(credentialOptions);

}
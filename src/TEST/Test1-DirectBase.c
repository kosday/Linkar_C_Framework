#include <malloc.h>
#include <stdio.h>

#include "LinkarStringsHelper.h"
#include "LinkarStrings.h"
#include "CredentialOptions.h"

#include "Types.h"

#include "FunctionsDirect.h"

void main(void)
{	
	char* credentialOptions = LkCreateCredentialOptions("192.168.100.101", "QMEP1", 11301, "ADMIN", "admin", "", "Test C Library");
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
		printf("ERRORS: %s\n", error);
	printf("result (MV): %s\n", result);

	free(credentialOptions);
	
	free(result);
}
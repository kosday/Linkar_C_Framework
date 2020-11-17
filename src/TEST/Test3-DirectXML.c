#include <malloc.h>
#include <stdio.h>

#include "LinkarStringsHelper.h"
#include "LinkarStrings.h"
#include "CredentialOptions.h"

#include "Types.h"

#include "FunctionsDirectXML.h"
#include "ReleaseMemory.h"

void main(void)
{	
	char* credentialOptions = LkCreateCredentialOptions("192.168.100.101", "QMEP1", 11301, "ADMIN", "admin", "", "Test C Library");	
	
	// Operation LkRead XML example
	printf("\nOperation LkRead XML example. LK.ORDERS Id 1\n");
	char* error;
	char* filename = "LK.ORDERS";
	
	char* recordIds = 
"<LINKAR>\
    <RECORDS>\
        <RECORD>\
            <LKITEMID>1</LKITEMID>\
        </RECORD>\
        <RECORD>\
            <LKITEMID>2</LKITEMID>\
        </RECORD>\
    </RECORDS>\
</LINKAR>";
		
	char* dictionaries = "";
	char* readOptions = NULL;
	char* customVars = "";
	uint32_t receiveTimeout = 10;
	char* result = LkRead(&error, credentialOptions, filename, recordIds, dictionaries, readOptions, XML_FORMAT_XML, customVars, receiveTimeout);
	if(error != NULL)
		printf("ERRORS: %s\n", error);
	printf("result (XML): %s\n", result);
	LkFreeMemory(result);

	printf("\nOperation LkRead XML_DICT example\n");
	result = LkRead(&error, credentialOptions, filename, recordIds, dictionaries, readOptions, XML_FORMAT_XML_DICT, customVars, receiveTimeout);
	if(error != NULL)
		printf("ERRORS: %s\n", error);
	printf("result (XML_DICT): %s\n", result);
	LkFreeMemory(result);

	printf("\nOperation LkRead XML_SCH example\n");
	result = LkRead(&error, credentialOptions, filename, recordIds, dictionaries, readOptions, XML_FORMAT_XML_SCH, customVars, receiveTimeout);
	if(error != NULL)
		printf("ERRORS: %s\n", error);
	printf("result (XML_SCH): %s\n", result);
	LkFreeMemory(result);

	LkFreeMemory(credentialOptions);
}
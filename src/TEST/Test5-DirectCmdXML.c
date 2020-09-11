#include <malloc.h>
#include <stdio.h>

#include "CredentialOptions.h"
#include "CommandsDirect.h"

void main(void)
{	
	char* credentialOptions = LkCreateCredentialOptions("192.168.100.101", "QMEP1", 11301, "ADMIN", "admin", "", "Test C Library");	
	
	// Operation LkSendCommand Read example
	printf("\nOperation LkSendCommand Read example. LK.ORDERS Id 1 and 2\n");

	char* commandTemplate1 = "\
<COMMAND NAME=\"READ\">\n\
	<CALCULATED>False</CALCULATED>\n\
	<CONVERSION>False</CONVERSION>\n\
	<FORMAT_SPEC>False</FORMAT_SPEC>\n\
	<ORIGINAL_RECORDS>False</ORIGINAL_RECORDS>\n\
	<CUSTOM_VARS></CUSTOM_VARS>\n\
	<OUTPUT_FORMAT>XML</OUTPUT_FORMAT>\n\
	<FILE_NAME>LK.ORDERS</FILE_NAME>\n\
	<DICT_CLAUSE></DICT_CLAUSE>\n\
   <RECORDS>\n\
       <RECORD>\n\
           <LKITEMID>1</LKITEMID>\n\
       </RECORD>\n\
       <RECORD>\n\
           <LKITEMID>2</LKITEMID>\n\
       </RECORD>\n\
   </RECORDS>\n\
</COMMAND>\n";
	
	printf("Command Template:\n%s\n", commandTemplate1);
	char* error;
	uint32_t receiveTimeout = 10;
	char* result = LkSendCommand(&error, credentialOptions, commandTemplate1, receiveTimeout);
	if(error != NULL)
		printf("ERRORS: %s\n", error);
	printf("result (XML): \n%s\n", result);
	free(result);

	char* commandTemplate2 = "\
<COMMAND NAME=\"READ\">\n\
	<CALCULATED>False</CALCULATED>\n\
	<CONVERSION>False</CONVERSION>\n\
	<FORMAT_SPEC>False</FORMAT_SPEC>\n\
	<ORIGINAL_RECORDS>False</ORIGINAL_RECORDS>\n\
	<CUSTOM_VARS></CUSTOM_VARS>\n\
	<OUTPUT_FORMAT>XML_DICT</OUTPUT_FORMAT>\n\
	<FILE_NAME>LK.ORDERS</FILE_NAME>\n\
	<DICT_CLAUSE></DICT_CLAUSE>\n\
   <RECORDS>\n\
       <RECORD>\n\
           <LKITEMID>1</LKITEMID>\n\
       </RECORD>\n\
       <RECORD>\n\
           <LKITEMID>2</LKITEMID>\n\
       </RECORD>\n\
   </RECORDS>\n\
</COMMAND>\n";
	
	printf("\n\nCommand Template:\n%s\n", commandTemplate2);
	result = LkSendCommand(&error, credentialOptions, commandTemplate2, receiveTimeout);
	if(error != NULL)
		printf("ERRORS: %s\n", error);
	printf("result (XML_DICT): \n%s\n", result);
	free(result);
	
	char* commandTemplate3 = "\
<COMMAND NAME=\"READ\">\n\
	<CALCULATED>False</CALCULATED>\n\
	<CONVERSION>False</CONVERSION>\n\
	<FORMAT_SPEC>False</FORMAT_SPEC>\n\
	<ORIGINAL_RECORDS>False</ORIGINAL_RECORDS>\n\
	<CUSTOM_VARS></CUSTOM_VARS>\n\
	<OUTPUT_FORMAT>XML_SCH</OUTPUT_FORMAT>\n\
	<FILE_NAME>LK.ORDERS</FILE_NAME>\n\
	<DICT_CLAUSE></DICT_CLAUSE>\n\
   <RECORDS>\n\
       <RECORD>\n\
           <LKITEMID>1</LKITEMID>\n\
       </RECORD>\n\
       <RECORD>\n\
           <LKITEMID>2</LKITEMID>\n\
       </RECORD>\n\
   </RECORDS>\n\
</COMMAND>\n";
	
	printf("\n\nCommand Template:\n%s\n", commandTemplate3);
	result = LkSendCommand(&error, credentialOptions, commandTemplate3, receiveTimeout);
	if(error != NULL)
		printf("ERRORS: %s\n", error);
	printf("result (XML_SCH): \n%s\n", result);
	free(result);
	
	free(credentialOptions);
}
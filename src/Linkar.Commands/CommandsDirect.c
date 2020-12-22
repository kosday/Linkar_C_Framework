/*
	File: CommandsDirect.c
	
	These functions perform direct (without establishing permanent session) operations with output format type XML or JSON, and
	through some templates in standard format XML or JSON.
*/

#include "Linkar.h"
#include "OperationArguments.h"
#include "CommandsDirect.h"

#include <malloc.h>

/*
	Function: LkSendCommand
		Allows making different operations, through some templates in standard format JSON.

	Arguments:
		error - It's the error text. This error can be a system error or socket communication errors with Linkar Server.
		credentialOptions - Object that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		command - Content of the operation you want to send.
		commandFormat - Indicates in what format you are doing the operation: XML or JSON.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. By default 0 (wait indefinitely).

Returns:
		The results of the operation.

	See Also:
		<LkSendJsonCommand>
		
		<LkSendXmlcommand>
		
		<Release Memory>
		
		<Templates LkSendCommand>
*/
DllEntry char* LkSendCommand(char** error, const char* const credentialOptions, const char* const command, EnvelopeFormatTYPE commandFormat, uint32_t receiveTimeout)
{
	uint8_t operationCode;
	if(commandFormat == EnvelopeFormatTYPE_XML)
		operationCode = OP_CODE_COMMAND_XML;
	else
		operationCode = OP_CODE_COMMAND_JSON;
	char* operationArguments = LkGetSendCommandArgs(command);
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	DataFormatTYPE outputFormat = DataFormatTYPE_MV;
	
	char* result = LkExecuteDirectOperation(error, credentialOptions, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	free(operationArguments);
	
	return result;
}

/*
	Function: LkSendJsonCommand
		Allows making different operations, through some templates in standard format JSON.

	Arguments:
		error - It's the error text. This error can be a system error or socket communication errors with Linkar Server.
		credentialOptions - Object that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		command - Content of the operation you want to send.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. By default 0 (wait indefinitely).

	Returns:
		The results of the operation.
		
	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "CommandsDirect.h"
		#include "ReleaseMemory.h"
		
		char* MyCommandRead(char** error)
		{
			char* result;
			char* credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			
			string command = 
		"{\
			\"NAME\" : \"READ\",
			\"COMMAND\" : 
			{\
				\"CALCULATED\" : \"True\" ,\
				\"OUTPUT_FORMAT\" : \"JSON_SCH\" ,\
				\"FILE_NAME\" : \"LK.CUSTOMERS\" ,\
				\"RECORDS\" : [ \
					{ \"LKITEMID\" : \"2\" }\ 
				]\
			}\
		}";

			result = LkSendJsonCommand(error, credentials, command, 600);
			LkFreeMemory(credentials);
			return result;
		}
		---

	See Also:
		<LkSendCommand>
		
		<Release Memory>
		
		<Templates LkSendCommand>
*/
DllEntry char* LkSendJsonCommand(char** error, const char* const credentialOptions, const char* const command, uint32_t receiveTimeout)
{
	return LkSendCommand(error, credentialOptions, command, EnvelopeFormatTYPE_JSON, receiveTimeout);
}

/*
	Function: LkSendXmlCommand
		Allows making different operations, through some templates in standard format XML.

	Arguments:
		error - It's the error text. This error can be a system error or socket communication errors with Linkar Server.
		credentialOptions - Object that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		command - Content of the operation you want to send.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. By default 0 (wait indefinitely).

	Returns:
		The results of the operation.

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "CommandsDirect.h"
		#include "ReleaseMemory.h"
		
		char* MyCommandRead(char** error)
		{
			char* result;
			char* credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			
			string command = 
		"<COMMAND NAME=\"READ\">\
			<CALCULATED>True</CALCULATED>\
			<OUTPUT_FORMAT>XML_SCH</OUTPUT_FORMAT>\
			<FILE_NAME>LK.CUSTOMERS</FILE_NAME>\
				<RECORDS>\
					<RECORD>\
						<LKITEMID>2</LKITEMID>\
					</RECORD>\
				</RECORDS>\
		</COMMAND>";

			result = LkSendXmlCommand(error, credentials, command, 600);
			LkFreeMemory(credentials);
			return result;
		}
		---

	See Also:
		<LkSendCommand>
	
		<Release Memory>
		
		<Templates LkSendCommand>
*/
DllEntry char* LkSendXmlCommand(char** error, const char* const credentialOptions, const char* const command, uint32_t receiveTimeout)
{
	return LkSendCommand(error, credentialOptions, command, EnvelopeFormatTYPE_XML, receiveTimeout);
}


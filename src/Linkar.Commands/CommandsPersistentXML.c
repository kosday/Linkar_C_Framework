/*
	File: PersistentCommandsXML.c
	
	These functions perform persistent (establishing permanent session) operations with output format type XML.
*/

#include "Linkar.h"
#include "OperationArguments.h"
#include "ConnectionInfo.h"
#include "CommandsPersistent.h"

#include <malloc.h>

/*
	Function: LkLogin
		Starts the communication with a server allowing making use of the rest of functions until the Logout method is executed or the connection with the server gets lost.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely. Values less than or equal to 0, waits indefinitely. This value is also the value that will be use the other persistent functions of the same session, when its receiveTimeout argument is less or equal to 0.
		
	Returns:
		A complex string that contains data about the established session in LinkarSERVER.
		You can extract data from this string using <LkExtractDataFromConnectionInfo> function.
		
	See Also:
		<LkCreateCredentialOptions>
		
		<LkExtractDataFromConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkLogin(char** error, char* credentialOptions, const char* const customVars, uint32_t receiveTimeout)
{	
	char* connectionInfo = LkCreateConnectionInfo(credentialOptions, receiveTimeout);
	char* connectionInfoCopy = connectionInfo;
	
	uint8_t operationCode = OP_CODE_LOGIN;	

	//operationArguments = customVars + ASCII_Chars.US_str + options;
	char* options = "";
	char* operationArguments = LkCatString(customVars, options, ASCII_US_str);	
	
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	DataFormatTYPE outputFormat = DataFormatTYPE_MV;
	
	char* result = LkExecutePersistentOperation(error, &connectionInfo, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	// After LOGIN, "connectionInfo" is modified with the new values of CONN_INFO_ID and CONN_INFO_PUBLIC_KEY
	// LkExecutePersistentOperation always execute the Login operation with "inputFormat" and "outputFormat" MV.
	if(connectionInfo != connectionInfoCopy)
		free(connectionInfoCopy);

	if(*error == NULL && result != NULL && *result != 0)
	{
		uint32_t *count = 0;
		char* sessionId = LkExtractData(result, RECORD_IDS_KEY, ASCII_FS, DBMV_Mark_AM);
					
		if(sessionId != NULL)
		{
			// Add to "connectionInfo", in CONN_INFO_SESSION_ID	position, the value of sessionId
			char* newConnectionInfo = LkChangeConnectionInfo(connectionInfo, CONN_INFO_SESSION_ID, sessionId);
			
			free(connectionInfo);
			connectionInfo = newConnectionInfo;
		}
	}	

	return connectionInfo;
}

/*
	Function: LkLogout
		Closes the communication with the server, that previously has been opened with a <LkLogin> function.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely. Values less than or equal to 0, waits indefinitely.
				
	See Also:
		<LkLogin>	
*/
DllEntry void LkLogout(char **error, char** connectionInfo, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_LOGOUT;
	//operationArguments = customVars;
	char* operationArguments = LkCatString(customVars, NULL, NULL);
	
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	DataFormatTYPE outputFormat = DataFormatTYPE_MV;
	
	LkExecutePersistentOperation(error, connectionInfo, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	char* newConnectionInfo = LkChangeConnectionInfo(*connectionInfo, CONN_INFO_SESSION_ID, "");
	char* newConnectionInfo2 = LkChangeConnectionInfo(newConnectionInfo, CONN_INFO_ID, "");
	free(newConnectionInfo);
	char* newConnectionInfo3 = LkChangeConnectionInfo(newConnectionInfo2, CONN_INFO_PUBLIC_KEY, "");
	free(newConnectionInfo2);
	
	*connectionInfo = newConnectionInfo3;
}

/*
	Function: LkSendCommand
		Allows making different operations, through some templates in standard format XML.

	Arguments:
		error - It's the error text. This error can be a system error or socket communication errors with Linkar Server.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
		command - Content of the operation you want to send.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. By default 0 (wait indefinitely).
		
	Returns:
		The results of the operation.
		

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "ConnectionInfo.h"
		#include "CommandsDirect.h"
		#include "ReleaseMemory.h"

		char* MyCommandRead(char** error)
		{
			char* result;
			CredentialOptions credentials = LkCreateCredentialOptions("192.168.100.101", "QMEP1", 11301, "admin", "admin", "", "");
			char* connectionInfo = LkLogin(error, credentials, "", 600);
			LkFreeMemory(credentials);
			if(error == NULL && connectionInfo != NULL)
			{
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

				result = LkSendCommand(error, connectionInfo, command, 0);
				LkLogout(error, connectionInfo, "", 0);
				LkFreeMemory(connectionInfo);
			}
			return result;
		}
		---

	See Also:
		<Release Memory>
		
		<Templates LkSendCommand>
*/
DllEntry char* LkSendCommand(char** error, char** connectionInfo, const char* const command, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_COMMAND_XML;	
	char* operationArguments = LkGetSendCommandArgs(command);
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	DataFormatTYPE outputFormat = DataFormatTYPE_MV;
	
	char* result = LkExecutePersistentOperation(error, connectionInfo, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	free(operationArguments);
		
	return result;
}
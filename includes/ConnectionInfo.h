/*
	File: ConnectionInfo.h
	Header file for ConnectionInfo private functions.
*/
#include "CompilerOptions.h"
#include "Types.h"

#define CONN_INFO_COUNT 12
#define CONN_INFO_HOST 0
#define CONN_INFO_ENTRYPOINT 1
#define CONN_INFO_PORT 2
#define CONN_INFO_USERNAME 3
#define CONN_INFO_PASSWORD 4
#define CONN_INFO_LANGUAGE 5
#define CONN_INFO_FREETEXT 6
#define CONN_INFO_PLUGINID 7
#define CONN_INFO_SESSION_ID 8
#define CONN_INFO_ID 9
#define CONN_INFO_PUBLIC_KEY 10
#define CONN_INFO_RECEIVE_TIMEOUT 11

/*
	Function: LkCreateConnectionInfo
		Creates a coded string that contains the connection info.
		This function creates a coded string that contains all the necessary information for the <Persistent functions>.

	Note: 
		This is just the prototype function. The real function is implemented inside the "Linkar" private library (Linkar.dll/Linkar.lib/Linkar.so/Linkar.a).
		
	Arguments:
		credentialOptions - The coded string create with <LkComposeCredentialOptions> or <LkComposeCredentialOptionsPlugin>.
		receiveTimeout - It's the DEFAULT maximum time in seconds that the client will keep waiting the answer by the server. By default 0 (wait indefinitely). When the operation functions use 0 or lower value in their receiveTimeout argument, this DEFAULT value will be used instead.
		
	Returns:
		A coded string that contains the connection info with the necessary information to connect to LinkarServer.
		
	See Also:
		<LkCreateCredentialOptions>
		
		<LkCreateCredentialOptionsPlugin>
				
		<Release Memory>
*/
DllEntry char* LkCreateConnectionInfo(const char* const credentialOptions, uint32_t receiveTimeout);

/*
	Function: LkChangeConnectionInfo
		Inside the "connectionInfo" string change the item of position "index" by the value of "newValue".

	Note: 
		This is just the prototype function. The real function is implemented inside the "Linkar" private library (Linkar.dll/Linkar.lib/Linkar.so/Linkar.a).
		
	Arguments:
		connectionInfo - The string where will be done the change.
		index - The item position inside the string where will be done the change.
		newValue - The new value to be changed inside the string.
		
	Returns:
		New connectionInfo string with the value changed.
		
	See Also:
		<Release Memory>
*/
DllEntry char* LkChangeConnectionInfo(const char* const connectionInfo, uint32_t index, const char* const newValue);

/*
	Function: LkExtractAllDataFromConnectionInfo

	Note: 
		This is just the prototype function. The real function is implemented inside the "Linkar" private library (Linkar.dll/Linkar.lib/Linkar.so/Linkar.a).
	
	Arguments:
		connectionInfo - String that contains the different elements that constitute the ConnectionInfo.
		
	Returns:
		Pointer array to strings, where each string is a ConnectionInfo element.
		
	See Also:
		<LkCreateCredentialOptions>
		
		<LkCreateCredentialOptionsPlugin>
		
		<Release Memory>
*/
DllEntry char** LkExtractAllDataFromConnectionInfo(const char* const connectionInfo);

/*
	Function: LkExtractDataFromConnectionInfo
		Extracts from a "CredentialOptions" coded string, each of its components.

	Note: 
		This is just the prototype function. The real function is implemented inside the "Linkar" private library (Linkar.dll/Linkar.lib/Linkar.so/Linkar.a).

	Arguments:
		connectionInfo - String that contains the different elements that constitute the Credential Options.
		index - Number that represents the item to be extracted from the "connectionInfo". See <ConnectionInfo Options Index>
	
	Returns:
		The extracted element from "credentialOptions".
		
	See Also:
		<LkCreateConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkExtractDataFromConnectionInfo(const char* const connectionInfo, uint32_t index);

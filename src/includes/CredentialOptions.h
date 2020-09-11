#include "CompilerOptions.h"
#include "Types.h"
/*
	Constants: For use with CredentialOptions strings

	These constants represent the position of every item inside the "credentialOptions" string.
		
		CRD_OPTIONS_COUNT  - The total numbers of items inside the "credentialOptions" string (8)
		CRD_OPTIONS_HOST - Position of the item HOST (0)
		CRD_OPTIONS_ENTRYPOINT - Position of the item ENTRYPOINT (1)
		CRD_OPTIONS_PORT - Position of the item PORT (2)
		CRD_OPTIONS_USERNAME - Position of the item USERNAME (3)
		CRD_OPTIONS_PASSWORD - Position of the item PASSWORD (4)
		CRD_OPTIONS_LANGUAGE - Position of the item LANGUAGE (5)
		CRD_OPTIONS_FREETEXT - Position of the item FREETEXT (6)
		CRD_OPTIONS_PLUGINID - Position of the item PLUGINID (7)
*/
#define CRD_OPTIONS_COUNT 8
#define CRD_OPTIONS_HOST 0
#define CRD_OPTIONS_ENTRYPOINT 1
#define CRD_OPTIONS_PORT 2
#define CRD_OPTIONS_USERNAME 3
#define CRD_OPTIONS_PASSWORD 4
#define CRD_OPTIONS_LANGUAGE 5
#define CRD_OPTIONS_FREETEXT 6
#define CRD_OPTIONS_PLUGINID 7

/*
	Function: LkCreateCredentialOptions
		Creates a coded string that contains the connection credentials.
		This function creates a coded string that contains all the necessary information for the <Direct functions>, as well as for the <LkLogin> function.
		
	Note: 
		This is just the prototype function. The real function is implemented inside the "Linkar" private library (Linkar.dll/Linkar.lib/Linkar.so/Linkar.a).
	
	Arguments:
		host - IP address or hostname where Linkar Server is listening.
		entrypoint - The EntryPoint Name defined in Linkar Server.
		port - Port number where the EntryPoint keeps listening.
		username - Linkar Server username.
		password - Password of the user Linkar Server.
		language - Used to make the database routines know in which language they must answer. 
					The Error messages coming from the Database are in English by default, but you can _*customize*_ them.
		freetext - Free text that will appear in the Linkar MANAGER to identify in an easy way who is making the petition.
					For example if the call is made from a ERP, here we can write "MyERP".
	
	Returns:
		A coded string that contains the connection credentials.
		
	See Also:
		<LkLogin>
		
		<Direct Functions>
		
		<Release Memory>
*/
DllEntry char* LkCreateCredentialOptions(char* host, char* entrypoint, uint32_t port, char* username, char* password, char* language, char* freetext);

/*
	Function: LkCreateCredentialOptionsPlugin
		Creates a coded string that contains the connection credentials.
		This function creates a coded string that contains all the necessary information for the <Direct functions>, as well as for the <LkLogin> function.

	Note: 
		This is just the prototype function. The real function is implemented inside the "Linkar" private library (Linkar.dll/Linkar.lib/Linkar.so/Linkar.a).
		
	Arguments:
		host - IP address or hostname where Linkar Server is listening.
		entrypoint - The EntryPoint Name defined in Linkar Server.
		port - Port number where the EntryPoint keeps listening.
		username - Linkar Server username.
		password - Password of the user Linkear Server.
		language - Used to make the database routines know in which language they must answer. 
					The Error messages coming from the Database are in English by default, but you can _*customize*_ them.
		freetext - Free text that will appear in the Linkar MANAGER to identify in an easy way who is making the petition.
					For example if the call is made from a ERP, here we can write "MyERP".
		pluginId - Plugin code to use in Linkar Server. The Plugin must be activated in Linkar Server.
	
	Returns:
		A coded string that contains the connection credentials.
		
	See Also:
		<LkLogin>
		
		<Direct Functions>
		
		<Release Memory>
*/
DllEntry char* LkCreateCredentialOptionsPlugin(char* host, char* entrypoint, uint32_t port, char* username, char* password, char* language, char* freetext, char* pluginId);

/*
	Function: LkExtractAllDataFromCredentialOptions

	Note: 
		This is just the prototype function. The real function is implemented inside the "Linkar" private library (Linkar.dll/Linkar.lib/Linkar.so/Linkar.a).
	
	Arguments:
		credentialOptions - String that contains the different elements that constitute the Credential Options.
		
	Returns:
		Pointer array to strings, where each string is a CredentialOptions element.
		
	See Also:
		<LkCreateCredentialOptions>
		
		<LkCreateCredentialOptionsPlugin>
		
		<Release Memory>
*/
DllEntry char** LkExtractAllDataFromCredentialOptions(const char* const credentialOptions);

/*
	Function: LkExtractDataFromCredentialOptions
		Extracts from a "credentialOptions" coded string, each of its components.

	Note: 
		This is just the prototype function. The real function is implemented inside the "Linkar" private library (Linkar.dll/Linkar.lib/Linkar.so/Linkar.a).

	Arguments:
		credentialOptions - String that contains the different elements that constitute the CredentialOptions.
		index - Number that represents the item to be extracted from the "credentialOptions".
	
	Returns:
		The extracted element from credentialOptions string.
		
	See Also:
		<LkComposeCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* LkExtractDataFromCredentialOptions(const char* const credentialOptions, uint32_t index);

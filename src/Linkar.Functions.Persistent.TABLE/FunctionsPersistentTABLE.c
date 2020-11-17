/*
	File: PersistentFunctionsTABLE.c
	
	These functions perform persistent (establishing permanent session) operations with output format type TABLE.
	
	Note:
	All functions comments here, return a char* value. That memory was allocated dynamically, so once those string is not needed anymore, the memory assigned to them *must be released*.
	See <Release Memory> for known how to do.
*/

#include "FunctionsPersistent.h"
#include "FunctionsPersistentTABLE.h"

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
	char* result = Base_LkLogin(error, credentialOptions, customVars, receiveTimeout);
	
	return result;
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
DllEntry void LkLogout(char **error, char* connectionInfo, const char* const customVars, uint32_t receiveTimeout)
{
	Base_LkLogout(error, connectionInfo, customVars, receiveTimeout);
}

/*
	Function: LkSchemas
		Returns a list of all the Schemas defined in Linkar Schemas, or the EntryPoint account data files with TABLE output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
		lkSchemasOptions - This string defines the different options in base of the asked Schema Type: LKSCHEMAS, SQLMODE o DICTIONARIES.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	See Also:
		<LkCreateSchOptionsTypeLKSCHEMAS>
		
		<LkCreateSchOptionsTypeSQLMODE>
		
		<LkCreateSchOptionsTypeDICTIONARIES>
		
		<LkLogin>
		
		<LkLogout>
		
		<LkCreateConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkSchemas(char** error, char* connectionInfo, const char* const lkSchemasOptions, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatSchTYPE outputFormat = DataFormatSchTYPE_TABLE;			
	char* result = Base_LkSchemas(error, connectionInfo, lkSchemasOptions, outputFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkProperties
		Returns the Schema properties list defined in Linkar Schemas or the file dictionaries with TABLE output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
		filename - File name to LkProperties.
		lkPropertiesOptions - This string defines the different options in base of the asked Schema Type: LKSCHEMAS, SQLMODE o DICTIONARIES.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	See Also:
		<LkCreatePropOptionsTypeLKSCHEMAS>
		
		<LkCreatePropOptionsTypeSQLMODE>
		
		<LkCreatePropOptionsTypeDICTIONARIES>
		
		<LkLogin>
		
		<LkLogout>
		
		<LkCreateConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkProperties(char** error, char* connectionInfo, const char* const filename, const char* const lkPropertiesOptions, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatSchTYPE outputFormat = DataFormatSchTYPE_TABLE;
	char* result = Base_LkProperties(error, connectionInfo, filename, lkPropertiesOptions, outputFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkGetTable
		Returns a query result in a table format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
        filename - File or table name defined in Linkar Schemas. Table notation is: MainTable[.MVTable[.SVTable]]
        selectClause - Fragment of the phrase that indicate the selection condition. For example WITH CUSTOMER = '1'
        dictClause - Is the list of dictionaries to read, separated by space. If dictionaries are not indicated the function will read the complete buffer. For example CUSTOMER DATE ITEM
        sortClause - Fragment of the phrase that indicates the selection order. If there is a selection rule Linkar will execute a SSELECT, otherwise Linkar will execute a SELECT. For example BY CUSTOMER
        tableOptions - Different function options: rowHeaders, rowProperties, onlyVisibe, usePropertyNames, repeatValues, applyConversion, applyFormat, calculated, pagination, regPage, numPage
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
	
	See Also:
		<LkCreateTableOptionsTypeLKSCHEMAS>
		
		<LkCreateTableOptionsTypeSQLMODE>
		
		<LkCreateTableOptionsTypeDICTIONARIES>
		
		<LkCreateTableOptionsTypeNONE>

		<LkLogin>
		
		<LkLogout>
		
		<LkCreateConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkGetTable(char** error, char* connectionInfo, const char* const filename, const char* const selectClause, const char* const dictClause, const char* const sortClause, const char* const tableOptions, const char* const customVars, uint32_t receiveTimeout)
{
	char* result = Base_LkGetTable(error, connectionInfo, filename, selectClause, dictClause, sortClause, tableOptions, customVars, receiveTimeout);
	
	return result;	
}

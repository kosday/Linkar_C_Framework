/*
	File: DirectFunctionsTABLE.c
	
	These functions perform direct (without establishing permanent session) operations with output format type TABLE.
	
	Note:
	All functions comments here, return a char* value. That memory was allocated dynamically, so once those string is not needed anymore, the memory assigned to them *must be released*.
	See <Release Memory> for known how to do.
*/

#include "FunctionsDirect.h"
#include "FunctionsDirectTABLE.h"

/*
	Function: LkSchemas
		Returns a list of all the Schemas defined in Linkar Schemas, or the EntryPoint account data files with TABLE output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		lkSchemasOptions - This string defines the different options in base of the asked Schema Type: LKSCHEMAS, SQLMODE o DICTIONARIES.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	See Also:
		<LkCreateSchOptionsTypeLKSCHEMAS>
		
		<LkCreateSchOptionsTypeSQLMODE>
		
		<LkCreateSchOptionsTypeDICTIONARIES>
		
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* LkSchemas(char** error, const char* const credentialOptions, const char* const lkSchemasOptions, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE outputFormat = DataFormatSchTYPE_TABLE;	
	char* result = Base_LkSchemas(error, credentialOptions, lkSchemasOptions, outputFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkProperties
		Returns the Schema properties list defined in Linkar Schemas or the file dictionaries with TABLE output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
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
		
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* LkProperties(char** error, const char* const credentialOptions, const char* const filename, const char* const lkPropertiesOptions, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE outputFormat = DataFormatSchTYPE_TABLE;	
	char* result = Base_LkProperties(error, credentialOptions, filename, lkPropertiesOptions, outputFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkGetTable
		Returns a query result in a table format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
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
		
		<LkCreateCredentialOptions>

		<Release Memory>
*/
DllEntry char* LkGetTable(char** error, const char* const credentialOptions, const char* const filename, const char* const selectClause, const char* const dictClause, const char* const sortClause, const char* const tableOptions, const char* const customVars, uint32_t receiveTimeout)
{
	char* result = Base_LkGetTable(error, credentialOptions, filename, selectClause, dictClause, sortClause, tableOptions, customVars, receiveTimeout);
		
	return result;	
}



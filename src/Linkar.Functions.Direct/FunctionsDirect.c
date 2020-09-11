/*
	File: DirectFunctions.c
	
	These functions perform direct (without establishing permanent session) operations with any kind of output format type.
	
	Used for direct and independent communication with the Database.
	Their arguments contain the necessary information to identify the user before returning the required information. 
	Unlike the Persistent Functions, they do not have a Session Code, each call is completely independent of the others and they do not have Login or Close functions. 
		
	They are used, for example, to access the Databases from public web pages, such as online stores. 
		
	Note: 
	All functions comments here, return a char* value. That memory was allocated dynamically, so once those string is not needed anymore, the memory assigned to them *must be released*.
	See <Release Memory> for known how to do.
*/

#include "Linkar.h"
#include "OperationArguments.h"
#include "FunctionsDirect.h"

#include <malloc.h>

/*
	Function: Base_LkRead
		Reads one or several records of a file.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		filename - File name to read.
		recordIds - It's the records codes list to read, separated by the Record Separator character (30). Use <LkComposeRecordIds> to compose this string.
		dictionaries - List of dictionaries to read, separated by space. If dictionaries are not indicated the function will read the complete buffer.
		readOptions - String that defines the different reading options of the Function: Calculated, dictClause, conversion, formatSpec, originalRecords.
		outputFormat - Indicates in what format you want to receive the data resulting from the Read, New, Update and Select operations: MV, XML, XML_DICT, XML_SCH, JSON, JSON_DICT or JSON_SCH
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	See Also:
		<LkCreateReadOptions>
		
		<LkCreateCredentialOptions>
				
		<Release Memory>
*/
DllEntry char* Base_LkRead(char** error, const char* const credentialOptions, const char* const filename, const char* const recordIds, const char* const dictionaries, const char* const readOptions, DataFormatCruTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{	
	uint8_t operationCode = OP_CODE_READ;
	char* operationArguments = LkGetReadArgs(filename, recordIds, dictionaries, readOptions, customVars);
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	
	char* result = LkExecuteDirectOperation(error, credentialOptions, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	free(operationArguments);
	
	return result;
}

/*
	Function: Base_LkUpdate
		Update one or several records of a file.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		filename - File name where you are going to write.
		records - Are the records you want to update. Inside this string are the recordIds, the records, and the originalRecords.
		updateOptions - Object that defines the different writing options of the Function: optimisticLockControl, readAfter, calculated, dictionaries, conversion, formatSpec, originalRecords.
		inputFormat - Indicates in what format you wish to send the resultant writing data: MV, XML or JSON.
		outputFormat - Indicates in what format you want to receive the data resulting from the Read, New, Update and Select operations: MV, XML, XML_DICT, XML_SCH, JSON, JSON_DICT or JSON_SCH.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
	
	See Also:
		<LkCreateUpdateOptions>
		
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* Base_LkUpdate(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const updateOptions, DataFormatTYPE inputFormat, DataFormatCruTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_UPDATE;
	char* operationArguments = LkGetUpdateArgs(filename, records, updateOptions, customVars);

	char* result = LkExecuteDirectOperation(error, credentialOptions, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	free(operationArguments);
	
	return result;	
}

/*
	Function: Base_LkNew
		Creates one or several records of a file.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		filename - File name where you are going to write.
		records - Are the records you want to write. Inside this string are the recordIds, and the records.
		newOptions - String that defines the following writing options of the Function: recordIdType, readAfter, calculated, dictionaries, conversion, formatSpec, originalRecords.
		inputFormat - Indicates in what format you wish to send the resultant writing data: MV, XML or JSON.
		outputFormat - Indicates in what format you want to receive the data resulting from the Read, New, Update and Select operations: MV, XML, XML_DICT, XML_SCH, JSON, JSON_DICT or JSON_SCH.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
	
	See Also:
		<LkCreateNewOptions>
		
		<LkCreateNewRecordIdTypeNone>
		
		<LkCreateNewRecordIdTypeLinkar>
		
		<LkCreateNewRecordIdTypeCustom>
		
		<LkCreateNewRecordIdTypeRandom>
		
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* Base_LkNew(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const newOptions, DataFormatTYPE inputFormat, DataFormatCruTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_NEW;
	char* operationArguments = LkGetNewArgs(filename, records, newOptions, customVars);	
	
	char* result = LkExecuteDirectOperation(error, credentialOptions, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);	
	
	free(operationArguments);
	
	return result;	
}

/*
	Function: Base_LkDelete
		Deletes one or several records in file.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		filename - It's the file name where the records are going to be deleted. DICT in case of deleting a record that belongs to a dictionary.
		records - It's the records list to be deleted.
		deleteOptions - Object that defines the different Function options: optimisticLockControl, recoverRecordIdType.
		outputFormat - Indicates in what format you want to receive the data resulting from the operation: MV, XML or JSON.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	See Also:
		<LkCreateDeleteOptions>
		
		<LkCreateRecoverRecordIdTypeNone>
		
		<LkCreateRecoverRecordIdTypeLinkar>
		
		<LkCreateRecoverRecordIdTypeCustom>
		
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* Base_LkDelete(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const deleteOptions, DataFormatCruTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_DELETE;
	char* operationArguments = LkGetDeleteArgs(filename, records, deleteOptions, customVars);
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	
	char* result = LkExecuteDirectOperation(error, credentialOptions, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	free(operationArguments);
	
	return result;
}

/*
	Function: Base_LkSelect
		Executes a Query in the Database.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		filename - File name where the select operation will be perform. For example LK.ORDERS
		selectClause - Fragment of the phrase that indicate the selection condition. For example WITH CUSTOMER = '1'
		sortClause - Fragment of the phrase that indicates the selection order. If there is a selection rule, Linkar will execute a SSELECT, otherwise Linkar will execute a SELECT. For example BY CUSTOMER
		dictClause - Is the list of dictionaries to read, separated by space. If dictionaries are not indicated the function will read the complete buffer. For example CUSTOMER DATE ITEM
		preSelectClause - It's an optional statement that will execute before the main Select.
		selectOptions - String that defines the different reading options of the Function: calculated, dictionaries, conversion, formatSpec, originalRecords, onlyItemId, pagination, regPage, numPage.
		outputFormat - Indicates in what format you want to receive the data resulting from the Read, New, Update and Select operations: MV, XML, XML_DICT, XML_SCH, JSON, JSON_DICT or JSON_SCH.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	See Also:
		<LkCreateSelectOptions>

		<LkCreateCredentialOptions>

		<Release Memory>
*/
DllEntry char* Base_LkSelect(char** error, const char* const credentialOptions, const char* const filename, const char* const selectClause, const char* const sortClause, const char* const dictClause, const char* const preSelectClause, const char* const selectOptions, DataFormatCruTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_SELECT;
	char* operationArguments = LkGetSelectArgs(filename, selectClause, sortClause, dictClause, preSelectClause, selectOptions, customVars);
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	
	char* result = LkExecuteDirectOperation(error, credentialOptions, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	free(operationArguments);
	
	return result;
}
		
/*
	Function: Base_LkSubroutine
		Executes a subroutine.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		subroutineName - Subroutine name you want to execute.
		argsNumber - The number of arguments.
		arguments - The subroutine arguments list.
		outputFormat - Indicates in what format you want to receive the data resulting from the operation: MV, XML or JSON.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	See Also:
		<LkAddArgumentSubroutine>
		
		<LkCreateCredentialOptions>

		<Release Memory>
*/
DllEntry char* Base_LkSubroutine(char** error, const char* const credentialOptions, const char* const subroutineName, uint32_t argsNumber, const char* const arguments, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_SUBROUTINE;
	char* operationArguments = LkGetSubroutineArgs(subroutineName, argsNumber, arguments, customVars);
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	
	char* result = LkExecuteDirectOperation(error, credentialOptions, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	free(operationArguments);
	
	return result;	
}

/*
	Function: Base_LkConversion
		Returns the result of executing ICONV() or OCONV() functions from a expression list in the Database.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		conversionOptions - Indicates the conversion type, input or output: Input=ICONV(); OUTPUT=OCONV()
		expression - The data or expression to convert. It can have MV marks, in which case the conversion will execute in each value obeying the original MV mark.
		code - The conversion code. It will have to obey the Database conversions specifications.
		outputFormat - Indicates in what format you want to receive the data resulting from the operation: MV, XML or JSON.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	See Also:
		<CONVERSION_TYPE>
		
		<LkCreateCredentialOptions>

		<Release Memory>
*/
DllEntry char* Base_LkConversion(char** error, const char* const credentialOptions, const char* const expression, const char* const code, CONVERSION_TYPE conversionOptions, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_CONVERSION;
	char* operationArguments = LkGetConversionArgs(expression, code, conversionOptions, customVars);
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	
	char* result = LkExecuteDirectOperation(error, credentialOptions, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	free(operationArguments);
	
	return result;	
}

/*
	Function: Base_LkFormat
		Returns the result of executing the FMT function in a expressions list in the Database.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		expression - The data or expression to format. It can contain MV marks, in which case the conversion in each value will be executed according to the original MV mark.
		formatSpec - Specified format.
		outputFormat - Indicates in what format you want to receive the data resulting from the operation: MV, XML or JSON.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation..
		
	See Also:
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* Base_LkFormat(char** error, const char* const credentialOptions, const char* const expression, const char* const formatSpec, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_FORMAT;
	char* operationArguments = LkGetFormatArgs(expression, formatSpec, customVars);
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	
	char* result = LkExecuteDirectOperation(error, credentialOptions, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	free(operationArguments);
	
	return result;	
}

/*
	Function: Base_LkDictionaries
		Returns all the dictionaries of a file.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		filename - File name.
		outputFormat - Indicates in what format you want to receive the data resulting from the operation: MV, XML or JSON.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	See Also:
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* Base_LkDictionaries(char** error, const char* const credentialOptions, const char* const filename, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_DICTIONARIES;
	char* operationArguments = LkGetDictionariesArgs(filename, customVars);
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	
	char* result = LkExecuteDirectOperation(error, credentialOptions, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	free(operationArguments);
	
	return result;	
}

/*
	Function: Base_LkExecute
		Allows the execution of any command from the Database.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		statement - The command you want to execute in the Database.
		outputFormat - Indicates in what format you want to receive the data resulting from the operation: MV, XML or JSON.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation..
		
	See Also:
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* Base_LkExecute(char** error, const char* const credentialOptions, const char* const statement, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_DICTIONARIES;
	char* operationArguments = LkGetExecuteArgs(statement, customVars);
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	
	char* result = LkExecuteDirectOperation(error, credentialOptions, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	free(operationArguments);
	
	return result;	
}

/*
	Function: Base_LkGetVersion
		Allows getting the server version.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		outputFormat - Indicates in what format you want to receive the data resulting from the operation: MV, XML or JSON.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	See Also:
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* Base_LkGetVersion(char** error, const char* const credentialOptions, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_GETVERSION;
	char* operationArguments = LkGetGetVersionArgs();
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	
	char* result = LkExecuteDirectOperation(error, credentialOptions, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	free(operationArguments);
	
	return result;	
}

/*
	Function: Base_LkSchemas
		Returns a list of all the Schemas defined in Linkar Schemas, or the EntryPoint account data files.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		lkSchemasOptions - This string defines the different options in base of the asked Schema Type: LKSCHEMAS, SQLMODE o DICTIONARIES.
		outputFormat - Indicates in what format you want to receive the data resulting from the operation: MV, XML, JSON or TABLE
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
DllEntry char* Base_LkSchemas(char** error, const char* const credentialOptions, const char* const lkSchemasOptions, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_LKSCHEMAS;
	char* operationArguments = LkGetLkSchemasArgs(lkSchemasOptions, customVars);
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	
	char* result = LkExecuteDirectOperation(error, credentialOptions, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	free(operationArguments);
	
	return result;	
}

/*
	Function: Base_LkProperties
		Returns the Schema properties list defined in Linkar Schemas or the file dictionaries with MV output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		filename - File name to LkProperties.
		lkPropertiesOptions - This string defines the different options in base of the asked Schema Type: LKSCHEMAS, SQLMODE o DICTIONARIES.
		outputFormat - Indicates in what format you want to receive the data resulting from the operation: MV, XML, JSON or TABLE
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
DllEntry char* Base_LkProperties(char** error, const char* const credentialOptions, const char* const filename, const char* const lkPropertiesOptions, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_LKPROPERTIES;
	char* operationArguments = LkGetLkPropertiesArgs(filename, lkPropertiesOptions, customVars);
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	
	char* result = LkExecuteDirectOperation(error, credentialOptions, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	free(operationArguments);
	
	return result;	
}

/*
	Function: Base_LkGetTable
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
DllEntry char* Base_LkGetTable(char** error, const char* const credentialOptions, const char* const filename, const char* const selectClause, const char* const dictClause, const char* const sortClause, const char* const tableOptions, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_GETTABLE;
	char* operationArguments = LkGetGetTableArgs(filename, selectClause, dictClause, sortClause, tableOptions, customVars);
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	DataFormatTYPE outputFormat = DataFormatSchTYPE_TABLE;
	
	char* result = LkExecuteDirectOperation(error, credentialOptions, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	free(operationArguments);
	
	return result;	
}

/*
	Function: Base_LkResetCommonBlocks
		Resets the COMMON variables with the 100 most used files.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		outputFormat - Indicates in what format you want to receive the data resulting from the operation: MV, XML or JSON.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	See Also:
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* Base_LkResetCommonBlocks(char** error, const char* const credentialOptions, DataFormatTYPE outputFormat, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_GETVERSION;
	char* operationArguments = LkGetResetCommonBlocksArgs();
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	
	char* result = LkExecuteDirectOperation(error, credentialOptions, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	free(operationArguments);
	
	return result;	
}

/*
	File: FunctionsDirect.c
	
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
		dictionaries - List of dictionaries to read, separated by space. If dictionaries are not indicated the function will read the complete buffer. You may use the format LKFLDx where x is the attribute number.
		readOptions - String that defines the different reading options of the Function: Calculated, dictClause, conversion, formatSpec, originalRecords.
		inputFormat - Indicates in what format you wish to send the record ids: MV, XML or JSON.
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
DllEntry char* Base_LkRead(char** error, const char* const credentialOptions, const char* const filename, const char* const recordIds, const char* const dictionaries, const char* const readOptions, DataFormatTYPE inputFormat, DataFormatCruTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{	
	uint8_t operationCode = OP_CODE_READ;
	char* operationArguments = LkGetReadArgs(filename, recordIds, dictionaries, readOptions, customVars);
	
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
	
	Remarks:
		Inside the records argument, the recordIds and the modified records always must be specified. But the originalRecords not always.
		When updateOptions argument is specified with its optimisticLock property set to true, a copy of the record must be provided before the modification (originalRecords argument)
		to use the Optimistic Lock technique. This copy can be obtained from a previous <Base_LkRead> operation. The database, before executing the modification, 
		reads the record and compares it with the copy in originalRecords, if they are equal the modified record is executed.
		But if they are not equal, it means that the record has been modified by other user and its modification will not be saved.
		The record will have to be read, modified and saved again.
	
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
	Function: Base_LkUpdatePartial
		Update one or more attributes of one or more file records.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		filename - File name where you are going to write.
		records - Are the records you want to update. Inside this string are the recordIds, the records, and the originalRecords.
		dictionaries - List of dictionaries to write, separated by space. In MV output format is mandatory. You may use the format LKFLDx where x is the attribute number.
		updateOptions - Object that defines the different writing options of the Function: optimisticLockControl, readAfter, calculated, dictionaries, conversion, formatSpec, originalRecords.
		inputFormat - Indicates in what format you wish to send the resultant writing data: MV, XML or JSON.
		outputFormat - Indicates in what format you want to receive the data resulting from the Read, New, Update and Select operations: MV, XML, XML_DICT, XML_SCH, JSON, JSON_DICT or JSON_SCH.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
	
	Remarks:
		Inside the records argument, the recordIds and the modified records always must be specified. But the originalRecords not always.
		When updateOptions argument is specified with its optimisticLock property set to true, a copy of the record must be provided before the modification (originalRecords argument)
		to use the Optimistic Lock technique. This copy can be obtained from a previous <Base_LkRead> operation. The database, before executing the modification, 
		reads the record and compares it with the copy in originalRecords, if they are equal the modified record is executed.
		But if they are not equal, it means that the record has been modified by other user and its modification will not be saved.
		The record will have to be read, modified and saved again.
	
	See Also:
		<LkCreateUpdateOptions>
		
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* Base_LkUpdatePartial(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const dictionaries, const char* const updateOptions, DataFormatTYPE inputFormat, DataFormatCruTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_UPDATEPARTIAL;
	char* operationArguments = LkGetUpdatePartialArgs(filename, records, dictionaries, updateOptions, customVars);

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
	
	Remarks:
		Inside the records argument, the records always must be specified. But the recordIds only must be specified when newOptions argument is null, or when the recordIdType argument of the newOptions argument is null.
		
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
		inputFormat - Indicates in what format you wish to send the resultant deleting data: MV, XML or JSON.
		outputFormat - Indicates in what format you want to receive the data resulting from the operation: MV, XML or JSON.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	Remarks:
		Inside the records argument, the recordIds always must be specified. But the originalRecords not always.
		When deleteOptions argument is specified with its optimisticLock property set to true,
		a copy of the record must be provided before the deletion (originalRecords argument) to use the Optimistic Lock technique.
		This copy can be obtained from a previous <Base_LkRead> operation. The database, before executing the deletion, 
		reads the record and compares it with the copy in originalRecords, if they are equal the record is deleted.
		But if they are not equal, it means that the record has been modified by other user and the record will not be deleted.
		The record will have to be read, and deleted again.
		
	See Also:
		<LkCreateDeleteOptions>
		
		<LkCreateRecoverRecordIdTypeNone>
		
		<LkCreateRecoverRecordIdTypeLinkar>
		
		<LkCreateRecoverRecordIdTypeCustom>
		
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* Base_LkDelete(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const deleteOptions, DataFormatTYPE inputFormat, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_DELETE;
	char* operationArguments = LkGetDeleteArgs(filename, records, deleteOptions, customVars);
	
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
		dictClause - Is the list of dictionaries to read, separated by space. If dictionaries are not indicated the function will read the complete buffer. For example CUSTOMER DATE ITEM. You may use the format LKFLDx where x is the attribute number.
		preSelectClause - It's an optional statement that will execute before the main Select.
		selectOptions - String that defines the different reading options of the Function: calculated, dictionaries, conversion, formatSpec, originalRecords, onlyItemId, pagination, regPage, numPage.
		outputFormat - Indicates in what format you want to receive the data resulting from the Read, New, Update and Select operations: MV, XML, XML_DICT, XML_SCH, JSON, JSON_DICT or JSON_SCH.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	Remarks:
		In the preSelectClause argument these operations can be carried out before executing the Select statement:
		
		- Previously call to a saved list with the GET.LIST command to use it in the Main Select input.
		- Make a previous Select to use the result as the Main Select input, with the SELECT or SSELECT commands.In this case the entire sentence must be indicated in the PreselectClause. For example:SSELECT LK.ORDERS WITH CUSTOMER = '1'
		- Exploit a Main File index to use the result as a Main Select input, with the SELECTINDEX command. The syntax for all the databases is SELECTINDEX index.name.value. For example SELECTINDEX ITEM,"101691"

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
		inputFormat - Indicates in what format you wish to send the subroutine arguments: MV, XML or JSON.
		outputFormat - Indicates in what format you want to receive the data resulting from the operation: MV, XML or JSON.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	See Also:
		<LkComposeSubroutineArgs>
		
		<LkCreateCredentialOptions>

		<Release Memory>
*/
DllEntry char* Base_LkSubroutine(char** error, const char* const credentialOptions, const char* const subroutineName, uint32_t argsNumber, const char* const arguments, DataFormatTYPE inputFormat, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_SUBROUTINE;
	char* operationArguments = LkGetSubroutineArgs(subroutineName, argsNumber, arguments, customVars);
	
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
		conversionType - Indicates the conversion type, input or output: Input=ICONV(); OUTPUT=OCONV()
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
DllEntry char* Base_LkConversion(char** error, const char* const credentialOptions, const char* const expression, const char* const code, CONVERSION_TYPE conversionType, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout)
{
	uint8_t operationCode = OP_CODE_CONVERSION;
	char* operationArguments = LkGetConversionArgs(expression, code, conversionType, customVars);
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
	uint8_t operationCode = OP_CODE_EXECUTE;
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
		
	Remarks:
		This function returns the following information:
		
		LKMVCOMPONENTSVERSION - MV Components version.
		LKSERVERVERSION - Linkar SERVER version.
		LKCLIENTVERSION - Used client library version.
		DATABASE - Database.
		OS - Operating system.
		DATEZERO - Date zero base in YYYYMMDD format.
		DATEOUTPUTCONVERSION - Output conversion for date used by Linkar Schemas.
		TIMEOUTPUTCONVERSION - Output conversion for time used by Linkar Schemas.
		MVDATETIMESEPARATOR - DateTime used separator used by Linkar Schemas, for instance 18325,23000.
		MVBOOLTRUE - Database used char for the Boolean true value used by Linkar Schemas.
		MVBOOLFALSE - Database used char for the Boolean false value used by Linkar Schemas.
		OUTPUTBOOLTRUE - Used char for the Boolean true value out of the database used by Linkar Schemas.
		OUTPUTBOOLFALSE - Used char for the Boolean false value out of the database used by Linkar Schemas.
		MVDECIMALSEPARATOR - Decimal separator in the database. May be point, comma or none when the database does not store decimal numbers. Used by Linkar Schemas.
		OTHERLANGUAGES - Languages list separated by commas.
		TABLEROWSEPARATOR - It is the decimal char that you use to separate the rows in the output table format. By default 11.
		TABLECOLSEPARATOR - It is the decimal char that you use to separate the columns in the output table format. By default 9.
	
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
		
	Remarks:
		TABLE output format uses the defined control characters in <EntryPoints Parameters: http://kosday.com/Manuals/en_web_linkar/lk_schemas_ep_parameters.html> Table Row Separator and Column Row Separator.
		
		By default:
		
		- TAB char (9) for columns.
		- VT char (11) for rows.
	
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
		
	Remarks:
		TABLE output format uses the defined control characters in <EntryPoints Parameters: http://kosday.com/Manuals/en_web_linkar/lk_schemas_ep_parameters.html> Table Row Separator and Column Row Separator.
		
		By default:
		
		- TAB char (9) for columns.
		- VT char (11) for rows.
	
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
        dictClause - Is the list of dictionaries to read, separated by space. If dictionaries are not indicated the function will read the complete buffer. For example CUSTOMER DATE ITEM. In NONE mode you may use the format LKFLDx where x is the attribute number.
        sortClause - Fragment of the phrase that indicates the selection order. If there is a selection rule Linkar will execute a SSELECT, otherwise Linkar will execute a SELECT. For example BY CUSTOMER
        tableOptions - Different function options: rowHeaders, rowProperties, onlyVisibe, usePropertyNames, repeatValues, applyConversion, applyFormat, calculated, pagination, regPage, numPage
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	Remarks:
		TABLE output format uses the defined control characters in <EntryPoints Parameters: http://kosday.com/Manuals/en_web_linkar/lk_schemas_ep_parameters.html> Table Row Separator and Column Row Separator.
		
		By default:
		
		- TAB char (9) for columns.
		- VT char (11) for rows.
	
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
	uint8_t operationCode = OP_CODE_RESETCOMMONBLOCKS;
	char* operationArguments = LkGetResetCommonBlocksArgs();
	DataFormatTYPE inputFormat = DataFormatTYPE_MV;
	
	char* result = LkExecuteDirectOperation(error, credentialOptions, operationCode, operationArguments, inputFormat, outputFormat, receiveTimeout);
	
	free(operationArguments);
	
	return result;	
}

/*
	File: FunctionsDirectXML.c
	
	These functions perform direct (without establishing permanent session) operations with output format type XML.
	
	Note:
	All functions comments here, return a char* value. That memory was allocated dynamically, so once those string is not needed anymore, the memory assigned to them *must be released*.
	See <Release Memory> for known how to do.
*/

#include "FunctionsDirect.h"
#include "FunctionsDirectXML.h"

/*
	Function: LkRead
		Reads one or several records of a file with XML output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		filename - File name to read.
		recordIds - It's the records codes list to read, separated by the Record Separator character (30). Use <LkComposeRecordIds> to compose this string.
		dictionaries - List of dictionaries to read, separated by space. If dictionaries are not indicated the function will read the complete buffer.
		readOptions - String that defines the different reading options of the Function: Calculated, dictClause, conversion, formatSpec, originalRecords.
		xmlFormat - Different XML output formats.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "DirectFunctionsXML.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
		
		char* MyRead(char** error)
		{
			char* result;
			char* credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* options = lkCreateReadOptions(TRUE, FALSE, FALSE, FALSE);
			XML_FORMAT xmlFormat = XML_FORMAT_XML;
			result = LkRead(error, credentials, "LK.CUSTOMERS",
		"<?xml version=\"1.0\" encoding=\"utf-16\"?>\
		<LINKAR>\
			<RECORDS>\
				<RECORD>\
					<LKITEMID>2</LKITEMID>\
				</RECORD>\
			</RECORDS>\
		</LINKAR>",
				"",options, xmlFormat, "", 600);
			LkFreeMemory(options);
			LkFreeMemory(credentials);
			return result;
		}
		---

	See Also:
		<LkCreateReadOptions>
		
		<LkCreateCredentialOptions>

		<Release Memory>
*/
DllEntry char* LkRead(char** error, const char* const credentialOptions, const char* const filename, const char* const recordIds, const char* const dictionaries, const char* const readOptions, XML_FORMAT xmlFormat, const char* const customVars, uint32_t receiveTimeout)
{	
	DataFormatTYPE inputFormat = DataFormatTYPE_XML;	
	char* result = Base_LkRead(error, credentialOptions, filename, recordIds, dictionaries, readOptions, inputFormat, xmlFormat, customVars, receiveTimeout);
		
	return result;
}

/*
	Function: LkUpdate
		Update one or several records of a file with XML input and output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		filename - File name where you are going to write.
		records - Are the records you want to update. Inside this string are the recordIds, the records, and the originalRecords.
		updateOptions - Object that defines the different writing options of the Function: optimisticLockControl, readAfter, calculated, dictionaries, conversion, formatSpec, originalRecords.
		xmlFormat - Different XML output formats.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "DirectFunctionsXML.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
		
		char* MyUpdate(char** error)
		{
			char* result;
			char* credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			
			char* options = LkCreateUpdateOptions(FALSE, TRUE, TRUE, FALSE, FALSE, FALSE);
			XML_FORMAT xmlFormat = XML_FORMAT_XML;
			result = LkUpdate(error, credentials, "LK.CUSTOMERS",
		"<?xml version=\"1.0\" encoding=\"utf-16\"?>\
		<LINKAR>\
			<RECORDS>\
				<RECORD>\
					<LKITEMID>2</LKITEMID>\
					<NAME>CUSTOMER 2</NAME>\
					<ADDR>NEW ADDRESS 2</ADDR>\
					<PHONE>444 - 444 - 002</PHONE>\
				</RECORD>\
			</RECORDS>\
		</LINKAR>",
				options, xmlFormat, "", 600);
			
			LkFreeMemory(options);
			LkFreeMemory(credentials);
			return result;
		}
		---

	See Also:
		<LkCreateUpdateOptions>
		
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* LkUpdate(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const updateOptions, XML_FORMAT xmlFormat, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE inputFormat = DataFormatTYPE_XML;
	char* result = Base_LkUpdate(error, credentialOptions, filename, records, updateOptions, inputFormat, xmlFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkNew
		Creates one or several records of a file with XML input and output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		filename - File name where you are going to write.
		records - Are the records you want to write. Inside this string are the recordIds, and the records.
		newOptions - String that defines the following writing options of the Function: recordIdType, readAfter, calculated, dictionaries, conversion, formatSpec, originalRecords.
		xmlFormat - Different XML output formats.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "DirectFunctionsXML.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
		
		char* MyNew(char** error)
		{
			char* result;
			char* credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* recordIdType = LkCreateNewRecordIdTypeNone();
			char* newOptions = lkCreateNewOptions(recordIdType, TRUE, FALSE, FALSE, FALSE);
			LkFreeMemory(recordIdType);
			XML_FORMAT xmlFormat = XML_FORMAT_XML;
			result = LkNew(error, credentials, "LK.CUSTOMERS",
		"<?xml version=\"1.0\" encoding=\"utf-16\"?>\
		<LINKAR>\
			<RECORDS>\
				<RECORD>\
					<LKITEMID>2</LKITEMID>\
					<NAME>CUSTOMER 2</NAME>
					<ADDR>ADDRESS 2</ADDR>
					<PHONE>444 - 444 - 002</PHONE>
				</RECORD>\
			</RECORDS>\
		</LINKAR>",
				options, xmlFormat, "", 600);
			LkFreeMemory(options);
			LkFreeMemory(credentials);
			return result;
		}
		---
		
	See Also:
		<LkCreateNewOptions>
		
		<LkCreateNewRecordIdTypeNone>
		
		<LkCreateNewRecordIdTypeLinkar>
		
		<LkCreateNewRecordIdTypeCustom>
		
		<LkCreateNewRecordIdTypeRandom>
		
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* LkNew(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const newOptions, XML_FORMAT xmlFormat, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE inputFormat = DataFormatTYPE_XML;
	char* result = Base_LkNew(error, credentialOptions, filename, records, newOptions, inputFormat, xmlFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkDelete
		Deletes one or several records in file with XML output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		filename - It's the file name where the records are going to be deleted. DICT in case of deleting a record that belongs to a dictionary.
		records - It's the records list to be deleted.
		deleteOptions - Object that defines the different Function options: optimisticLockControl, recoverRecordIdType.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "DirectFunctionsXML.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
		
		char* MyDelete(char** error)
		{
			char* result;
			char* credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* recoverRecordIdType = LkCreateRecoverRecordIdTypeNone();
			char* options = lkCreateDeleteOptions(FALSE, recoverRecordIdType);
			LkFreeMemory(recoverRecordIdType);
			result = LkNew(error, credentials, "LK.CUSTOMERS",
		"<?xml version=\"1.0\" encoding=\"utf-16\"?>\
		<LINKAR>\
			<RECORDS>\
				<RECORD>\
					<LKITEMID>2</LKITEMID>\
				</RECORD>\
			</RECORDS>\
		</LINKAR>",
				options, "", 600);
			LkFreeMemory(options);
			LkFreeMemory(credentials);
			return result;
		}
		---

	See Also:
		<LkCreateDeleteOptions>
		
		<LkCreateRecoverRecordIdTypeNone>
		
		<LkCreateRecoverRecordIdTypeLinkar>
		
		<LkCreateRecoverRecordIdTypeCustom>
		
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* LkDelete(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const deleteOptions, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE inputFormat = DataFormatTYPE_XML;	
	DataFormatTYPE outputFormat = DataFormatTYPE_XML;	
	char* result = Base_LkDelete(error, credentialOptions, filename, records, deleteOptions, inputFormat, outputFormat, customVars, receiveTimeout);
	
	return result;
}

/*
	Function: LkSelect
		Executes a Query in the Database with XML output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		filename - File name where the select operation will be perform. For example LK.ORDERS
		selectClause - Fragment of the phrase that indicate the selection condition. For example WITH CUSTOMER = '1'
		sortClause - Fragment of the phrase that indicates the selection order. If there is a selection rule, Linkar will execute a SSELECT, otherwise Linkar will execute a SELECT. For example BY CUSTOMER
		dictClause - Is the list of dictionaries to read, separated by space. If dictionaries are not indicated the function will read the complete buffer. For example CUSTOMER DATE ITEM
		preSelectClause - It's an optional statement that will execute before the main Select.
		selectOptions - String that defines the different reading options of the Function: calculated, dictionaries, conversion, formatSpec, originalRecords, onlyItemId, pagination, regPage, numPage.
		xmlFormat - Different XML output formats.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "DirectFunctionsXML.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
		
		public char* MySelect(char** error)
		{
			char* result;
			char* credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* options = lkCreateSelectOptions(FALSE, FALSE, 0, 0, TRUE, FALSE, FALSE, FALSE);
			XML_FORMAT xmlFormat = XML_FORMAT_XML;
			result = LkSelect(error, credentials, "LK.CUSTOMERS", "","BY ID","","",options, xmlFormat, "", 600);
			LkFreeMemory(options);
			LkFreeMemory(credentials);
			return result;
		}
		---

	See Also:
		<LkCreateSelectOptions>
		
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* LkSelect(char** error, const char* const credentialOptions, const char* const filename, const char* const selectClause, const char* const sortClause, const char* const dictClause, const char* const preSelectClause, const char* const selectOptions, XML_FORMAT xmlFormat, const char* const customVars, uint32_t receiveTimeout)
{

	char* result = Base_LkSelect(error, credentialOptions, filename, selectClause, sortClause, dictClause, preSelectClause, selectOptions, xmlFormat, customVars, receiveTimeout);
	
	return result;
}

/*
	Function: LkSubroutine
		Executes a subroutine with XML output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		subroutineName - Subroutine name you want to execute.
		argsNumber - The number of arguments.
		arguments - The subroutine arguments list.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "DirectFunctionsXML.h"
		#include "LinkarStrings.h"
		#include "ReleaseMemory.h"
		
		char* MySubroutine(char** error)
		{
			char* result;
			char* credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			
			char* subroutineName = "SUB.DEMOLINKAR";

			uint32_t argsNumber = 3;
			char* lstArgs [3] = { "0", "aaaa", "" };
			char* arguments = LkComposeSubroutineArgs((const char** const)lstArgs, argsNumber);
			
			result = LkSubroutine(&error, credentialOptions, subroutineName, argsNumber, arguments, "", 600);
			LkFreeMemory(arguments);
			LkFreeMemory(credentials);
			return result;
		}
		---

	See Also:
		<LkComposeSubroutineArgs>
		
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* LkSubroutine(char** error, const char* const credentialOptions, const char* const subroutineName, uint32_t argsNumber, const char* const arguments, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE inputFormat = DataFormatTYPE_XML;		
	DataFormatTYPE outputFormat = DataFormatTYPE_XML;		
	char* result = Base_LkSubroutine(error, credentialOptions, subroutineName, argsNumber, arguments, inputFormat, outputFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkConversion
		Returns the result of executing ICONV() or OCONV() functions from a expression list in the Database with XML output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		conversionType - Indicates the conversion type, input or output: Input=ICONV(); OUTPUT=OCONV()
		expression - The data or expression to convert. It can have MV marks, in which case the conversion will execute in each value obeying the original MV mark.
		code - The conversion code. It will have to obey the Database conversions specifications.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "DirectFunctionsXML.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
		
		char* MyConversion(char** error)
		{
			char* result;
			char* credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			
			result = LkConversion(error, credentials, CONVERSION_TYPE.INPUT,"31-12-2017","D2-", "", 600);
			LkFreeMemory(credentials);
			return result;
		}
		---

	See Also:
		<CONVERSION_TYPE>
		
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* LkConversion(char** error, const char* const credentialOptions, const char* const expression, const char* const code, CONVERSION_TYPE conversionType, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE outputFormat = DataFormatTYPE_XML;
	char* result = Base_LkConversion(error, credentialOptions, expression, code, conversionType, outputFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkFormat
		Returns the result of executing the FMT function in a expressions list in the Database with XML output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		expression - The data or expression to format. It can contain MV marks, in which case the conversion in each value will be executed according to the original MV mark.
		formatSpec - Specified format.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation..

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "DirectFunctionsXML.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
		
		char* MyFormat(char** error)
		{
			char* result;
			char* credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			
			result = LkFormat(error, credentials, "123","R#10", "", 600);
			LkFreeMemory(credentials);
			return result;
		}
		---

	See Also:
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* LkFormat(char** error, const char* const credentialOptions, const char* const expression, const char* const formatSpec, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE outputFormat = DataFormatTYPE_XML;	
	char* result = Base_LkFormat(error, credentialOptions, expression, formatSpec, outputFormat, customVars, receiveTimeout);

	return result;	
}

/*
	Function: LkDictionaries
		Returns all the dictionaries of a file with XML output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		filename - File name.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "DirectFunctionsXML.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
		
		char* MyDictionaries(char** error)
		{
			char* result;
			char* credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			
			result = LkDictionaries(error, credentials, "LK.CUSTOMERS", "", 600);
			LkFreeMemory(credentials);
			return result;
		}
		---

	See Also:
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* LkDictionaries(char** error, const char* const credentialOptions, const char* const filename, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE outputFormat = DataFormatTYPE_XML;	
	char* result = Base_LkDictionaries(error, credentialOptions, filename, outputFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkExecute
		Allows the execution of any command from the Database with XML output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		statement - The command you want to execute in the Database.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation..

		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "DirectFunctionsXML.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
		
		char* MyExecute(char** error)
		{
			char* result;
			char* credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			
			result = LkExecute(error, credentials, "WHO", "", 600);
			LkFreeMemory(credentials);
			return result;
		}
		---

	See Also:
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* LkExecute(char** error, const char* const credentialOptions, const char* const statement, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE outputFormat = DataFormatTYPE_XML;	
	char* result = Base_LkExecute(error, credentialOptions, statement, outputFormat, customVars, receiveTimeout);

	return result;	
}

/*
	Function: LkGetVersion
		Allows getting the server version with XML output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "DirectFunctionsXML.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
		
		char* MyGetVersion(char** error)
		{
			char* result;
			char* credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			
			result = LkGetVersion(error, credentials, 600);
			LkFreeMemory(credentials);
			return result;
		}
		---

	See Also:
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* LkGetVersion(char** error, const char* const credentialOptions, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE outputFormat = DataFormatTYPE_XML;	
	char* result = Base_LkGetVersion(error, credentialOptions, outputFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkSchemas
		Returns a list of all the Schemas defined in Linkar Schemas, or the EntryPoint account data files with XML output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		lkSchemasOptions - This string defines the different options in base of the asked Schema Type: LKSCHEMAS, SQLMODE o DICTIONARIES.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "DirectFunctionsXML.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
		
		char* MyLkSchemas(char** error)
		{
			char* result;
			char* credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* options = LkCreateSchOptionsTypeLKSCHEMAS(RowHeadersTYPE_MAINLABEL, FALSE, FALSE, FALSE, 0, 0);
			// char* options = LkCreateSchOptionsTypeSQLMODE (FALSE, FALSE, 0, 0);
			// char* options = LkCreateSchOptionsTypeDICTIONARIES (RowHeadersTYPE _MAINLABEL, FALSE, 0, 0);
			result = LkLkSchemas(error, credentials, options, "", "", 600);
			LkFreeMemory(options);
			LkFreeMemory(credentials);
			return result;
		}
		---

	See Also:
		<LkCreateSchOptionsTypeLKSCHEMAS>
		
		<LkCreateSchOptionsTypeSQLMODE>
		
		<LkCreateSchOptionsTypeDICTIONARIES>
		
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* LkSchemas(char** error, const char* const credentialOptions, const char* const lkSchemasOptions, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE outputFormat = DataFormatSchTYPE_XML;	
	char* result = Base_LkSchemas(error, credentialOptions, lkSchemasOptions, outputFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkProperties
		Returns the Schema properties list defined in Linkar Schemas or the file dictionaries with XML output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		filename - File name to LkProperties.
		lkPropertiesOptions - This string defines the different options in base of the asked Schema Type: LKSCHEMAS, SQLMODE o DICTIONARIES.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "DirectFunctionsXML.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
		
		char* MyLkProperties(char** error)
		{
			char* result;
			char* credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* options = LkCreatePropOptionsTypeLKSCHEMAS (RowHeadersTYPE_MAINLABEL, FALSE, FALSE, FALSE, FALSE, 0, 0);
			//char* options = LkCreatePropOptionsTypeSQLMODE(FALSE, FALSE, 0, 0);
			//char* options = LkCreatePropOptionsTypeDICTIONARIES(RowHeadersTYPE_MAINLABEL, FALSE, 0, 0);

			result = LkProperties(error, credentials, "LK.CUSTOMERS", options, "", 600);
			LkFreeMemory(options);
			LkFreeMemory(credentials);
			return result;
		}
		---

	See Also:
		<LkCreatePropOptionsTypeLKSCHEMAS>
		
		<LkCreatePropOptionsTypeSQLMODE>
		
		<LkCreatePropOptionsTypeDICTIONARIES>
		
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* LkProperties(char** error, const char* const credentialOptions, const char* const filename, const char* const lkPropertiesOptions, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE outputFormat = DataFormatSchTYPE_XML;	
	char* result = Base_LkProperties(error, credentialOptions, filename, lkPropertiesOptions, outputFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkResetCommonBlocks
		Resets the COMMON variables with the 100 most used files with XML output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - String that defines the necessary data to access to the Linkar Server: Username, Password, EntryPoint, Language, FreeText.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "DirectFunctionsXML.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
		
		char* MyResetCommonBlocks(char** error)
		{
			char* result;
			char* credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			
			result = LkResetCommonBlocks(error, credentials, 30);
			LkFreeMemory(credentials);
			return result;
		}
		---

	See Also:
		<LkCreateCredentialOptions>
		
		<Release Memory>
*/
DllEntry char* LkResetCommonBlocks(char** error, const char* const credentialOptions, uint32_t receiveTimeout)
{
	DataFormatTYPE outputFormat = DataFormatTYPE_XML;	
	char* result = Base_LkResetCommonBlocks(error, credentialOptions, outputFormat, receiveTimeout);
	
	return result;	
}

/*
	File: FunctionsPersistentJSON.c
	
	These functions perform persistent (establishing permanent session) operations with output format type JSON.
	
	Note:
	All functions comments here, return a char* value. That memory was allocated dynamically, so once those string is not needed anymore, the memory assigned to them *must be released*.
	See <Release Memory> for known how to do.
*/

#include "FunctionsPersistent.h"
#include "FunctionsPersistentJSON.h"

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
		
	Remarks:
		Login is actually a "virtual" operation which creates a new Client Session ID. No DBMS login is performed unless Linkar SERVER determines new Database Sessions are required. These operations are not related.

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
				
	Remarks:
		Logout is actually a "virtual" operation which disposes the current Client Session ID. No DBMS logout is performed.
	
	See Also:
		<LkLogin>	
*/
DllEntry void LkLogout(char** error, char* connectionInfo, const char* const customVars, uint32_t receiveTimeout)
{
	Base_LkLogout(error, connectionInfo, customVars, receiveTimeout);
}

/*
	Function: LkRead
		Reads one or several records of a file with JSON input and output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
		filename - File name to read.
		recordIds - It's the records codes list to read.
		dictionaries - List of dictionaries to read, separated by space. If dictionaries are not indicated the function will read the complete buffer.
		readOptions - String that defines the different reading options of the Function: Calculated, dictClause, conversion, formatSpec, originalRecords.
		jsonFormat - Different JSON output formats.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "ConnectionInfo.h"
		#include "PersistentFunctionsJSON.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
			
		char* MyRead(char** error)
		{
			char* result;
			CredentialOptions credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* connectionInfo = LkLogin(error, credentials, "", 600);
			LkFreeMemory(credentials);
			if(error == NULL && connectionInfo != NULL)
			{
				char* options = lkCreateReadOptions(TRUE, FALSE, FALSE, FALSE);
				JSON_FORMAT jsonFormat = JSON_FORMAT_JSON;
				result = LkRead(error, connectionInfo, "LK.CUSTOMERS",
		"{\
			\"RECORDS\": [\
				{\
					\"LKITEMID\": \"2\"\
				}\
			]\
		}",
					"", options, jsonFormat, "", 0);
				LkFreeMemory(options);
				LkLogout(error, connectionInfo, "", 0);
				LkFreeMemory(connectionInfo);
			}
			return result;
		}
		---

	See Also:
		<LkCreateReadOptions>
				
		<LkLogin>
		
		<LkLogout>
		
		<LkCreateConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkRead(char** error, char* connectionInfo, const char* const filename, const char* const recordIds, const char* const dictionaries, const char* const readOptions, JSON_FORMAT jsonFormat, const char* const customVars, uint32_t receiveTimeout)
{	
	DataFormatTYPE inputFormat = DataFormatTYPE_JSON;	
	char* result = Base_LkRead(error, connectionInfo, filename, recordIds, dictionaries, readOptions, inputFormat, jsonFormat, customVars, receiveTimeout);
		
	return result;
}

/*
	Function: LkUpdate
		Update one or several records of a file with JSON input and output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
		filename - File name where you are going to write.
		records - Are the records you want to update. Inside this string are the recordIds, the records, and the originalRecords.
		updateOptions - Object that defines the different writing options of the Function: optimisticLockControl, readAfter, calculated, dictionaries, conversion, formatSpec, originalRecords.
		jsonFormat - Different JSON output formats.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Remarks:
		Inside the records argument, the recordIds and the modified records always must be specified. But the originalRecords not always.
		When updateOptions argument is specified with its optimisticLock property set to true, a copy of the record must be provided before the modification (originalRecords argument)
		to use the Optimistic Lock technique. This copy can be obtained from a previous <LkRead> operation. The database, before executing the modification, 
		reads the record and compares it with the copy in originalRecords, if they are equal the modified record is executed.
		But if they are not equal, it means that the record has been modified by other user and its modification will not be saved.
		The record will have to be read, modified and saved again.
	
	Example:
		--- Code
	#include "Types.h"
	#include "CredentialOptions.h"
	#include "ConnectionInfo.h"
	#include "PersistentFunctionsJSON.h"
	#include "OperationOptions.h"
	#include "ReleaseMemory.h"
		
	char* MyUpdate(char** error)
	{
		char* result;
		CredentialOptions credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
		char* connectionInfo = LkLogin(error, credentials, "", 600);
		LkFreeMemory(credentials);
		if(error == NULL && connectionInfo != NULL)
		{
			char* options = LkCreateUpdateOptions(FALSE, TRUE, TRUE, FALSE, FALSE, FALSE);
			JSON_FORMAT jsonFormat = JSON_FORMAT_JSON;
			result = LkUpdate(error, connectionInfo, "LK.CUSTOMERS",
	"{\
		\"RECORDS\": [\
			{\
				\"LKITEMID\": \"2\",\
				\"NAME\": \"CUSTOMER 2\",\
				\"ADDR\": \"ADDRESS 2\",\
				\"PHONE\": \"444 - 444 - 002\"\
			}\
		]\
	}",
				options, jsonFormat, "", 0);
			LkFreeMemory(options);
			
			LkLogout(error, connectionInfo, "", 0);
			LkFreeMemory(connectionInfo);
		}
		return result;
	}
		---

	See Also:
		<LkCreateUpdateOptions>
				
		<LkLogin>
		
		<LkLogout>
		
		<LkCreateConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkUpdate(char** error, char* connectionInfo, const char* const filename, const char* const records, const char* const updateOptions, JSON_FORMAT jsonFormat, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE inputFormat = DataFormatTYPE_JSON;		
	char* result = Base_LkUpdate(error, connectionInfo, filename, records, updateOptions, inputFormat, jsonFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkNew
		Creates one or several records of a file with JSON input and output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
		filename - File name where you are going to write.
		records - Are the records you want to write. Inside this string are the recordIds, and the records.
		newOptions - String that defines the following writing options of the Function: recordIdType, readAfter, calculated, dictionaries, conversion, formatSpec, originalRecords.
		jsonFormat - Different JSON output formats.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Remarks:
		Inside the records argument, the records always must be specified. But the recordIds only must be specified when newOptions argument is null, or when the recordIdType argument of the newOptions argument is null.
		
	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "ConnectionInfo.h"
		#include "PersistentFunctionsJSON.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
			
		char* MyNew(char** error)
		{
			char* result;
			CredentialOptions credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* connectionInfo = LkLogin(error, credentials, "", 600);
			LkFreeMemory(credentials);
			if(error == NULL && connectionInfo != NULL)
			{
				char* recordIdType = LkCreateNewRecordIdTypeNone();
				char* newOptions = lkCreateNewOptions(recordIdType, TRUE, FALSE, FALSE, FALSE);
				LkFreeMemory(recordIdType);
				JSON_FORMAT jsonFormat = JSON_FORMAT_JSON;
				result = LkNew(error, connectionInfo, "LK.CUSTOMERS",
		"{\
			\"RECORDS\": [\
				{\
					\"LKITEMID\": \"2\",\
					\"NAME\": \"CUSTOMER 2\",\
					\"ADDR\": \"ADDRESS 2\",\
					\"PHONE\": \"444 - 444 - 002\"\
				}\
		]\
		}",
					options, jsonFormat, "", 0);
				LkFreeMemory(options);
				LkLogout(error, connectionInfo, "", 0);
				LkFreeMemory(connectionInfo);
			}
			return result;
		}
		---

	See Also:
		<LkCreateNewOptions>
		
		<LkCreateNewRecordIdTypeNone>
		
		<LkCreateNewRecordIdTypeLinkar>
		
		<LkCreateNewRecordIdTypeCustom>
		
		<LkCreateNewRecordIdTypeRandom>
		
		<LkLogin>
		
		<LkLogout>
		
		<LkCreateConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkNew(char** error, char* connectionInfo, const char* const filename, const char* const records, const char* const newOptions, JSON_FORMAT jsonFormat, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE inputFormat = DataFormatTYPE_JSON;		
	char* result = Base_LkNew(error, connectionInfo, filename, records, newOptions, inputFormat, jsonFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkDelete
		Deletes one or several records in file with JSON input and output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
		filename - It's the file name where the records are going to be deleted. DICT in case of deleting a record that belongs to a dictionary.
		records - It's the records list to be deleted.
		deleteOptions - Object that defines the different Function options: optimisticLockControl, recoverRecordIdType.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	Remarks:
		Inside the records argument, the recordIds always must be specified. But the originalRecords not always.
		When deleteOptions argument is specified with its optimisticLock property set to true,
		a copy of the record must be provided before the deletion (originalRecords argument) to use the Optimistic Lock technique.
		This copy can be obtained from a previous <LkRead> operation. The database, before executing the deletion, 
		reads the record and compares it with the copy in originalRecords, if they are equal the record is deleted.
		But if they are not equal, it means that the record has been modified by other user and the record will not be deleted.
		The record will have to be read, and deleted again.
		
	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "ConnectionInfo.h"
		#include "PersistentFunctionsJSON.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
			
		char* MyDelete(char** error)
		{
			char* result;
			CredentialOptions credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* connectionInfo = LkLogin(error, credentials, "", 600);
			LkFreeMemory(credentials);
			if(error == NULL && connectionInfo != NULL)
			{
				char* recoverRecordIdType = LkCreateRecoverRecordIdTypeNone();
				char* options = lkCreateDeleteOptions(FALSE, recoverRecordIdType);
				LkFreeMemory(recoverRecordIdType);
				result = LkDelete(error, connectionInfo, "LK.CUSTOMERS",
		"{\
			\"RECORDS\": [\
				{\
					\"LKITEMID\": \"2\",\
				}\
			]\
		}",
					options, "", 0);
				LkFreeMemory(options);
				LkLogout(error, connectionInfo, "", 0);
				LkFreeMemory(connectionInfo);
			}
			return result;
		}
		---

	See Also:
		<LkCreateDeleteOptions>
		
		<LkCreateRecoverRecordIdTypeNone>
		
		<LkCreateRecoverRecordIdTypeLinkar>
		
		<LkCreateRecoverRecordIdTypeCustom>
		
		<LkLogin>
		
		<LkLogout>
		
		<LkCreateConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkDelete(char** error, char* connectionInfo, const char* const filename, const char* const records, const char* const deleteOptions, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE inputFormat = DataFormatTYPE_JSON;
	DataFormatTYPE outputFormat = DataFormatTYPE_JSON;
	char* result = Base_LkDelete(error, connectionInfo, filename, records, deleteOptions, inputFormat, outputFormat, customVars, receiveTimeout);
	
	return result;
}

/*
	Function: LkSelect
		Executes a Query in the Database with JSON output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
		filename - File name where the select operation will be perform. For example LK.ORDERS
		selectClause - Fragment of the phrase that indicate the selection condition. For example WITH CUSTOMER = '1'
		sortClause - Fragment of the phrase that indicates the selection order. If there is a selection rule, Linkar will execute a SSELECT, otherwise Linkar will execute a SELECT. For example BY CUSTOMER
		dictClause - Is the list of dictionaries to read, separated by space. If dictionaries are not indicated the function will read the complete buffer. For example CUSTOMER DATE ITEM
		preSelectClause - It's an optional statement that will execute before the main Select.
		selectOptions - String that defines the different reading options of the Function: calculated, dictionaries, conversion, formatSpec, originalRecords, onlyItemId, pagination, regPage, numPage.
		jsonFormat - Different JSON output formats.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Remarks:
		In the preSelectClause argument these operations can be carried out before executing the Select statement:
		
		- Previously call to a saved list with the GET.LIST command to use it in the Main Select input.
		- Make a previous Select to use the result as the Main Select input, with the SELECT or SSELECT commands.In this case the entire sentence must be indicated in the PreselectClause. For example:SSELECT LK.ORDERS WITH CUSTOMER = '1'
		- Exploit a Main File index to use the result as a Main Select input, with the SELECTINDEX command. The syntax for all the databases is SELECTINDEX index.name.value. For example SELECTINDEX ITEM,"101691"

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "ConnectionInfo.h"
		#include "PersistentFunctionsJSON.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
			
		char* MySelect(char** error)
		{
			char* result;
			CredentialOptions credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* connectionInfo = LkLogin(error, credentials, "", 600);
			LkFreeMemory(credentials);
			if(error == NULL && connectionInfo != NULL)
			{
				char* options = lkCreateSelectOptions(FALSE, FALSE, 0, 0, TRUE, FALSE, FALSE, FALSE);
				JSON_FORMAT jsonFormat = JSON_FORMAT_JSON;
				result = LkSelect(error, connectionInfo, "LK.CUSTOMERS", "", "BY ID", "", "", options, jsonFormat, "", 0);
				LkFreeMemory(options);
				LkLogout(error, connectionInfo, "", 0);
				LkFreeMemory(connectionInfo);
			}
			return result;
		}
		---

	See Also:
		<LkCreateSelectOptions>
		
		<LkLogin>
		
		<LkLogout>
		
		<LkCreateConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkSelect(char** error, char* connectionInfo, const char* const filename, const char* const selectClause, const char* const sortClause, const char* const dictClause, const char* const preSelectClause, const char* const selectOptions, JSON_FORMAT jsonFormat, const char* const customVars, uint32_t receiveTimeout)
{		
	char* result = Base_LkSelect(error, connectionInfo, filename, selectClause, sortClause, dictClause, preSelectClause, selectOptions, jsonFormat, customVars, receiveTimeout);
	
	return result;
}

/*
	Function: LkSubroutine
		Executes a subroutine with JSON input and output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
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
		#include "ConnectionInfo.h"
		#include "PersistentFunctionsJSON.h"
		#include "LinkarStrings.h"
		#include "ReleaseMemory.h"
			
		char* MySubroutine(char** error)
		{
			char* result = NULL;
			CredentialOptions credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* connectionInfo = LkLogin(error, credentials, "", 600);
			LkFreeMemory(credentials);
			if(error == NULL && connectionInfo != NULL)
			{
				char* subroutineName = "SUB.DEMOLINKAR";
	
				uint32_t argsNumber = 3;
				char* lstArgs [3] = { "0", "aaaa", "" };
				char* arguments = LkComposeSubroutineArgs((const char** const)lstArgs, argsNumber);
			
				result = LkSubroutine(error, connectionInfo, subroutineName, argsNumber, arguments, "", 0);
				LkFreeMemory(arguments);
				LkLogout(error, connectionInfo, "", 0);
				LkFreeMemory(connectionInfo);
			}
			return result;
		}
		---

		See Also:
		<LkComposeSubroutineArgs>

		<LkLogin>
		
		<LkLogout>
		
		<LkCreateConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkSubroutine(char** error, char* connectionInfo, const char* const subroutineName, uint32_t argsNumber, const char* const arguments, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE inputFormat = DataFormatTYPE_JSON;			
	DataFormatTYPE outputFormat = DataFormatTYPE_JSON;			
	char* result = Base_LkSubroutine(error, connectionInfo, subroutineName, argsNumber, arguments, inputFormat, outputFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkConversion
		Returns the result of executing ICONV() or OCONV() functions from a expression list in the Database with JSON output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
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
		#include "ConnectionInfo.h"
		#include "PersistentFunctionsJSON.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
			
		char* MyConversion(char** error)
		{
			char* result = NULL;
			CredentialOptions credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* connectionInfo = LkLogin(error, credentials, "", 600);
			LkFreeMemory(credentials);
			if(error == NULL && connectionInfo != NULL)
			{
				result = LkConversion(error, connectionInfo, CONVERSION_TYPE.INPUT,"31-12-2017","D2-", "", 0);
				LkLogout(error, connectionInfo, "", 0);
				LkFreeMemory(connectionInfo);
			}
			return result;
		}
		---

	See Also:
		<CONVERSION_TYPE>
		
		<LkLogin>
		
		<LkLogout>
		
		<LkCreateConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkConversion(char** error, char* connectionInfo, const char* const expression, const char* const code, CONVERSION_TYPE conversionType, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE outputFormat = DataFormatTYPE_JSON;			
	char* result = Base_LkConversion(error, connectionInfo, expression, code, conversionType, outputFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkFormat
		Returns the result of executing the FMT function in a expressions list in the Database with JSON output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
		expression - The data or expression to format. It can contain MV marks, in which case the conversion in each value will be executed according to the original MV mark.
		formatSpec - Specified format.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "ConnectionInfo.h"
		#include "PersistentFunctionsJSON.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
			
		char* MyFormat(char** error)
		{
			char* result = NULL;
			CredentialOptions credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* connectionInfo = LkLogin(error, credentials, "", 600);
			LkFreeMemory(credentials);
			if(error == NULL && connectionInfo != NULL)
			{
				result = LkFormat(error, connectionInfo, "123","R#10", "", 0);
				LkLogout(error, connectionInfo, "", 0);
				LkFreeMemory(connectionInfo);
			}
			return result;
		}
		---

		
	See Also:
		<LkLogin>
		
		<LkLogout>
		
		<LkCreateConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkFormat(char** error, char* connectionInfo, const char* const expression, const char* const formatSpec, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE outputFormat = DataFormatTYPE_JSON;		
	char* result = Base_LkFormat(error, connectionInfo, expression, formatSpec, outputFormat, customVars, receiveTimeout);

	return result;	
}

/*
	Function: LkDictionaries
		Returns all the dictionaries of a file with JSON output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
		filename - File name.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "ConnectionInfo.h"
		#include "PersistentFunctionsJSON.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
			
		char* MyDictionaries(char** error)
		{
			char* result = NULL;
			CredentialOptions credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* connectionInfo = LkLogin(error, credentials, "", 600);
			LkFreeMemory(credentials);
			if(error == NULL && connectionInfo != NULL)
			{
				result = LkDictionaries(error, connectionInfo, "LK.CUSTOMERS", "", 0);
				LkLogout(error, connectionInfo, "", 0);
				LkFreeMemory(connectionInfo);
			}
			return result;
		}
		---

	See Also:
		<LkLogin>
		
		<LkLogout>
		
		<LkCreateConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkDictionaries(char** error, char* connectionInfo, const char* const filename, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE outputFormat = DataFormatTYPE_JSON;		
	char* result = Base_LkDictionaries(error, connectionInfo, filename, outputFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkExecute
		Allows the execution of any command from the Database with JSON output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
		statement - The command you want to execute in the Database.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "ConnectionInfo.h"
		#include "PersistentFunctionsJSON.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
			
		char* MyExecute(char** error)
		{
			char* result = NULL;
			CredentialOptions credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* connectionInfo = LkLogin(error, credentials, "", 600);
			LkFreeMemory(credentials);
			if(error == NULL && connectionInfo != NULL)
			{
				
				result = LkExecute(error, connectionInfo, "WHO", "", 0);
				LkLogout(error, connectionInfo, "", 0);
				LkFreeMemory(connectionInfo);
			}
			return result;
		}
		---

	See Also:
		<LkLogin>
		
		<LkLogout>
		
		<LkCreateConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkExecute(char** error, char* connectionInfo, const char* const statement, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE outputFormat = DataFormatTYPE_JSON;		
	char* result = Base_LkExecute(error, connectionInfo, statement, outputFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkGetVersion
		Allows getting the server version with JSON output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
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
	
	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "ConnectionInfo.h"
		#include "PersistentFunctionsJSON.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"

		char* MyGetVersion(char** error)
		{
			char* result = NULL;
			CredentialOptions credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* connectionInfo = LkLogin(error, credentials, "", 600);
			LkFreeMemory(credentials);
			if(error == NULL && connectionInfo != NULL)
			{
				result = LkGetVersion(error, connectionInfo, 0);
				LkLogout(error, connectionInfo, "", 0);
				LkFreeMemory(connectionInfo);
			}
			return result;
		}
		---

	See Also:
		<LkLogin>
		
		<LkLogout>
		
		<LkCreateConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkGetVersion(char** error, char* connectionInfo, const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE outputFormat = DataFormatTYPE_JSON;		
	char* result = Base_LkGetVersion(error, connectionInfo, outputFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkSchemas
		Returns a list of all the Schemas defined in Linkar Schemas, or the EntryPoint account data files with JSON output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
		lkSchemasOptions - This string defines the different options in base of the asked Schema Type: LKSCHEMAS, SQLMODE o DICTIONARIES.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Remarks:
		TABLE output format uses the defined control characters in <EntryPoints Parameters: http://kosday.com/Manuals/en_web_linkar/lk_schemas_ep_parameters.html> Table Row Separator and Column Row Separator.
		
		By default:
		
		- TAB char (9) for columns.
		- VT char (11) for rows.
	
	Example:
		--- Code
	#include "Types.h"
	#include "CredentialOptions.h"
	#include "ConnectionInfo.h"
	#include "PersistentFunctionsJSON.h"
	#include "OperationOptions.h"
	#include "ReleaseMemory.h"
		
	char* MyLkSchemas(char** error)
	{
		char* result;
		CredentialOptions credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
		char* connectionInfo = LkLogin(error, credentials, "", 600);
		LkFreeMemory(credentials);
		if(error == NULL && connectionInfo != NULL)
		{
			char* options = LkCreateSchOptionsTypeLKSCHEMAS(RowHeadersTYPE_MAINLABEL, FALSE, FALSE, FALSE, 0, 0);
			// char* options = LkCreateSchOptionsTypeSQLMODE (FALSE, FALSE, 0, 0);
			// char* options = LkCreateSchOptionsTypeDICTIONARIES (RowHeadersTYPE _MAINLABEL, FALSE, 0, 0);
			result = LkLkSchemas(error, connectionInfo, options, "", "", 0);
			LkFreeMemory(options);
			LkLogout(error, connectionInfo, "", 0);
			LkFreeMemory(connectionInfo);
		}
		return result;
	}
		---

	See Also:
		<LkCreateSchOptionsTypeLKSCHEMAS>
		
		<LkCreateSchOptionsTypeSQLMODE>
		
		<LkCreateSchOptionsTypeDICTIONARIES>
		
		<LkLogin>
		
		<LkLogout>
		
		<LkCreateConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkSchemas(char** error, char* connectionInfo, const char* const lkSchemasOptions,  const char* const customVars, uint32_t receiveTimeout)
{
	DataFormatTYPE outputFormat = DataFormatSchTYPE_JSON;			
	char* result = Base_LkSchemas(error, connectionInfo, lkSchemasOptions, outputFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkProperties
		Returns the Schema properties list defined in Linkar Schemas or the file dictionaries with JSON output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
		filename - File name to LkProperties.
		lkPropertiesOptions - This string defines the different options in base of the asked Schema Type: LKSCHEMAS, SQLMODE o DICTIONARIES.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.
		
	Remarks:
		TABLE output format uses the defined control characters in <EntryPoints Parameters: http://kosday.com/Manuals/en_web_linkar/lk_schemas_ep_parameters.html> Table Row Separator and Column Row Separator.
		
		By default:
		
		- TAB char (9) for columns.
		- VT char (11) for rows.
	
	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "ConnectionInfo.h"
		#include "PersistentFunctionsJSON.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
			
		char* MyLkProperties(char** error)
		{
			char* result;
			CredentialOptions credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* connectionInfo = LkLogin(error, credentials, "", 600);
			LkFreeMemory(credentials);
			if(error == NULL && connectionInfo != NULL)
			{
				char* options = LkCreatePropOptionsTypeLKSCHEMAS (RowHeadersTYPE_MAINLABEL, FALSE, FALSE, FALSE, FALSE, 0, 0);
				//char* options = LkCreatePropOptionsTypeSQLMODE(FALSE, FALSE, 0, 0);
				//char* options = LkCreatePropOptionsTypeDICTIONARIES(RowHeadersTYPE_MAINLABEL, FALSE, 0, 0);

				result = LkProperties(error, connectionInfo, "LK.CUSTOMERS",options, "", "", 0);
				LkFreeMemory(options);
				LkLogout(error, connectionInfo, "", 0);
				LkFreeMemory(connectionInfo);
			}
			return result;
		}
		---

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
	DataFormatTYPE outputFormat = DataFormatSchTYPE_JSON;
	char* result = Base_LkProperties(error, connectionInfo, filename, lkPropertiesOptions, outputFormat, customVars, receiveTimeout);
	
	return result;	
}

/*
	Function: LkResetCommonBlocks
		Resets the COMMON variables with the 100 most used files with JSON output format.
		
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - String that is returned by the Login function and that contains all the necessary data of the connection.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
		receiveTimeout - It's the maximum time in seconds that the client will keep waiting the answer by the server. Values less than or equal to 0, waits indefinitely.
		
	Returns:
		The results of the operation.

	Example:
		--- Code
		#include "Types.h"
		#include "CredentialOptions.h"
		#include "ConnectionInfo.h"
		#include "PersistentFunctionsJSON.h"
		#include "OperationOptions.h"
		#include "ReleaseMemory.h"
			
		char* MyResetCommonBlocks(char** error)
		{
			char* result = NULL;
			CredentialOptions credentials = LkCreateCredentialOptions("127.0.0.1", "EPNAME", 11300, "admin", "admin", "", "");
			char* connectionInfo = LkLogin(error, credentials, "", 30);
			LkFreeMemory(credentials);
			if(error == NULL && connectionInfo != NULL)
			{
				result = LkResetCommonBlocks(error, connectionInfo, 0);
				LkLogout(error, connectionInfo, "", 0);
				LkFreeMemory(connectionInfo);
			}
			return result;
		}
		----

	See Also:
		<LkLogin>
		
		<LkLogout>
		
		<LkCreateConnectionInfo>
		
		<Release Memory>
*/
DllEntry char* LkResetCommonBlocks(char** error, char* connectionInfo, uint32_t receiveTimeout)
{
	DataFormatTYPE outputFormat = DataFormatTYPE_JSON;	
	char* result = Base_LkResetCommonBlocks(error, connectionInfo, outputFormat, receiveTimeout);
	
	return result;	
}

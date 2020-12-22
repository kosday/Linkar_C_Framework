/*	
	File: LinkarString.c
	This module contains auxiliary functions to work with <LkStrings>.

	All functions comments here, except <LkExtractTotalRecords>, return a char* or char** value. That memory was allocated dynamically, so once those string is not needed anymore, the memory assigned to them *must be released*.
	See <Release Memory> for known how to do.
*/

#include "LinkarStrings.h"
#include "LinkarStringsHelper.h"
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

/*
	Function: LkExtractTotalRecords
		Extracts the total number of records from an operation resultant <LkString>.

	Arguments:
		lkString - Text string on which you are going to extract.
		
	Returns:
		The total number of records from the <LkString>.
		
	Example:
		--- Code
		// lkStringResult it's a char * returned by a LkRead function
		
		uint32_t numRecords = LkExtractTotalRecords(lkStringResult);
		---
		
	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry uint32_t LkExtractTotalRecords(const char* const lkString)
{
	char* block = LkExtractData(lkString, TOTAL_RECORDS_KEY, ASCII_FS, DBMV_Mark_AM);
	uint32_t result = atoi(block);
	free(block);
	return result;
}
	
/*
	Function: LkExtractRecordIds
		Extracts the codes from an operation resultant <LkString>.

	Arguments:
		lkString - Text string on which you are going to extract.
		count - Output argument that inform about the size of the pointer array, that mean, how many strings contains.
		
	Returns:
		Pointer array of string with the codes from the <LkString>.
		
	Example:
		--- Code
		// lkStringResult it's a char * returned by a LkRead function
		
		uint32_t count;
		char** recordIds = LkExtractRecordIds(lkStringResult, &count);
		for(int i=0; i<count; i++)
		{
			printf("%s\r\n", recordIds[i]);
		}
		LkFreeMemoryStringArray(recordIds, count);
		---

	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry char** LkExtractRecordIds(const char* const lkString, uint32_t *count)
{
	*count = 0;
	char* block = LkExtractData(lkString, RECORD_IDS_KEY, ASCII_FS, DBMV_Mark_AM);
	if(block != NULL)
	{
		char** data = LkStrSplit(block, ASCII_RS, count);
		free(block);

		if(*count == 1 && (data[0] == NULL || strcmp(data[0], "") == 0))
		{
			*count = 0;
			free(data[0]);
			free(data);
			return NULL;
		}
		else
			return data;
	}
	else
		return NULL;
}

/*
	Function: LkExtractRecords
		Extracts the records from an operation resultant <LkString>.

	Arguments:
		lkString - Text string on which you are going to extract.
		count - Output argument that inform about the size of the pointer array, that mean, how many strings contains.
	
	Returns:
		Pointer array of string with the records from the <LkString>.
		
	Example:
		--- Code
		// lkStringResult it's a char * returned by a LkRead function
		
		uint32_t count;
		char** records = LkExtractRecords(lkStringResult, &count);
		for(int i=0; i<count; i++)
		{
			printf("%s\r\n", records[i]);
		}
		LkFreeMemoryStringArray(records, count);
		---

	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry char** LkExtractRecords(const char* const lkString, uint32_t *count)
{
	*count = 0;
	char* block = LkExtractData(lkString, RECORDS_KEY, ASCII_FS, DBMV_Mark_AM);
	if(block != NULL)
	{
		char** data = LkStrSplit(block, ASCII_RS, count);
		free(block);

		if(*count == 1 && (data[0] == NULL || strcmp(data[0], "") == 0))
		{
			*count = 0;
			free(data[0]);
			free(data);
			return NULL;
		}
		else
			return data;
	}
	else
		return NULL;
}

/*
	Function: LkExtractErrors
		Extracts the errors from an operation resultant <LkString>.
		
	Arguments:
		lkString - Text string on which you are going to extract.
		count - Output argument that inform about the size of the pointer array, that mean, how many strings contains.
	
	Returns:	
		Pointer array of string with the errors from the <LkString>.	
		
	Example:
		--- Code
		// lkStringResult it's a char * returned by a LkRead function
		
		uint32_t count;
		char** errors = LkExtractErrors(lkStringResult, &count);
		for(int i=0; i<count; i++)
		{
			printf("%s\r\n", errors[i]);
		}
		LkFreeMemoryStringArray(errors, count);
		---

	Also See:
		<LkString>

		<Release Memory>
*/
DllEntry char** LkExtractErrors(const char* const lkString, uint32_t *count)
{
	*count = 0;
	char* block = LkExtractData(lkString, ERRORS_KEY, ASCII_FS, DBMV_Mark_AM);
	if(block != NULL)
	{
		char** data = LkStrSplit(block, DBMV_Mark_AM, count);		
		free(block);

		if(*count == 1 && (data[0] == NULL || strcmp(data[0], "") == 0))
		{
			*count = 0;
			free(data[0]);
			free(data);
			return NULL;
		}
		else
			return data;
	}
	else
		return NULL;
}

/*
	Function: LkExtractRecordsCalculated
		Extracts the records calculated fields from an operation resultant <LkString>.

	Arguments:
		lkString - Text string on which you are going to extract.
		count - Output argument that inform about the size of the pointer array, that mean, how many strings contains.
	
	Returns:
		Pointer array of string with the records calculated fields from the <LkString>.	
		
	Example:
		--- Code
		// lkStringResult it's a char * returned by a LkRead function
		
		uint32_t count;
		char** recordsCalculated = LkExtractRecordsCalculated(lkStringResult, &count);
		for(int i=0; i<count; i++)
		{
			printf("%s\r\n", recordsCalculated[i]);
		}
		LkFreeMemoryStringArray(recordsCalculated, count);
		---

	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry char** LkExtractRecordsCalculated(const char* const lkString, uint32_t *count)
{	
	char* block = LkExtractData(lkString, CALCULATED_KEY, ASCII_FS, DBMV_Mark_AM);
	if(block != NULL)
	{
		char** data = LkStrSplit(block, DBMV_Mark_AM, count);
		free(block);

		if(*count == 1 && (data[0] == NULL || strcmp(data[0], "") == 0))
		{
			*count = 0;
			free(data[0]);
			free(data);
			return NULL;
		}
		else
			return data;
	}
	else
		return NULL;
}

/*
	Function: LkExtractRecordsDicts
		Extracts the record's dictionaries from  an operation resultant <LkString>.
		
	Arguments:
		lkString - Text string on which you are going to extract.
		count - Output argument that inform about the size of the pointer array, that mean, how many strings contains.
	
	Returns:
		Pointer array of string with the record's dictionaries from the <LkString>.	
	
	Example:
		--- Code
		// lkStringResult it's a char * returned by a LkRead function
		
		uint32_t count;
		char** recordsDictionaries = LkExtractRecordsDicts(lkStringResult, &count);
		for(int i=0; i<count; i++)
		{
			printf("%s\r\n", recordsDictionaries[i]);
		}
		LkFreeMemoryStringArray(recordsDictionaries, count);
		---

	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry char** LkExtractRecordsDicts(const char* const lkString, uint32_t *count)
{
	char* block = LkExtractData(lkString, RECORD_DICTS_KEY, ASCII_FS, DBMV_Mark_AM);
	if(block != NULL)
	{
		char** data = LkStrSplit(block, DBMV_Mark_AM, count);
		free(block);

		if(*count == 1 && (data[0] == NULL || strcmp(data[0], "") == 0))
		{
			*count = 0;
			free(data[0]);
			free(data);
			return NULL;
		}
		else
			return data;
	}
	else
		return NULL;
}
		
/*
	Function: LkExtractRecordsCalculatedDicts
		Extracts the dictionaries from the records of an operation resultant <LkString>.

	Arguments:
	
	Returns:
		Pointer array of string with the dictionaries from the records of the <LkString>.	
	
	Example:
		--- Code
		// lkStringResult it's a char * returned by a LkRead function
		
		uint32_t count;
		char** recordsCalculatedDictionaries = LkExtractRecordsCalculatedDicts(lkStringResult, &count);
		for(int i=0; i<count; i++)
		{
			printf("%s\r\n", recordsCalculatedDictionaries[i]);
		}
		LkFreeMemoryStringArray(recordsCalculatedDictionaries, count);
		---

	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry char** LkExtractRecordsCalculatedDicts(const char* const lkString, uint32_t *count)
{
	char* block = LkExtractData(lkString, CALCULATED_DICTS_KEY, ASCII_FS, DBMV_Mark_AM);
	if(block != NULL)
	{
		char** data = LkStrSplit(block, DBMV_Mark_AM, count);
		free(block);

		if(*count == 1 && (data[0] == NULL || strcmp(data[0], "") == 0))
		{
			*count = 0;
			free(data[0]);
			free(data);
			return NULL;
		}
		else
			return data;
	}
	else
		return NULL;
}

/*
	Function: LkExtractRecordsIdDicts
		Extracts the ID's dictionaries from an operation resultant <LkString>.

	Arguments:
		lkString - Text string on which you are going to extract.
		count - Output argument that inform about the size of the pointer array, that mean, how many strings contains.
	
	Returns:
		Pointer array of string with the ID's dictionaries from the <LkString>.	
	
	Example:
		--- Code
		// lkStringResult it's a char * returned by a LkRead function
		
		uint32_t count;
		char** recordsIdDicts = LkExtractRecordsIdDicts(lkStringResult, &count);
		for(int i=0; i<count; i++)
		{
			printf("%s\r\n", recordsIdDicts[i]);
		}
		LkFreeMemoryStringArray(recordsIdDicts, count);
		---

	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry char** LkExtractRecordsIdDicts(const char* const lkString, uint32_t* count)
{
	char* block = LkExtractData(lkString, RECORD_ID_DICTS_KEY, ASCII_FS, DBMV_Mark_AM);
	if(block != NULL)
	{
		char** data = LkStrSplit(block, DBMV_Mark_AM, count);
		free(block);

		if(*count == 1 && (data[0] == NULL || strcmp(data[0], "") == 0))
		{
			*count = 0;
			free(data[0]);
			free(data);
			return NULL;
		}
		else
			return data;
	}
	else
		return NULL;
}

/*
	Function: LkExtractOriginalRecords
		Extracts the copies from the original records of an operation resultant <LkString>.

	Arguments:
		lkString - Text string on which you are going to extract.
		count - Output argument that inform about the size of the pointer array, that mean, how many strings contains.
	
	Returns:
		Pointer array of string with the copies from the original records from the <LkString>.	
	
	Example:
		--- Code
		// lkStringResult it's a char * returned by a LkRead function
		
		uint32_t count;
		char** originalRecords = LkExtractOriginalRecords(lkStringResult, &count);
		for(int i=0; i<count; i++)
		{
			printf("%s\r\n", originalRecords[i]);
		}
		LkFreeMemoryStringArray(originalRecords, count);
		---

	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry char** LkExtractOriginalRecords(const char* const lkString, uint32_t* count)
{
	char* block = LkExtractData(lkString, ORIGINAL_RECORDS_KEY, ASCII_FS, DBMV_Mark_AM);
	if(block != NULL)
	{
		char** data = LkStrSplit(block, ASCII_RS, count);
		free(block);

		if(*count == 1 && (data[0] == NULL || strcmp(data[0], "") == 0))
		{
			*count = 0;
			free(data[0]);
			free(data);
			return NULL;
		}
		else
			return data;
	}
	else
		return NULL;
}

/*
	Function: LkExtractDictionaries
		Extracts all the file dictionaries of an operation resultant <LkString>.

	Arguments:
		lkString - Text string on which you are going to extract.
		count - Output argument that inform about the size of the pointer array, that mean, how many strings contains.
	
	Returns:
		Pointer array of string with the file dictionaries of the <LkString>.	
	
	Example:
		--- Code
		// lkStringResult it's a char * returned by a LkRead function
		
		uint32_t count;
		char** dictionaries = LkExtractDictionaries(lkStringResult, &count);
		for(int i=0; i<count; i++)
		{
			printf("%s\r\n", dictionaries[i]);
		}
		LkFreeMemoryStringArray(dictionaries, count);
		---

	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry char** LkExtractDictionaries(const char* const lkString, uint32_t* count)
{
	char* block = LkExtractData(lkString, RECORDS_KEY, ASCII_FS, DBMV_Mark_AM);
	if(block != NULL)
	{
		char** data = LkStrSplit(block, ASCII_RS, count);
		free(block);

		if(*count == 1 && (data[0] == NULL || strcmp(data[0], "") == 0))
		{
			*count = 0;
			free(data[0]);
			free(data);
			return NULL;
		}
		else
			return data;
	}
	else
		return NULL;
}

/*
	Function: LkExtractConversion
		Extracts the CONVERSION value of the LkConversion functions resultant <LkString>.

	Arguments:
		lkString - Text string on which you are going to extract.
	
	Returns:
		String CONVERSION value of the <LkString>.
		
	Example:
		--- Code
		// lkStringResult it's a char * returned by a LkConversion function
		
		char* conversion = LkExtractConversion(lkStringResult);
		printf("%s\r\n", conversion);
		LkFreeMemory(conversion);
		---

	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry char* LkExtractConversion(const char* const lkString)
{
	char* data = LkExtractData(lkString, CONVERSION_KEY, ASCII_FS, DBMV_Mark_AM);
	return data;
}

/*
	Function: LkExtractFormat
		Extracts the FORMAT value of the LkFormat functions resultant <LkString>.
	
	Arguments:
		lkString - Text string on which you are going to extract.
	
	Returns:
		String FORMAT value of the <LkString>.
		
	Example:
		--- Code
		// lkStringResult it's a char * returned by a LkFormat function
		
		char* format = LkExtractFormat(lkStringResult);
		printf("%s\r\n", format);
		LkFreeMemory(format);
		---

	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry char* LkExtractFormat(const char* const lkString)
{
	char* data = LkExtractData(lkString, FORMAT_KEY, ASCII_FS, DBMV_Mark_AM);
	return data;
}

/*
	Function: LkExtractCapturing
		Extracts the CAPTURING value of an lkExecute functions resultant <LkString>.
		
	Arguments:
		lkString - Text string on which you are going to extract.
	
	Returns:
		String CAPTURING value of the <LkString>.
	
	Example:
		--- Code
		// lkStringResult it's a char * returned by a LkExecute function
		
		char* capturing = LkExtractCapturing(lkStringResult);
		printf("%s\r\n", capturing);
		LkFreeMemory(capturing);
		---

	Also See:
		<LkString>
				
		<Release Memory>
*/
DllEntry char* LkExtractCapturing(const char* const lkString)
{
	char* data = LkExtractData(lkString, CAPTURING_KEY, ASCII_FS, DBMV_Mark_AM);
	return data;
}

/*
	Function: LkExtractReturning
		Extracts the RETURNING value of the LkExecute functions resultant <LkString>.
	
	Arguments:
		lkString - Text string on which you are going to extract.
	
	Returns:
		String RETURNING value of the <LkString>.
		
	Example:
		--- Code
		// lkStringResult it's a char * returned by a LkExecute function
		
		char* returning = LkExtractReturning(lkStringResult);
		printf("%s\r\n", returning);
		LkFreeMemory(returning);
		---

	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry char* LkExtractReturning(const char* const lkString)
{
	char* data = LkExtractData(lkString, RETURNING_KEY, ASCII_FS, DBMV_Mark_AM);
	return data;
}

/*
	Function: LkExtractSubroutineArgs
		Extracts the ARGUMENTS value of the LkSubroutine functions resultant <LkString>.
		
	Arguments:
		lkString - Text string on which you are going to extract.
		count - Output argument that inform about the size of the pointer array, that mean, how many strings contains.

	Returns:
		Pointer array of string with the ARGUMENTS value of the LkSubroutine functions resultant <LkString>.
		
	Example:
		--- Code
		// lkStringResult it's a char * returned by a LkSubroutine function
		
		uint32_t count;
		char** arguments = LkExtractSubroutineArgs(lkStringResult, &count);
		for(int i=0; i<count; i++)
		{
			printf("%s\r\n", arguments[i]);
		}
		LkFreeMemoryStringArray(arguments, count);
		---

	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry char** LkExtractSubroutineArgs(const char* const lkString, uint32_t *count)
{
	char* block = LkExtractData(lkString, ARGUMENTS_KEY, ASCII_FS, DBMV_Mark_AM);
	if(block != NULL)
	{
		char** data = LkStrSplit(block, ASCII_DC4, count);
		free(block);
		return data;
	}
	else
		return NULL;
}

/*
	Function: LkExtractRowProperties
		Extracts the ROWPROPERTIES value of the Schemas functions resultant <LkString>.
		
	Arguments:
		lkString - Text string on which you are going to extract.
		count - Output argument that inform about the size of the pointer array, that mean, how many strings contains.
	
	Returns:
		Pointer array of string with the ROWPROPERTIES value of the Schemas functions resultant <LkString>.
		
	Example:
		--- Code
		// lkStringResult it's a char * returned by a Schemas functions
		
		char* rowProperties = LkExtractRowProperties(lkStringResult);
		printf("%s\r\n", rowHeaders);
		LkFreeMemory(rowHeaders);
		---

	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry char** LkExtractRowProperties(const char* const lkString, uint32_t *count)
{
	char* block = LkExtractData(lkString, ROWPROPERTIES_KEY, ASCII_FS, DBMV_Mark_AM);
	if(block != NULL)
	{
		char** data = LkStrSplit(block, DBMV_Mark_AM, count);
		free(block);
		return data;
	}
	else
		return NULL;
}

/*
	Function: LkExtractRowHeaders
		Extracts the ROWHEADERS value of the Schemas functions resultant <LkString>.
		
	Arguments:
		lkString - Text string on which you are going to extract.
		count - Output argument that inform about the size of the pointer array, that mean, how many strings contains.
	
	Returns:
		Pointer array of string with the ROWHEADERS value of the Schemas functions resultant <LkString>.
		
	Example:
		--- Code
		// lkStringResult it's a char * returned by a Schemas functions
		
		char* rowHeaders = LkExtractRowHeaders(lkStringResult);
		printf("%s\r\n", rowHeaders);
		LkFreeMemory(rowHeaders);
		---

	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry char** LkExtractRowHeaders(const char* const lkString, uint32_t *count)
{
	char* block = LkExtractData(lkString, ROWHEADERS_KEY, ASCII_FS, DBMV_Mark_AM);
	if(block != NULL)
	{
		char** data = LkStrSplit(block, DBMV_Mark_AM, count);
		free(block);
		return data;
	}
	else
		return NULL;
}
		
/*
	Function: LkComposeRecordIds
		Composes the final string of various "recordIds". Used by LkRead Operation and <LkComposeNewBuffer>, <LkComposeUpdateBuffer> and <LkComposeDeleteBuffer> functions in CRUD Operations.
	
	Arguments:
		lstRecordIds - Array (pointer to array of char pointers) with the "recordIds" to be joined.
		count - The array size. 
	
	Returns:
		The final string of "recordIds" to be used in CRUD Operations.
		
	Example:
		--- Code
		char* id1 = "1";
		char* id2 = "2";
		char* lstIds[2] = { id1, id2 };
		char* recordIds = LkComposeRecordIds(lstIds, 2);
		---
		"recordIds" variable contains the Ids in the correct format to be used by <LkComposeNewBuffer>, <LkComposeUpdateBuffer> and <LkComposeDeleteBuffer> functions in CRUD Operations.

	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry char* LkComposeRecordIds(const char** const lstRecordIds, uint32_t count)
{
	return LkStrJoin(lstRecordIds, count, ASCII_RS_str);
}

/*
	Function: LkComposeRecords
		Composes the final string of various "records". Used by <LkComposeNewBuffer>, <LkComposeUpdateBuffer> and <LkComposeDeleteBuffer> functions in LkNew, LkUpdate and LkDelete Operations.
	
	Arguments:
		lstRecords - Array (pointer to array of char pointers) with the "records" to be joined.
		count - The array size. 
	
	Returns:
		The final string of "records" to be used by CRUD Operations.
		
	Example:
		--- Code
		// Building the record1
		char record1 [100];
		strcpy(record1, "CUSTOMER_NEWID1"); // CUSTOMER NAME
		strcat(record1, DBMV_Mark_AM_str);
		strcat(record1, "ADDRESS NEWID1"); // CUSTOMER ADDRESS
		strcat(record1, DBMV_Mark_AM_str);
		strcat(record1, "555 123456"); // CUSTOMER PHONE
		
		// Building the record2
		char record2 [100];
		strcpy(record2, "CUSTOMER_NEWID2"); // CUSTOMER NAME
		strcat(record2, DBMV_Mark_AM_str);
		strcat(record2, "ADDRESS NEWID2"); // CUSTOMER ADDRESS
		strcat(record2, DBMV_Mark_AM_str);
		strcat(record2, "555 654321"); // CUSTOMER PHONE
		
		//Building the array of records
		char* lstRecords[2] = { record1, record2 };				
		char* records = LkComposeRecords(lstRecords, 2);
		---
		"records" variable contains the records data in the correct format to be used by <LkComposeNewBuffer>, <LkComposeUpdateBuffer> and <LkComposeDeleteBuffer> functions.
				
	Also See:
		<LkString>
		
		<Release Memory>	
*/
DllEntry char* LkComposeRecords(const char** const lstRecords, uint32_t count)
{
    return LkStrJoin(lstRecords, count, ASCII_RS_str);
}

/*
	Function: LkComposeOriginalRecords
		Composes the final string of various "originalRecords". Used by <LkComposeUpdateBuffer> and <LkComposeDeleteBuffer> functions in LkUpdate and LkDelete Operations.
	
	Arguments:
		lstOriginalRecords - Array (pointer to array of char pointers) with the "originalRecords" to be joined.
		count - The array size. 
	
	Returns:
		The final string of "originalRecords" to be used by CRUD Operations.
	
	Also See:
		<LkString>
		
		<Release Memory>	
*/
DllEntry char* LkComposeOriginalRecords(const char** const lstOriginalRecords, uint32_t count)
{
    return LkStrJoin(lstOriginalRecords, count, ASCII_RS_str);
}

/*
	Function: LkComposeDictionaries.
		Composes the final string of various "dictClauses". Used by Read and Select Operations.
		
	Arguments:
		lstDictionaries - Array (pointer to array of char pointers) with the "dictionaries" to be joined.
		count - The array size
	
	Returns:
		The final string of "dictionaries" to be used by Read and Select Operations.
		
	Example:
		--- Code
		char* id1 = "1";
		char* id2 = "2";
		char* lstIds[2] = { id1, id2 };
		char* recordIds = LkComposeRecordIds(lstIds, 2);
		char* error;
		char* credentialOptions = LkCreateCredentialOptions("localhost", "EPNAME", 11300, "USERNAME", "PASSWORD", "", "Test C Library");
		// Change "localhost", "EPNAME", 11300, "USERNAME" and "PASSWORD" by the correct data of your EntryPoint.
		
		char* filename = "LK.CUSTOMERS";
		
		char* lstDictionaries[2] = { "NAME", "PHONE" }; // We will read only the dicionaries "NAME" (1) and "PHONE" (3)
		char* dictionaries = LkComposeDictionaries(lstDictionaries);
		
		char* readOptions = NULL;
		char* customVars = "";
		uint32_t receiveTimeout = 30;
		char* result = LkRead(&error, credentialOptions, filename, recordIds, dictionaries, readOptions, customVars, receiveTimeout);

		// Don't forget release memory when you don't need anymore the "result" and "credentialOptions" string.
		LkFreeMemory(result);
		lkFreeMemory(credentialOptions);
		---
	
	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry char* LkComposeDictionaries(const char** const lstDictionaries, uint32_t count)
{
    return LkStrJoin(lstDictionaries, count, " ");
}

/*
	Function: LkComposeExpressions
		Composes the final string of various "expressions". Used by Format and Conversion Operations.
	
	Arguments:
		lstExpressions - Array (pointer to array of char pointers) with the "expressions" to be joined.
		count - The array size
		
	Returns:
		The final string of "expressions" to be used in Format and Conversion Operations.
				
	Also See:
		<LkString>
		
		<Release Memory>
*/
DllEntry char* LkComposeExpressions(const char** const lstExpressions, uint32_t count)
{
    return LkStrJoin(lstExpressions, count, DBMV_Mark_AM_str);
}

/*
	Function: LkComposeSubroutineArgs
		Composes the final string of various "arguments" of a subroutine.
	
	Arguments:
		lstArgs - Array (pointer to array of char pointers) with the "arguments" to be joined.
		count - The array size
	
	Returns:
		The final string to be used in Subroutine Operations.
		
	Example:
		--- Code
		char* subroutineName = "SUB.DEMOLINKAR";
		
		uint32_t argsNumber = 3;
		char* lstArgs[3] = { "0", "aaaaa", "" };
		char* arguments = LkComposeSubroutineArgs(lstArgs, argsNumber);
		
		char* error;
		char* credentialOptions = LkCreateCredentialOptions("localhost", "EPNAME", 11300, "USERNAME", "PASSWORD", "", "Test C Library");
		// Change "localhost", "EPNAME", 11300, "USERNAME" and "PASSWORD" by the correct data of your EntryPoint.

		result = LkSubroutine(&error, credentialOptions, subroutineName, argsNumber, arguments, customVars, receiveTimeout);
		LkFreeMemory(arguments);	
		if(error != NULL)
		{
			printf("ERRORS: %s\n", error);
			free(error);
		}
		else
		{
			printf("result: %s\n", result);		
			char* resultArgs = LkExtractSubroutineArgs(result);
			LkFreeMemory(result);
			printf("resultArgs: %s\n", resultArgs);
			
			lstArgs = LkStrSplit(resultArgs, ASCII_DC4, &argsNumber);
			LkFreeMemory(resultArgs);

			for(int i=0; i<argsNumber; i++)
				printf("resultArg %d: %s\n", i, lstArgs[i]);
			
			LkFreeMemoryStringArray(lstArgs, argsNumber);
		}
		
		lkFreeMemory(credentialOptions);
		---
		
	Also See:
		<Release Memory>
		
		<LkString>
*/
DllEntry char* LkComposeSubroutineArgs(const char** const lstArgs, uint32_t count)
{
    return LkStrJoin(lstArgs, count, ASCII_DC4_str);
}

/*
	Function: LkComposeUpdateBuffer
		Compose the fully buffer of the Update Operations with the block of "recordIds", "records" and "originalRecords".
	
	Arguments:
		recordIds - Block of "recordIds". You can obtain this block with <LkComposeRecordIds> function.
		records - Block of "records". You can obtain this block with <LkComposeRecords> function.
		originalRecords - Block of "originalRecords". You can obtain this block with <LkComposeRecords> function.
	
	Returns:
		The buffer to be used by Update Operations.
		
	Example:
		--- Code
		// We assumed that e LkRead Operation was executed and in "recordIds" are the Ids of the records, and in "lstRecords" we extracted the 2 readed records.
		char* pRec = lstRecords[0];
		lstRecords[0] = LkReplace(lstRecords[0], "CUSTOMER_TEST1_UPDATE", 1, 0, 0);
		LkFreeMemory(pRec);
		pRec = lstRecords[1];
		lstRecords[1] = LkReplace(lstRecords[1], "CUSTOMER_TEST2_UPDATE", 1, 0, 0);
		LkFreeMemory(pRec);
		
		for(int i=0; i<count; i++)
			printf("Record %i: %s\n", (i+1), lstRecords[i]);
	
		BOOL opOptimisticLock = FALSE;
		BOOL opReadAfter = TRUE;
		BOOL opCalculated = FALSE;
		BOOL opConversion = FALSE;
		BOOL opFormatSpec = FALSE;
		BOOL opOriginalRecords = TRUE;
		char* updateOptions = LkCreateUpdateOptions(opOptimisticLock, opReadAfter, opCalculated, opConversion, opFormatSpec, opOriginalRecords);
		char* records = LkComposeRecords(lstRecords, 2);
		
		char* updateBuffer = LkComposeUpdateBuffer(recordIds, records, NULL);
		LkFreeMemory(records);
	
		result = LkUpdate(&error, credentialOptions, filename, updateBuffer, updateOptions, customVars, receiveTimeout);
		LkFreeMemory(updateBuffer);		
		
		// "result" contains the result of the LkUpdate Operation
		
		// Don't forget release memory when you don't need anymore the "result" and "credentialOptions" string
		LkFreeMemory(result);
		lkFreeMemory(credentialOptions);				
		---
		
	Also See:
		<LkComposeRecordIds>
		
		<LkComposeRecords>
	
		<Release Memory>	
*/
DllEntry char* LkComposeUpdateBuffer(const char* const recordIds, const char* const records, const char* const originalRecords)
{
	int lenRecordIds = 0;
	int lenRecords = 0;
	int lenOriginalRecords = 0;
	if(recordIds != NULL)
		lenRecordIds = strlen(recordIds);
	if(records != NULL)
		lenRecords = strlen(records);
	if(originalRecords != NULL)
		lenOriginalRecords = strlen(originalRecords);
		
	uint32_t len = lenRecordIds + lenRecords + lenOriginalRecords + 2*strlen(ASCII_FS_str) + 1;
	char* updateBuffer = malloc(len);
	if(updateBuffer != NULL)
	{
		if(recordIds != NULL)
		{
			strcpy(updateBuffer, recordIds);
			strcat(updateBuffer, ASCII_FS_str);
		}
		else
			strcpy(updateBuffer, ASCII_FS_str);
		
		if(records != NULL)
			strcat(updateBuffer, records);
		
		strcat(updateBuffer, ASCII_FS_str);
		
		if(originalRecords != NULL)
			strcat(updateBuffer, originalRecords);
	}
	
	return updateBuffer;
}
        
/*
	Function: LkComposeNewBuffer
		Compose the fully buffer of the New Operations with the block of "recordIds" and "records".
	
	Arguments:
		recordIds - Block of "recordIds". You can obtain this block with <LkComposeRecordIds> function.
		records - Block of "records". You can obtain this block with <LkComposeRecords> function.

	Returns:
		The buffer to be used by New Operations.
	
	Example:
		--- Code
		// Building the array of recordIds
		char* lstRecordIds[2] = { "NEWID1", "NEWID2" };
		char* recordIds = LkComposeRecordIds(lstRecordIds, 2);
		
		// Building the record1
		char record1 [100];
		strcpy(record1, "CUSTOMER_NEWID1"); // CUSTOMER NAME
		strcat(record1, DBMV_Mark_AM_str);
		strcat(record1, "ADDRESS NEWID1"); // CUSTOMER ADDRESS
		strcat(record1, DBMV_Mark_AM_str);
		strcat(record1, "555 123456"); // CUSTOMER PHONE
		
		// Building the record2
		char record2 [100];
		strcpy(record2, "CUSTOMER_NEWID2"); // CUSTOMER NAME
		strcat(record2, DBMV_Mark_AM_str);
		strcat(record2, "ADDRESS NEWID2"); // CUSTOMER ADDRESS
		strcat(record2, DBMV_Mark_AM_str);
		strcat(record2, "555 654321"); // CUSTOMER PHONE
		
		//Building the array of records
		char* lstRecords[2] = { record1, record2 };				
		char* records = LkComposeRecords(lstRecords, 2);
		
		char* newBuffer = LkComposeNewBuffer(recordIds, records);
		LkFreeMemory(recordIds);
		LkFreeMemory(records);
	
		char* error;
		char* credentialOptions = LkCreateCredentialOptions("localhost", "EPNAME", 11300, "USERNAME", "PASSWORD", "", "Test C Library");
		// Change "localhost", "EPNAME", 11300, "USERNAME" and "PASSWORD" by the correct data of your EntryPoint.

		char* filename = "LK.CUSTOMERS";
		char* dictionaries = "";
		char* newOptions = NULL;
		char* customVars = "";
		uint32_t receiveTimeout = 30;
		char* result = LkNew(&error, credentialOptions, filename, newBuffer, newOptions, customVars, receiveTimeout);
		LkFreeMemory(newBuffer);
		
		// "result" contains the result of the LkNew Operation
		
		// Don't forget release memory when you don't need anymore the "result" and "credentialOptions" string
		LkFreeMemory(result);
		lkFreeMemory(credentialOptions);				
		---
		
	Also See:
		<LkComposeRecordIds>
		
		<LkComposeRecords>
	
		<Release Memory>
*/
DllEntry char* LkComposeNewBuffer(const char* const recordIds, const char* const records)
{
	int lenRecordIds = 0;
	int lenRecords = 0;
	if(recordIds != NULL)
		lenRecordIds = strlen(recordIds);
	if(records != NULL)
		lenRecords = strlen(records);

	uint32_t len = lenRecordIds + lenRecords + strlen(ASCII_FS_str) + 1;
    char* newBuffer = malloc(len);
	if(newBuffer != NULL)
	{
		if(recordIds != NULL)
		{
			strcpy(newBuffer, recordIds);
			strcat(newBuffer, ASCII_FS_str);
		}
		else
			strcpy(newBuffer, ASCII_FS_str);

		if(records != NULL)
			strcat(newBuffer, records);
	}
	
	return newBuffer;
}

/*
	Function: LkComposeDeleteBuffer
		Compose the fully buffer of the Delete Operations with the block of "recordIds" and "originalRecords".
	
	Arguments:
		recordIds - Block of "recordIds". You can obtain this block with <LkComposeRecordIds> function.
		originalRecords - Block of "originalRecords". You can obtain this block with <LkComposeRecords> function.
		
	Returns:
		The buffer to be used by Delete Operations.
	
	Example:
		--- Code
		char* id1 = "1";
		char* id2 = "2";
		char* lstIds[2] = { id1, id2 };
		char* recordIds = LkComposeRecordIds(lstIds, 2);
		char* error;
		char* credentialOptions = LkCreateCredentialOptions("localhost", "EPNAME", 11300, "USERNAME", "PASSWORD", "", "Test C Library");
		// Change "localhost", "EPNAME", 11300, "USERNAME" and "PASSWORD" by the correct data of your EntryPoint.
		
		char* filename = "LK.CUSTOMERS";
				
		char* deleteOptions = NULL;
		char* originalRecords = ""; // If "deleteOptions" variable is create with "originalRecords" to TRUE, then
									// if this variable will be the original records
									
		char* records = LkComposeDeleteBuffer(recordIds, originalRecords);
		
		char* customVars = "";
		uint32_t receiveTimeout = 30;
		char* result = LkDelete(&error, credentialOptions, filename, records, deleteOptions, customVars, receiveTimeout);

		// "result" contains the result of the LkDelete Operation

		// Don't forget release memory when you don't need anymore the "result" and "credentialOptions" string
		LkFreeMemory(result);
		lkFreeMemory(credentialOptions);				
		---
		
	Also See:
		<LkComposeRecordIds>
		
		<LkComposeRecords>
	
		<Release Memory>
*/
DllEntry char* LkComposeDeleteBuffer(const char* const recordIds, const char* const originalRecords)
{
	int lenRecordIds = 0;
	int lenOriginalRecords = 0;
	if(recordIds != NULL)
		lenRecordIds = strlen(recordIds);
	if(originalRecords != NULL)
		lenOriginalRecords = strlen(originalRecords);

	uint32_t len = lenRecordIds + lenOriginalRecords + strlen(ASCII_FS_str) + 1;
	char* deleteBuffer = malloc(len);
	if(deleteBuffer != NULL)
	{
		if(recordIds != NULL)
		{
			strcpy(deleteBuffer, recordIds);
			strcat(deleteBuffer, ASCII_FS_str);
		}
		else
			strcpy(deleteBuffer, ASCII_FS_str);

		if(originalRecords != NULL)
			strcat(deleteBuffer, originalRecords);
	}

	return deleteBuffer;
}

/*	
	File: OperationsOptions.c
	This module contains auxiliary functions to create the options of every operation.

	Note:
	All functions comments here, return a char* value. That memory was allocated dynamically, so once those string is not needed anymore, the memory assigned to them *must be released*.
	See <Release Memory> for known how to do.
*/

#include "OperationOptions.h"

#include <stdio.h>
#include <malloc.h>
#include <string.h>

/* 
	Function: LkCreateCommonOptions
		Helper function to build the string with the common options to others operation options.
	
	Arguments:
		calculated - Return the resulting values from the calculated dictionaries.
		conversion - Execute the defined conversions in the dictionaries before returning.
		formatSpec - Execute the defined formats in the dictionaries before returning.
		originalRecords - Return a copy of the records in MV format.
   
	Returns:      
		A string with the Read Options codified inside.
	
	See Also:	
		<LkCreateReadOptions>
		
		<LkCreateReadAfterCommonOptions>
		
		<LkCreateSelectOptions>
		
		<Release Memory>
*/
static char* LkCreateCommonOptions(BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords)
{
	int len = 5 + 4 * sizeof(DBMV_Mark_AM_str);
	char* str = malloc(len + 1);
	if(str)
	{	
		strcpy(str, (calculated? "1" : "0"));
		strcat(str, DBMV_Mark_AM_str);
		//strcat(str, (dictionaries? "1" : "0"));
		strcat(str, DBMV_Mark_AM_str);
		strcat(str, (conversion? "1" : "0"));
		strcat(str, DBMV_Mark_AM_str);
		strcat(str, (formatSpec? "1" : "0"));
		strcat(str, DBMV_Mark_AM_str);
		strcat(str, (originalRecords? "1" : "0"));
	}				

	return str;
}

/* 
	Function: LkCreateReadOptions
		Creates a string that contains the options for LkRead functions.
	
	Arguments:
		calculated - Return the resulting values from the calculated dictionaries.
		conversion - Execute the defined conversions in the dictionaries before returning.
		formatSpec - Execute the defined formats in the dictionaries before returning.
		originalRecords - Return a copy of the records in MV format.
   
	Returns:      
		A string with the Read Options codified inside. To use with <LkRead> functions.
		
	Example:
		--- Code
		BOOL calculated = TRUE;
		BOOL conversion = FALSE;
		BOOL formatSpec = FALSE;
		BOOL originalRecords = TRUE;
		
		char* readOptions = LkCreateReadOptions(calculated, conversion, formatSpec, originalRecords);
		---
	
	See Also:				
		<Release Memory>
*/
DllEntry char* LkCreateReadOptions(BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords)
{	
	return LkCreateCommonOptions(calculated, conversion, formatSpec, originalRecords);
}

/*
	Function: LkCreateReadAfterCommonOptions
		Helper function to build the string with the common options to others operation options.

	Arguments:
		readAfter - Reads the record again and returns it after the update. The calculated, dictionaries, conversion, formatSpec and originalBuffer arguments will only make effect if this option is true.
		calculated - Return the resulting values from the calculated dictionaries.
		conversion - Execute the defined conversions in the dictionaries before returning.
		formatSpec - Execute the defined formats in the dictionaries before returning.
		originalRecords - Return a copy of the records in MV format.
	
	Returns:
		A string with the ReadAfter and CommonOptions codified inside.
		
	See Also:		
		<LkCreateCommonOptions>
		
		<LkCreateUpdateOptions>
		
		<LkCreateNewOptions>
		
		<Release Memory>
*/
static char* LkCreateReadAfterCommonOptions(BOOL readAfter, BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords)
{
	char* readAfterCommOpt = NULL;
	char* commonOpt = LkCreateCommonOptions(calculated, conversion, formatSpec, originalRecords);
	if(commonOpt)
	{
		int len = 1 + sizeof(DBMV_Mark_AM_str) + strlen(commonOpt);
		readAfterCommOpt = malloc(len + 1);
		if(readAfterCommOpt)
		{
			strcpy(readAfterCommOpt, (readAfter? "1" : "0"));
			strcat(readAfterCommOpt, DBMV_Mark_AM_str);
			strcat(readAfterCommOpt, commonOpt);
		}
		
		free(commonOpt);
	}

	return readAfterCommOpt;
}

/*
	Function: LkCreateUpdateOptions
		Creates a string that contains the options for the LkUpdate functions.

	Arguments:
		optimisticLock - Checks out if the file has not been modified by other user.
		readAfter - Reads the record again and returns it after the update. The calculated, dictionaries, conversion, formatSpec and originalBuffer arguments will only make effect if this option is true.
		calculated - Return the resulting values from the calculated dictionaries.
		conversion - Execute the defined conversions in the dictionaries before returning.
		formatSpec - Execute the defined formats in the dictionaries before returning.
		originalRecords - Return a copy of the records in MV format.
	
	Returns:
		A string with the Update Options codified inside. To use with <LkUpdate> and <LkUpdateD> functions.
	
	Remarks:
		If the OptimisticLock property is set to true, a copy of the record must be provided before the modification (originalRecords argument)
		to use the Optimistic Lock technique. This copy can be obtained from a previous Read operation. The database, before executing the modification, 
		reads the record and compares it with the copy in originalRecords, if they are equal the modified record is executed.
		But if they are not equal, it means that the record has been modified by other user and its modification will not be saved.
		The record will have to be read, modified and saved again.
	
	Example:
		--- Code
		BOOL calculated = TRUE;
		BOOL readAfter = TRUE;
		BOOL conversion = FALSE;
		BOOL formatSpec = FALSE;
		BOOL originalRecords = TRUE;
		
		char* readOptions = LkCreateUpdateOptions(calculated, readAfter, conversion, formatSpec, originalRecords);
		---

	See Also:		
		<Release Memory>
*/
DllEntry char* LkCreateUpdateOptions(BOOL optimisticLock, BOOL readAfter, BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords)
{
	char* updateOpt = NULL;
	char* readAfterCommOpt = LkCreateReadAfterCommonOptions(readAfter, calculated, conversion, formatSpec, originalRecords);
	if(readAfterCommOpt)
	{
		int len = 1 + sizeof(DBMV_Mark_AM_str) + strlen(readAfterCommOpt);
		updateOpt = malloc(len + 1);
		if(updateOpt)
		{
			strcpy(updateOpt, (optimisticLock? "1" : "0"));
			strcat(updateOpt, DBMV_Mark_AM_str);
			strcat(updateOpt, readAfterCommOpt);			
		}
		
		free(readAfterCommOpt);
	}
	
	return updateOpt;
}

/*
	Function: LkCreateNewOptions
		Creates a string that contains the options for the LkNew functions.

	Arguments:
		newItemIdType - A string where is codified the options for the creation of codes. There are 4 options:
		
			- None. The code is supply by the argument recordIds in the <LkNew> and <LkNewD> function. Use <LkCreateNewRecordIdTypeNone> function to work with these options.
			
			- Linkar. The code is generated using Linkar codes type. Use <LkCreateNewRecordIdTypeLinkar> function to work with these options.
			
			- Custom. The code is generated using Custom codes type. Use <LkCreateNewRecordIdTypeCustom> function to work with these options.
			
			- Random. The code is generated using Random codes type. Use <LkCreateNewRecordIdTypeRandom> function to work with these options.		
		
		readAfter - Reads the record again and returns it after the creation. The calculated, dictionaries, conversion, formatSpec and originalBuffer arguments will only make effect if this option is true.
		calculated - Return the resulting values from the calculated dictionaries.
		conversion - Execute the defined conversions in the dictionaries before returning.
		formatSpec - Execute the defined formats in the dictionaries before returning.
		originalRecords - Return a copy of the records in MV format.
		dictionaries - Return the File dictionaries.
	
	Returns:
		A string with the New Options codified inside. To use with <LkNew> and <LkNewD> functions.
		
	Example:
		--- Code
		char* recordIdTypeNode = LkCreateNewRecordIdTypeNone();
		BOOL calculated = TRUE;
		BOOL readAfter = TRUE;
		BOOL conversion = FALSE;
		BOOL formatSpec = FALSE;
		BOOL originalRecords = TRUE;
	
		char* newOptions = LkCreateNewOptions(recordIdTypeNode, readAfter, calculated, conversion, formatSpec, originalRecords);
		---
		
	See Also:	
		<LkCreateNewRecordIdTypeNone>
		
		<LkCreateNewRecordIdTypeLinkar>
		
		<LkCreateNewRecordIdTypeCustom>
		
		<LkCreateNewRecordIdTypeRandom>
		
		<Release Memory>
*/
DllEntry char* LkCreateNewOptions(const char* const newItemIdType, BOOL readAfter, BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords)
{
	char* newOpt = NULL;
	char* readAfterCommOpt = LkCreateReadAfterCommonOptions(readAfter, calculated, conversion, formatSpec, originalRecords);
	if(readAfterCommOpt)
	{
		char* newItemIdType2;
		if(newItemIdType == NULL)
			newItemIdType2 = LkCreateNewRecordIdTypeNone();
		else
			newItemIdType2 = (char*)newItemIdType;
		
		// newItemIdType @AM readAfterCommOpt
		int len = strlen(newItemIdType2) + strlen(DBMV_Mark_AM_str) + strlen(readAfterCommOpt);
		newOpt = malloc(len + 1);
		if(newOpt)
		{
			strcpy(newOpt, newItemIdType2);
			strcat(newOpt, DBMV_Mark_AM_str);
			strcat(newOpt, readAfterCommOpt);
		}
		if(newItemIdType != newItemIdType2)
			free(newItemIdType2);
	}
	
	return newOpt;
}

/*
	Function: LkCreateNewRecordIdTypeNone
		Creates a string that defines the type of ID to be used in <LkCreateNewOptions> function as NONE.
		That mean, the type of ID will be free. The code is supply by the argument recordIds in the <LkNew> and <LkNewD> function.
			
	Returns:
		A string that defines the type of ID to be used in <LkCreateNewOptions> as NONE.
		
	Example:
		--- Code
		char* recordIdTypeNone = LkCreateNewRecordIdTypeNone();
		---
	
	See Also:
		<LkCreateNewOptions>
		
		<Release Memory>
*/
DllEntry char* LkCreateNewRecordIdTypeNone()
{	
	// 0 @AM 0 @AM 0
	int lenItemIdType = 3 + 2*strlen(DBMV_Mark_AM_str);
	char* itemIdType = malloc(lenItemIdType + 1);
	if(itemIdType)
	{
		strcpy(itemIdType, "0");
		strcat(itemIdType, DBMV_Mark_AM_str);
		strcat(itemIdType, "0");
		strcat(itemIdType, DBMV_Mark_AM_str);
		strcat(itemIdType, "0");
	}
	
	return itemIdType;
}

/*
	Function: LkCreateNewRecordIdTypeLinkar
		Creates a string that defines the type of ID to be used in <LkCreateNewOptions> function as Linkar.
		That mean, the type of ID will be of Linkar type: with prefix, separator and formatSpec.
		
	Arguments:
		prefix - Add a prefix to the code.
		separator - The separator between the prefix and the code. The list of allowed separators is: ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~
		formatSpec - The format of the code, under the syntax of the database.
	
	Returns:
		A string that defines the type of ID to be used in <LkCreateNewOptions> as Linkar.
		
	Example:
		--- Code
		char* recordIdTypeLinkar = LkCreateNewRecordIdTypeLinkar("2020", "_", "4\"0\"R");
		// The first ID ti be created will be 2020_0001, the second 2020_0002, etc...
		---
	
	See Also:
		<LkCreateNewOptions>
		
		<Release Memory>
*/
DllEntry char* LkCreateNewRecordIdTypeLinkar(const char* const prefix, const char* const separator, const char* const formatSpec)
{	
	// 1 @VM prefix @VM separator @VM formatSpec @AM 0 @AM 0
	int lenItemIdType = 3 + 2*strlen(DBMV_Mark_AM_str) + 3*strlen(DBMV_Mark_VM_str) + strlen(prefix) + strlen(separator) + strlen(formatSpec);
	char* itemIdType = malloc(lenItemIdType + 1);
	if(itemIdType)
	{
		strcpy(itemIdType, "1");
		strcat(itemIdType, DBMV_Mark_VM_str);
		strcat(itemIdType, prefix);
		strcat(itemIdType, DBMV_Mark_VM_str);
		strcat(itemIdType, separator);
		strcat(itemIdType, DBMV_Mark_VM_str);
		strcat(itemIdType, formatSpec);		
		strcat(itemIdType, DBMV_Mark_AM_str);
		strcat(itemIdType, "0");
		strcat(itemIdType, DBMV_Mark_AM_str);
		strcat(itemIdType, "0");
	}	
	return itemIdType;
}

/*
	Function: LkCreateNewRecordIdTypeCustom
		Creates a string that defines the type of ID to be used in <LkCreateNewOptions> function as Custom.
		That mean, the type of ID will be of Custom type: defined by custom SUB.LK.MAIN.NEWRECOVERRECORDID.CUSTOM subroutine.
	
	Returns:
		A string that defines the type of ID to be used in <LkCreateNewOptions> function as Custom.
		
	See Also:
		<LkCreateNewOptions>
		
		<Release Memory>
*/
DllEntry char* LkCreateNewRecordIdTypeCustom()
{	
	// 0 @AM 1 @AM 0
	int lenItemIdType = 3 + 2*strlen(DBMV_Mark_AM_str);
	char* itemIdType = malloc(lenItemIdType + 1);
	if(itemIdType)
	{
		strcpy(itemIdType, "0");
		strcat(itemIdType, DBMV_Mark_AM_str);
		strcat(itemIdType, "1");
		strcat(itemIdType, DBMV_Mark_AM_str);
		strcat(itemIdType, "0");
	}
	
	return itemIdType;
}

/*
	Function: LkCreateNewRecordIdTypeRandom
		Creates a string that defines the type of ID to be used in <LkCreateNewOptions> function as Random.
		That mean, the type of ID will be of Random type: The ID will be generated randomly

	Arguments:
		numeric - Indicates if the code must be numeric.
		length - Length of the code to be generated. It must be greater than 0.
	
	Returns:
		A string that defines the type of ID to be used in <LkCreateNewOptions> function as Random.
		
	Example:
		--- Code
		BOOL numeric = TRUE;
		uint32_t length = 4;
		char* recordIdTypeRandom = LkCreateNewRecordIdTypeRandom(numeric, length);
		---
		
	See Also:
		<LkCreateNewOptions>
		
		<Release Memory>
*/
DllEntry char* LkCreateNewRecordIdTypeRandom(BOOL numeric, uint32_t length)
{
	// 0 @AM 0 @AM 1 @VM numeric @VM length
	char lengthStr[50];
	sprintf(lengthStr, "%d", length);
	int lenItemIdType = 3 + 2*strlen(DBMV_Mark_AM_str) + 2*strlen(DBMV_Mark_VM_str) + 1 + strlen(lengthStr);
	char* itemIdType = malloc(lenItemIdType + 1);
	if(itemIdType)
	{
		strcpy(itemIdType, "0");
		strcat(itemIdType, DBMV_Mark_AM_str);
		strcat(itemIdType, "0");
		strcat(itemIdType, DBMV_Mark_AM_str);
		strcat(itemIdType, "1");
		strcat(itemIdType, DBMV_Mark_VM_str);
		strcat(itemIdType, (numeric? "1" : "0"));
		strcat(itemIdType, DBMV_Mark_VM_str);
		strcat(itemIdType, lengthStr);
	}
	
	return itemIdType;
}

/*
	Function: LkCreateDeleteOptions
		Creates a string that contains the options for the LkDelete functions.

	Arguments:
		optimisticLock - Checks out if the file has not been modified by other user.
		recoverIdType - A string where is codified the options for code recovering. There are 3 options:
			
			- None. The recovery of deleted ID codes will not be used. Use <LkCreateRecoverRecordIdTypeNone> function to work with these options.
			
			- Linkar. It will use the recovery of deleted codes of type Linkar. Use <LkCreateRecoverRecordIdTypeLinkar> function to work with these options.
			
			- Custom. The recovery of deleted codes will be performed through the use of custom subroutines. Use <LkCreateRecoverRecordIdTypeCustom> function to work with these options.
	
	Returns:
		A string with the Delete Options codified inside. To use with <LkDelete> and <LkDeleteD> functions.
		
	Example:
		--- Code
		BOOL optimisticLock = TRUE;
		char* recoverRecordIdTypeLinkar = LkCreateRecoverRecordIdTypeLinkar("2020", "_");
		char* deleteOptions = LkCreateDeleteOptions(optimisticLock, recoverRecordIdTypeLinkar);
		---
		
	See Also:
		<LkCreateRecoverRecordIdTypeNone>
		
		<LkCreateRecoverRecordIdTypeLinkar>
		
		<LkCreateRecoverRecordIdTypeCustom>
				
		<Release Memory>
*/
DllEntry char* LkCreateDeleteOptions(BOOL optimisticLock, const char* const recoverIdType)
{
	char* recoverIdType2;
	if(recoverIdType == NULL)
		recoverIdType2 = LkCreateRecoverRecordIdTypeNone();
	else
		recoverIdType2 = (char*)recoverIdType;
	
	int len = 1 + strlen(DBMV_Mark_AM_str) + strlen(recoverIdType2);
	char* deleteOpt = malloc(len + 1);
	if(deleteOpt)
	{
		strcpy(deleteOpt, (optimisticLock? "1" : "0"));
		strcat(deleteOpt, DBMV_Mark_AM_str);
		strcat(deleteOpt, recoverIdType2);
	}
	if(recoverIdType != recoverIdType2)
		free(recoverIdType2);
	
	return deleteOpt;
}

/*
	Function: LkCreateRecoverRecordIdTypeNone
		Creates a string that defines the type of recovery options for deleted codes that will be used in <LkCreateDeleteOptions> function as None.
		That mean, the recovery of deleted ID codes will not be used.
	
	Returns:
		A string that defines the type of recovery options for deleted codes that will be used in <LkCreateDeleteOptions> function as None.
		
	See Also:
		<LkCreateDeleteOptions>
		
		<Release Memory>
*/
DllEntry char* LkCreateRecoverRecordIdTypeNone()
{
	// 0 @AM 0
	int lenRecoverIdType = 2 + strlen(DBMV_Mark_AM_str);
	char* recoverIdType = malloc(lenRecoverIdType + 1);
	if(recoverIdType)
	{
		strcpy(recoverIdType, "0");
		strcat(recoverIdType, DBMV_Mark_AM_str);
		strcat(recoverIdType, "0");
	}	
	return recoverIdType;
}

/*
	Function: LkCreateRecoverRecordIdTypeLinkar
		Creates a string that defines the type of recovery options for deleted codes that will be used in LkCreateDeleteOptions as Linkar.
		That mean, it will use the recovery of deleted codes of type Linkar: with prefix and separator.

	Arguments:
		prefix - Add a prefix to the code.
		separator - The separator between the prefix and the code. The list of allowed separators is: ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~
	
	Returns:
		A string that defines the type of recovery options for deleted codes that will be used in LkCreateDeleteOptions as Linkar.
		
	Example:
		--- Code
		char* prefix = "2020";
		char* separator = "_";
		char* recoverRecordIdTypeLinkar = LkCreateRecoverRecordIdTypeLinkar(prefix, separator);
		---
		
	See Also:
		<LkCreateDeleteOptions>
		
		<Release Memory>
*/
DllEntry char* LkCreateRecoverRecordIdTypeLinkar(const char* const prefix, const char* const separator)
{
	// 1 @VM prefix @VM separator @AM 0
	int lenRecoverIdType = 2 + strlen(DBMV_Mark_AM_str) + 2*strlen(DBMV_Mark_VM_str) + strlen(prefix) + strlen(separator);
	char* recoverIdType = malloc(lenRecoverIdType + 1);
	if(recoverIdType)
	{
		strcpy(recoverIdType, "1");
		strcat(recoverIdType, DBMV_Mark_VM_str);
		strcat(recoverIdType, prefix);
		strcat(recoverIdType, DBMV_Mark_VM_str);
		strcat(recoverIdType, separator);
		strcat(recoverIdType, DBMV_Mark_AM_str);
		strcat(recoverIdType, "0");
	}	
	return recoverIdType;
}

/*
	Function: LkCreateRecoverRecordIdTypeCustom
		Creates a string that defines the type of recovery options for deleted codes that will be used in LkCreateDeleteOptions as Custom.
		That mean, the recovery of deleted codes will be performed through the use of custom SUB.LK.MAIN.NEWRECOVERRECORDID.CUSTOM subroutine.
		
	Returns:
		A string that defines the type of recovery options for deleted codes that will be used in LkCreateDeleteOptions as Custom.
		
	See Also:
		<LkCreateDeleteOptions>
		
		<Release Memory>
*/
DllEntry char* LkCreateRecoverRecordIdTypeCustom()
{	
	// 0 @AM 1
	int lenRecoverIdType = 2 + strlen(DBMV_Mark_AM_str);
	char* recoverIdType = malloc(lenRecoverIdType + 1);
	if(recoverIdType)
	{
		strcpy(recoverIdType, "0");
		strcat(recoverIdType, DBMV_Mark_AM_str);
		strcat(recoverIdType, "1");
	}	
	return recoverIdType;
}

/*
	Function: LkCreateSelectOptions
		Creates a string that contains the options for Select functions.

	Arguments:
		onlyRecordId - Returns just the selected records codes.
		pagination - Indicates if pagination is being used or not.
		regPage - In case of pagination indicates the number of records by page. It must be bigger than 0.
		numPage - In case of pagination indicates the page to obtain. It must be bigger than 0.
		calculated - Return the resulting values from the calculated dictionaries.
		conversion - Execute the defined conversions in the dictionaries before returning.
		formatSpec - Execute the defined formats in the dictionaries before returning.
		originalRecords - Return a copy of the records in MV format.
		dictionaries - Return the File dictionaries.
	
	Returns:
		A string that contains the options for <Select> and <SelectD> functions.
	
	Example:
		--- Code
		BOOL onlyRecordId = FALSE;
		BOOL pagination = TRUE;
		uint32_t regPag = 10;
		uint32_t numPag = 1;
		BOOL calculated = TRUE;
		BOOL conversion = FALSE;
		BOOL formatSpec = FALSE;
		BOOL originalRecords = FALSE;
		char* selectOptions = LkCreateSelectOptions(onlyRecordId, pagination, regPag, numPag, calculated, conversion, formatSpec, originalRecords);
		---
		
	See Also:		
		<Release Memory>
*/
DllEntry char* LkCreateSelectOptions(BOOL onlyRecordId, BOOL pagination, uint32_t regPage, uint32_t numPage, 
                                     BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords)
{
	char* selectOpt = NULL;
	
	char paginationOpt[100];
	strcpy(paginationOpt, (pagination? "1" : "0"));
	if(pagination)
	{
		strcat(paginationOpt, DBMV_Mark_VM_str);

		char aux[20];
		sprintf(aux, "%d", regPage);
		strcat(paginationOpt, aux);
		
		strcat(paginationOpt, DBMV_Mark_VM_str);
		sprintf(aux, "%d", numPage);
		strcat(paginationOpt, aux);
	}
	strcat(paginationOpt, DBMV_Mark_AM_str);
	strcat(paginationOpt, (onlyRecordId? "1" : "0"));
	
	char* commonOpt = LkCreateCommonOptions(calculated, conversion, formatSpec, originalRecords);
	if(commonOpt)
	{
		int len = strlen(paginationOpt) + strlen(DBMV_Mark_AM_str) + strlen(commonOpt);
		selectOpt = malloc(len + 1);
		if(selectOpt)
		{
			strcpy(selectOpt, paginationOpt);
			strcat(selectOpt, DBMV_Mark_AM_str);
			strcat(selectOpt, commonOpt);
		}
	}
	
	return selectOpt;
}


//SCHEMAS

static const char* const GetStrSchemaType(SchemaTYPE schemaType)
{
	if(schemaType == SchemaTYPE_DICTIONARIES)
		return "2";
	else if(schemaType == SchemaTYPE_NONE)
		return "3";
	else
		return "1";
}

static const char* const GetStrRowHeadersType(RowHeadersTYPE rowHeadersType)
{
	if(rowHeadersType == RowHeadersTYPE_SHORTLABEL)
		return "2";
	else if(rowHeadersType == RowHeadersTYPE_NONE)
		return "3";
	else
		return "1";
}

static char* LkCreateLkSchemasOptions(SchemaTYPE schemaType, RowHeadersTYPE rowHeaders, BOOL sqlMode, BOOL rowProperties, BOOL onlyVisibles, BOOL pagination, uint32_t regPage, uint32_t numPage)
{		
	char paginationOpt[100];
	strcpy(paginationOpt, (pagination? "1" : "0"));
	if(pagination)
	{
		strcat(paginationOpt, DBMV_Mark_VM_str);

		char aux[20];
		sprintf(aux, "%d", regPage);
		strcat(paginationOpt, aux);
		
		strcat(paginationOpt, DBMV_Mark_VM_str);
		sprintf(aux, "%d", numPage);
		strcat(paginationOpt, aux);
	}
	
	int len = 5 + 5 * strlen(DBMV_Mark_AM_str) + strlen(paginationOpt);
	
	char* lkSchemasOpt = malloc(len + 1);
	if(lkSchemasOpt)
	{	
		strcpy(lkSchemasOpt, GetStrSchemaType(schemaType));
		strcat(lkSchemasOpt, DBMV_Mark_AM_str);
		strcat(lkSchemasOpt, (sqlMode? "1" : "0"));
		strcat(lkSchemasOpt, DBMV_Mark_AM_str);
		strcat(lkSchemasOpt, (rowProperties? "1" : "0"));
		strcat(lkSchemasOpt, DBMV_Mark_AM_str);
		strcat(lkSchemasOpt, (onlyVisibles? "1" : "0"));
		strcat(lkSchemasOpt, DBMV_Mark_AM_str);
		strcat(lkSchemasOpt, GetStrRowHeadersType(rowHeaders));
		strcat(lkSchemasOpt, DBMV_Mark_AM_str);		
		strcat(lkSchemasOpt, paginationOpt);
	}
		
	return lkSchemasOpt;
}

/*
	Function: LkCreateSchOptionsTypeLKSCHEMAS
		Creates a string that contains the LkSchemas options for LkSchemas functions (*LKSCHEMAS Schema Type*)
		
	Arguments:
		rowHeaders - Include headings in first row *MAINLABEL* (main headings), *SHORTLABEL* (short label headings),  y *NONE* (without headings)
		rowProperties - First row includes Property Names.
		onlyVisibles - Use only visible Schemas and Properties.
		pagination - Indicates if pagination is being used or not.
		regPage - In case of pagination indicates the number of records by page. It must be bigger than 0.
		numPage - In case of pagination indicates the page to obtain. It must be bigger than 0.
	
	Returns:
		A string that contains the LkSchemas options for LkSchemas functions.
	
	Example:
		--- Code
		RowHeadersTYPE rowHeaders = RowHeadersTYPE_MAINLABEL;
		BOOL rowProperties = TRUE;
		BOOL onlyVisibles = TRUE;
		BOOL pagination = TRUE;
		uint32_t regPage = 10;
		uint32_t numPage = 1;
		char* schOptTypeLKSCHEMAS = LkCreateSchOptionsTypeLKSCHEMAS(rowHeaders, rowProperties, onlyVisibles, pagination, regPage, numPage);
		---
		
	See Also:		
		<Release Memory>
*/
DllEntry char* LkCreateSchOptionsTypeLKSCHEMAS(RowHeadersTYPE rowHeaders, BOOL rowProperties, BOOL onlyVisibles, BOOL pagination, uint32_t regPage, uint32_t numPage)
{
	return LkCreateLkSchemasOptions(SchemaTYPE_LKSCHEMAS, rowHeaders, FALSE, rowProperties, onlyVisibles, pagination, regPage, numPage);
}

/*
	Function: LkCreateSchOptionsTypeSQLMODE
		Creates a string that contains the LkSchemas options for LkSchemas functions (*SQLMODE Schema Type*)

	Arguments:
		onlyVisibles - Use only visible Schemas and Properties.
		pagination - Indicates if pagination is being used or not.
		regPage - In case of pagination indicates the number of records by page. It must be bigger than 0.
		numPage - In case of pagination indicates the page to obtain. It must be bigger than 0.
	
	Returns:
		A string that contains the LkSchemas options for LkSchemas functions.
	
	Example:
		--- Code
		BOOL onlyVisibles = TRUE;
		BOOL pagination = TRUE;
		uint32_t regPage = 10;
		uint32_t numPage = 1;
		char* schOptTypeSQLMODE(onlyVisibles, pagination, regPage, numPage);
		---
		
	See Also:		
		<Release Memory>
*/
DllEntry char* LkCreateSchOptionsTypeSQLMODE(BOOL onlyVisibles, BOOL pagination, uint32_t regPage, uint32_t numPage)
{
	return LkCreateLkSchemasOptions(SchemaTYPE_LKSCHEMAS, RowHeadersTYPE_NONE, TRUE, TRUE, onlyVisibles, pagination, regPage, numPage);
}

/*
	Function: LkCreateSchOptionsTypeDICTIONARIES
		Creates a string that contains the LkSchemas options for LkSchemas functions (*DICIONARIES Schema Type*)

	Arguments:
		rowHeaders - Include headings in first row *MAINLABEL* (main headings), *SHORTLABEL* (short label headings),  y *NONE* (without headings)
		pagination - Indicates if pagination is being used or not.
		regPage - In case of pagination indicates the number of records by page. It must be bigger than 0.
		numPage - In case of pagination indicates the page to obtain. It must be bigger than 0.
	
	Returns:
		A string that contains the LkSchemas options for LkSchemas functions.
	
	Example:
		--- Code:
		RowHeadersTYPE rowHeaders = RowHeadersTYPE_MAINLABEL;
		BOOL pagination = TRUE;
		uint32_t regPage = 10;
		uint32_t numPage = 1;
		char* schOptTypeDICTIONARIES = LkCreateSchOptionsTypeDICTIONARIES(rowHeaders, pagination, regPage, numPage);
		---
		
	See Also:
		<Release Memory>
*/
DllEntry char* LkCreateSchOptionsTypeDICTIONARIES(RowHeadersTYPE rowHeaders, BOOL pagination, uint32_t regPage, uint32_t numPage)
{
	return LkCreateLkSchemasOptions(SchemaTYPE_DICTIONARIES, rowHeaders, FALSE, TRUE, TRUE, pagination, regPage, numPage);
}

static char* LkCreateLkPropertiesOptions(SchemaTYPE schemaType, RowHeadersTYPE rowHeaders, BOOL sqlMode, BOOL rowProperties, BOOL onlyVisibles, BOOL usePropertyNames, BOOL pagination, uint32_t regPage, uint32_t numPage)
{
	char paginationOpt[100];
	strcpy(paginationOpt, (pagination? "1" : "0"));
	if(pagination)
	{
		strcat(paginationOpt, DBMV_Mark_VM_str);

		char aux[20];
		sprintf(aux, "%d", regPage);
		strcat(paginationOpt, aux);
		
		strcat(paginationOpt, DBMV_Mark_VM_str);
		sprintf(aux, "%d", numPage);
		strcat(paginationOpt, aux);
	}
	
	int len = 6 + 6 * strlen(DBMV_Mark_AM_str) + strlen(paginationOpt);
	char* lkPropertiesOpt = malloc(len + 1);
	if(lkPropertiesOpt)
	{	
		strcpy(lkPropertiesOpt, GetStrSchemaType(schemaType));
		strcat(lkPropertiesOpt, DBMV_Mark_AM_str);
		strcat(lkPropertiesOpt, (sqlMode? "1" : "0"));
		strcat(lkPropertiesOpt, DBMV_Mark_AM_str);
		strcat(lkPropertiesOpt, (usePropertyNames? "1" : "0"));
		strcat(lkPropertiesOpt, DBMV_Mark_AM_str);
		strcat(lkPropertiesOpt, (rowProperties? "1" : "0"));
		strcat(lkPropertiesOpt, DBMV_Mark_AM_str);
		strcat(lkPropertiesOpt, (onlyVisibles? "1" : "0"));
		strcat(lkPropertiesOpt, DBMV_Mark_AM_str);
		strcat(lkPropertiesOpt, GetStrRowHeadersType(rowHeaders));
		strcat(lkPropertiesOpt, DBMV_Mark_AM_str);
		strcat(lkPropertiesOpt, paginationOpt);
	}
	
	return lkPropertiesOpt;
}

/*
	Function: LkCreatePropOptionsTypeLKSCHEMAS
		Creates a string that contains the LkProperties options for LkProperties functions (*LKSCHEMAS Schema Type*)

	Arguments:
		rowHeaders - Include headings in first row *MAINLABEL* (main headings), *SHORTLABEL* (short label headings),  y *NONE* (without headings)
		rowProperties - First row includes Property Names.
		onlyVisibles - Use only visible Schemas and Properties.
		usePropertyNames - Use properties and table names defined in Schemas.
		pagination - Indicates if pagination is being used or not.
		regPage - In case of pagination indicates the number of records by page. It must be bigger than 0.
		numPage - In case of pagination indicates the page to obtain. It must be bigger than 0.
	
	Returns:
		A string that contains the LkProperties options for LkProperties functions.
	
	Example:
		--- Code
		RowHeadersTYPE rowHeaders = RowHeadersTYPE_MAINLABEL;
		BOOL rowProperties = TRUE;
		BOOL onlyVisibles = TRUE;
		BOOL usePropertyNames = TRUE;
		BOOL pagination = TRUE;
		uint32_t regPage = 10;
		uint32_t numPage = 1;		
		char* propOptTypeLKSCHEMAS = LkCreatePropOptionsTypeLKSCHEMAS(rowHeaders, rowProperties, onlyVisibles, usePropertyNames, pagination, regPage, numPage);
		---
		
	See Also:		
		<Release Memory>
*/
DllEntry char* LkCreatePropOptionsTypeLKSCHEMAS(RowHeadersTYPE rowHeaders, BOOL rowProperties, BOOL onlyVisibles, BOOL usePropertyNames, BOOL pagination, uint32_t regPage, uint32_t numPage)
{
	return LkCreateLkPropertiesOptions(SchemaTYPE_LKSCHEMAS, rowHeaders, FALSE, rowProperties, onlyVisibles, usePropertyNames, pagination, regPage, numPage);
}

/*
	Function: LkCreatePropOptionsTypeSQLMODE
		Creates a string that contains the LkProperties options for LkProperties functions (*SQLMODE Schema Type*)
		
	Arguments:
		onlyVisibles - Use only visible Schemas and Properties.
		pagination - Indicates if pagination is being used or not.
		regPage - In case of pagination indicates the number of records by page. It must be bigger than 0.
		numPage - In case of pagination indicates the page to obtain. It must be bigger than 0.
	
	Returns:
		A string that contains the LkProperties options for LkProperties functions.
	
	Example:
		--- Code
		BOOL onlyVisibles = TRUE;
		BOOL pagination = TRUE;
		uint32_t regPage = 10;
		uint32_t numPage = 1;
		char* propOptTypeSQLMODE = LkCreatePropOptionsTypeSQLMODE(onlyVisibles, pagination, regPage, numPage);
		---
		
	See Also:
		<Release Memory>
*/
DllEntry char* LkCreatePropOptionsTypeSQLMODE(BOOL onlyVisibles, BOOL pagination, uint32_t regPage, uint32_t numPage)
{
	return LkCreateLkPropertiesOptions(SchemaTYPE_LKSCHEMAS, RowHeadersTYPE_NONE, TRUE, TRUE, onlyVisibles, TRUE, pagination, regPage, numPage);
}

/*
	Function: LkCreatePropOptionsTypeDICTIONARIES
		Creates a string that contains the LkProperties options for LkProperties functions (*DICTIONARIES Schema Type*)
		
	Arguments:
		rowHeaders - Include headings in first row *MAINLABEL* (main headings), *SHORTLABEL* (short label headings),  y *NONE* (without headings)
		pagination - Indicates if pagination is being used or not.
		regPage - In case of pagination indicates the number of records by page. It must be bigger than 0.
		numPage - In case of pagination indicates the page to obtain. It must be bigger than 0.
	
	Returns:
		A string that contains the LkProperties options for LkProperties functions.
	
	Example:
		--- Code
		RowHeadersTYPE rowHeaders = RowHeadersTYPE_MAINLABEL;
		BOOL pagination = TRUE;
		uint32_t regPage = 10;
		uint32_t numPage = 1;		
		char* propOptTypeDICTIONARIES = LkCreatePropOptionsTypeDICTIONARIES(rowHeaders, pagination, regPage, numPage);
		---
		
	See Also:			
		<Release Memory>
*/
DllEntry char* LkCreatePropOptionsTypeDICTIONARIES(RowHeadersTYPE rowHeaders, BOOL pagination, uint32_t regPage, uint32_t numPage)
{
	return LkCreateLkPropertiesOptions(SchemaTYPE_DICTIONARIES, rowHeaders, FALSE, FALSE, FALSE, FALSE, pagination, regPage, numPage);
}

static char* LkCreateLkGetTableOptions(SchemaTYPE schemaType, RowHeadersTYPE rowHeaders, BOOL sqlMode, BOOL rowProperties, BOOL onlyVisibles, BOOL usePropertyNames, BOOL repeatValues, BOOL applyConversion, BOOL applyFormat, BOOL calculated, BOOL pagination, uint32_t regPage, uint32_t numPage)
{
	char paginationOpt[100];
	strcpy(paginationOpt, (pagination? "1" : "0"));
	if(pagination)
	{
		strcat(paginationOpt, DBMV_Mark_VM_str);

		char aux[20];
		sprintf(aux, "%d", regPage);
		strcat(paginationOpt, aux);
		
		strcat(paginationOpt, DBMV_Mark_VM_str);
		sprintf(aux, "%d", numPage);
		strcat(paginationOpt, aux);
	}
	
	int len = 10 + 10 * strlen(DBMV_Mark_AM_str) + strlen(paginationOpt);
	char* lkGetTableOpt = malloc(len + 1);
	if(lkGetTableOpt)
	{	
		strcpy(lkGetTableOpt, GetStrSchemaType(schemaType));
		strcat(lkGetTableOpt, DBMV_Mark_AM_str);
		strcat(lkGetTableOpt, (sqlMode? "1" : "0"));
		strcat(lkGetTableOpt, DBMV_Mark_AM_str);
		strcat(lkGetTableOpt, (usePropertyNames? "1" : "0"));
		strcat(lkGetTableOpt, DBMV_Mark_AM_str);
		strcat(lkGetTableOpt, (rowProperties? "1" : "0"));
		strcat(lkGetTableOpt, DBMV_Mark_AM_str);
		strcat(lkGetTableOpt, (onlyVisibles? "1" : "0"));
		strcat(lkGetTableOpt, DBMV_Mark_AM_str);
		strcat(lkGetTableOpt, GetStrRowHeadersType(rowHeaders));
		strcat(lkGetTableOpt, DBMV_Mark_AM_str);
		strcat(lkGetTableOpt, (repeatValues? "1" : "0"));
		strcat(lkGetTableOpt, DBMV_Mark_AM_str);
		strcat(lkGetTableOpt, (applyConversion? "1" : "0"));
		strcat(lkGetTableOpt, DBMV_Mark_AM_str);
		strcat(lkGetTableOpt, (applyFormat? "1" : "0"));
		strcat(lkGetTableOpt, DBMV_Mark_AM_str);
		strcat(lkGetTableOpt, (calculated? "1" : "0"));
		strcat(lkGetTableOpt, DBMV_Mark_AM_str);
		strcat(lkGetTableOpt, paginationOpt);
	}
	
	return lkGetTableOpt;
}

/*
	Function: LkCreateTableOptionsTypeLKSCHEMAS
		Creates a string that contains the options for LkGetTable functions (*LKSCHEMAS Schema Type*)
		
	Arguments:
		rowHeaders - Include headings in first row *MAINLABEL* (main headings), *SHORTLABEL* (short label headings),  y *NONE* (without headings)
		rowProperties - First row includes property Names.
		onlyVisibles - Use only visible Schemas and Properties.
		usePropertyNames - Use properties and table names defined in Schemas.
		repeatValues - Repeat common atributes in MV and SV groups.
		applyConversion - Execute conversions defined in Linkar Schemas.
		applyFormat - Execute formats defined in Linkar Schemas.
		calculated - Return the resulting values from the calculated dictionaries.
		pagination - Indicates if pagination is being used or not.
		regPage - In case of pagination indicates the number of records by page. It must be bigger than 0.
		numPage - In case of pagination indicates the page to obtain. It must be bigger than 0.
	
	Returns:
		A string that contains the options for LkGetTable functions.
		
	Example:
		--- Code
		RowHeadersTYPE rowHeaders = RowHeadersTYPE_MAINLABEL;
		BOOL rowProperties = TRUE;
		BOOL onlyVisibles = TRUE;
		BOOL usePropertyNames = TRUE;
		BOOL repeatValues = TRUE;
		BOOL applyConversion = TRUE;
		BOOL applyFormat = TRUE;
		BOOL calculated = TRUE;
		BOOL pagination = TRUE;
		uint32_t regPage = 10;
		uint32_t numPage = 1;		
		char* tableOptTypeLKSCHEMAS = LkCreateTableOptionsTypeLKSCHEMAS(rowHeaders, rowProperties, onlyVisibles, usePropertyNames, 
										  repeatValues, applyConversion, applyFormat, calculated, pagination, regPage, numPage);
		---
		
	See Also:		
		<Release Memory>
*/
DllEntry char* LkCreateTableOptionsTypeLKSCHEMAS(RowHeadersTYPE rowHeaders, BOOL rowProperties, BOOL onlyVisibles, BOOL usePropertyNames, 
 BOOL repeatValues, BOOL applyConversion, BOOL applyFormat, BOOL calculated, 
 BOOL pagination, uint32_t regPage, uint32_t numPage)
 {
	 return LkCreateLkGetTableOptions(SchemaTYPE_LKSCHEMAS, rowHeaders, FALSE, rowProperties, onlyVisibles, usePropertyNames, repeatValues, applyConversion, applyFormat, calculated, pagination, regPage, numPage);
 }
									 
/*
	Function: LkCreateTableOptionsTypeSQLMODE
		Creates a string that contains the options for LkGetTable functions (*SQLMODE Schema Type*)
		
	Arguments:
		onlyVisibles - Use only visible Schemas and Properties.
		applyConversion - Execute conversions defined in Linkar Schemas.
		applyFormat - Execute formats defined in Linkar Schemas.
		calculated - Return the resulting values from the calculated dictionaries.
		pagination - Indicates if pagination is being used or not.
		regPage - In case of pagination indicates the number of records by page. It must be bigger than 0.
		numPage - In case of pagination indicates the page to obtain. It must be bigger than 0.
	
	Returns:
		A string that contains the options for LkGetTable functions.
		
	Example:
		--- Code
		BOOL onlyVisibles = TRUE;
		BOOL applyConversion = TRUE;
		BOOL applyFormat = TRUE;
		BOOL calculated = TRUE;
		BOOL pagination = TRUE;
		uint32_t regPage = 10;
		uint32_t numPage = 1;		
		char* tableOptTypeSQLMODE = LkCreateTableOptionsTypeSQLMODE(onlyVisibles, applyConversion, applyFormat, calculated, pagination, regPage, numPage);
		---

	See Also:		
		<Release Memory>
*/
DllEntry char* LkCreateTableOptionsTypeSQLMODE(BOOL onlyVisibles, 
 BOOL applyConversion, BOOL applyFormat, BOOL calculated, 
 BOOL pagination, uint32_t regPage, uint32_t numPage)
 {
	 return LkCreateLkGetTableOptions(SchemaTYPE_LKSCHEMAS, RowHeadersTYPE_NONE, TRUE, TRUE, onlyVisibles, TRUE, TRUE, applyConversion, applyFormat, calculated, pagination, regPage, numPage);
 }
									 
/*
	Function: LkCreateTableOptionsTypeDICTIONARIES
		Creates a string that contains the options for LkGetTable functions (*DICTIONARIES Schema Type*)
		
	Arguments:
		rowHeaders - Include headings in first row *MAINLABEL* (main headings), *SHORTLABEL* (short label headings),  y *NONE* (without headings)
		repeatValues - Repeat common atributes in MV and SV groups.
		applyConversion - Execute conversions defined in the dictionary.
		applyFormat - Execute formats defined in the dictionary.
		calculated - Return the resulting values from the calculated dictionaries.
		pagination - Indicates if pagination is being used or not.
		regPage - In case of pagination indicates the number of records by page. It must be bigger than 0.
		numPage - In case of pagination indicates the page to obtain. It must be bigger than 0.
	
	Example:
		--- Code
		RowHeadersTYPE rowHeaders = RowHeadersTYPE_MAINLABEL;
		BOOL repeatValues = TRUE;
		BOOL applyConversion = TRUE;
		BOOL applyFormat = TRUE;
		BOOL calculated = TRUE;
		BOOL pagination = TRUE;
		uint32_t regPage = 10;
		uint32_t numPage = 1;		
		char* tableOptTypeDICTIONARIES = LkCreateTableOptionsTypeDICTIONARIES(rowHeaders, repeatValues, applyConversion, applyFormat, calculated, pagination, regPage, numPage);
		---
		
	Returns:
		A string that contains the options for LkGetTable functions.
		
	See Also:
		<Release Memory>
*/
DllEntry char* LkCreateTableOptionsTypeDICTIONARIES(RowHeadersTYPE rowHeaders, 
 BOOL repeatValues, BOOL applyConversion, BOOL applyFormat, BOOL calculated, 
 BOOL pagination, uint32_t regPage, uint32_t numPage)
 {
	 return LkCreateLkGetTableOptions(SchemaTYPE_DICTIONARIES, rowHeaders, FALSE, FALSE, FALSE, FALSE, repeatValues, applyConversion, applyFormat, calculated, pagination, regPage, numPage);
 }
									 
/*
	Function: LkCreateTableOptionsTypeNONE
		Creates a string that contains the options for LkGetTable functions (*NONE Schema Type*)
		
	Arguments:
		rowHeaders - Include headings in first row *MAINLABEL* (main headings), *SHORTLABEL* (short label headings),  y *NONE* (without headings)
		repeatValues - Repeat common atributes in MV and SV groups.
		pagination - Indicates if pagination is being used or not.
		regPage - In case of pagination indicates the number of records by page. It must be bigger than 0.
		numPage - In case of pagination indicates the page to obtain. It must be bigger than 0.
	
	Returns:
		A string that contains the options for LkGetTable functions.
		
	Example:
		--- Code
		BOOL onlyVisibles = TRUE;
		BOOL repeatValues = TRUE;
		BOOL pagination = TRUE;
		uint32_t regPage = 10;
		uint32_t numPage = 1;		
		char* tableOptTypeNONE = LkCreateTableOptionsTypeNONE(onlyVisibles, repeatValues, pagination, regPage, numPage);
		---

	See Also:
		<Release Memory>
*/
DllEntry char* LkCreateTableOptionsTypeNONE(RowHeadersTYPE rowHeaders, 
 BOOL repeatValues,  
 BOOL pagination, uint32_t regPage, uint32_t numPage)
 {
	 return LkCreateLkGetTableOptions(SchemaTYPE_NONE, rowHeaders, FALSE, FALSE, FALSE, FALSE, repeatValues, FALSE, FALSE, FALSE, pagination, regPage, numPage);
 }

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "Types.h"
#include "LinkarStringsHelper.h"
#include "LinkarStrings.h"
#include "CredentialOptions.h"
#include "FunctionsDirectMV.h"
#include "MvOperations.h"
#include "OperationOptions.h"

void main(void)
{	
	char* credentialOptions = LkCreateCredentialOptions("192.168.100.101", "QMEP1", 11301, "ADMIN", "admin", "", "Test C Library");	

	// Operation LkNew MV example
	printf("\n***Operation New MV example. LK.CUTOMERS Create Id TEST98 and TEST99\n");
	char* filename = "LK.CUSTOMERS";
	char** lstRecordIds = malloc(sizeof(char*) * 2);
	lstRecordIds[0] = "TEST98";
	lstRecordIds[1] = "TEST99";
	
	//const char* const lstRecordIds[2] = { "TEST98", "TEST99" };
	
	char record1 [100];
	strcpy(record1, "CUSTOMER_TEST98"); // CUSTOMER NAME
	strcat(record1, DBMV_Mark_AM_str);
	strcat(record1, "ADDRESS TEST98"); // CUSTOMER ADDRESS
	strcat(record1, DBMV_Mark_AM_str);
	strcat(record1, "98989898"); // CUSTOMER PHONE
	
	char record2 [100];
	strcpy(record2, "CUSTOMER_TEST99"); // CUSTOMER NAME
	strcat(record2, DBMV_Mark_AM_str);
	strcat(record2, "ADDRESS TEST99"); // CUSTOMER ADDRESS
	strcat(record2, DBMV_Mark_AM_str);
	strcat(record2, "99999999"); // CUSTOMER PHONE
	
	char** lstRecords = malloc(sizeof(char*) * 2);
	lstRecords[0] = record1;
	lstRecords[1] = record2;
	printf("lstRecords[0] = %s\n", lstRecords[0]);
	printf("lstRecords[1] = %s\n", lstRecords[1]);
		
	char* recordIds = LkComposeRecordIds((const char** const)lstRecordIds, 2);
	
	
	printf("recordIds: %s\n", recordIds);
	
	
	
	LkFreeMemoryStringArray(lstRecordIds, 2);
	
	printf("*************************\n");
	
	printf("recordIds: %s\n", recordIds);
	
	char* records = LkComposeRecords((const char** const)lstRecords, 2);
	LkFreeMemory(lstRecords);
	printf("records: %s\n", records);
	
	char* newRecords = LkComposeNewBuffer(recordIds, records);
	LkFreeMemory(records);
	printf("newRecords: %s\n", newRecords);
	
	char* newOptions = NULL;
	char* error;
	char* customVars = "";
	int32_t receiveTimeout = 10;	
	char* result = LkNew(&error, credentialOptions, filename, newRecords, newOptions, customVars, receiveTimeout);
	LkFreeMemory(newRecords);
	if(error != NULL)
	{
		printf("ERRORS: %s\n", error);
		LkFreeMemory(error);
	}
	printf("result (MV): %s\n", result);
	LkFreeMemory(result);


	// Operation LkRead MV example
	printf("\n***Operation LkRead MV example.\n");
	char* dictionaries = "";
	char* readOptions = NULL;
	result = LkRead(&error, credentialOptions, filename, recordIds, dictionaries, readOptions, customVars, receiveTimeout);
	if(error != NULL)
	{
		printf("ERRORS: %s\n", error);
		LkFreeMemory(error);
	}
	printf("result (MV): %s\n", result);

	uint32_t count;
	lstRecords = LkExtractRecords(result, &count);
	LkFreeMemory(result);
	int i;
    for(i=0; i<count; i++)
		printf("Record %i: %s\n", (i+1), lstRecords[i]);
		
	// Operation LkUpdate MV example (with ReadAfter option)
	printf("\n***Operation LkUpdate MV example (with ReadAfter option).\n");
	char* pRec = lstRecords[0];
	lstRecords[0] = LkReplace(lstRecords[0], "CUSTOMER_TEST98_UPDATE", 1, 0, 0);
	LkFreeMemory(pRec);
	pRec = lstRecords[1];
	lstRecords[1] = LkReplace(lstRecords[1], "CUSTOMER_TEST99_UPDATE", 1, 0, 0);
	LkFreeMemory(pRec);
	
	for(i=0; i<count; i++)
		printf("Record %i: %s\n", (i+1), lstRecords[i]);

	BOOL opOptimisticLock = FALSE;
	BOOL opReadAfter = TRUE;
	BOOL opCalculated = FALSE;
	BOOL opConversion = FALSE;
	BOOL opFormatSpec = FALSE;
	BOOL opOriginalRecords = TRUE;
	char* updateOptions = LkCreateUpdateOptions(opOptimisticLock, opReadAfter, opCalculated, opConversion, opFormatSpec, opOriginalRecords);
	records = LkComposeRecords((const char** const)lstRecords, 2);

	LkFreeMemoryStringArray(lstRecords, count);
	
	char* updateRecords = LkComposeUpdateBuffer(recordIds, records, NULL);
	LkFreeMemory(records);
	
	result = LkUpdate(&error, credentialOptions, filename, updateRecords, updateOptions, customVars, receiveTimeout);
	LkFreeMemory(updateRecords);
	LkFreeMemory(updateOptions);
	if(error != NULL)
	{
		printf("ERRORS: %s\n", error);
		LkFreeMemory(error);
	}
	printf("result (MV): %s\n", result);
	
	lstRecords = LkExtractRecords(result, &count);
    for(i=0; i<count; i++)
		printf("Record %i: %s\n", (i+1), lstRecords[i]);
	LkFreeMemoryStringArray(lstRecords, count);


	// Operation LkDelete MV example (with OptimisticLock option )
	printf("\n***Operation LkDelete MV example (with OptimisticLock option ).\n");
	
	opOptimisticLock = TRUE;
	char* recoverIdType = NULL;
	char* deleteOptions = LkCreateDeleteOptions(opOptimisticLock, recoverIdType);
	char** lstOriginalRecords = LkExtractOriginalRecords(result, &count);	
	
	LkFreeMemory(result);
	char* originalRecords = LkComposeRecords((const char** const)lstOriginalRecords, count);	
	char* deleteRecords = LkComposeDeleteBuffer(recordIds, originalRecords);
	LkFreeMemory(recordIds);
	LkFreeMemory(originalRecords);
	result = LkDelete(&error, credentialOptions, filename, deleteRecords, deleteOptions, customVars, receiveTimeout);
	LkFreeMemory(deleteRecords);
	LkFreeMemory(deleteOptions);
	if(error != NULL)
	{
		printf("ERRORS: %s\n", error);
		LkFreeMemory(error);
	}
	printf("result (MV): %s\n", result);
	
	lstRecordIds = LkExtractRecordIds(result, &count);	
	LkFreeMemory(result);
	printf("Deleted Record Ids:\n");
	for(i=0; i<count; i++)
		printf("%s\n", lstRecordIds[i]);
	LkFreeMemoryStringArray(lstRecordIds, count);
	
	// Operation LkSelect MV example
	printf("\n***Operation LkSelect MV example.\n");
	char* selectClause = "";
	char* sortClause = "BY CODE";
	char* dictClause = "";
	char* preSelectClause = "";
	char* selectOptions = NULL;	
	
	result = LkSelect(&error, credentialOptions, filename, selectClause, sortClause, dictClause, preSelectClause, selectOptions, customVars, receiveTimeout);
	if(error != NULL)
	{
		printf("ERRORS: %s\n", error);
		LkFreeMemory(error);
	}
	lstRecords = LkExtractRecords(result, &count);
	lstRecordIds = LkExtractRecordIds(result, &count);
	for(i=0; i< count; i++)
		printf("%s: %s\n", lstRecordIds[i], lstRecords[i]);
	LkFreeMemory(result);		
	LkFreeMemoryStringArray(lstRecords, count);
	LkFreeMemoryStringArray(lstRecordIds, count);
		
	
	// Operation LkSubroutine MV example
	printf("\n***Operation LkSubroutine MV example.\n");
	
	char* subroutineName = "SUB.DEMOLINKAR";
	
	uint32_t argsNumber = 3;
	char** lstArgs = malloc(sizeof(char*) * argsNumber);
	lstArgs[0] = "0";
	lstArgs[1] = "aaaaaa";
	lstArgs[2] = "";
	
	char* arguments = LkComposeSubroutineArgs((const char** const)lstArgs, argsNumber);
	LkFreeMemory(lstArgs);
	result = LkSubroutine(&error, credentialOptions, subroutineName, argsNumber, arguments, customVars, receiveTimeout);
	LkFreeMemory(arguments);
	if(error != NULL)
	{
		printf("ERRORS: %s\n", error);
		LkFreeMemory(error);
	}
	else
	{
		printf("result (MV): %s\n", result);		
		char* resultArgs = LkExtractSubroutineArgs(result);
		LkFreeMemory(result);
		printf("resultArgs: %s\n", resultArgs);
		
		lstArgs = LkStrSplit(resultArgs, ASCII_DC4, &argsNumber);
		free(resultArgs);
		for(i=0; i<argsNumber; i++)
			printf("resultArg %d: %s\n", i, lstArgs[i]);
		LkFreeMemoryStringArray(lstArgs, argsNumber);
	}
	
	LkFreeMemory(credentialOptions);
}
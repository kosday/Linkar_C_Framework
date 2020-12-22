/*
	File: LinkarStrings.h
	Header file for <LinkarStrings.c>

	Prototype Functions:
	--- Code
	DllEntry uint32_t LkExtractTotalRecords(const char* const lkString);	
	DllEntry char** LkExtractRecordIds(const char* const lkString, uint32_t *count);
	DllEntry char** LkExtractRecords(const char* const lkString, uint32_t *count);
	DllEntry char** LkExtractErrors(const char* const lkString, uint32_t *count);
	DllEntry char** LkExtractRecordsCalculated(const char* const lkString, uint32_t *count);
	DllEntry char** LkExtractRecordsDicts(const char* const lkString, uint32_t *count);
	DllEntry char** LkExtractRecordsCalculatedDicts(const char* const lkString, uint32_t *count);
	DllEntry char** LkExtractRecordsIdDicts(const char* const lkString, uint32_t* count);
	DllEntry char** LkExtractOriginalRecords(const char* const lkString, uint32_t* count);
	DllEntry char** LkExtractDictionaryIds(const char* const lkString, uint32_t* count);
	DllEntry char** LkExtractDictionaries(const char* const lkString, uint32_t* count);
	DllEntry char* LkExtractConversion(const char* const lkString);
	DllEntry char* LkExtractFormat(const char* const lkString);
	DllEntry char* LkExtractCapturing(const char* const lkString);
	DllEntry char* LkExtractReturning(const char* const lkString);
	DllEntry char* LkExtractSubroutineArgs(const char* const lkString);
	DllEntry char** LkExtractRowProperties(const char* const lkString, uint32_t *count);
	DllEntry char** LkExtractRowHeaders(const char* const lkString, uint32_t *count);
	
	DllEntry char* LkComposeRecordIds(const char** const lstRecordIds, uint32_t count);
	DllEntry char* LkComposeRecords(const char** const lstRecords, uint32_t count);
	DllEntry char* LkComposeDictionaries(const char** const lstDictionries, uint32_t count);
	DllEntry char* LkComposeExpressions(const char** const lstExpressions, uint32_t count);
	DllEntry char* LkComposeSubroutineArgs(const char** const lstArgs, uint32_t count);
	DllEntry char* LkComposeUpdateBuffer(const char* const recordIds, const char* const records, const char* const originalRecords);
	DllEntry char* LkComposeNewBuffer(const char* const recordIds, const char* const records);
	DllEntry char* LkComposeDeleteBuffer(const char* const recordIds, const char* const originalRecords);
	---
*/
#include "CompilerOptions.h"
#include "Types.h"

/*
	Constants: LkStrings MV
		For use with the <LkString> results of Operation with MV output format.
	
	--- Code
	#define TOTAL_RECORDS_KEY "TOTAL_RECORDS"
	#define RECORD_IDS_KEY "RECORD_ID"
	#define RECORDS_KEY "RECORD"
	#define CALCULATED_KEY "CALCULATED"
	#define RECORD_DICTS_KEY "RECORD_DICTS"
	#define RECORD_ID_DICTS_KEY "RECORD_ID_DICTS"
	#define CALCULATED_DICTS_KEY "CALCULATED_DICTS"
	#define ARGUMENTS_KEY "ARGUMENTS"
	#define ORIGINAL_RECORDS_KEY "ORIGINALRECORD"
	#define FORMAT_KEY "FORMAT"
	#define CONVERSION_KEY "CONVERSION"
	#define CAPTURING_KEY "CAPTURING"
	#define RETURNING_KEY "RETURNING"
	#define ROWHEADERS_KEY "ROWHEADERS"
	#define ROWPROPERTIES_KEY "ROWPROPERTIES"
	#define ERRORS_KEY "ERRORS"
	---
*/
#define TOTAL_RECORDS_KEY "TOTAL_RECORDS"
#define RECORD_IDS_KEY "RECORD_ID"
#define RECORDS_KEY "RECORD"
#define CALCULATED_KEY "CALCULATED"
#define RECORD_DICTS_KEY "RECORD_DICTS"
#define RECORD_ID_DICTS_KEY "RECORD_ID_DICTS"
#define CALCULATED_DICTS_KEY "CALCULATED_DICTS"
#define ARGUMENTS_KEY "ARGUMENTS"
#define ORIGINAL_RECORDS_KEY "ORIGINALRECORD"
#define FORMAT_KEY "FORMAT"
#define CONVERSION_KEY "CONVERSION"
#define CAPTURING_KEY "CAPTURING"
#define RETURNING_KEY "RETURNING"
#define ROWHEADERS_KEY "ROWHEADERS"
#define ROWPROPERTIES_KEY "ROWPROPERTIES"
#define ERRORS_KEY "ERRORS"

DllEntry uint32_t LkExtractTotalRecords(const char* const lkString);
DllEntry char** LkExtractRecordIds(const char* const lkString, uint32_t *count);
DllEntry char** LkExtractRecords(const char* const lkString, uint32_t *count);
DllEntry char** LkExtractErrors(const char* const lkString, uint32_t *count);
DllEntry char** LkExtractRecordsCalculated(const char* const lkString, uint32_t *count);
DllEntry char** LkExtractRecordsDicts(const char* const lkString, uint32_t *count);
DllEntry char** LkExtractRecordsCalculatedDicts(const char* const lkString, uint32_t *count);
DllEntry char** LkExtractRecordsIdDicts(const char* const lkString, uint32_t* count);
DllEntry char** LkExtractOriginalRecords(const char* const lkString, uint32_t* count);
DllEntry char** LkExtractDictionaries(const char* const lkString, uint32_t* count);
DllEntry char* LkExtractConversion(const char* const lkString);
DllEntry char* LkExtractFormat(const char* const lkString);
DllEntry char* LkExtractCapturing(const char* const lkString);
DllEntry char* LkExtractReturning(const char* const lkString);
DllEntry char** LkExtractSubroutineArgs(const char* const lkString, uint32_t *count);
DllEntry char** LkExtractRowProperties(const char* const lkString, uint32_t *count);
DllEntry char** LkExtractRowHeaders(const char* const lkString, uint32_t *count);

DllEntry char* LkComposeRecordIds(const char** const lstRecordIds, uint32_t count);
DllEntry char* LkComposeRecords(const char** const lstRecords, uint32_t count);
DllEntry char* LkComposeOriginalRecords(const char** const lstOriginalRecords, uint32_t count);
DllEntry char* LkComposeDictionaries(const char** const lstDictionries, uint32_t count);
DllEntry char* LkComposeExpressions(const char** const lstExpressions, uint32_t count);
DllEntry char* LkComposeSubroutineArgs(const char** const lstArgs, uint32_t count);
DllEntry char* LkComposeUpdateBuffer(const char* const recordIds, const char* const records, const char* const originalRecords);
DllEntry char* LkComposeNewBuffer(const char* const recordIds, const char* const records);
DllEntry char* LkComposeDeleteBuffer(const char* const recordIds, const char* const originalRecords);

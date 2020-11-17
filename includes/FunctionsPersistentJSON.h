/*
	File: PersistentFunctionsJSON.h
	Header file for PersistentFunctionsJSON.c

	Prototype Functions:
	--- Code
	DllEntry char* LkLogin(char** error, char* credentialOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry void LkLogout(char** error, char* connectionInfo, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkRead(char** error, char* connectionInfo, const char* const filename, const char* const recordIds, const char* const dictionaries, const char* const readOptions, JSON_FORMAT jsonFormat, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkUpdate(char** error,  char** connectionInfo, const char* const filename, const char* const records, const char* const updateOptions, JSON_FORMAT jsonFormat, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkNew(char** error, char* connectionInfo, const char* const filename, const char* const records, const char* const newOptions, JSON_FORMAT jsonFormat, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkDelete(char** error, char* connectionInfo, const char* const filename, const char* const records, const char* const deleteOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkSelect(char** error, char* connectionInfo, const char* const filename, const char* const selectClause, const char* const sortClause, const char* const dictClause, const char* const preSelectClause, const char* const selectOptions, JSON_FORMAT jsonFormat, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkSubroutine(char** error, char* connectionInfo, const char* const subroutineName, uint32_t argsNumber, const char* const arguments, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkConversion(char** error, char* connectionInfo, const char* const expression, const char* const code, CONVERSION_TYPE conversionType, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkFormat(char** error, char* connectionInfo, const char* const expression, const char* const formatSpec, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkDictionaries(char** error, char* connectionInfo, const char* const filename, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkExecute(char** error, char* connectionInfo, const char* const statement, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkGetVersion(char** error, char* connectionInfo, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkSchemas(char** error, char* connectionInfo, const char* const lkSchemasOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkProperties(char** error, char* connectionInfo, const char* const filename, const char* const lkSchemasOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkResetCommonBlocks(char** error, char* connectionInfo, uint32_t receiveTimeout);
	---
*/
#include "CompilerOptions.h"
#include "Types.h"

/*
	typedef: JSON_FORMAT
	JSON output formats for Read, Update, New and Select
	There are 3 possible options: JSON, JSON_DICT, and JSON_SCG.
	
		--- Code
		typedef uint8_t JSON_FORMAT;	
		---
		
	Defined constants of JSON_FORMAT::
		Used to define the options JSON, JSON_DICT and JSON_SCG.
	
		--- Code
		#define JSON_FORMAT_JSON 3
		#define JSON_FORMAT_JSON_DICT 7
		#define JSON_FORMAT_JSON_SCH 8
		---	
*/	
typedef uint8_t JSON_FORMAT;
#define JSON_FORMAT_JSON 3
#define JSON_FORMAT_JSON_DICT 7
#define JSON_FORMAT_JSON_SCH 8

DllEntry char* LkLogin(char** error, char* credentialOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry void LkLogout(char** error, char* connectionInfo, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkRead(char** error, char* connectionInfo, const char* const filename, const char* const recordIds, const char* const dictionaries, const char* const readOptions, JSON_FORMAT jsonFormat, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkUpdate(char** error, char* connectionInfo, const char* const filename, const char* const records, const char* const updateOptions, JSON_FORMAT jsonFormat, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkNew(char** error, char* connectionInfo, const char* const filename, const char* const records, const char* const newOptions, JSON_FORMAT jsonFormat, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkDelete(char** error, char* connectionInfo, const char* const filename, const char* const records, const char* const deleteOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkSelect(char** error, char* connectionInfo, const char* const filename, const char* const selectClause, const char* const sortClause, const char* const dictClause, const char* const preSelectClause, const char* const selectOptions, JSON_FORMAT jsonFormat, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkSubroutine(char** error, char* connectionInfo, const char* const subroutineName, uint32_t argsNumber, const char* const arguments, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkConversion(char** error, char* connectionInfo, const char* const expression, const char* const code, CONVERSION_TYPE conversionType, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkFormat(char** error, char* connectionInfo, const char* const expression, const char* const formatSpec, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkDictionaries(char** error, char* connectionInfo, const char* const filename, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkExecute(char** error, char* connectionInfo, const char* const statement, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkGetVersion(char** error, char* connectionInfo, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkSchemas(char** error, char* connectionInfo, const char* const lkSchemasOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkProperties(char** error, char* connectionInfo, const char* const filename, const char* const lkSchemasOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkResetCommonBlocks(char** error, char* connectionInfo, uint32_t receiveTimeout);

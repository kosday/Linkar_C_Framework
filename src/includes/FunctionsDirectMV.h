/*
	File: DirectFunctionsMV.h
	Header file for DirectFunctionsMV.c

	Prototype Functions:
	--- Code
	DllEntry char* LkRead(char** error, const char* const credentialOptions, const char* const filename, const char* const recordIds, const char* const dictionaries, const char* const readOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkUpdate(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const updateOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkNew(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const newOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkDelete(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const deleteOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkSelect(char** error, const char* const credentialOptions, const char* const filename, const char* const selectClause, const char* const sortClause, const char* const dictClause, const char* const preSelectClause, const char* const selectOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkSubroutine(char** error, const char* const credentialOptions, const char* const subroutineName, uint32_t argsNumber, const char* const arguments, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkConversion(char** error, const char* const credentialOptions, const char* const expression, const char* const code, CONVERSION_TYPE conversionOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkFormat(char** error, const char* const credentialOptions, const char* const expression, const char* const formatSpec, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkDictionaries(char** error, const char* const credentialOptions, const char* const filename, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkExecute(char** error, const char* const credentialOptions, const char* const statement, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkGetVersion(char** error, const char* const credentialOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkSchemas(char** error, const char* const credentialOptions, const char* const lkSchemasOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkProperties(char** error, const char* const credentialOptions, const char* const filename, const char* const lkSchemasOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkResetCommonBlocks(char** error, const char* const credentialOptions, uint32_t receiveTimeout);
	---
*/
#include "CompilerOptions.h"
#include "Types.h"

DllEntry char* LkRead(char** error, const char* const credentialOptions, const char* const filename, const char* const recordIds, const char* const dictionaries, const char* const readOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkUpdate(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const updateOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkNew(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const newOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkDelete(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const deleteOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkSelect(char** error, const char* const credentialOptions, const char* const filename, const char* const selectClause, const char* const sortClause, const char* const dictClause, const char* const preSelectClause, const char* const selectOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkSubroutine(char** error, const char* const credentialOptions, const char* const subroutineName, uint32_t argsNumber, const char* const arguments, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkConversion(char** error, const char* const credentialOptions, const char* const expression, const char* const code, CONVERSION_TYPE conversionOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkFormat(char** error, const char* const credentialOptions, const char* const expression, const char* const formatSpec, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkDictionaries(char** error, const char* const credentialOptions, const char* const filename, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkExecute(char** error, const char* const credentialOptions, const char* const statement, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkGetVersion(char** error, const char* const credentialOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkSchemas(char** error, const char* const credentialOptions, const char* const lkSchemasOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkProperties(char** error, const char* const credentialOptions, const char* const filename, const char* const lkSchemasOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkResetCommonBlocks(char** error, const char* const credentialOptions, uint32_t receiveTimeout);

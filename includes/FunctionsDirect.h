/*
	File: DirectFunctions.h
	Header file for <DirectFunctions.c>

	Prototype Functions:
	--- Code
	DllEntry char* Base_LkRead(char** error, const char* const credentialOptions, const char* const filename, const char* const recordIds, const char* const dictionaries, const char* const readOptions, DataFormatTYPE inputFormat, DataFormatCruTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* Base_LkUpdate(char** error,  const char* const credentialOptions, const char* const filename, const char* const records, const char* const updateOptions, DataFormatTYPE inputFormat, DataFormatCruTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* Base_LkNew(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const newOptions, DataFormatTYPE inputFormat, DataFormatCruTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* Base_LkDelete(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const deleteOptions, DataFormatTYPE inputFormat, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* Base_LkSelect(char** error, const char* const credentialOptions, const char* const filename, const char* const selectClause, const char* const sortClause, const char* const dictClause, const char* const preSelectClause, const char* const selectOptions, DataFormatCruTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* Base_LkSubroutine(char** error, const char* const credentialOptions, const char* const subroutineName, uint32_t argsNumber, const char* const arguments, DataFormatTYPE inputFormat, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* Base_LkConversion(char** error, const char* const credentialOptions, const char* const expression, const char* const code, CONVERSION_TYPE conversionType, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* Base_LkFormat(char** error, const char* const credentialOptions, const char* const expression, const char* const formatSpec, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* Base_LkDictionaries(char** error, const char* const credentialOptions, const char* const filename, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* Base_LkExecute(char** error, const char* const credentialOptions, const char* const statement, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* Base_LkGetVersion(char** error, const char* const credentialOptions, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* Base_LkSchemas(char** error, const char* const credentialOptions, const char* const lkSchemasOptions, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* Base_LkProperties(char** error, const char* const credentialOptions, const char* const filename, const char* const lkSchemasOptions, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* Base_LkGetTable(char** error, const char* const credentialOptions, const char* const filename, const char* const selectClause, const char* const dictClause, const char* const sortClause, const char* const getTableOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* Base_LkResetCommonBlocks(char** error, const char* const credentialOptions, DataFormatTYPE outputFormat, uint32_t receiveTimeout);
	---
*/
#include "CompilerOptions.h"
#include "Types.h"

DllEntry char* Base_LkRead(char** error, const char* const credentialOptions, const char* const filename, const char* const recordIds, const char* const dictionaries, const char* const readOptions, DataFormatTYPE inputFormat, DataFormatCruTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* Base_LkUpdate(char** error,  const char* const credentialOptions, const char* const filename, const char* const records, const char* const updateOptions, DataFormatTYPE inputFormat, DataFormatCruTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* Base_LkNew(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const newOptions, DataFormatTYPE inputFormat, DataFormatCruTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* Base_LkDelete(char** error, const char* const credentialOptions, const char* const filename, const char* const records, const char* const deleteOptions, DataFormatTYPE inputFormat, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* Base_LkSelect(char** error, const char* const credentialOptions, const char* const filename, const char* const selectClause, const char* const sortClause, const char* const dictClause, const char* const preSelectClause, const char* const selectOptions, DataFormatCruTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* Base_LkSubroutine(char** error, const char* const credentialOptions, const char* const subroutineName, uint32_t argsNumber, const char* const arguments, DataFormatTYPE inputFormat, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* Base_LkConversion(char** error, const char* const credentialOptions, const char* const expression, const char* const code, CONVERSION_TYPE conversionType, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* Base_LkFormat(char** error, const char* const credentialOptions, const char* const expression, const char* const formatSpec, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* Base_LkDictionaries(char** error, const char* const credentialOptions, const char* const filename, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* Base_LkExecute(char** error, const char* const credentialOptions, const char* const statement, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* Base_LkGetVersion(char** error, const char* const credentialOptions, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* Base_LkSchemas(char** error, const char* const credentialOptions, const char* const lkSchemasOptions, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* Base_LkProperties(char** error, const char* const credentialOptions, const char* const filename, const char* const lkSchemasOptions, DataFormatTYPE outputFormat, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* Base_LkGetTable(char** error, const char* const credentialOptions, const char* const filename, const char* const selectClause, const char* const dictClause, const char* const sortClause, const char* const getTableOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* Base_LkResetCommonBlocks(char** error, const char* const credentialOptions, DataFormatTYPE outputFormat, uint32_t receiveTimeout);

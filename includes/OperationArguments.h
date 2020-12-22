/*
	File: OperationArguments.h
	Header file for <OperationArguments.c>
	
	Prototype Functions:
	--- Code
	DllEntry char* LkGetReadArgs(const char* const filename, const char* const recordIds, const char* const dictionaries, const char* const readOptions, const char* const customVars);
	DllEntry char* LkGetUpdateArgs(const char* const filename, const char* const records, const char* const updateOptions, const char* const customVars);
	DllEntry char* LkGetNewArgs(const char* const filename, const char* const records, const char* const newOptions, const char* const customVars);
	DllEntry char* LkGetDeleteArgs(const char* const filename, const char* const records, const char* deleteOptions, const char* const customVars);
	DllEntry char* LkGetSelectArgs(const char* const filename, const char* const selectClause, const char* const sortClause, const char* const dictClause, const char* const preSelectClause, const char* const selectOptions, const char* const customVars);
	DllEntry char* LkGetSubroutineArgs(const char* const subroutineName, uint32_t argsNumber, const char* const arguments, const char* const customVars);
	DllEntry char* LkGetConversionArgs(const char* const expression, const char* const code, CONVERSION_TYPE conversionOptions, const char* const customVars);
	DllEntry char* LkGetFormatArgs(const char* const expression, const char* const formatSpec, const char* const customVars);
	DllEntry char* LkGetDictionariesArgs(const char* const filename, const char* const customVars);
	DllEntry char* LkGetExecuteArgs(const char* const statement, const char* const customVars);
	DllEntry char* LkGetGetVersionArgs();
	DllEntry char* LkGetLkSchemasArgs(const char* const lkSchemasOptions, const char* const customVars);
	DllEntry char* LkGetLkPropertiesArgs(const char* const filename, const char* const lkPropertiesOptions, const char* const customVars);
	DllEntry char* LkGetGetTableArgs(const char* const filename, const char* const selectClause, const char* const dictClause, const char* const sortClause, const char* const tableOptions, const char* const customVars);
	DllEntry char* LkGetResetCommonBlocksArgs();
	---
*/
#include "CompilerOptions.h"
#include "Types.h"

#include <stdint.h>

DllEntry char* LkGetReadArgs(const char* const filename, const char* const recordIds, const char* const dictionaries, const char* const readOptions, const char* const customVars);
DllEntry char* LkGetUpdateArgs(const char* const filename, const char* const records, const char* const updateOptions, const char* const customVars);
DllEntry char* LkGetNewArgs(const char* const filename, const char* const records, const char* const newOptions, const char* const customVars);
DllEntry char* LkGetDeleteArgs(const char* const filename, const char* const records, const char* deleteOptions, const char* const customVars);
DllEntry char* LkGetSelectArgs(const char* const filename, const char* const selectClause, const char* const sortClause, const char* const dictClause, const char* const preSelectClause, const char* const selectOptions, const char* const customVars);
DllEntry char* LkGetSubroutineArgs(const char* const subroutineName, uint32_t argsNumber, const char* const arguments, const char* const customVars);
DllEntry char* LkGetConversionArgs(const char* const expression, const char* const code, CONVERSION_TYPE conversionOptions, const char* const customVars);
DllEntry char* LkGetFormatArgs(const char* const expression, const char* const formatSpec, const char* const customVars);
DllEntry char* LkGetDictionariesArgs(const char* const filename, const char* const customVars);
DllEntry char* LkGetExecuteArgs(const char* const statement, const char* const customVars);
DllEntry char* LkGetGetVersionArgs();
DllEntry char* LkGetLkSchemasArgs(const char* const lkSchemasOptions, const char* const customVars);
DllEntry char* LkGetLkPropertiesArgs(const char* const filename, const char* const lkPropertiesOptions, const char* const customVars);
DllEntry char* LkGetGetTableArgs(const char* const filename, const char* const selectClause, const char* const dictClause, const char* const sortClause, const char* const tableOptions, const char* const customVars);
DllEntry char* LkGetResetCommonBlocksArgs();

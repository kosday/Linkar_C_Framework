/*
	File: PersistentFunctionsTABLE.h
	Header file for PersistentFunctionsTABLE.c

	Prototype Functions:
	--- Code
	DllEntry char* LkLogin(char** error, char* credentialOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry void LkLogout(char** error, char** connectionInfo, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkSchemas(char** error, char** connectionInfo, const char* const lkSchemasOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkProperties(char** error, char** connectionInfo, const char* const filename, const char* const lkSchemasOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkGetTable(char** error, char** connectionInfo, const char* const filename, const char* const selectClause, const char* const dictClause, const char* const sortClause, const char* const tableOptions, const char* const customVars, uint32_t receiveTimeout);
	---
*/
#include "CompilerOptions.h"
#include "Types.h"

DllEntry char* LkLogin(char** error, char* credentialOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry void LkLogout(char** error, char** connectionInfo, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkSchemas(char** error, char** connectionInfo, const char* const lkSchemasOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkProperties(char** error, char** connectionInfo, const char* const filename, const char* const lkSchemasOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkGetTable(char** error, char** connectionInfo, const char* const filename, const char* const selectClause, const char* const dictClause, const char* const sortClause, const char* const tableOptions, const char* const customVars, uint32_t receiveTimeout);

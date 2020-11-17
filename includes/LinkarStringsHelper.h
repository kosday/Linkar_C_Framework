/*
	File: LinkarStringsHelper.h
	Header file for LinkarStringsHelper.c

	Prototype Functions:
	--- Code
	DllEntry char ** LkStrSplit(const char* const str, const char delim, uint32_t* count);
	DllEntry char* LkStrJoin(const char** const lstStr, uint32_t count, const char* const delim);
	DllEntry char* LkExtractFromSplit(const char* const str, const char delim, uint32_t index);
	DllEntry char* LkCatString(const char* const str, const char* const newStr, const char* const delim);
	DllEntry char* LkExtractData(const char* const lkString, const char* const tag, char delimiter, char delimiterThisList);
	---	
*/
#include "CompilerOptions.h"
#include "Types.h"

DllEntry char ** LkStrSplit(const char* const str, const char delim, uint32_t* count);
DllEntry char* LkStrJoin(const char** const lstStr, uint32_t count, const char* const delim);
DllEntry char* LkExtractFromSplit(const char* const str, const char delim, uint32_t index);
DllEntry char* LkCatString(const char* const str1, const char* const str2, const char* const delim);
DllEntry char* LkExtractData(const char* const lkString, const char* const tag, char delimiter, char delimiterThisList);

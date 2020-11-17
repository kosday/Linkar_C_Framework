/*
	File: MvOperations.h
	Header file for MvOperations.c

	Prototype Functions:
	--- Code
	DllEntry uint32_t LkCount(const char* const str, char delimiter);
	DllEntry uint32_t LkDCount(const char* const str, char delimiter);
	DllEntry char* LkExtract(const char* const str, int32_t field, int32_t value, int32_t subvalue);
	static char* AddMarks(const char* const str, int32_t numMarcas, char mark);
	DllEntry char* LkReplace(const char* const str, const char* const newVal, int32_t field, int32_t value, int32_t subvalue);
	static uint32_t _strFind(const char* const str, const char* const searchStr);
	static char* _strReplace(const char* const str, uint32_t pos, uint32_t length, const char* newStr);
	DllEntry char* LkChange(const char* const str, const char* const oldStr, const char* const newStr, int32_t occurrences, int32_t start);
	---
*/
#include "CompilerOptions.h"
#include "Types.h"

DllEntry uint32_t LkCount(const char* const str, char delimiter);
DllEntry uint32_t LkDCount(const char* const str, char delimiter);
DllEntry char* LkExtract(const char* const str, int32_t field, int32_t value, int32_t subvalue);
static char* AddMarks(const char* const str, int32_t numMarcas, char mark);
DllEntry char* LkReplace(const char* const str, const char* const newVal, int32_t field, int32_t value, int32_t subvalue);
static uint32_t _strFind(const char* const str, const char* const searchStr);
static char* _strReplace(const char* const str, uint32_t pos, uint32_t length, const char* newStr);
DllEntry char* LkChange(const char* const str, const char* const oldStr, const char* const newStr, int32_t occurrence, int32_t start);

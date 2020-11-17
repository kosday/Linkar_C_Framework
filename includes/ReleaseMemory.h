/*
	File: ReleaseMemory.h
	Header file for ReleaseMemory.c

	Prototype Functions:
	--- Code
	DllEntry void LkFreeMemory(char * str);
	DllEntry void LkFreeMemoryStringArray(char **ptr, uint32_t count);
	DllEntry void WrapperPy_LkFreeMemoryStringArray(char *ptr, uint32_t count);
	---
*/
#include "CompilerOptions.h"
#include "Types.h"

DllEntry void LkFreeMemory(char * str);
DllEntry void LkFreeMemoryStringArray(char **ptr, uint32_t count);
DllEntry void WrapperPy_LkFreeMemoryStringArray(char *ptr, uint32_t count);

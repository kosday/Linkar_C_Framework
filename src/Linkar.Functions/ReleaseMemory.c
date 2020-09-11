/*	
	File: ReleaseMemory.c
	This module contains auxiliary functions to help in release memory.
		
*/
#include <malloc.h>
#include "ReleaseMemory.h"

// Group: Release Memory

/* 
 Topic: About char* and char** return values.
		All functions that its return values is a char*, use dynamic memory allocation to store the return string.
		Once that string is not needed anymore, the memory assigned to it *must be released*.
		Since the memory allocation was made inside the C library, you must use the <LkFreeMemory> function to release that memory.
		
		The functions that return an array of strings do so by means of a double pointer (char **).
		In C, this is a pointer that points to an array of pointers, each of which points to a string of characters (a "string").
		All this memory (the strings of characters and the array of pointers) has been assigned dynamically.
		And therefore it *must be released* when it is no longer needed.
		To assist in the release of memory, use <LkFreeMemoryStringArray> function.
 
*/


// Group: Functions

/*
	Function: LkFreeMemory
		Releases memory assigned by functions that return a char* as value.
	
	Arguments:
		str - pointer to the memory that must be released
*/
DllEntry void LkFreeMemory(char * str)
{
	free(str);
}

/*
	Function: LkFreeMemoryStringArray
		Releases memory assigned by functions that return a char** (double pointer) as value.

	Arguments:
		ptr - Pointer to the memory that must be released.
		
		count - Number of elements (number of character strings)		
*/
DllEntry void LkFreeMemoryStringArray(char **ptr, uint32_t count)
{
  int i;
  for(i = 0; i < count; i++)
    free(ptr[i]);
  free((char *)ptr);
}

/*
	Function: WrapperPy_LkFreeMemoryStringArray
		Allows python scripts to invoke the <LkFreeMemoryStringArray> function.
		
	Arguments:
		ptr - Pointer to the memory that must be released.
		
		count - Number of elements (number of character strings)				
*/
DllEntry void WrapperPy_LkFreeMemoryStringArray(char *ptr, uint32_t count)
{
// WRAPPER for PYTHON can invoke to the function LkFreeMemoryStringArray
  char ** ptr_matrix = (char**)ptr;
  
  LkFreeMemoryStringArray(ptr_matrix, count);
}

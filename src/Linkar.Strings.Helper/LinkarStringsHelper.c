/*
	File: LinkarStringsHelper.c
	Auxiliary functions used by <LinkarString.c>
	
*/
#include "LinkarStringsHelper.h"

#include <string.h>
#include <malloc.h>

/*
	Function: LkStrSplit
		Auxiliary function that slit a string into substrings that are based on the characters in an array.
		
	Arguments:
		str - The string to split.
		delim - The char to use for split.
		count - The numbers of substrings after the split.

	Returns:
		Split substrings. The result is a pointer to strings (pointer to C string pointers).
		
	See Also:
		<Release Memory>
*/
DllEntry char ** LkStrSplit(const char* const str, const char delim, uint32_t* count)
{
	uint32_t i;
	uint32_t len = strlen(str);
	uint32_t c = 0;
	unsigned char delim2 = delim & 0xFF;

	for(i=0; i<len; i++)
		if((unsigned char)str[i] == delim2)
			c++;
		
	*count = c + 1;
	
	uint32_t size = sizeof(char*) * (c + 2);
	char** array = malloc(size);
	
	const char* inicio = str;
	c = 0;
	uint32_t index = 0;
	for(i=0; i<len; i++, c++)
	{
		if(str[i] == delim)
		{
			array[index] = malloc(c + 1);
			memcpy(array[index], inicio, c);
			array[index][c] = 0;
			
			index++;
			inicio = str + i + 1;
			c = -1;
		}
	}
	
	if(c >= 0)
	{
		array[index] = malloc(c + 1);
		memcpy(array[index], inicio, c);
		array[index][c] = 0;
		index++;
	}
	
	array[index] = NULL;
			
	return array;
}

/*
	Function: LkStrJoin
		Auxiliary function to compose the final string of multiple substrings into "lstStr" using "delim" as separation char.
		
	Arguments:
		lstStr -  Array of substring (pointer to C string pointers).
		count - The size of the array.
		delim - The char to use for join the substrings.
	
	Returns:
		The final string of joined substrings.
		
	See Also:
		<Release Memory>
*/
DllEntry char* LkStrJoin(const char** const lstStr, uint32_t count, const char* const delim)
{
	if(count > 0)
	{
		int len = count;
		int i;
		for(i=0; i<count; i++)
			len += strlen(lstStr[i]);
		
		char* str = malloc(len);
		
		strcpy(str, lstStr[0]);
		for(i=1; i<count; i++)
		{
			strcat(str, delim);
			strcat(str, lstStr[i]);
		}
		
		return str;
	}
	else
		return NULL;
}

/*
	Function: LkExtractFromSplit
		Extract the substring, delimited with "delim" char, of "index" position from "str" string.
		
	Arguments:
		str - The string where the substring will be extracted.
		delim - The char used to delimiter the substrings
		index - The position of substring to be extracted.
		
	Returns:
		The substring extracted. NULL if the substring of "index" position not found.
		
	See Also:
		<Release Memory>
*/
DllEntry char* LkExtractFromSplit(const char* const str, const char delim, uint32_t index)
{
	char *data = NULL;
	uint32_t count;
	char** items = LkStrSplit(str, delim, &count);
	
	if(items && index >=0 && index < count)
	{
		int i;
		for(i = 0; items[i]; i++)
		{
			if(i == index)
				data = items[i];
			else
				free(items[i]);
		}
		free(items);
	}

	return data;
}

/*
	Function: LkCatString
		Join "str1" and "str2" strings using "delim" char, in a new string.
		
	Arguments:
		str1 - The first string.
		str2 - The second string.
		delim - The separator char between the joined string.
	
	Returns:
		The new string with joined "str1" and "str2" strings.
		
	See Also:
		<Release Memory>
*/
DllEntry char* LkCatString(const char* const str1, const char* const str2, const char* const delim)
{
	int lenStr1 = 0;
	int lenStr2 = 0;
	int lenDelim = 0;
	if(str1)
		lenStr1 = strlen(str1);
	if(str2)
		lenStr2 = strlen(str2);
	if(delim)
		lenDelim = strlen(delim);
	
	uint32_t len = lenStr1 + lenStr2 + lenDelim;
	char* catStr = malloc(len + 1);
	if(catStr)
	{
		if(str1)
		{
			strcpy(catStr, str1);
			if(delim)
				strcat(catStr, delim);
			if(str2)
				strcat(catStr, str2);
		}
		else
			if(str2)
			{
				if(delim)
				{
					strcpy(catStr, delim);
					strcat(catStr, str2);
				}
				else
					strcpy(catStr, str2);
			}
			else
			{
				if(delim)
					strcpy(catStr, delim);
				else
					catStr[0] = 0;
			}
	}
	
	return catStr;
}

/*
	Function: LkExtractData
		Auxiliary function used to extract data from the result <LkString> of any Operation with output format MV.
		
	Arguments:
		lkString - The result string of any Operation with output format MV.
		tag - The name of the item to be extracted. This names are defined in <LkString.h>
		delimiter - The separator char between the items of <LkString>. By default is the ASCII char of code 28.
		delimiterThisList - The first item of <LkString> contains the tag names. This is the separator char between these tags. By default is the ASCII char of code 254.
		
	Returns:
		An string with the item extracted.
		
	See Also:
		<LkString>
		
		<Release Memory>
*/
DllEntry char* LkExtractData(const char* const lkString, const char* const tag, char delimiter, char delimiterThisList)
{
	char* block = NULL;
	if(lkString)
	{		
		uint32_t count;
		char** parts = LkStrSplit(lkString, delimiter, &count);
		
		if(count >= 1)
		{	
			uint32_t count2;
			char** headersList = LkStrSplit(parts[0], delimiterThisList, &count2);
			
			int i;			
			for(i=0; i<count2; i++)
			{
				if(strcmp(headersList[i], tag) == 0)
					block = strdup(parts[i]);
				
				free(parts[i]);
				free(headersList[i]);
			}
			
			free(parts);
			free(headersList);
		}
	}
	return block;
}

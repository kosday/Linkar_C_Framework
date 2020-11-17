/*	
	File: MvOperations.c
	This module contains the basic functions to work with strings of multivalues. These functions are locally executed.
*/

#include "MvOperations.h"
#include "LinkarStringsHelper.h"

#include <malloc.h>
#include <string.h>

/*
	Function: LkCount
		Counts the occurrences of a substring inside a string.

	Arguments:
		str - The string you are going to count.
		delimiter - The separator you are going to count.

	Returns:
		The number of occurrences found.
*/
DllEntry uint32_t LkCount(const char* const str, char delimiter)
{
	if(str)
	{
		uint32_t len = strlen(str);
		uint32_t count = 0;
		int i;
		for(i=0; i<len; i++)
			if(str[i] == delimiter)
				count++;

		return count;
	}
	else
		return 0;
}

/*
	Function: LkDCount
		Counts the delimited substrings inside a string
		
	Arguments:
		str - The string you are going to count.
		delimiter - The separator you are going to count.
		
	Returns:
		The number of occurrences found.
*/
DllEntry uint32_t LkDCount(const char* const str, char delimiter)
{
	return LkCount(str, delimiter) + 1;
}

/*
	Function: LkExtract
		Extracts a field, value or subvalue from a dynamic array.

	Arguments:
		str - The string on which you are going to extract a value.
		field - The position or the dictionary name of the attribute where you want to extract.
		value - The multivalue position where you want to extract.
		subvalue - The subvalue position where you want to extract.
	
	Returns:
		A new string with the extracted value.
		
	See Also:	
		<Release Memory>
*/
DllEntry char* LkExtract(const char* const str, int32_t field, int32_t value, int32_t subvalue)
{	
	if(field > 0 && str != NULL)
	{
		char* atributo = LkExtractFromSplit(str, DBMV_Mark_AM, field - 1);
		
		if(value > 0 && atributo != NULL)
		{
			char* multivalor = LkExtract(atributo, 0, value, subvalue);
			free(atributo);

			return multivalor;
		}
		else
		{
			return atributo;
		}
	}	
	else if(value > 0 && str != NULL)
	{
		char* multivalor = LkExtractFromSplit(str, DBMV_Mark_VM, value - 1);
		
		if(subvalue > 0 && multivalor != NULL)
		{
			char* subvalor = LkExtract(multivalor, 0, 0, subvalue);
			free(multivalor);
			
			return subvalor;
		}
		else
		{
			return multivalor;
		}
	}	
	else if(subvalue > 0 && str != NULL)
	{
		char *subvalor = LkExtractFromSplit(str, DBMV_Mark_SM, subvalue - 1);

		return subvalor;
	}
	else
		return NULL;
}
	
/*
	Function: AddMarks
		Helper function for <LkReplace> that adds as many chars with ASCII code "chr" as indicated by the argument "count" at the end of the string "str".

	Arguments:
		str - The string at the end of which the characters will be added.
		count - The number of characters to be added.
		chr - The character to be added.

	Returns:
		The new string with the added chars.
		
	See Also:	
		<LkReplace>
				
		<Release Memory>	
*/
static char* AddMarks(const char* const str, int32_t count, char chr)
{
	int32_t lenStr = strlen(str);
	char* result = malloc(lenStr + count + 1);
	if(result)
	{
		strcpy(result, str);
		memset(result + lenStr, chr, count);
		result[lenStr + count] = 0;
		
		return result;			
	}
	else
		return NULL;
}

/*
	Function: LkReplace
		Replaces a field, value or subvalue from a dynamic array, returning the result.

	Arguments:
		str - The string on which you are going to replace a value.
		newVal - The new value that will be replaced in the indicated string.
		field - The position or the dictionary name of the attribute where you want to replace.
		value - The multivalue position where you want to replace.
		subvalue - The subvalue position where you want to extract.
	
	Returns:
		A new string with the replaced value.
		
	See Also:	
		<Release Memory>
*/
DllEntry char* LkReplace(const char* const str, const char* const newVal, int32_t field, int32_t value, int32_t subvalue)
{	
	if(field < 0)
		return LkCatString(str, newVal, DBMV_Mark_AM_str);
	
	if(field == 0)
		field = 1;

	char* fresult = NULL;
	int32_t fcount = LkDCount(str, DBMV_Mark_AM);
	if(field > fcount)
	{
		int32_t numMarcas = field - fcount;
		fresult = AddMarks(str, numMarcas, DBMV_Mark_AM);
	}
	
	char** fparts;
	if(fresult)
	{
		fparts = LkStrSplit(fresult, DBMV_Mark_AM, &fcount);
		free(fresult);
		fresult = NULL;
	}
	else
		fparts = LkStrSplit(str, DBMV_Mark_AM, &fcount);
	
	int i;
	field--;
	for(i=0; i<fcount; i++)
	{
		if(i == field)
		{
			if(value == 0)
			{
				if(fresult)
				{
					char* aux = LkCatString(fresult, newVal, DBMV_Mark_AM_str);
					free(fresult);
					fresult = aux;
				}
				else
					fresult = LkCatString(fresult, newVal, NULL);
			}
			else if(value == -1)
			{
				if(fparts[i][0] == 0) // Si el FIELD esta vacio, se pone directamente NEWVAL
				{
					char* aux;
					if(fresult)
						aux = LkCatString(fresult, newVal, DBMV_Mark_AM_str);
					else
						aux = LkCatString(fresult, newVal, NULL);
					free(fresult);
					fresult = aux;
				}
				else
				{
					char* aux;
					if(fresult)
						aux = LkCatString(fresult, fparts[i], DBMV_Mark_AM_str);
					else
						aux = LkCatString(fresult, fparts[i], NULL);
					free(fresult);
					fresult = aux;
					aux = LkCatString(fresult, newVal, DBMV_Mark_VM_str);
					free(fresult);
					fresult = aux;						
				}
			}
			else
			{							
				char* vresult = NULL;
				int32_t vcount = LkDCount(fparts[i], DBMV_Mark_VM);
				if((value-1) > vcount)
				{
					int32_t numMarcas = value - vcount;
					vresult = AddMarks(fparts[i], numMarcas, DBMV_Mark_VM);
				}				
				
				char** vparts;
				if(vresult)
				{
					vparts = LkStrSplit(vresult, DBMV_Mark_VM, &vcount);
					free(vresult);
					vresult = NULL;
				}
				else
					vparts = LkStrSplit(fparts[i], DBMV_Mark_VM, &vcount);
				
				int j;
				value--;
				for(j=0; j<vcount; j++)
				{
					if(j == value)
					{
						if(subvalue == 0)
						{
							char* aux;
							if(vresult)
							{
								aux = LkCatString(vresult, newVal, DBMV_Mark_VM_str);
								free(vresult);
							}
							else
								aux = LkCatString(vresult, newVal, NULL);
							vresult = aux;
						}
						else if(subvalue == -1)
						{
							if(vparts[j][0] == 0)
							{
								char* aux;
								if(vresult)
									aux = LkCatString(vresult, newVal, DBMV_Mark_VM_str);
								else
									aux = LkCatString(vresult, newVal, NULL);
								free(vresult);
								vresult = aux;
							}
							else
							{
								char* aux;
								if(vresult)
									aux = LkCatString(vresult, vparts[j], DBMV_Mark_VM_str);
								else
									aux = LkCatString(vresult, vparts[j], NULL);
								free(vresult);
								vresult = aux;
								aux = LkCatString(vresult, newVal, DBMV_Mark_SM_str);
								free(vresult);
								vresult = aux;						
							}				
						}
						else
						{
							char* sresult = NULL;
							int32_t scount = LkDCount(vparts[j], DBMV_Mark_SM);
							if((subvalue-1) > scount)
							{
								int32_t numMarcas = subvalue - scount;
								sresult = AddMarks(vparts[j], numMarcas, DBMV_Mark_SM);
							}				
				
							char** sparts;
							if(sresult)
							{
								sparts = LkStrSplit(sresult, DBMV_Mark_SM, &scount);
								free(sresult);
								sresult = NULL;
							}
							else
								sparts = LkStrSplit(vparts[j], DBMV_Mark_SM, &scount);
							
							subvalue--;
							int k;
							for(k=0; k<scount; k++)
							{
								if(k==subvalue)
								{
									char* aux;
									if(sresult)
									{
										aux = LkCatString(sresult, newVal, DBMV_Mark_SM_str);
										free(sresult);
									}
									else
										aux = LkCatString(sresult, newVal, NULL);
									sresult = aux;
								}
								else
								{
									char* aux;
									if(sresult)
									{
										aux = LkCatString(sresult, sparts[k], DBMV_Mark_SM_str);
										free(sresult);
									}
									else
										aux = LkCatString(sresult, sparts[k], NULL);
									sresult = aux;
								}
								free(sparts[k]);
							}
							free(sparts);
							
							if(vresult)
							{
								char* aux = LkCatString(vresult, sresult, DBMV_Mark_VM_str);
								free(vresult);
								vresult = aux;
							}
							else
								vresult = LkCatString(vresult, sresult, NULL);
						}
					}
					else
					{
						char* aux;
						if(vresult)
						{
							aux = LkCatString(vresult, vparts[j], DBMV_Mark_VM_str);
							free(vresult);
						}
						else
							aux = LkCatString(vresult, vparts[j], NULL);
						vresult = aux;
					}

					free(vparts[j]);
				}
			
				free(vparts);
				
				if(fresult)
				{
					char* aux = LkCatString(fresult, vresult, DBMV_Mark_AM_str);
					free(fresult);
					fresult = aux;
				}
				else
				{
					fresult = LkCatString(fresult, vresult, NULL);
				}
			}
		}
		else
		{
			char* aux;
			if(fresult)
			{
				aux = LkCatString(fresult, fparts[i], DBMV_Mark_AM_str);
				free(fresult);
			}
			else
				aux = LkCatString(fresult, fparts[i], NULL);
			fresult = aux;
		}
		free(fparts[i]);
	}
	free(fparts);
	
	return fresult;	
}

/*
	Function: strFind
		Helper function for <LkChange> that look for the string "str2" inside the string "str".
		
	Arguments:
		str - The string where the search will be performed.
		str2 - The string to search
		
	Returns:
		If string str2 is found, its starting position within string str will be returned. Otherwise -1 will be returned.
		
	See Also:
		<LkChange>

		<Release Memory>
*/
static uint32_t strFind(const char* const str, const char* const str2)
{	
	int lenSearchStr = strlen(str2);
	int len = strlen(str) - lenSearchStr;
	int i;
	char* subStr = malloc(lenSearchStr + 1);
	if(subStr)
	{
		for(i=0; i<=len; i++)
		{
			strncpy(subStr, str+i, lenSearchStr);
			subStr[lenSearchStr] = 0;
			if(strcmp(subStr, str2) == 0)
				return i;
		}
		return -1;
	}
	else
		return -1;
}

/*
	Function: strReplace
		Helper function for <LkChange> that replaces inside the string "str" ​​the substring that begins in the position "pos" and has as many chars as length as indicated by the argument "length", by the string indicated in the argument "newStr"
	
	Arguments:
		str - The string where the replacement will be made.
		pos - The position within the string "str" ​​where the substring to be replaced begins.
		length - Chars to replace from position "pos".
		newStr - The new string to replace the substring inside the string "str"
		
	Returns:
		The new string with the replacement made.
		
	See Also:
		<LkChange>
				
		<Release Memory>
*/
static char* strReplace(const char* const str, uint32_t pos, uint32_t length, const char* newStr)
{	
	int lenNewStr = 0;
	if(newStr)
		lenNewStr = strlen(newStr);
	int len = strlen(str) - length + lenNewStr;
	char* result = malloc(len + 1);
	
	if(result)
	{
		strncpy(result, str, pos);
		result[pos] = 0;
		if(newStr)
			strcat(result, newStr);
		strcat(result, str + pos + length);

		return result;
	}
	else
		return NULL;
}

/*
	Function: LkChange
		Replaces the occurrence of a substring inside a string, by other substring.
		
	Arguments:
		str - The string on which the value is going to change.
		oldStr - The value to change.
		newStr - The new value.
		occurrence - The number of times it will change.
		start - The position from which you are going to start changing values.
	
	Returns:
		A new string with replaced text.
		
	See Also:	
		<Release Memory>
*/
DllEntry char* LkChange(const char* const str, const char* const oldStr, const char* const newStr, int32_t occurrence, int32_t start)
{	
	int lenOldStr = strlen(oldStr);
	int lenNewStr = strlen(newStr);
	if(start < 1)
		start = 1;
	
	int i;
	uint32_t posBuscar = 0;
	int posCambiar = -1;
	int c = 0;
	for(i=0; i<start; i++)
	{
		c = strFind(str + posBuscar, oldStr);
		if(c >= 0)
		{
			if(posCambiar == -1)
				posCambiar = c;
			else
				posCambiar += c + lenOldStr;
			
			posBuscar = posCambiar + lenOldStr;
		}

		c++;
	}
		
	char* result = NULL;
	if(c == -1)
		return (char*)str;

	BOOL end = FALSE;
	do
	{
		if(occurrence > 0)
		{
			occurrence--;
			if(occurrence == 0)
				end = TRUE;
		}
			
		if(result)
		{
			char* aux = strReplace(result, posCambiar, lenOldStr, newStr);
			free(result);
			result = aux;
		}
		else
			result = strReplace(str, posCambiar, lenOldStr, newStr);

		posBuscar = posCambiar + lenNewStr;
		uint32_t len = strlen(result);
		
		if(posBuscar <= (len - lenOldStr))
		{
			c = strFind(result + posBuscar, oldStr);
			if(c == -1)
				end = TRUE;
			else
				posCambiar = posBuscar + c;
		}
		else
			end = TRUE;
	} while(!end);
		
	return result;
}




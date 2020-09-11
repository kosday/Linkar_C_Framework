/*	
	File: OperationArguments.c 

    Auxiliary functions to obtain the 3 items of every LinkarSERVER operation.

    These items are: CUSTOMVARS, OPTIONS and INPUTDATA.

    Unit Separator character (31) is used as separator between these items.

   	CUSTOMVARS: String for database custom subroutines.
	
    OPTIONS: The options of every operation.
    
	INPUT: The necesary data for perform every operation.

	CUSTOMVARS US_char OPTIONS US_char INPUT
*/

#include "OperationArguments.h"
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

/* 
	Function: LkGetSendCommandArgs
		Compose the 3 items (CUSTOMVARS, OPTIONS and INPUTDATA) of the Version operation.
	   
	Arguments:
		command - Content of the operation you want to send.
		
	Returns:      
		A string ready to be used in <LkExecuteDirectOperation> and <LkExecutePersistentOperation>.
		
	See Also:
		<Release Memory>
*/
DllEntry char* LkGetSendCommandArgs(const char* const command)
{
	int lenCommand = 0;
	if(command != NULL)
		lenCommand = strlen(command);
	
	int len = lenCommand + 2*strlen(ASCII_US_str) + 1;
	char* operationArguments = malloc(len);
	if(operationArguments != NULL)
	{
		strcpy(operationArguments, ASCII_US_str);
		strcat(operationArguments, ASCII_US_str);
		if(command != NULL)
			strcat(operationArguments, command);
		else
			strcat(operationArguments, "");
	}	
	
	return operationArguments;
}
	
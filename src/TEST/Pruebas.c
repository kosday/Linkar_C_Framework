		#include <malloc.h>
		#include <stdio.h>
		
		#include "LinkarStrings.h"
		#include "CredentialOptions.h"
		#include "FunctionsDirectMV.h"
		#include "MvOperations.h"
		#include "OperationOptions.h"
	
		void main(void)
		{
			char* error;
			char* credentialOptions = LkCreateCredentialOptions("localhost", "EP_NAME", 11301, "ADMIN", "admin", "", "Test C Library");	
			char* filename = "LK.CUSTOMERS";
			char* recordIds = "1";
			char* dictionaries = "";
			char* readOptions = NULL;
			char* customVars = "";
			int32_t receiveTimeout = 10;	

			char* result = LkRead(&error, credentialOptions, filename, recordIds, dictionaries, readOptions, customVars, receiveTimeout);
			if(error != NULL)
			{
				printf("ERRORS: %s\n", error);
				free(error);
			}
			printf("result (MV): %s\n", result);	
		}
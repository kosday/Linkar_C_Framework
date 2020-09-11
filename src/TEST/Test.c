#include <malloc.h>
#include <stdio.h>

#include "LinkarStringsHelper.h"
#include "LinkarStrings.h"
#include "CredentialOptions.h"

#include "Types.h"

#include "FunctionsDirect.h"

void main(void)
{	
	char* credentialOptions = LkCreateCredentialOptions("192.168.100.101", "QMEP1", 11301, "ADMIN", "admin", "", "Test C Library");
	free(credentialOptions);
}
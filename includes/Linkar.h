#include "CompilerOptions.h"
#include <stdint.h>

/*
	Function: LkExecutePersistentOperation
		Execute "persistent operations". These operations required that a session will be stablished previously with Login operation.

	Note: 
		This is just the prototype function. The real function is implemented inside the "Linkar" private library (Linkar.dll/Linkar.lib/Linkar.so/Linkar.a).
	
	Arguments:
		error - System or communication errors with LinkarSERVER.
		connectionInfo - Contains the data necessary to access an established LinkarSERVER session.
		operationCode - Code of the operation to be performed.
		operationArgs - Specific arguments of every operation.
		inputDataFormat - Format of the input data.
		outputDataFormat - Format of the output data.
		receiveTimeout - Maximum time in seconds to wait the response from LinkarSERVER. A value less or equal to 0, wait for response indefinitely.
	
	Returns:
		Complex string with the result of the operation.

	Examples:
		See <PersistentFunctions.c> for examples.
		
*/
DllEntry char* LkExecutePersistentOperation(char** error, char** connectionInfo, uint8_t operationCode, const char* const operationArgs, uint8_t inputDataFormat, uint8_t outputDataFormat, uint32_t receiveTimeout);

/*
	Function: LkExecuteDirectOperation
		Execute "direct operations". These operations don't stablish a permanent session. Once the operations is finished, the session is closed.

	Note: 
		This is just the prototype function. The real function is implemented inside the "Linkar" private library (Linkar.dll/Linkar.lib/Linkar.so/Linkar.a).
	
	Arguments:
		error - System or communication errors with LinkarSERVER.
		credentialOptions - The credentials for access to LinkarSERVER.
		operationCode - Code of the operation to be performed.
		operationArgs - Specific arguments of every operation.
		inputDataFormat - Format of the input data.
		outputDataFormat - Format of the output data.
		receiveTimeout - Maximum time in seconds to wait the response from LinkarSERVER. A value less or equal to 0, wait for response indefinitely.
	
	Returns:
		Complex string with the result of the operation.

	Examples:
		See <DirectFunctions.c> for examples.
		
*/
DllEntry char* LkExecuteDirectOperation(char** error, const char* const credentialOptions, uint8_t operationCode, const char* const operationArgs, uint8_t inputDataFormat, uint8_t outputDataFormat, uint32_t receiveTimeout);

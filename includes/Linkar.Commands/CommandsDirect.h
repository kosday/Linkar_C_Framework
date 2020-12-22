/*
	File: DirectCommands.h
	Header file for <CommandsDirect.c>

	Prototype Functions:
	--- Code
	DllEntry char* LkSendCommand(char** error, const char* const credentialOptions, const char* const command, EnvelopeFormatTYPE commandFormat, uint32_t receiveTimeout)
	DllEntry char* LkSendJsonCommand(char** error, const char* const credentialOptions, const char* const command, uint32_t receiveTimeout);
	DllEntry char* LkSendXmlCommand(char** error, const char* const credentialOptions, const char* const command, uint32_t receiveTimeout);
	---
*/
#include "CompilerOptions.h"
#include "Types.h"

DllEntry char* LkSendCommand(char** error, const char* const credentialOptions, const char* const command, EnvelopeFormatTYPE commandFormat, uint32_t receiveTimeout);
DllEntry char* LkSendJsonCommand(char** error, const char* const credentialOptions, const char* const command, uint32_t receiveTimeout);
DllEntry char* LkSendXmlCommand(char** error, const char* const credentialOptions, const char* const command, uint32_t receiveTimeout);
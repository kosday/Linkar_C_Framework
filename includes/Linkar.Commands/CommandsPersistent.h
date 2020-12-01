/*
	File: PersistentCommands.h
	Header file for CommandsPersistentJSON.c and CommandsPersistentXML.c

	Prototype Functions:
	--- Code
	DllEntry char* LkLogin(char** error, char* credentialOptions, const char* const customVars, uint32_t receiveTimeout);
	DllEntry void LkLogout(char **error, char** connectionInfo, const char* const customVars, uint32_t receiveTimeout);
	DllEntry char* LkSendCommand(char** error, char** connectionInfo, const char* const command, EnvelopeFormatTYPE commandFormat, uint32_t receiveTimeout)
	DllEntry char* LkSendJsonCommand(char** error, char** connectionInfo, const char* const command, uint32_t receiveTimeout);
	DllEntry char* LkSendXmlCommand(char** error, char** connectionInfo, const char* const command, uint32_t receiveTimeout);
	---
*/
#include "CompilerOptions.h"
#include "Types.h"
#include "LinkarStrings.h"
#include "LinkarStringsHelper.h"

DllEntry char* LkLogin(char** error, char* credentialOptions, const char* const customVars, uint32_t receiveTimeout);
DllEntry void LkLogout(char **error, char** connectionInfo, const char* const customVars, uint32_t receiveTimeout);
DllEntry char* LkSendCommand(char** error, char** connectionInfo, const char* const command, EnvelopeFormatTYPE commandFormat, uint32_t receiveTimeout);
DllEntry char* LkSendJsonCommand(char** error, char** connectionInfo, const char* const command, uint32_t receiveTimeout);
DllEntry char* LkSendXmlCommand(char** error, char** connectionInfo, const char* const command, uint32_t receiveTimeout);

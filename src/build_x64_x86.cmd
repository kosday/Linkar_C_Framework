@echo off
cls
echo IMPORTANT: You must execute this script from "x64 Native Tools Command Prompt for VS 2019"
echo to build 64 bits libraries or "x86 Native Tools Command Prompt for VS 2019" to
echo build 32 bits libraries.
echo.
if "%VSCMD_ARG_TGT_ARCH%"=="x64" goto RUN_X64
if "%VSCMD_ARG_TGT_ARCH%"=="x86" goto RUN_X86
echo NO detected VSCMD_ARG_TGT_ARCH environment variable. Are you sure you are runing this script under
echo "x64 Native Tools Command Prompt for VS 2019" or "x86 Native Tools Command Prompt for VS 2019" ?
pause
goto END

:RUN_X64
echo Running under "x64 Native Tools Command Prompt for VS 2019"
goto START

:RUN_X86
echo Running under "x86 Native Tools Command Prompt for VS 2019"
goto START

:START
set STOP=N

if "%1%"=="/P" set STOP=Y
if "%1%"=="/p" set STOP=Y

rem Output directory for compiled libraries
set BIN_DIR=..\..\bin\
set BIN_DIR_DLL=%BIN_DIR%DLL\%VSCMD_ARG_TGT_ARCH%\
set BIN_DIR_LIB=%BIN_DIR%LIB\%VSCMD_ARG_TGT_ARCH%\

set COMPILER_OPTIONS_STATIC_LIB=/c /I ..\..\includes /D__LK_STATIC_LIB__ /D__LK_EXPORT__
set COMPILER_OPTIONS_DYNAMIC_LIB=/c /I ..\..\includes /LD /D__LK_DYNAMIC_LIB__ /D__LK_EXPORT__

rem Linkar.Strings.Helper Libraries
cd Linkar.Strings.Helper

rem Linkar.Strings.Helper Static Library
echo.
echo *** Linkar.Strings.Helper Static Library
CL %COMPILER_OPTIONS_STATIC_LIB% LinkarStringsHelper.c /Fo"LinkarStringsHelper_st.obj"
LIB LinkarStringsHelper_st.obj /OUT:%BIN_DIR_LIB%Linkar.Strings.Helper.lib

rem Linkar.Strings.Helper Dynamic Library
echo.
echo *** Linkar.Strings.Helper Dynamic Library
CL %COMPILER_OPTIONS_DYNAMIC_LIB% LinkarStringsHelper.c /Fo"LinkarStringsHelper_dy.obj"
LINK /DLL /MAP LinkarStringsHelper_dy.obj /OUT:%BIN_DIR_DLL%Linkar.Strings.Helper.dll

del %BIN_DIR_DLL%Linkar.Strings.Helper.map
del %BIN_DIR_DLL%Linkar.Strings.Helper.exp
cd ..

if %STOP%==Y pause & cls

rem Linkar.Strings Libraries
cd Linkar.Strings

rem Linkar.Strings Static Library
echo.
echo *** Linkar.Strings Static Library
CL %COMPILER_OPTIONS_STATIC_LIB% LinkarStrings.c /Fo"LinkarStrings_st.obj"
LIB %BIN_DIR_LIB%Linkar.Strings.Helper.lib LinkarStrings_st.obj /OUT:%BIN_DIR_LIB%Linkar.Strings.lib

rem Linkar.Strings Dynamic Library
echo.
echo *** Linkar.Strings Dynamic Library
CL %COMPILER_OPTIONS_DYNAMIC_LIB% LinkarStrings.c /Fo"LinkarStrings_dy.obj"
LINK /DLL /MAP %BIN_DIR_DLL%Linkar.Strings.Helper.lib LinkarStrings_dy.obj /OUT:%BIN_DIR_DLL%Linkar.Strings.dll

del %BIN_DIR_DLL%Linkar.Strings.map
del %BIN_DIR_DLL%Linkar.Strings.exp
cd ..

if %STOP%==Y pause & cls

rem Linkar.Functions Libraries
cd Linkar.Functions

rem Linkar.Functions Static Library
echo.
echo *** Linkar.Functions Static Library
CL %COMPILER_OPTIONS_STATIC_LIB% MvOperations.c /Fo"MvOperations_st.obj"
CL %COMPILER_OPTIONS_STATIC_LIB% OperationOptions.c /Fo"OperationOptions_st.obj"
CL %COMPILER_OPTIONS_STATIC_LIB% OperationArguments.c /Fo"OperationArguments_st.obj"
CL %COMPILER_OPTIONS_STATIC_LIB% ReleaseMemory.c /Fo"ReleaseMemory_st.obj"
LIB %BIN_DIR_LIB%Linkar.Strings.Helper.lib MvOperations_st.obj OperationOptions_st.obj OperationArguments_st.obj ReleaseMemory_st.obj /OUT:%BIN_DIR_LIB%Linkar.Functions.lib

rem Linkar.Functions Dynamic Library
echo.
echo *** Linkar.Functions Dynamic Library
CL %COMPILER_OPTIONS_DYNAMIC_LIB% MvOperations.c /Fo"MvOperations_dy.obj"
CL %COMPILER_OPTIONS_DYNAMIC_LIB% OperationOptions.c /Fo"OperationOptions_dy.obj"
CL %COMPILER_OPTIONS_DYNAMIC_LIB% OperationArguments.c /Fo"OperationArguments_dy.obj"
CL %COMPILER_OPTIONS_DYNAMIC_LIB% ReleaseMemory.c /Fo"ReleaseMemory_dy.obj"
LINK /DLL /MAP %BIN_DIR_DLL%Linkar.Strings.Helper.lib MvOperations_dy.obj OperationOptions_dy.obj OperationArguments_dy.obj ReleaseMemory_dy.obj /OUT:%BIN_DIR_DLL%Linkar.Functions.dll

del %BIN_DIR_DLL%Linkar.Functions.map
del %BIN_DIR_DLL%Linkar.Functions.exp
cd ..

if %STOP%==Y pause & cls

rem Linkar.Functions.Direct Libraries
cd Linkar.Functions.Direct

rem Linkar.Functions.Direct Static Library
echo.
echo *** Linkar.Functions.Direct Static Library
CL %COMPILER_OPTIONS_STATIC_LIB% FunctionsDirect.c /Fo"DirectFunctions_st.obj"
LIB %BIN_DIR_LIB%Linkar.lib %BIN_DIR_LIB%Linkar.Functions.lib DirectFunctions_st.obj /OUT:%BIN_DIR_LIB%Linkar.Functions.Direct.lib

rem Linkar.Functions.Direct Dynamic Library
echo.
echo *** Linkar.Functions.Direct Dynamic Library
CL %COMPILER_OPTIONS_DYNAMIC_LIB% FunctionsDirect.c /Fo"DirectFunctions_dy.obj"
LINK /DLL /MAP %BIN_DIR_DLL%Linkar.lib %BIN_DIR_DLL%Linkar.Functions.lib DirectFunctions_dy.obj /OUT:%BIN_DIR_DLL%Linkar.Functions.Direct.dll

del %BIN_DIR_DLL%Linkar.Functions.Direct.map
del %BIN_DIR_DLL%Linkar.Functions.Direct.exp
cd ..

if %STOP%==Y pause & cls

rem Linkar.Functions.Direct.MV Libraries
cd Linkar.Functions.Direct.MV

rem Linkar.Functions.Direct.MV Static Library
echo.
echo *** Linkar.Functions.Direct.MV Static Library
CL %COMPILER_OPTIONS_STATIC_LIB% FunctionsDirectMV.c /Fo"DirectFunctionsMV_st.obj"
LIB %BIN_DIR_LIB%Linkar.Functions.Direct.lib DirectFunctionsMV_st.obj /OUT:%BIN_DIR_LIB%Linkar.Functions.Direct.MV.lib

rem Linkar.Functions.Direct.MV Dynamic Library
echo.
echo *** Linkar.Functions.Direct.MV Dynamic Library
CL %COMPILER_OPTIONS_DYNAMIC_LIB% FunctionsDirectMV.c /Fo"DirectFunctionsMV_dy.obj"
LINK /DLL /MAP %BIN_DIR_DLL%Linkar.Functions.Direct.lib DirectFunctionsMV_dy.obj /OUT:%BIN_DIR_DLL%Linkar.Functions.Direct.MV.dll

del %BIN_DIR_DLL%Linkar.Functions.Direct.MV.map
del %BIN_DIR_DLL%Linkar.Functions.Direct.MV.exp
cd ..

if %STOP%==Y pause & cls

rem Linkar.Functions.Direct.JSON Libraries
cd Linkar.Functions.Direct.JSON

rem Linkar.Functions.Direct.JSON Static Library
echo.
echo *** Linkar.Functions.Direct.JSON Static Library
CL %COMPILER_OPTIONS_STATIC_LIB% FunctionsDirectJSON.c /Fo"DirectFunctionsJSON_st.obj"
LIB %BIN_DIR_LIB%Linkar.Functions.Direct.lib DirectFunctionsJSON_st.obj /OUT:%BIN_DIR_LIB%Linkar.Functions.Direct.JSON.lib

rem Linkar.Functions.Direct.JSON Dynamic Library
echo.
echo *** Linkar.Functions.Direct.JSON Dynamic Library
CL %COMPILER_OPTIONS_DYNAMIC_LIB% FunctionsDirectJSON.c /Fo"DirectFunctionsJSON_dy.obj"
LINK /DLL /MAP %BIN_DIR_DLL%Linkar.Functions.Direct.lib DirectFunctionsJSON_dy.obj /OUT:%BIN_DIR_DLL%Linkar.Functions.Direct.JSON.dll

del %BIN_DIR_DLL%Linkar.Functions.Direct.JSON.map
del %BIN_DIR_DLL%Linkar.Functions.Direct.JSON.exp
cd ..

if %STOP%==Y pause & cls

rem Linkar.Functions.Direct.XML Libraries
cd Linkar.Functions.Direct.XML

rem Linkar.Functions.Direct.XML Static Library
echo.
echo *** Linkar.Functions.Direct.XML Static Library
CL %COMPILER_OPTIONS_STATIC_LIB% FunctionsDirectXML.c /Fo"DirectFunctionsXML_st.obj"
LIB %BIN_DIR_LIB%Linkar.Functions.Direct.lib DirectFunctionsXML_st.obj /OUT:%BIN_DIR_LIB%Linkar.Functions.Direct.XML.lib

rem Linkar.Functions.Direct.XML Dynamic Library
echo.
echo *** Linkar.Functions.Direct.XML Dynamic Library
CL %COMPILER_OPTIONS_DYNAMIC_LIB% FunctionsDirectXML.c /Fo"DirectFunctionsXML_dy.obj"
LINK /DLL /MAP %BIN_DIR_DLL%Linkar.Functions.Direct.lib DirectFunctionsXML_dy.obj /OUT:%BIN_DIR_DLL%Linkar.Functions.Direct.XML.dll

del %BIN_DIR_DLL%Linkar.Functions.Direct.XML.map
del %BIN_DIR_DLL%Linkar.Functions.Direct.XML.exp
cd ..

if %STOP%==Y pause & cls

rem Linkar.Functions.Direct.TABLE Libraries
cd Linkar.Functions.Direct.TABLE

rem Linkar.Functions.Direct.TABLE Static Library
echo.
echo *** Linkar.Functions.Direct.TABLE Static Library
CL %COMPILER_OPTIONS_STATIC_LIB% FunctionsDirectTABLE.c /Fo"DirectFunctionsTABLE_st.obj"
LIB %BIN_DIR_LIB%Linkar.Functions.Direct.lib DirectFunctionsTABLE_st.obj /OUT:%BIN_DIR_LIB%Linkar.Functions.Direct.TABLE.lib

rem Linkar.Functions.Direct.TABLE Dynamic Library
echo.
echo *** Linkar.Functions.Direct.TABLE Dynamic Library
CL %COMPILER_OPTIONS_DYNAMIC_LIB% FunctionsDirectTABLE.c /Fo"DirectFunctionsTABLE_dy.obj"
LINK /DLL /MAP %BIN_DIR_DLL%Linkar.Functions.Direct.lib DirectFunctionsTABLE_dy.obj /OUT:%BIN_DIR_DLL%Linkar.Functions.Direct.TABLE.dll

del %BIN_DIR_DLL%Linkar.Functions.Direct.TABLE.map
del %BIN_DIR_DLL%Linkar.Functions.Direct.TABLE.exp
cd ..

if %STOP%==Y pause & cls

rem Linkar.Commands.Direct Libraries
cd Linkar.Commands

rem Linkar.Commands.Direct Static Library
echo.
echo *** Linkar.Commands.Direct Static Library
CL /I..\..\includes\Linkar.Commands %COMPILER_OPTIONS_STATIC_LIB% OperationArguments.c /Fo"OperationArguments_st.obj"
CL /I..\..\includes\Linkar.Commands %COMPILER_OPTIONS_STATIC_LIB% CommandsDirect.c /Fo"DirectCommands_st.obj"
LIB %BIN_DIR_LIB%Linkar.lib %BIN_DIR_LIB%Linkar.Strings.Helper.lib OperationArguments_st.obj DirectCommands_st.obj /OUT:%BIN_DIR_LIB%Linkar.Commands.Direct.lib

rem Linkar.Commands.Direct Dynamic Library
echo.
echo *** Linkar.Commands.Direct Dynamic Library
CL /I..\..\includes\Linkar.Commands %COMPILER_OPTIONS_DYNAMIC_LIB% OperationArguments.c /Fo"OperationArguments_dy.obj"
CL /I..\..\includes\Linkar.Commands %COMPILER_OPTIONS_DYNAMIC_LIB% CommandsDirect.c /Fo"DirectCommands_dy.obj"
LINK /DLL /MAP %BIN_DIR_DLL%Linkar.lib OperationArguments_dy.obj DirectCommands_dy.obj /OUT:%BIN_DIR_DLL%Linkar.Commands.Direct.dll

del %BIN_DIR_DLL%Linkar.Commands.Direct.map
del %BIN_DIR_DLL%Linkar.Commands.Direct.exp
cd ..

if %STOP%==Y pause & cls

rem Linkar.Functions.Persistent Libraries
cd Linkar.Functions.Persistent

rem Linkar.Functions.Persistent Static Library
echo.
echo *** Linkar.Functions.Persistent Static Library
CL %COMPILER_OPTIONS_STATIC_LIB% FunctionsPersistent.c /Fo"PersistentFunctions_st.obj"
LIB %BIN_DIR_LIB%Linkar.lib %BIN_DIR_LIB%Linkar.Functions.lib PersistentFunctions_st.obj /OUT:%BIN_DIR_LIB%Linkar.Functions.Persistent.lib

rem Linkar.Functions.Persistent Dynamic Library
echo.
echo *** Linkar.Functions.Persistent Dynamic Library
CL %COMPILER_OPTIONS_DYNAMIC_LIB% FunctionsPersistent.c /Fo"PersistentFunctions_dy.obj"
LINK /DLL /MAP %BIN_DIR_DLL%Linkar.lib %BIN_DIR_DLL%Linkar.Functions.lib %BIN_DIR_DLL%Linkar.Strings.Helper.lib PersistentFunctions_dy.obj /OUT:%BIN_DIR_DLL%Linkar.Functions.Persistent.dll

del %BIN_DIR_DLL%Linkar.Functions.Persistent.map
del %BIN_DIR_DLL%Linkar.Functions.Persistent.exp
cd ..

if %STOP%==Y pause & cls

rem Linkar.Functions.Persistent.MV Libraries
cd Linkar.Functions.Persistent.MV

rem Linkar.Functions.Persistent.MV Static Library
echo.
echo *** Linkar.Functions.Persistent.MV Static Library
CL %COMPILER_OPTIONS_STATIC_LIB% FunctionsPersistentMV.c /Fo"PersistentFunctionsMV_st.obj"
LIB %BIN_DIR_LIB%Linkar.Functions.Persistent.lib PersistentFunctionsMV_st.obj /OUT:%BIN_DIR_LIB%Linkar.Functions.Persistent.MV.lib

rem Linkar.Functions.Persistent.MV Dynamic Library
echo.
echo *** Linkar.Functions.Persistent.MV Dynamic Library
CL %COMPILER_OPTIONS_DYNAMIC_LIB% FunctionsPersistentMV.c /Fo"PersistentFunctionsMV_dy.obj"
LINK /DLL /MAP %BIN_DIR_DLL%Linkar.lib %BIN_DIR_DLL%Linkar.Functions.Persistent.lib PersistentFunctionsMV_dy.obj /OUT:%BIN_DIR_DLL%Linkar.Functions.Persistent.MV.dll

del %BIN_DIR_DLL%Linkar.Functions.Persistent.MV.map
del %BIN_DIR_DLL%Linkar.Functions.Persistent.MV.exp
cd ..

if %STOP%==Y pause & cls

rem Linkar.Functions.Persistent.JSON Libraries
cd Linkar.Functions.Persistent.JSON

rem Linkar.Functions.Persistent.JSON Static Library
echo.
echo *** Linkar.Functions.Persistent.JSON Static Library
CL %COMPILER_OPTIONS_STATIC_LIB% FunctionsPersistentJSON.c /Fo"PersistentFunctionsJSON_st.obj"
LIB %BIN_DIR_LIB%Linkar.lib PersistentFunctionsJSON_st.obj /OUT:%BIN_DIR_LIB%Linkar.Functions.Persistent.JSON.lib

rem Linkar.Functions.Persistent.JSON Dynamic Library
echo.
echo *** Linkar.Functions.Persistent.JSON Dynamic Library
CL %COMPILER_OPTIONS_DYNAMIC_LIB% FunctionsPersistentJSON.c /Fo"PersistentFunctionsJSON_dy.obj"
LINK /DLL /MAP %BIN_DIR_DLL%Linkar.Functions.Persistent.lib PersistentFunctionsJSON_dy.obj /OUT:%BIN_DIR_DLL%Linkar.Functions.Persistent.JSON.dll

del %BIN_DIR_DLL%Linkar.Functions.Persistent.JSON.map
del %BIN_DIR_DLL%Linkar.Functions.Persistent.JSON.exp
cd ..

if %STOP%==Y pause & cls

rem Linkar.Functions.Persistent.XML Libraries
cd Linkar.Functions.Persistent.XML

rem Linkar.Functions.Persistent.XML Static Library
echo.
echo *** Linkar.Functions.Persistent.XML Static Library
CL %COMPILER_OPTIONS_STATIC_LIB% FunctionsPersistentXML.c /Fo"PersistentFunctionsXML_st.obj"
LIB %BIN_DIR_LIB%Linkar.lib PersistentFunctionsXML_st.obj /OUT:%BIN_DIR_LIB%Linkar.Functions.Persistent.XML.lib

rem Linkar.Functions.Persistent.XML Dynamic Library
echo.
echo *** Linkar.Functions.Persistent.XML Dynamic Library
CL %COMPILER_OPTIONS_DYNAMIC_LIB% FunctionsPersistentXML.c /Fo"PersistentFunctionsXML_dy.obj"
LINK /DLL /MAP %BIN_DIR_DLL%Linkar.Functions.Persistent.lib PersistentFunctionsXML_dy.obj /OUT:%BIN_DIR_DLL%Linkar.Functions.Persistent.XML.dll

del %BIN_DIR_DLL%Linkar.Functions.Persistent.XML.map
del %BIN_DIR_DLL%Linkar.Functions.Persistent.XML.exp
cd ..

if %STOP%==Y pause & cls

rem Linkar.Functions.Persistent.TABLE Libraries
cd Linkar.Functions.Persistent.TABLE

rem Linkar.Functions.Persistent.TABLE Static Library
echo.
echo *** Linkar.Functions.Persistent.TABLE Static Library
CL %COMPILER_OPTIONS_STATIC_LIB% FunctionsPersistentTABLE.c /Fo"PersistentFunctionsTABLE_st.obj"
LIB %BIN_DIR_LIB%Linkar.lib PersistentFunctionsTABLE_st.obj /OUT:%BIN_DIR_LIB%Linkar.Functions.Persistent.TABLE.lib

rem Linkar.Functions.Persistent.TABLE Dynamic Library
echo.
echo *** Linkar.Functions.Persistent.TABLE Dynamic Library
CL %COMPILER_OPTIONS_DYNAMIC_LIB% FunctionsPersistentTABLE.c /Fo"PersistentFunctionsTABLE_dy.obj"
LINK /DLL /MAP %BIN_DIR_DLL%Linkar.Functions.Persistent.lib PersistentFunctionsTABLE_dy.obj /OUT:%BIN_DIR_DLL%Linkar.Functions.Persistent.TABLE.dll

del %BIN_DIR_DLL%Linkar.Functions.Persistent.TABLE.map
del %BIN_DIR_DLL%Linkar.Functions.Persistent.TABLE.exp
cd ..

if %STOP%==Y pause & cls

rem Linkar.Commands.Persistent Libraries
cd Linkar.Commands

rem Linkar.Commands.Persistent Static Library
echo.
echo *** Linkar.Commands.Persistent Static Library
CL %COMPILER_OPTIONS_STATIC_LIB% ..\Linkar.Strings.Helper\LinkarStringsHelper.c /Fo".\LinkarStringsHelper_st.obj"
CL /I..\..\includes\Linkar.Commands %COMPILER_OPTIONS_STATIC_LIB% OperationArguments.c /Fo"OperationArguments_st.obj"
CL /I..\..\includes\Linkar.Commands %COMPILER_OPTIONS_STATIC_LIB% CommandsPersistent.c /Fo"PersistentCommands_st.obj"
LIB %BIN_DIR_LIB%Linkar.lib LinkarStringsHelper_st.obj OperationArguments_st.obj PersistentCommands_st.obj /OUT:%BIN_DIR_LIB%Linkar.Commands.Persistent.lib

rem Linkar.Commands.Persistent Dynamic Library
echo.
echo *** Linkar.Commands.Persistent Dynamic Library
CL %COMPILER_OPTIONS_DYNAMIC_LIB% ..\Linkar.Strings.Helper\LinkarStringsHelper.c /Fo".\LinkarStringsHelper_dy.obj"
CL /I..\..\includes\Linkar.Commands %COMPILER_OPTIONS_DYNAMIC_LIB% OperationArguments.c /Fo"OperationArguments_dy.obj"
CL /I..\..\includes\Linkar.Commands %COMPILER_OPTIONS_DYNAMIC_LIB% CommandsPersistent.c /Fo"PersistentCommands_dy.obj"
LINK /DLL /MAP %BIN_DIR_DLL%Linkar.lib LinkarStringsHelper_dy.obj OperationArguments_dy.obj PersistentCommands_dy.obj /OUT:%BIN_DIR_DLL%Linkar.Commands.Persistent.dll

del %BIN_DIR_DLL%Linkar.Commands.Persistent.map
del %BIN_DIR_DLL%Linkar.Commands.Persistent.exp
cd ..

if %STOP%==Y pause & cls

:END

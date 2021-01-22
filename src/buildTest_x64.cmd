@echo off
REM IMPORTANT: You must execute this script from "x64 Native Tools Command Prompt for VS 2019"

cls

set STOP=N
if "%1%"=="/P" set STOP=Y
if "%1%"=="/p" set STOP=Y

cd TEST

set BIN_DIR=..\..\bin\
set BIN_DIR_DLL=%BIN_DIR%DLL\x64\
set BIN_DIR_LIB=%BIN_DIR%LIB\x64\

set COMPILER_OPTIONS_STATIC_LIB=/c /I ..\includes /D__LK_STATIC_LIB__ /D__LK_EXPORT__
set COMPILER_OPTIONS_DYNAMIC_LIB=/c /I ..\includes /LD /D__LK_DYNAMIC_LIB__ /D__LK_EXPORT__

echo *** Test1-DirectBase Static and Dynamic
echo.
REM Test1-DirectBase program with Static Libraries
CL Test1-DirectBase.c /I..\..\includes /D__LK_STATIC_LIB__ %BIN_DIR_LIB%Linkar.Functions.Direct.lib /Fe%BIN_DIR_LIB%Test1-DirectBase.exe

REM Test1-DirectBase program with Dynamic Libraries
REM ****CL Test1-DirectBase.c /I..\..\includes /D__LK_DYNAMIC_LIB__ %BIN_DIR_DLL%Linkar.Functions.Direct.lib %BIN_DIR_DLL%Linkar.lib %BIN_DIR_DLL%Linkar.Strings.Helper.lib %BIN_DIR_DLL%Linkar.Strings.lib /Fe%BIN_DIR_DLL%Test1-DirectBase.exe
CL Test1-DirectBase.c /I..\..\includes /D__LK_DYNAMIC_LIB__ %BIN_DIR_DLL%Linkar.Functions.Direct.lib %BIN_DIR_DLL%Linkar.lib %BIN_DIR_DLL%Linkar.Strings.lib /Fe%BIN_DIR_DLL%Test1-DirectBase.exe


if %STOP%==Y pause & cls

echo *** Test2-DirectMV Static and Dynamic
echo.
REM Test2-DirectMV program with Static Libraries
CL Test2-DirectMV.c /I..\..\includes /D__LK_STATIC_LIB__ %BIN_DIR_LIB%Linkar.Functions.Direct.MV.lib %BIN_DIR_DLL%Linkar.Strings.lib /Fe%BIN_DIR_LIB%Test2-DirectMV.exe
REM Test2-DirectMV program with Dynamic Libraries
REM ****CL Test2-DirectMV.c /I..\..\includes /D__LK_DYNAMIC_LIB__ %BIN_DIR_DLL%Linkar.Functions.Direct.MV.lib %BIN_DIR_DLL%Linkar.Functions.lib %BIN_DIR_DLL%Linkar.lib %BIN_DIR_DLL%Linkar.Strings.lib %BIN_DIR_DLL%Linkar.Strings.Helper.lib /Fe%BIN_DIR_DLL%Test2-DirectMV.exe
CL Test2-DirectMV.c /I..\..\includes /D__LK_DYNAMIC_LIB__ %BIN_DIR_DLL%Linkar.Functions.Direct.MV.lib %BIN_DIR_DLL%Linkar.Functions.lib %BIN_DIR_DLL%Linkar.lib %BIN_DIR_DLL%Linkar.Strings.lib /Fe%BIN_DIR_DLL%Test2-DirectMV.exe

if %STOP%==Y pause & cls

echo *** Test3-DirectXML Static and Dynamic
echo.
REM Test3-DirectXML program with Static Libraries
CL Test3-DirectXML.c /I..\..\includes /D__LK_STATIC_LIB__ %BIN_DIR_LIB%Linkar.Functions.Direct.XML.lib /Fe%BIN_DIR_LIB%Test3-DirectXML.exe
REM Test3-DirectXML program with Dynamic Libraries
CL Test3-DirectXML.c /I..\..\includes /D__LK_DYNAMIC_LIB__ %BIN_DIR_DLL%Linkar.Functions.Direct.XML.lib %BIN_DIR_DLL%Linkar.Functions.lib %BIN_DIR_DLL%Linkar.lib /Fe%BIN_DIR_DLL%Test3-DirectXML.exe

if %STOP%==Y pause & cls

echo *** Test4-DirectJSON Static and Dynamic
echo.
REM Test4-DirectJSON program with Static Libraries
CL Test4-DirectJSON.c /I..\..\includes /D__LK_STATIC_LIB__ %BIN_DIR_LIB%Linkar.Functions.Direct.JSON.lib /Fe%BIN_DIR_LIB%Test4-DirectJSON.exe
REM Test4-DirectJSON program with Dynamic Libraries
CL Test4-DirectJSON.c /I..\..\includes /D__LK_DYNAMIC_LIB__ %BIN_DIR_DLL%Linkar.Functions.Direct.JSON.lib %BIN_DIR_DLL%Linkar.Functions.lib %BIN_DIR_DLL%Linkar.lib /Fe%BIN_DIR_DLL%Test4-DirectJSON.exe

if %STOP%==Y pause & cls

echo *** Test5-DirectCmdJSON Static and Dynamic
echo.
REM Test5-DirectCmdJSON program with Static Libraries
CL Test5-DirectCmdJSON.c /I ..\..\includes\Linkar.Commands /I..\..\includes /D__LK_STATIC_LIB__ %BIN_DIR_LIB%Linkar.Commands.Direct.lib /Fe%BIN_DIR_LIB%Test5-DirectCmdJSON.exe
REM Test5-DirectCmdJSON program with Dynamic Libraries
CL Test5-DirectCmdJSON.c /I ..\..\includes\Linkar.Commands /I..\..\includes /D__LK_DYNAMIC_LIB__ %BIN_DIR_DLL%Linkar.Commands.Direct.lib %BIN_DIR_DLL%Linkar.lib /Fe%BIN_DIR_DLL%Test5-DirectCmdJSON.exe

if %STOP%==Y pause & cls

echo *** Test5-DirectCmdXML Static and Dynamic
echo.
REM Test5-DirectCmdXML program with Static Libraries
CL Test5-DirectCmdXML.c /I ..\..\includes\Linkar.Commands /I..\..\includes /D__LK_STATIC_LIB__ %BIN_DIR_LIB%Linkar.Commands.Direct.lib /Fe%BIN_DIR_LIB%Test5-DirectCmdXML.exe
REM Test5-DirectCmdXML program with Dynamic Libraries
CL Test5-DirectCmdXML.c /I ..\..\includes\Linkar.Commands /I..\..\includes /D__LK_DYNAMIC_LIB__ %BIN_DIR_DLL%Linkar.Commands.Direct.lib %BIN_DIR_DLL%Linkar.lib /Fe%BIN_DIR_DLL%Test5-DirectCmdXML.exe

if %STOP%==Y pause & cls

echo *** Test1-PersistentBase Static and Dynamic
echo.
REM Test1-PersistentBase program with Static Libraries
CL Test1-PersistentBase.c /I..\..\includes /D__LK_STATIC_LIB__ %BIN_DIR_LIB%Linkar.Functions.Persistent.lib %BIN_DIR_LIB%\Linkar.Strings.lib /Fe%BIN_DIR_LIB%Test1-PersistentBase.exe
REM Test1-PersistentBase program with Dynamic Libraries
CL Test1-PersistentBase.c /I..\..\includes /D__LK_DYNAMIC_LIB__ %BIN_DIR_DLL%Linkar.Functions.Persistent.lib %BIN_DIR_DLL%Linkar.lib %BIN_DIR_DLL%Linkar.Strings.lib /Fe%BIN_DIR_DLL%Test1-PersistentBase.exe

if %STOP%==Y pause & cls

echo *** Test2-PersistentMV Static and Dynamic
echo.
REM Test2-PersistentMV program with Static Libraries
CL Test2-PersistentMV.c /I..\..\includes /D__LK_STATIC_LIB__ %BIN_DIR_LIB%Linkar.Functions.lib %BIN_DIR_LIB%Linkar.Functions.Persistent.MV.lib %BIN_DIR_LIB%\Linkar.Strings.lib /Fe%BIN_DIR_LIB%Test2-PersistentMV.exe
REM Test2-PersistentMV program with Dynamic Libraries
REM ****CL Test2-PersistentMV.c /I..\..\includes /D__LK_DYNAMIC_LIB__ %BIN_DIR_LIB%Linkar.Functions.lib %BIN_DIR_DLL%Linkar.Functions.Persistent.MV.lib %BIN_DIR_DLL%Linkar.Functions.Persistent.lib %BIN_DIR_DLL%Linkar.Functions.lib %BIN_DIR_DLL%Linkar.lib %BIN_DIR_DLL%Linkar.Strings.lib %BIN_DIR_DLL%Linkar.Strings.Helper.lib /Fe%BIN_DIR_DLL%Test2-PersistentMV.exe
CL Test2-PersistentMV.c /I..\..\includes /D__LK_DYNAMIC_LIB__ %BIN_DIR_LIB%Linkar.Functions.lib %BIN_DIR_DLL%Linkar.Functions.Persistent.MV.lib %BIN_DIR_DLL%Linkar.Functions.Persistent.lib %BIN_DIR_DLL%Linkar.Functions.lib %BIN_DIR_DLL%Linkar.lib %BIN_DIR_DLL%Linkar.Strings.lib /Fe%BIN_DIR_DLL%Test2-PersistentMV.exe

if %STOP%==Y pause & cls

echo *** Test5-PersistentCmdJSON Static and Dynamic
echo.
REM Test5-PersistentCmdJSON program with Static Libraries
CL Test5-PersistentCmdJSON.c /I ..\..\includes\Linkar.Commands /I..\..\includes /D__LK_STATIC_LIB__ %BIN_DIR_LIB%Linkar.Commands.Persistent.lib %BIN_DIR_LIB%Linkar.Strings.lib /Fe%BIN_DIR_LIB%Test5-PersistentCmdJSON.exe
REM Test5-PersistentCmdJSON program with Dynamic Libraries
CL Test5-PersistentCmdJSON.c /I ..\..\includes\Linkar.Commands /I..\..\includes /D__LK_DYNAMIC_LIB__ %BIN_DIR_DLL%Linkar.Commands.Persistent.lib %BIN_DIR_DLL%Linkar.lib /Fe%BIN_DIR_DLL%Test5-PersistentCmdJSON.exe

if %STOP%==Y pause & cls

echo *** Test5-PersistentCmdXML Static and Dynamic
echo.
REM Test5-PersistentCmdXML program with Static Libraries
CL Test5-PersistentCmdXML.c /I ..\..\includes\Linkar.Commands /I..\..\includes /D__LK_STATIC_LIB__ %BIN_DIR_LIB%Linkar.Commands.Persistent.lib %BIN_DIR_LIB%Linkar.Strings.lib /Fe%BIN_DIR_LIB%Test5-PersistentCmdXML.exe
REM Test5-PersistentCmdXML program with Dynamic Libraries
CL Test5-PersistentCmdXML.c /I ..\..\includes\Linkar.Commands /I..\..\includes /D__LK_DYNAMIC_LIB__ %BIN_DIR_DLL%Linkar.Commands.Persistent.lib %BIN_DIR_DLL%Linkar.lib /Fe%BIN_DIR_DLL%Test5-PersistentCmdXML.exe

:FIN
cd ..

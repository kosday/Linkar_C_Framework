#!/bin/bash
clear
echo "This script will build x64 and x86 C Linkar Framework Library"
echo ""

STOP=N
if [ "$1" == "-p" ] || [ "$1" == "-P" ] ; then
	STOP=Y
fi

BIN_DIR=../../bin
BIN_DIR_SO_x64=$BIN_DIR/linux.so/x64
BIN_DIR_A_x64=$BIN_DIR/linux.a/x64
BIN_DIR_SO_x86=$BIN_DIR/linux.so/x86
BIN_DIR_A_x86=$BIN_DIR/linux.a/x86

COMPILER_OPTIONS_STATIC_LIB_x64="-c -D__LK_STATIC_LIB__ -D__LK_EXPORT__ -I../includes -fPIC -Bstatic -lcrypto"
COMPILER_OPTIONS_STATIC_LIB_x86="-c -D__LK_STATIC_LIB__ -D__LK_EXPORT__ -I../includes -fPIC -m32 -Bstatic -lcrypto32"
COMPILER_OPTIONS_DYNAMIC_LIB_x64="-D__LK_DYNAMIC_LIB__ -D__LK_EXPORT__ -I../includes -fPIC -lcrypto"
COMPILER_OPTIONS_DYNAMIC_LIB_x86="-D__LK_DYNAMIC_LIB__ -D__LK_EXPORT__ -I../includes -m32 -fPIC -lcrypto32"


##################################################################################################
# STATIC LIBRARIES
##################################################################################################
echo "STATIC LIBRARIES"
echo "================"
echo ""
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Strings.Helper Static Libraries
#======================================
cd Linkar.Strings.Helper

echo "Compiling x64 Static LinkarStringsHelper.c"
cc $COMPILER_OPTIONS_STATIC_LIB_x64 -o LinkarStringsHelper.o LinkarStringsHelper.c
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.MV.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.JSON.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.XML.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.TABLE.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Commands.Direct.JSON.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Commands.Direct.XML.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.MV.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.JSON.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.XML.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.TABLE.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Commands.Persistent.JSON.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Commands.Persistent.XML.a LinkarStringsHelper.o

echo ""
echo "Compiling x86 Static LinkarStringsHelper.c"
cc $COMPILER_OPTIONS_STATIC_LIB_x86 -o LinkarStringsHelper.o LinkarStringsHelper.c
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.MV.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.JSON.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.XML.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.TABLE.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x86/libLinkar.Commands.Direct.JSON.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x86/libLinkar.Commands.Direct.XML.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.MV.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.JSON.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.XML.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.TABLE.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x86/libLinkar.Commands.Persistent.JSON.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x86/libLinkar.Commands.Persistent.XML.a LinkarStringsHelper.o

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Strings Static Libraries
#===============================
cd Linkar.Strings

echo "Compiling x64 Static LinkarStrings.c"
cc $COMPILER_OPTIONS_STATIC_LIB_x64 -o LinkarStrings.o LinkarStrings.c
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.MV.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.JSON.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.XML.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.TABLE.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.MV.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.JSON.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.XML.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.TABLE.a LinkarStrings.o 

echo ""
echo "Compiling x86 Static LinkarStrings.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o LinkarStrings.o LinkarStrings.c
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.MV.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.JSON.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.XML.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.TABLE.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.MV.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.JSON.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.XML.a LinkarStrings.o 
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.TABLE.a LinkarStrings.o 

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions Static Libraries
#=================================
cd Linkar.Functions

echo "Compiling x64 Static Functions (MvOperations.c)"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o MvOperations.o MvOperations.c
echo "Compiling x64 Static Functions (OperationOptions.c)"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o OperationOptions.o OperationOptions.c
echo "Compiling x64 Static Functions (OperationArguments.c)"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o OperationArguments.o OperationArguments.c
echo "Compiling x64 Static Functions (ReleaseMemory.c)"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o ReleaseMemory.o ReleaseMemory.c
##ld -relocatable MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o -o Functions.o
#ar rcs $BIN_DIR_A_x64/libLinkar.Functions.a MvOperations_x64.o OperationOptions_x64.o OperationArguments_x64.o ReleaseMemory_x64.o ../Linkar.Strings.Helper/LinkarStringsHelper_x64.o

ar rcs $BIN_DIR_A_x64/libLinkar.Functions.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.MV.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.JSON.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.XML.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.TABLE.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.MV.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.JSON.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.XML.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.TABLE.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o

echo ""
echo "Compiling x86 Static Functions (MvOperations.c)"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o MvOperations.o MvOperations.c
echo "Compiling x86 Static Functions (OperationOptions.c)"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o OperationOptions.o OperationOptions.c
echo "Compiling x86 Static Functions (OperationArguments.c)"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o OperationArguments.o OperationArguments.c
echo "Compiling x86 Static Functions (ReleaseMemory.c)"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o ReleaseMemory.o ReleaseMemory.c

####ld -relocatable -m elf32-i386 MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o -o Functions.o
####ld -relocatable -m elf32_x86_64 MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o -o Functions.o
####ld -relocatable -m elf_x86_64 MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o -o Functions.o
##ld -relocatable -m elf_i386 -MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o -o Functions.o
##ar rcs $BIN_DIR_A_x86/libLinkar.Functions.a MvOperations_x86.o OperationOptions_x86.o OperationArguments_x86.o ReleaseMemory_x86.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.MV.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.JSON.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.XML.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.TABLE.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.MV.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.JSON.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.XML.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.TABLE.a MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Direct Static Libraries
#========================================
cd Linkar.Functions.Direct

echo "Compiling x64 Static FunctionsDirect.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o FunctionsDirect.o FunctionsDirect.c
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.a FunctionsDirect.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.MV.a FunctionsDirect.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.JSON.a FunctionsDirect.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.XML.a FunctionsDirect.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.TABLE.a FunctionsDirect.o

echo ""
echo "Compiling x86 Static FunctionsDirect.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o FunctionsDirect.o FunctionsDirect.c
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.a FunctionsDirect.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.MV.a FunctionsDirect.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.JSON.a FunctionsDirect.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.XML.a FunctionsDirect.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.TABLE.a FunctionsDirect.o

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Direct.MV Static Libraries
#===========================================
cd Linkar.Functions.Direct.MV

echo "Compiling x64 Static FunctionsDirectMV.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o FunctionsDirectMV.o FunctionsDirectMV.c
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.MV.a FunctionsDirectMV.o

echo ""
echo "Compiling x86 Static FunctionsDirectMV.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o FunctionsDirectMV.o FunctionsDirectMV.c
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.MV.a FunctionsDirectMV.o 

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Direct.JSON Static Libraries
#=============================================
cd Linkar.Functions.Direct.JSON

echo "Compiling x64 Static FunctionsDirectJSON.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o FunctionsDirectJSON.o FunctionsDirectJSON.c
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.JSON.a FunctionsDirectJSON.o

echo ""
echo "Compiling x86 Static FunctionsDirectJSON.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o FunctionsDirectJSON.o FunctionsDirectJSON.c
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.JSON.a FunctionsDirectJSON.o

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Direct.XML Static Libraries
#============================================
cd Linkar.Functions.Direct.XML

echo "Compiling x64 Static FunctionsDirectXML.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o FunctionsDirectXML.o FunctionsDirectXML.c
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.XML.a FunctionsDirectXML.o 

echo ""
echo "Compiling x86 Static FunctionsDirectXML.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o FunctionsDirectXML.o FunctionsDirectXML.c
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.XML.a FunctionsDirectXML.o

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Direct.TABLE Static Libraries
#==============================================
cd Linkar.Functions.Direct.TABLE

echo "Compiling x64 Static FunctionsDirectTABLE.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o FunctionsDirectTABLE.o FunctionsDirectTABLE.c
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Direct.TABLE.a FunctionsDirectTABLE.o

echo ""
echo "Compiling x86 Static FunctionsDirectTABLE.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o FunctionsDirectTABLE.o FunctionsDirectTABLE.c
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Direct.TABLE.a FunctionsDirectTABLE.o

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Commands.Direct.JSON Static Libraries
#============================================
cd Linkar.Commands

echo "Compiling x64 Static CommandsDirectJSON.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o OperationArguments.o OperationArguments.c
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o CommandsDirectJSON.o CommandsDirectJSON.c
ar rcs $BIN_DIR_A_x64/libLinkar.Commands.Direct.JSON.a OperationArguments.o CommandsDirectJSON.o

echo ""
echo "Compiling x86 Static CommandsDirectJSON.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o OperationArguments.o OperationArguments.c
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o CommandsDirectJSON.o CommandsDirectJSON.c
ar rcs $BIN_DIR_A_x86/libLinkar.Commands.Direct.JSON.a OperationArguments.o CommandsDirectJSON.o

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Commands.Direct.XML Static Libraries                            
#===========================================
cd Linkar.Commands

echo "Compiling x64 Static CommandsDirectXML.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o OperationArguments.o OperationArguments.c
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o CommandsDirectXML.o CommandsDirectXML.c
ar rcs $BIN_DIR_A_x64/libLinkar.Commands.Direct.XML.a OperationArguments.o CommandsDirectXML.o

echo ""
echo "Compiling x86 Static DirectCommandsXML.a"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o OperationArguments.o OperationArguments.c
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o CommandsDirectXML.o CommandsDirectXML.c
ar rcs $BIN_DIR_A_x86/libLinkar.Commands.Direct.XML.a OperationArguments.o CommandsDirectXML.o

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Persistent Static Libraries
#============================================
cd Linkar.Functions.Persistent

echo "Compiling x64 Static FunctionsPersistent.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o FunctionsPersistent.o FunctionsPersistent.c
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.a FunctionsPersistent.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.MV.a FunctionsPersistent.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.JSON.a FunctionsPersistent.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.XML.a FunctionsPersistent.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.TABLE.a FunctionsPersistent.o

echo ""
echo "Compiling x86 Static FunctionsPersistent.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o FunctionsPersistent.o FunctionsPersistent.c
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.a FunctionsPersistent.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.MV.a FunctionsPersistent.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.JSON.a FunctionsPersistent.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.XML.a FunctionsPersistent.o
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.TABLE.a FunctionsPersistent.o

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Persistent.MV Static Libraries
#===============================================
cd Linkar.Functions.Persistent.MV

echo "Compiling x64 Static FunctionsPersistentMV.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o FunctionsPersistentMV.o FunctionsPersistentMV.c
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.MV.a FunctionsPersistentMV.o

echo ""
echo "Compiling x86 Static FunctionsPersistentMV.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o FunctionsPersistentMV.o FunctionsPersistentMV.c
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.MV.a FunctionsPersistentMV.o

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Persistent.JSON Static Libraries
#=================================================
cd Linkar.Functions.Persistent.JSON

echo "Compiling x64 Static FunctionsPersistentJSON.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o FunctionsPersistentJSON.o FunctionsPersistentJSON.c
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.JSON.a FunctionsPersistentJSON.o

echo ""
echo "Compiling x86 Static FunctionsPersistentJSON.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o FunctionsPersistentJSON.o FunctionsPersistentJSON.c
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.JSON.a FunctionsPersistentJSON.o

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Persistent.XML Static Libraries
#================================================
cd Linkar.Functions.Persistent.XML

echo "Compiling x64 Static FunctionsPersistentXML.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o FunctionsPersistentXML.o FunctionsPersistentXML.c
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.XML.a FunctionsPersistentXML.o

echo ""
echo "Compiling x86 Static FunctionsPersistentXML.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o FunctionsPersistentXML.o FunctionsPersistentXML.c
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.XML.a FunctionsPersistentXML.o

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Persistent.TABLE Static Libraries
#==================================================
cd Linkar.Functions.Persistent.TABLE

echo "Compiling x64 Static FunctionsPersistentTABLE.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o FunctionsPersistentTABLE.o FunctionsPersistentTABLE.c
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.TABLE.a FunctionsPersistentTABLE.o

echo ""
echo "Compiling x86 Static FunctionsPersistentTABLE.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o FunctionsPersistentTABLE.o FunctionsPersistentTABLE.c
ar rcs $BIN_DIR_A_x86/libLinkar.Functions.Persistent.TABLE.a FunctionsPersistentTABLE.o

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Commands.Persistent.JSON Static Libraries
#================================================
cd Linkar.Commands

echo "Building x64 Static CommandsPersistentJSON.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o OperationArguments.o OperationArguments.c
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o CommandsPersistentJSON.o CommandsPersistentJSON.c
ar rcs $BIN_DIR_A_x64/libLinkar.Commands.Persistent.JSON.a OperationArguments.o CommandsPersistentJSON.o

echo ""
echo "Building x86 Static CommandsPersistentJSON.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o OperationArguments.o OperationArguments.c
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o CommandsPersistentJSON.o CommandsPersistentJSON.c
ar rcs $BIN_DIR_A_x86/libLinkar.Commands.Persistent.JSON.a OperationArguments.o CommandsPersistentJSON.o

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Commands.Persistent.XML Static Libraries
#===============================================
cd Linkar.Commands

echo "Compiling x64 Static CommandsPersistentXML.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o OperationArguments.o OperationArguments.c
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o CommandsPersistentXML.o CommandsPersistentXML.c
ar rcs $BIN_DIR_A_x64/libLinkar.Commands.Persistent.XML.a OperationArguments.o CommandsPersistentXML.o

echo ""
echo "Compiling x86 Static CommandsPersistentXML.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o OperationArguments.o OperationArguments.c
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o CommandsPersistentXML.o CommandsPersistentXML.c
ar rcs $BIN_DIR_A_x86/libLinkar.Commands.Persistent.XML.a OperationArguments.o CommandsPersistentXML.o

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi


##################################################################################################
# DYNAMIC LIBRARIES
##################################################################################################
echo "DYNAMIC LIBRARIES"
echo "================="
echo ""
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Strings.Helper Dynamic Libraries
#=======================================
cd Linkar.Strings.Helper

echo "Building x64 Dynamic Library: libLinkar.Strings.Helper.so"
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Strings.Helper.so LinkarStringsHelper.c

echo ""
echo "Building x86 Dynamic Library: libLinkar.Strings.Helper.so"
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Strings.Helper.so LinkarStringsHelper.c

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Strings Dynamic Libraries
#================================
cd Linkar.Strings

#Linkar.Strings Dynamic Libraries
echo "Building x64 Dynamic Library: libLinkar.Strings.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o LinkarStrings.o -O -g LinkarStrings.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Strings.so LinkarStrings.o -L$BIN_DIR_SO_x64 -lLinkar.Strings.Helper

echo ""
echo "Building x86 Dynamic Library: libLinkar.Strings.so"
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Strings.so LinkarStrings.c -L$BIN_DIR_SO_x86 -lLinkar.Strings.Helper

echo ""
cd ..

if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions Dynamic Libraries
#==================================
cd Linkar.Functions

echo "Compiling x64 Dynamic MvOperations.c"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o MvOperations.o -O -g MvOperations.c
echo "Compiling x64 Dynamic OperationOptions.c"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o OperationOptions.o -O -g OperationOptions.c
echo "Compiling x64 Dynamic OperationArguments.c"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o OperationArguments.o -O -g OperationArguments.c
echo "Compiling x64 Dynamic ReleaseMemory.c"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o ReleaseMemory.o -O -g ReleaseMemory.c

echo "Building x64 Dynamic Library: libLinkar.Functions.so"
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Functions.so MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o -L$BIN_DIR_SO_x64 -lLinkar.Strings.Helper -lLinkar.Strings

echo ""
echo "Compiling x86 Dynamic MvOperations.c"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o MvOperations.o -O -g MvOperations.c
echo "Compiling x86 Dynamic OperationOptions.c"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o OperationOptions.o -O -g OperationOptions.c
echo "Compiling x86 Dynamic OperationArguments.c"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o OperationArguments.o -O -g OperationArguments.c
echo "Compiling x86 Dynamic ReleaseMemory.c"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o ReleaseMemory.o -O -g ReleaseMemory.c

echo "Building x86 Dynamic Library: libLinkar.Functions.so"
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.so MvOperations.o OperationOptions.o OperationArguments.o ReleaseMemory.o -L$BIN_DIR_SO_x86 -lLinkar.Strings.Helper -lLinkar.Strings

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Direct Dynamic Libraries
#=========================================
cd Linkar.Functions.Direct

echo "Building x64 Dynamic Library: libLinkar.Functions.Direct.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o FunctionsDirect.o -O -g FunctionsDirect.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Functions.Direct.so -L$BIN_DIR_SO_x64 -lLinkar.Strings.Helper -lLinkar -lLinkar.Strings -lLinkar.Functions FunctionsDirect.o

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Direct.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o FunctionsDirect.o -O -g FunctionsDirect.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Direct.so -L$BIN_DIR_SO_x86 --lLinkar.Strings.Helper -lLinkar -lLinkar.Strings -lLinkar.Functions FunctionsDirect.o

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Direct.MV Dynamic Libraries
#============================================
cd Linkar.Functions.Direct.MV

echo "Building x64 Dynamic Library: libLinkar.Functions.Direct.MV.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o FunctionsDirectMV.o -O -g FunctionsDirectMV.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Functions.Direct.MV.so -L$BIN_DIR_SO_x64 -lLinkar.Functions -lLinkar.Functions.Direct FunctionsDirectMV.o

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Direct.MV.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o  FunctionsDirectMV.o -O -g FunctionsDirectMV.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Direct.MV.so -L$BIN_DIR_SO_x86 -lLinkar.Functions -lLinkar.Functions.Direct FunctionsDirectMV.o

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Direct.JSON Dynamic Libraries
#==============================================
cd Linkar.Functions.Direct.JSON

echo "Building x64 Dynamic Library: libLinkar.Functions.Direct.JSON.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o FunctionsDirectJSON.o -O -g FunctionsDirectJSON.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Functions.Direct.JSON.so FunctionsDirectJSON.o -L$BIN_DIR_SO_x64 -lLinkar.Functions.Direct

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Direct.JSON.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o  FunctionsDirectJSON.o -O -g FunctionsDirectJSON.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Direct.JSON.so FunctionsDirectJSON.o -L$BIN_DIR_SO_x86 -lLinkar.Functions.Direct

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Direct.XML Dynamic Libraries
#=============================================
cd Linkar.Functions.Direct.XML

echo "Building x64 Dynamic Library: libLinkar.Functions.Direct.XML.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o FunctionsDirectXML.o -O -g FunctionsDirectXML.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Functions.Direct.XML.so FunctionsDirectXML.o -L$BIN_DIR_SO_x64 -lLinkar.Functions.Direct

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Direct.XML.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o  FunctionsDirectXML.o -O -g FunctionsDirectXML.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Direct.XML.so FunctionsDirectXML.o -L$BIN_DIR_SO_x86 -lLinkar.Functions.Direct

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Direct.TABLE Dynamic Libraries
#===============================================
cd Linkar.Functions.Direct.TABLE

echo "Building x64 Dynamic Library: libLinkar.Functions.Direct.TABLE.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o  FunctionsDirectTABLE.o -O -g FunctionsDirectTABLE.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Functions.Direct.TABLE.so FunctionsDirectTABLE.o -L$BIN_DIR_SO_x64 -lLinkar.Functions.Direct

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Direct.TABLE.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o FunctionsDirectTABLE.o FunctionsDirectTABLE.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Direct.TABLE.so FunctionsDirectTABLE.o -L$BIN_DIR_SO_x86 -lLinkar.Functions.Direct

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Commands.Direct.JSON Dynamic Libraries
#=============================================
cd Linkar.Commands

echo "Building x64 Dynamic Library: libLinkar.Commands.Direct.JSON.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o OperationArguments.o -O -g OperationArguments.c
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o CommandsDirectJSON.o -O -g CommandsDirectJSON.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Commands.Direct.JSON.so OperationArguments.o CommandsDirectJSON.o -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings

echo ""
echo "Building x86 Dynamic Library: libLinkar.Commands.Direct.JSON.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o OperationArguments.o -O -g OperationArguments.c
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o CommandsDirectJSON.o -O -g CommandsDirectJSON.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Commands.Direct.JSON.so OperationArguments.o CommandsDirectJSON.o -L$BIN_DIR_SO_x86 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Commands.Direct.XML Dynamic Libraries
#============================================
cd Linkar.Commands

echo "Building x64 Dynamic Library: libLinkar.Commands.Direct.XML.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o OperationArguments.o -O -g OperationArguments.c
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o CommandsDirectXML.o -O -g CommandsDirectXML.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Commands.Direct.XML.so OperationArguments.o CommandsDirectXML.o -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings

echo ""
echo "Building x86 Dynamic Library: libLinkar.Commands.Direct.XML.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o OperationArguments.o -O -g OperationArguments.c
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o CommandsDirectXML.o -O -g CommandsDirectXML.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Commands.Direct.XML.so OperationArguments.o CommandsDirectXML.o -L$BIN_DIR_SO_x86 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Persistent Dynamic Libraries
#=============================================
cd Linkar.Functions.Persistent

echo "Building x64 Dynamic Library: libLinkar.Functions.Persistent.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o FunctionsPersistent.o -O -g FunctionsPersistent.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Functions.Persistent.so FunctionsPersistent.o -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings -lLinkar.Functions

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Persistent.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o FunctionsPersistent.o -O -g FunctionsPersistent.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Persistent.so FunctionsPersistent.o -L$BIN_DIR_SO_x86 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings -lLinkar.Functions

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Persistent.MV Dynamic Libraries
#================================================
cd Linkar.Functions.Persistent.MV

echo "Building x64 Dynamic Library: libLinkar.Functions.Persistent.MV.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o FunctionsPersistentMV.o -O -g FunctionsPersistentMV.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Functions.Persistent.MV.so FunctionsPersistentMV.o -L$BIN_DIR_SO_x64 -lLinkar.Functions.Persistent

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Persistent.MV.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o FunctionsPersistentMV.o -O -g FunctionsPersistentMV.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Persistent.MV.so FunctionsPersistentMV.o -L$BIN_DIR_SO_x86 -lLinkar.Functions.Persistent

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Persistent.JSON Dynamic Libraries
#==================================================
cd Linkar.Functions.Persistent.JSON

echo "Building x64 Dynamic Library: libLinkar.Functions.Persistent.JSON.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o FunctionsPersistentJSON.o -O -g FunctionsPersistentJSON.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Functions.Persistent.JSON.so FunctionsPersistentJSON.o -L$BIN_DIR_SO_x64 -lLinkar.Functions.Persistent

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Persistent.JSON.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o FunctionsPersistentJSON.o -O -g FunctionsPersistentJSON.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Persistent.JSON.so FunctionsPersistentJSON.o -L$BIN_DIR_SO_x86 -lLinkar.Functions.Persistent

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Persistent.XML Dynamic Libraries
#=================================================
cd Linkar.Functions.Persistent.XML

echo "Building x64 Dynamic Library: libLinkar.Functions.Persistent.XML.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o FunctionsPersistentXML.o -O -g FunctionsPersistentXML.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Functions.Persistent.XML.so FunctionsPersistentXML.o -L$BIN_DIR_SO_x64 -lLinkar.Functions.Persistent

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Persistent.XML.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o FunctionsPersistentXML.o -O -g FunctionsPersistentXML.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Persistent.XML.so FunctionsPersistentXML.o -L$BIN_DIR_SO_x86 -lLinkar.Functions.Persistent

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Functions.Persistent.TABLE Dynamic Libraries
#===================================================
cd Linkar.Functions.Persistent.TABLE

echo "Building x64 Dynamic Library: libLinkar.Functions.Persistent.TABLE.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o FunctionsPersistentTABLE.o -O -g FunctionsPersistentTABLE.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Functions.Persistent.TABLE.so FunctionsPersistentTABLE.o -L$BIN_DIR_SO_x64 -lLinkar.Functions.Persistent

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Persistent.TABLE.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o FunctionsPersistentTABLE.o -O -g FunctionsPersistentTABLE.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Persistent.TABLE.so FunctionsPersistentTABLE.o -L$BIN_DIR_SO_x86 -lLinkar.Functions.Persistent

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Commands.Persistent.JSON Dynamic Libraries
#=================================================
cd Linkar.Commands

echo "Building x64 Dynamic Library: libLinkar.Commands.Persistent.JSON.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o OperationArguments.o -O -g OperationArguments.c
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o CommandsPersistentJSON.o -O -g CommandsPersistentJSON.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Commands.Persistent.JSON.so OperationArguments.o CommandsPersistentJSON.o -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings

echo ""
echo "Building x86 Dynamic Library: libLinkar.Commands.Persistent.JSON.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o OperationArguments.o -O -g OperationArguments.c
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o CommandsPersistentJSON.o -O -g CommandsPersistentJSON.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Commands.Persistent.JSON.so OperationArguments.o CommandsPersistentJSON.o -L$BIN_DIR_SO_x86 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Commands.Persistent.XML Dynamic Libraries
#================================================
cd Linkar.Commands

echo "Building x64 Dynamic Library: libLinkar.Commands.Persistent.XML.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o OperationArguments.o -O -g OperationArguments.c
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o CommandsPersistentXML.o -O -g CommandsPersistentXML.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Commands.Persistent.XML.so OperationArguments.o CommandsPersistentXML.o -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings

echo ""
echo "Building x86 Dynamic Library: libLinkar.Commands.Persistent.XML.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o OperationArguments.o -O -g OperationArguments.c
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o CommandsPersistentXML.o -O -g CommandsPersistentXML.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Commands.Persistent.XML.so OperationArguments.o CommandsPersistentXML.o -L$BIN_DIR_SO_x86 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings

echo ""

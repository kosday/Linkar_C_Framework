#!/bin/bash
clear
echo "This script will build x64 and x86 C Linkar Framework Library"
echo ""

STOP=N
if [ "$1" == "-p" ] || [ "$1" == "-P" ] ; then
	STOP=Y
fi

# Output directory for compiled libraries
BIN_DIR=../../bin
BIN_DIR_SO_x64=$BIN_DIR/linux.so/x64
BIN_DIR_A_x64=$BIN_DIR/linux.a/x64
BIN_DIR_SO_x86=$BIN_DIR/linux.so/x86
BIN_DIR_A_x86=$BIN_DIR/linux.a/x86

# If not empty, the directory where the symbolic link for dynamic libraries will be created
LIB_DIR_SO_x64=/usr/lib
LIB_DIR_SO_x86=/usr/lib32

COMPILER_OPTIONS_STATIC_LIB_x64="-c -D__LK_STATIC_LIB__ -D__LK_EXPORT__ -I../../includes -fPIC -Bstatic"
COMPILER_OPTIONS_STATIC_LIB_x86="-c -D__LK_STATIC_LIB__ -D__LK_EXPORT__ -I../../includes -fPIC -m32 -Bstatic"
COMPILER_OPTIONS_DYNAMIC_LIB_x64="-D__LK_DYNAMIC_LIB__ -D__LK_EXPORT__ -I../../includes -fPIC"
COMPILER_OPTIONS_DYNAMIC_LIB_x86="-D__LK_DYNAMIC_LIB__ -D__LK_EXPORT__ -I../../includes -m32 -fPIC"


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
ar rcs $BIN_DIR_A_x64/libLinkar.Commands.Direct.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.MV.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.JSON.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.XML.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Functions.Persistent.TABLE.a LinkarStringsHelper.o
ar rcs $BIN_DIR_A_x64/libLinkar.Commands.Persistent.a LinkarStringsHelper.o

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
ar rcs $BIN_DIR_A_x86/libLinkar.Commands.Persistent.a LinkarStringsHelper.o

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

#Linkar.Commands.Direct Static Libraries
#=======================================
cd Linkar.Commands

echo "Compiling x64 Static CommandsDirect.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o OperationArguments.o OperationArguments.c
gcc -I../../includes/Linkar.Commands $COMPILER_OPTIONS_STATIC_LIB_x64 -o CommandsDirect.o CommandsDirect.c
ar rcs $BIN_DIR_A_x64/libLinkar.Commands.Direct.a OperationArguments.o CommandsDirect.o

echo ""
echo "Compiling x86 Static CommandsDirect.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o OperationArguments.o OperationArguments.c
gcc -I../../includes/Linkar.Commands $COMPILER_OPTIONS_STATIC_LIB_x86 -o CommandsDirect.o CommandsDirect.c
ar rcs $BIN_DIR_A_x86/libLinkar.Commands.Direct.a OperationArguments.o CommandsDirect.o

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

#Linkar.Commands.Persistent Static Libraries
#===========================================
cd Linkar.Commands

echo "Building x64 Static CommandsPersistent.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x64 -o OperationArguments.o OperationArguments.c
gcc -I../../includes/Linkar.Commands $COMPILER_OPTIONS_STATIC_LIB_x64 -o CommandsPersistent.o CommandsPersistent.c
ar rcs $BIN_DIR_A_x64/libLinkar.Commands.Persistent.a OperationArguments.o CommandsPersistent.o

echo ""
echo "Building x86 Static CommandsPersistent.c"
gcc $COMPILER_OPTIONS_STATIC_LIB_x86 -o OperationArguments.o OperationArguments.c
gcc -I../../includes/Linkar.Commands $COMPILER_OPTIONS_STATIC_LIB_x86 -o CommandsPersistent.o CommandsPersistent.c
ar rcs $BIN_DIR_A_x86/libLinkar.Commands.Persistent.a OperationArguments.o CommandsPersistent.o

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
if [ ! -z "${LIB_DIR_SO_x64}" ] ; then
	ln -srf $BIN_DIR_SO_x64/libLinkar.Strings.Helper.so $LIB_DIR_SO_x64/libLinkar.Strings.Helper.so ;
fi

echo ""
echo "Building x86 Dynamic Library: libLinkar.Strings.Helper.so"
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Strings.Helper.so LinkarStringsHelper.c
if [ ! -z "${LIB_DIR_SO_x86}" ] ; then
	ln -srf $BIN_DIR_SO_x86/libLinkar.Strings.Helper.so $LIB_DIR_SO_x86/libLinkar.Strings.Helper.so ;
fi

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
if [ ! -z "${LIB_DIR_SO_x64}" ] ; then
	ln -srf $BIN_DIR_SO_x64/libLinkar.Strings.so $LIB_DIR_SO_x64/libLinkar.Strings.so
fi

echo ""
echo "Building x86 Dynamic Library: libLinkar.Strings.so"
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Strings.so LinkarStrings.c -L$BIN_DIR_SO_x86 -lLinkar.Strings.Helper
if [ ! -z "${LIB_DIR_SO_x86}" ] ; then
	ln -srf $BIN_DIR_SO_x86/libLinkar.Strings.so $LIB_DIR_SO_x86/libLinkar.Strings.so
fi
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
if [ ! -z "${LIB_DIR_SO_x64}" ] ; then
	ln -srf $BIN_DIR_SO_x64/libLinkar.Functions.so $LIB_DIR_SO_x64/libLinkar.Functions.so
fi

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
if [ ! -z "${LIB_DIR_SO_x86}" ] ; then
	ln -srf $BIN_DIR_SO_x86/libLinkar.Functions.so $LIB_DIR_SO_x86/libLinkar.Functions.so
fi

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
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Functions.Direct.so FunctionsDirect.o -L$BIN_DIR_SO_x64 -lLinkar.Strings.Helper -lLinkar -lLinkar.Strings -lLinkar.Functions
if [ ! -z "${LIB_DIR_SO_x64}" ] ; then
	ln -srf $BIN_DIR_SO_x64/libLinkar.Functions.Direct.so $LIB_DIR_SO_x64/libLinkar.Functions.Direct.so
fi

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Direct.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o FunctionsDirect.o -O -g FunctionsDirect.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Direct.so FunctionsDirect.o -L$BIN_DIR_SO_x86 -lLinkar.Strings.Helper -lLinkar -lLinkar.Strings -lLinkar.Functions
if [ ! -z "${LIB_DIR_SO_x86}" ] ; then
	ln -srf $BIN_DIR_SO_x86/libLinkar.Functions.Direct.so $LIB_DIR_SO_x86/libLinkar.Functions.Direct.so
fi

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
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Functions.Direct.MV.so FunctionsDirectMV.o -L$BIN_DIR_SO_x64 -lLinkar.Functions -lLinkar.Functions.Direct -lLinkar.Functions.Direct.MV
if [ ! -z "${LIB_DIR_SO_x64}" ] ; then
	ln -srf $BIN_DIR_SO_x64/libLinkar.Functions.Direct.MV.so $LIB_DIR_SO_x64/libLinkar.Functions.Direct.MV.so
fi

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Direct.MV.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o  FunctionsDirectMV.o -O -g FunctionsDirectMV.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Direct.MV.so FunctionsDirectMV.o -L$BIN_DIR_SO_x86 -lLinkar.Functions -lLinkar.Functions.Direct -lLinkar.Functions.Direct.MV
if [ ! -z "${LIB_DIR_SO_x86}" ] ; then
ln -srf $BIN_DIR_SO_x86/libLinkar.Functions.Direct.MV.so $LIB_DIR_SO_x86/libLinkar.Functions.Direct.MV.so
fi

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
if [ ! -z "${LIB_DIR_SO_x64}" ] ; then
	ln -srf $BIN_DIR_SO_x64/libLinkar.Functions.Direct.JSON.so $LIB_DIR_SO_x64/libLinkar.Functions.Direct.JSON.so
fi

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Direct.JSON.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o  FunctionsDirectJSON.o -O -g FunctionsDirectJSON.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Direct.JSON.so FunctionsDirectJSON.o -L$BIN_DIR_SO_x86 -lLinkar.Functions.Direct
if [ ! -z "${LIB_DIR_SO_x86}" ] ; then
	ln -srf $BIN_DIR_SO_x86/libLinkar.Functions.Direct.JSON.so $LIB_DIR_SO_x86/libLinkar.Functions.Direct.JSON.so
fi

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
if [ ! -z "${LIB_DIR_SO_x64}" ] ; then
	ln -srf $BIN_DIR_SO_x64/libLinkar.Functions.Direct.XML.so $LIB_DIR_SO_x64/libLinkar.Functions.Direct.XML.so
fi

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Direct.XML.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o  FunctionsDirectXML.o -O -g FunctionsDirectXML.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Direct.XML.so FunctionsDirectXML.o -L$BIN_DIR_SO_x86 -lLinkar.Functions.Direct
if [ ! -z "${LIB_DIR_SO_x86}" ] ; then
	ln -srf $BIN_DIR_SO_x86/libLinkar.Functions.Direct.XML.so $LIB_DIR_SO_x86/libLinkar.Functions.Direct.XML.so
fi

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
if [ ! -z "${LIB_DIR_SO_x64}" ] ; then
	ln -srf $BIN_DIR_SO_x64/libLinkar.Functions.Direct.TABLE.so $LIB_DIR_SO_x64/libLinkar.Functions.Direct.TABLE.so
fi

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Direct.TABLE.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o FunctionsDirectTABLE.o FunctionsDirectTABLE.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Direct.TABLE.so FunctionsDirectTABLE.o -L$BIN_DIR_SO_x86 -lLinkar.Functions.Direct
if [ ! -z "${LIB_DIR_SO_x86}" ] ; then
	ln -srf $BIN_DIR_SO_x86/libLinkar.Functions.Direct.TABLE.so $LIB_DIR_SO_x86/libLinkar.Functions.Direct.TABLE.so
fi

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Commands.Direct Dynamic Libraries
#========================================
cd Linkar.Commands

echo "Building x64 Dynamic Library: libLinkar.Commands.Direct.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o OperationArguments.o -O -g OperationArguments.c
gcc -c -I../../includes/Linkar.Commands $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o CommandsDirect.o -O -g CommandsDirect.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Commands.Direct.so OperationArguments.o CommandsDirect.o -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings
if [ ! -z "${LIB_DIR_SO_x64}" ] ; then
	ln -srf $BIN_DIR_SO_x64/libLinkar.Commands.Direct.so $LIB_DIR_SO_x64/libLinkar.Commands.Direct.so
fi

echo ""
echo "Building x86 Dynamic Library: libLinkar.Commands.Direct.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o OperationArguments.o -O -g OperationArguments.c
gcc -c -I../../includes/Linkar.Commands $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o CommandsDirect.o -O -g CommandsDirect.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Commands.Direct.so OperationArguments.o CommandsDirect.o -L$BIN_DIR_SO_x86 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings
if [ ! -z "${LIB_DIR_SO_x86}" ] ; then
	ln -srf $BIN_DIR_SO_x86/libLinkar.Commands.Direct.so $LIB_DIR_SO_x86/libLinkar.Commands.Direct.so
fi

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
if [ ! -z "${LIB_DIR_SO_x64}" ] ; then
	ln -srf $BIN_DIR_SO_x64/libLinkar.Functions.Persistent.so $LIB_DIR_SO_x64/libLinkar.Functions.Persistent.so
fi

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Persistent.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o FunctionsPersistent.o -O -g FunctionsPersistent.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Persistent.so FunctionsPersistent.o -L$BIN_DIR_SO_x86 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings -lLinkar.Functions
if [ ! -z "${LIB_DIR_SO_x86}" ] ; then
	ln -srf $BIN_DIR_SO_x86/libLinkar.Functions.Persistent.so $LIB_DIR_SO_x86/libLinkar.Functions.Persistent.so
fi


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
if [ ! -z "${LIB_DIR_SO_x64}" ] ; then
	ln -srf $BIN_DIR_SO_x64/libLinkar.Functions.Persistent.MV.so $LIB_DIR_SO_x64/libLinkar.Functions.Persistent.MV.so
fi

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Persistent.MV.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o FunctionsPersistentMV.o -O -g FunctionsPersistentMV.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Persistent.MV.so FunctionsPersistentMV.o -L$BIN_DIR_SO_x86 -lLinkar.Functions.Persistent
if [ ! -z "${LIB_DIR_SO_x86}" ] ; then
	ln -srf $BIN_DIR_SO_x86/libLinkar.Functions.Persistent.MV.so $LIB_DIR_SO_x86/libLinkar.Functions.Persistent.MV.so
fi

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
if [ ! -z "${LIB_DIR_SO_x64}" ] ; then
	ln -srf $BIN_DIR_SO_x64/libLinkar.Functions.Persistent.JSON.so $LIB_DIR_SO_x64/libLinkar.Functions.Persistent.JSON.so
fi

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Persistent.JSON.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o FunctionsPersistentJSON.o -O -g FunctionsPersistentJSON.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Persistent.JSON.so FunctionsPersistentJSON.o -L$BIN_DIR_SO_x86 -lLinkar.Functions.Persistent
if [ ! -z "${LIB_DIR_SO_x86}" ] ; then
	ln -srf $BIN_DIR_SO_x86/libLinkar.Functions.Persistent.JSON.so $LIB_DIR_SO_x86/libLinkar.Functions.Persistent.JSON.so
fi

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
if [ ! -z "${LIB_DIR_SO_x64}" ] ; then
	ln -srf $BIN_DIR_SO_x64/libLinkar.Functions.Persistent.XML.so $LIB_DIR_SO_x64/libLinkar.Functions.Persistent.XML.so
fi

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Persistent.XML.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o FunctionsPersistentXML.o -O -g FunctionsPersistentXML.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Persistent.XML.so FunctionsPersistentXML.o -L$BIN_DIR_SO_x86 -lLinkar.Functions.Persistent
if [ ! -z "${LIB_DIR_SO_x86}" ] ; then
	ln -srf $BIN_DIR_SO_x86/libLinkar.Functions.Persistent.XML.so $LIB_DIR_SO_x86/libLinkar.Functions.Persistent.XML.so
fi

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
if [ ! -z "${LIB_DIR_SO_x64}" ] ; then
	ln -srf $BIN_DIR_SO_x64/libLinkar.Functions.Persistent.TABLE.so $LIB_DIR_SO_x64/libLinkar.Functions.Persistent.TABLE.so
fi

echo ""
echo "Building x86 Dynamic Library: libLinkar.Functions.Persistent.TABLE.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o FunctionsPersistentTABLE.o -O -g FunctionsPersistentTABLE.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Functions.Persistent.TABLE.so FunctionsPersistentTABLE.o -L$BIN_DIR_SO_x86 -lLinkar.Functions.Persistent
if [ ! -z "${LIB_DIR_SO_x86}" ] ; then
	ln -srf $BIN_DIR_SO_x86/libLinkar.Functions.Persistent.TABLE.so $LIB_DIR_SO_x86/libLinkar.Functions.Persistent.TABLE.so
fi

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

#Linkar.Commands.Persistent Dynamic Libraries
#============================================
cd Linkar.Commands

echo "Building x64 Dynamic Library: libLinkar.Commands.Persistent.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o OperationArguments.o -O -g OperationArguments.c
gcc -c -I../../includes/Linkar.Commands $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o CommandsPersistent.o -O -g CommandsPersistent.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x64 -o $BIN_DIR_SO_x64/libLinkar.Commands.Persistent.so OperationArguments.o CommandsPersistent.o -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings
if [ ! -z "${LIB_DIR_SO_x64}" ] ; then
	ln -srf $BIN_DIR_SO_x64/libLinkar.Commands.Persistent.so $LIB_DIR_SO_x64/libLinkar.Commands.Persistent.so
fi

echo ""
echo "Building x86 Dynamic Library: libLinkar.Commands.Persistent.so"
gcc -c $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o OperationArguments.o -O -g OperationArguments.c
gcc -c -I../../includes/Linkar.Commands $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o CommandsPersistent.o -O -g CommandsPersistent.c
gcc -shared $COMPILER_OPTIONS_DYNAMIC_LIB_x86 -o $BIN_DIR_SO_x86/libLinkar.Commands.Persistent.so OperationArguments.o CommandsPersistent.o -L$BIN_DIR_SO_x86 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings
if [ ! -z "${LIB_DIR_SO_x86}" ] ; then
	ln -srf $BIN_DIR_SO_x86/libLinkar.Commands.Persistent.so $LIB_DIR_SO_x86/libLinkar.Commands.Persistent.so
fi

echo ""
cd ..
if [ "$STOP" == "Y" ] ; then
	read -p "Press any key to continue ..."
	clear
fi

echo ""

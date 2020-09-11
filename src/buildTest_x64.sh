#!/bin/bash
# IMPORTANT: You must execute this script from "x64 Native Tools Command Prompt for VS 2019"
clear
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
COMPILER_OPTIONS_DYNAMIC_LIB_x64="-shared -D__LK_DYNAMIC_LIB__ -D__LK_EXPORT__ -I../includes -fPIC -lcrypto"
COMPILER_OPTIONS_DYNAMIC_LIB_x86="-shared -D__LK_DYNAMIC_LIB__ -D__LK_EXPORT__ -I../includes -m32 -fPIC -lcrypto32"

cd TEST

# Test1-DirectBase program with Static Libraries

####cc test.c -D__LINKARCLIENT_STATIC_LIB__ ../linux.a/x64/libLinkarClientC.a -lcrypto -o Test_A/x64/test_A
####cc test.c -D__LINKARCLIENT_DYNAMIC_LIB__ -L../linux.so/x64 -lLinkarClientC -o Test_SO/x64/test_SO
####cc test.c -D__LINKARCLIENT_STATIC_LIB__ -D__DIRECTAS__ ../linux.a/x64/libLinkarClientC.a -lcrypto -o Test_A/x64/testD_A
####cc test.c -D__LINKARCLIENT_DYNAMIC_LIB__ -D__DIRECTAS__ -L../linux.so/x64 -lLinkarClientC -o Test_SO/x64/testD_SO


echo "Compiling x64 Examples with STATIC LIBRARIES"
echo "============================================"
echo ""

echo "Compiling x64 Test1-DirectBase.c"
gcc Test1-DirectBase.c -D__LK_STATIC_LIB__ -I../includes -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Functions.Direct -lcrypto -o $BIN_DIR_A_x64/Test1-DirectBase

echo "Compiling x64 Test1-PersistentBase.c"
gcc Test1-PersistentBase.c -D__LK_STATIC_LIB__ -I../includes -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Functions.Persistent -lcrypto -o $BIN_DIR_A_x64/Test1-PersistentBase

echo "Compiling x64 Test2-DirectMV.c"
gcc Test2-DirectMV.c -D__LK_STATIC_LIB__ -I../includes -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Functions.Direct.MV -lcrypto -o $BIN_DIR_A_x64/Test2-DirectMV

echo "Compiling x64 Test2-PersistentMV.c"
gcc Test2-PersistentMV.c -D__LK_STATIC_LIB__ -I../includes -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Functions.Persistent.MV -lcrypto -o $BIN_DIR_A_x64/Test2-PersistentMV

echo "Compiling x64 Test3-DirectXML.c"
gcc Test3-DirectXML.c -D__LK_STATIC_LIB__ -I../includes -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Functions.Direct.XML -lcrypto -o $BIN_DIR_A_x64/Test3-DirectXML

echo "Compiling x64 Test4-DirectJSON.c"
gcc Test4-DirectJSON.c -D__LK_STATIC_LIB__ -I../includes -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Functions.Direct.JSON -lcrypto -o $BIN_DIR_A_x64/Test4-DirectJSON

echo "Compiling x64 Test5-DirectCmdJSON.c"
gcc Test5-DirectCmdJSON.c -D__LK_STATIC_LIB__ -I../Linkar.Commands -I../includes -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Commands.Direct.JSON -lcrypto -o $BIN_DIR_A_x64/Test5-DirectCmdJSON

echo "Compiling x64 Test5-PersistentCmdJSON.c"
gcc Test5-PersistentCmdJSON.c -D__LK_STATIC_LIB__ -I../Linkar.Commands -I../includes -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Commands.Persistent.JSON -lcrypto -o $BIN_DIR_A_x64/Test5-PersistentCmdJSON

echo "Compiling x64 Test5-DirectCmdXML.c"
gcc Test5-DirectCmdXML.c -D__LK_STATIC_LIB__ -I../Linkar.Commands -I../includes -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Commands.Direct.XML -lcrypto -o $BIN_DIR_A_x64/Test5-DirectCmdXML

echo "Compiling x64 Test5-PersistentCmdXML.c"
gcc Test5-PersistentCmdXML.c -D__LK_STATIC_LIB__ -I../Linkar.Commands -I../includes -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Commands.Persistent.XML -lcrypto -o $BIN_DIR_A_x64/Test5-PersistentCmdXML


echo ""
echo "Compiling x64 Examples with DYNAMIC LIBRARIES"
echo "============================================="
echo ""

echo "Test.c"
gcc Test.c -D__LK_DYNAMIC_LIB__ -I../includes -lcrypto -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -o $BIN_DIR_SO_x64/Test

echo "Compiling x64 Test1-DirectBase.c"
gcc Test1-DirectBase.c -D__LK_DYNAMIC_LIB__ -I../includes -lcrypto -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings -lLinkar.Functions -lLinkar.Functions.Direct -o $BIN_DIR_SO_x64/Test1-DirectBase

exit

echo "Compiling x64 Test1-PersistentBase.c"
gcc Test1-PersistentBase.c -D__LK_DYNAMIC_LIB__ -I../includes -lcrypto -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings -lLinkar.Functions -lLinkar.Functions.Persistent -o $BIN_DIR_SO_x64/Test1-PersistentBase

echo "Compiling x64 Test2-DirectMV.c"
gcc Test2-DirectMV.c -D__LK_DYNAMIC_LIB__ -I../includes -lcrypto -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings -lLinkar.Functions -lLinkar.Functions.Direct -lLinkar.Functions.Direct.MV -o $BIN_DIR_SO_x64/Test2-DirectMV

echo "Compiling x64 Test2-PersistentMV.c"
gcc Test2-PersistentMV.c -D__LK_DYNAMIC_LIB__ -I../includes -lcrypto -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings -lLinkar.Functions -lLinkar.Functions.Persistent -lLinkar.Functions.Persistent.MV -o $BIN_DIR_SO_x64/Test2-PersistentMV

echo "Compiling x64 Test3-DirectXML.c"
gcc Test3-DirectXML.c -D__LK_DYNAMIC_LIB__ -I../includes -lcrypto -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings -lLinkar.Functions -lLinkar.Functions.Direct -lLinkar.Functions.Direct.XML -o $BIN_DIR_SO_x64/Test3-DirectXML

echo "Compiling x64 Test4-DirectJSON.c"
gcc Test4-DirectJSON.c -D__LK_DYNAMIC_LIB__ -I../includes -lcrypto -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings -lLinkar.Functions -lLinkar.Functions.Direct -lLinkar.Functions.Direct.JSON -o $BIN_DIR_SO_x64/Test4-DirectJSON

echo "Compiling x64 Test5-DirectCmdJSON.c"
gcc Test5-DirectCmdJSON.c -D__LK_DYNAMIC_LIB__ -I../Linkar.Commands -I../includes -lcrypto -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Commands.Direct.JSON -o $BIN_DIR_SO_x64/Test5-DirectCmdJSON

echo "Compiling x64 Test5-PersistentCmdJSON.c"
gcc Test5-PersistentCmdJSON.c -D__LK_DYNAMIC_LIB__ -I../Linkar.Commands -I../includes -lcrypto -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Commands.Persistent.JSON -o $BIN_DIR_SO_x64/Test5-PersistentCmdJSON

echo "Compiling x64 Test5-DirectCmdXML.c"
gcc Test5-DirectCmdXML.c -D__LK_DYNAMIC_LIB__ -I../Linkar.Commands -I../includes -lcrypto -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Commands.Direct.XML -o $BIN_DIR_SO_x64/Test5-DirectCmdXML

echo "Compiling x64 Test5-PersistentCmdXML.c"
gcc Test5-PersistentCmdXML.c -D__LK_DYNAMIC_LIB__ -I../Linkar.Commands -I../includes -lcrypto -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Commands.Persistent.XML -o $BIN_DIR_SO_x64/Test5-PersistentCmdXML


exit

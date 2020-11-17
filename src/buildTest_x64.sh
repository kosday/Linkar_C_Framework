#!/bin/bash
clear
STOP=N
if [ "$1" == "-p" ] || [ "$1" == "-P" ] ; then
	STOP=Y
fi

cd TEST

BIN_DIR=../../bin
BIN_DIR_SO_x64=$BIN_DIR/linux.so/x64
BIN_DIR_A_x64=$BIN_DIR/linux.a/x64
BIN_DIR_SO_x86=$BIN_DIR/linux.so/x86
BIN_DIR_A_x86=$BIN_DIR/linux.a/x86

echo "Compiling x64 Examples with STATIC LIBRARIES"
echo "============================================"
echo ""

echo "Compiling x64 Test1-DirectBase.c"
gcc Test1-DirectBase.c -D__LK_STATIC_LIB__ -I../../includes -o $BIN_DIR_A_x64/Test1-DirectBase -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Functions.Direct -lcrypto

echo "Compiling x64 Test1-PersistentBase.c"
gcc Test1-PersistentBase.c -D__LK_STATIC_LIB__ -I../../includes -o $BIN_DIR_A_x64/Test1-PersistentBase -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Functions.Persistent -lcrypto

echo "Compiling x64 Test2-DirectMV.c"
gcc Test2-DirectMV.c -D__LK_STATIC_LIB__ -I../../includes -o $BIN_DIR_A_x64/Test2-DirectMV -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Functions -lLinkar.Functions.Direct -lLinkar.Functions.Direct.MV -lcrypto -lcrypto

echo "Compiling x64 Test2-PersistentMV.c"
gcc Test2-PersistentMV.c -D__LK_STATIC_LIB__ -I../../includes -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Functions -lLinkar.Functions.Persistent.MV -lcrypto -o $BIN_DIR_A_x64/Test2-PersistentMV

echo "Compiling x64 Test3-DirectXML.c"
gcc Test3-DirectXML.c -D__LK_STATIC_LIB__ -I../../includes -o $BIN_DIR_A_x64/Test3-DirectXML -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Functions.Direct.XML -lcrypto

echo "Compiling x64 Test4-DirectJSON.c"
gcc Test4-DirectJSON.c -D__LK_STATIC_LIB__ -I../../includes -o $BIN_DIR_A_x64/Test4-DirectJSON -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Functions.Direct.JSON -lcrypto

echo "Compiling x64 Test5-DirectCmdJSON.c"
gcc Test5-DirectCmdJSON.c -D__LK_STATIC_LIB__ -I../../includes/Linkar.Commands -I../../includes -o $BIN_DIR_A_x64/Test5-DirectCmdJSON -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Commands.Direct.JSON -lcrypto

echo "Compiling x64 Test5-PersistentCmdJSON.c"
gcc Test5-PersistentCmdJSON.c -D__LK_STATIC_LIB__ -I../../includes/Linkar.Commands -I../../includes -o $BIN_DIR_A_x64/Test5-PersistentCmdJSON -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Commands.Persistent.JSON -lcrypto

echo "Compiling x64 Test5-DirectCmdXML.c"
gcc Test5-DirectCmdXML.c -D__LK_STATIC_LIB__ -I../../includes/Linkar.Commands -I../../includes -o $BIN_DIR_A_x64/Test5-DirectCmdXML -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Commands.Direct.XML -lcrypto

echo "Compiling x64 Test5-PersistentCmdXML.c"
gcc Test5-PersistentCmdXML.c -D__LK_STATIC_LIB__ -I../../includes/Linkar.Commands -I../../includes -o $BIN_DIR_A_x64/Test5-PersistentCmdXML -L$BIN_DIR_A_x64 -lLinkar -lLinkar.Commands.Persistent.XML -lcrypto

echo ""
echo "Compiling x64 Examples with DYNAMIC LIBRARIES"
echo "============================================="
echo ""

echo "Compiling x64 Test1-DirectBase.c"
gcc Test1-DirectBase.c -D__LK_DYNAMIC_LIB__ -I../../includes -o $BIN_DIR_SO_x64/Test1-DirectBase -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings -lLinkar.Functions.Direct -lLinkar.Functions -lcrypto

echo "Compiling x64 Test1-PersistentBase.c"
gcc Test1-PersistentBase.c -D__LK_DYNAMIC_LIB__ -I../../includes -o $BIN_DIR_SO_x64/Test1-PersistentBase -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings -lLinkar.Functions -lLinkar.Functions.Persistent -lcrypto

echo "Compiling x64 Test2-DirectMV.c"
gcc Test2-DirectMV.c -D__LK_DYNAMIC_LIB__ -I../../includes -o $BIN_DIR_SO_x64/Test2-DirectMV -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings -lLinkar.Functions -lLinkar.Functions.Direct -lLinkar.Functions.Direct.MV -lcrypto

echo "Compiling x64 Test2-PersistentMV.c"
gcc Test2-PersistentMV.c -D__LK_DYNAMIC_LIB__ -I../../includes -o $BIN_DIR_SO_x64/Test2-PersistentMV -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings -lLinkar.Functions -lLinkar.Functions.Persistent -lLinkar.Functions.Persistent.MV -lcrypto

echo "Compiling x64 Test3-DirectXML.c"
gcc Test3-DirectXML.c -D__LK_DYNAMIC_LIB__ -I../../includes  -o $BIN_DIR_SO_x64/Test3-DirectXML -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings -lLinkar.Functions -lLinkar.Functions.Direct -lLinkar.Functions.Direct.XML -lcrypto

echo "Compiling x64 Test4-DirectJSON.c"
gcc Test4-DirectJSON.c -D__LK_DYNAMIC_LIB__ -I../../includes -o $BIN_DIR_SO_x64/Test4-DirectJSON -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Strings -lLinkar.Functions -lLinkar.Functions.Direct -lLinkar.Functions.Direct.JSON -lcrypto

echo "Compiling x64 Test5-DirectCmdJSON.c"
gcc Test5-DirectCmdJSON.c -D__LK_DYNAMIC_LIB__ -I../../includes/Linkar.Commands -I../../includes -o $BIN_DIR_SO_x64/Test5-DirectCmdJSON -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Commands.Direct.JSON -lcrypto 

echo "Compiling x64 Test5-PersistentCmdJSON.c"
gcc Test5-PersistentCmdJSON.c -D__LK_DYNAMIC_LIB__ -I../../includes/Linkar.Commands -I../../includes -o $BIN_DIR_SO_x64/Test5-PersistentCmdJSON -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Commands.Persistent.JSON -lcrypto 

echo "Compiling x64 Test5-DirectCmdXML.c"
gcc Test5-DirectCmdXML.c -D__LK_DYNAMIC_LIB__ -I../../includes/Linkar.Commands -I../../includes -o $BIN_DIR_SO_x64/Test5-DirectCmdXML -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Commands.Direct.XML -lcrypto

echo "Compiling x64 Test5-PersistentCmdXML.c"
gcc Test5-PersistentCmdXML.c -D__LK_DYNAMIC_LIB__ -I../../includes/Linkar.Commands -I../../includes -o $BIN_DIR_SO_x64/Test5-PersistentCmdXML -L$BIN_DIR_SO_x64 -lLinkar -lLinkar.Strings.Helper -lLinkar.Commands.Persistent.XML -lcrypto

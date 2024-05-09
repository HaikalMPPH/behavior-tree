#!/usr/bin/bash

BIN_DIR="bin/"
NAME="bt"
WARN="-Wall"
CC="clang++"
STD="-std=c++17"
MODE="-g"
INCLUDES="-Isrc"
LIB="-lraylib"
SRC="src/*.cpp src/**/*.cpp src/**/**/*.cpp"

$CC $STD -o $BIN_DIR$NAME $SRC $WARN $MODE $INCLUDES $LIB

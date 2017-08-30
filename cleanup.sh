#!/bin/bash

find . -name "*.o" -type f -delete
find . -regextype posix-extended -regex "\./test/test[0-9]*\.cpp" -delete
make clean
rm -rf html/ CMakeCache.txt CMakeFiles/ cmake_install.cmake Makefile runTests compile_commands.json


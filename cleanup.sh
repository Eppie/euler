#!/bin/bash

find . -name "*.o" -type f -delete
find {0,1,2,3,4,5,6,7,8}/ -executable -type f -delete
find . -regextype posix-extended -regex "\./test/test[0-9]*\.cpp" -delete
make clean
rm -rf html/ CMakeCache.txt CMakeFiles/ cmake_install.cmake Makefile runTests compile_commands.json


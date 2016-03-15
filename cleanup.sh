#!/bin/bash

find . -name "*.o" -type f -delete
find {0,1,2,3}/ -executable -type f -delete
make clean
rm -rf html/ CMakeCache.txt CMakeFiles/ cmake_install.cmake Makefile runTests
rm -rf "test/CMakeCache.txt" "test/CMakeFiles/" "test/cmake_install.cmake" "test/Makefile" "test/runTests"


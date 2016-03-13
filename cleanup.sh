#!/bin/bash

find . -name "*.o" -type f -delete
find {0,1,2,3}/ -executable -type f -delete
make clean
rm -rf CMakeCache.txt CMakeFiles/ cmake_install.cmake Makefile

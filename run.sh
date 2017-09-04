#!/bin/bash

./cleanup.sh
pushd "test"
./generate.py
popd
cmake -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ .
cores=$(sysctl hw.ncpu | cut -d ' ' -f2)
make -j"$cores"
cat /dev/null > timings.txt
for i in {1..100}; do
	result=($(./euler $i))
	echo "$i: ${result[0]}"
	echo "$i: ${result[1]}" >> timings.txt
done


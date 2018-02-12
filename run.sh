#!/bin/bash

./cleanup.sh
pushd "test"
./generate.py
popd
CXX=/usr/local/opt/ccache/libexec/clang++ CC=/usr/local/opt/ccache/libexec/clang cmake .
cores=$(sysctl hw.ncpu | cut -d ' ' -f2)
make -j"$cores"
cat /dev/null > timings.txt
for i in {1..106}; do
	result=($(./euler $i))
	echo "$i: ${result[0]}"
	echo "$i: ${result[1]}" >> timings.txt
done


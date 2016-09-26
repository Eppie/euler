#!/bin/bash

./cleanup.sh
pushd "test"
./generate.py
popd
cmake .
cores=$(grep -c ^processor /proc/cpuinfo)
make -j$cores
cat /dev/null > timings.txt
for i in {1..76}; do
	result=($(./euler $i))
	echo "$i: ${result[0]}"
	echo "$i: ${result[1]}" >> timings.txt
done


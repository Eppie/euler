#!/bin/bash

./cleanup.sh
cmake .
cores=$(grep -c ^processor /proc/cpuinfo)
make -j$cores
cat /dev/null > timings.txt
for i in {1..60}; do
	result=($(./euler $i))
	echo "$i: ${result[0]}"
	echo "$i: ${result[1]}" >> timings.txt
done


#!/bin/bash

./cleanup.sh
cmake .
make -j12
cat /dev/null > timings.txt
for i in {1..49}; do
	result=($(./euler $i))
	echo "$i: ${result[0]}"
	echo "$i: ${result[1]}" >> timings.txt
done


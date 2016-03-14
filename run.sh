#!/bin/bash

cmake .
make clean
make -j12
for i in {1..34}; do
	result=$(./euler $i)
	echo "$i: $result"
done


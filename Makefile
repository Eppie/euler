#!/bin/bash

all:
	g++ -std=c++14 -g -Ofast -mtune=native -march=native main.cpp -o euler

clean:
	find . -name "*.o" -type f -delete
	find {0,1,2}/ -executable -type f -delete
	rm -rf euler

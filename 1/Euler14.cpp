/*
 * =====================================================================================
 *
 *       Filename:  Euler14.cpp
 *
 *    Description:  Solution to Project Euler, Problem 14
 *
 *        Version:  1.0
 *        Created:  08/01/2015 11:42:39 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The following iterative sequence is defined for the set of positive integers:
 *                  n → n/2 (n is even)
 *                  n → 3n + 1 (n is odd)
 *                  Which starting number, under one million, produces the longest chain?
 *         Answer:  837799
 * =====================================================================================
 */

#include "../helper.hpp"

int solve14() {
	int cache[1000001] = { 1, 1 };
	int result = 0;
	int best = 0;

	for( int i = 2; i <= 1000000; ++i ) {
		int length = 0;
		uint64_t start = i;

		while( start != 1 && start >= i ) {
			if( ( start & 1 ) == 0 ) {
				start >>= 1;
			} else {
				start = start * 3 + 1;
			}

			++length;
		}

		cache[i] = length + cache[start];

		if( cache[i] > best ) {
			best = cache[i];
			result = i;
		}
	}

	return result;
}

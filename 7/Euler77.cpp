/*
 * =====================================================================================
 *
 *       Filename:  Euler77.cpp
 *
 *    Description:  Solution to Project Euler, Problem 77
 *
 *        Version:  1.0
 *        Created:  9/26/2016 8:39:59 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  It is possible to write ten as the sum of primes in exactly five different ways:
 *
 *                  7 + 3
 *                  5 + 5
 *                  5 + 3 + 2
 *                  3 + 3 + 2 + 2
 *                  2 + 2 + 2 + 2 + 2
 *
 *                  What is the first value which can be written as the sum of primes in over five thousand different ways?
 *         Answer:  71
 * =====================================================================================
 */

#include "../helper.hpp"

int solve77() {
	int limit = 100;
	auto primes = sieve( 100 );
	vector<int> ways( limit, 0 );
	ways[0] = 1;

	for( int prime : primes ) {
		for( int j = prime; j < limit; ++j ) {
			ways[j] += ways[j - prime];
		}
	}

	for( int i = 0; i < limit; ++i ) {
		if( ways[i] > 5000 ) {
			return i;
		}
	}

	return -1;
}


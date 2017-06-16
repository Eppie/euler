/*
 * =====================================================================================
 *
 *       Filename:  Euler76.cpp
 *
 *    Description:  Solution to Project Euler, Problem 76
 *
 *        Version:  1.1
 *        Created:  9/26/2016 3:14:15 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  It is possible to write five as a sum in exactly six different ways:
 *
 *                  4 + 1
 *                  3 + 2
 *                  3 + 1 + 1
 *                  2 + 2 + 1
 *                  2 + 1 + 1 + 1
 *                  1 + 1 + 1 + 1 + 1
 *
 *                  How many different ways can one hundred be written as a sum of at least two positive integers?
 *         Answer:  190569291
 *
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler76 {
/*
 * This is an implementation based on Euler's Pentagonal number theorem: https://en.wikipedia.org/wiki/Pentagonal_number_theorem
 * @param int n
 * @return int
 */
int p( int n ) {
	static vector<int> cache( 102, 0 );
	cache[1] = 1;

	if( n <= 0 ) {
		return 0;
	}

	if( cache[n] != 0 ) {
		return cache[n];
	}

	int result = 0;

	// k < 9 was determined empirically to be large enough to get an accurate result
	for( int k = 1; k < 9; ++k ) {
		result += pow( -1, k - 1 ) * p( n - genPent( k ) );
		k *= -1;
		result += pow( -1, k - 1 ) * p( n - genPent( k ) );
		k *= -1;
	}

	cache[n] = result;

	return result;
}
}

int solve76() {
	return euler76::p( 101 ) - 1;
}


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

// Yes, the memoized / recursive version of the function is slower,
// but I think the memoize wrapper is neat and I want to demonstrate
// its usage.
function<uint64_t( uint64_t )> mCollatz;

uint64_t rCollatz( uint64_t start ) {
	if( start == 1 ) {
		return 1;
	}

	if( start % 2 == 0 ) {
		return mCollatz( start / 2 ) + 1;
	}

	return mCollatz( ( start * 3 ) + 1 ) + 1;

}

uint64_t solve14() {
	mCollatz = rCollatz;
	mCollatz = memoize( mCollatz );
	uint64_t result = 0;
	uint64_t best = 1;
	uint64_t temp = 0;

	for( uint64_t i = 2; i <= 1000000; i++ ) {
		temp = mCollatz( i );

		if( temp > best ) {
			best = temp;
			result = i;
		}
	}

	return result;
}

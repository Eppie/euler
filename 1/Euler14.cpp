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
 *   Organization:  SevOne
 *        Problem:  The following iterative sequence is defined for the set of positive integers:
 *                  n → n/2 (n is even)
 *                  n → 3n + 1 (n is odd)
 *                  Which starting number, under one million, produces the longest chain?
 *         Answer:  837799
 * =====================================================================================
 */

#include "../helper.hpp"

ull collatz( ull start ) {
	ull result = 1;
	while( start != 1 ) {
		if( start % 2 == 0 ) {
			start /= 2;
		} else {
			start = ( start * 3 ) + 1;
		}
		result += 1;
	}
	return result;
}

int main() {
	function<ull(ull)> mCollatz = collatz;
	mCollatz = memoize( mCollatz );
	ull result;
	ull best = 1;
	ull temp;
	for( ull i = 2; i <= 1000000; i++ ) {
		temp = collatz( i );
		if( temp > best ) {
			best = temp;
			result = i;
		}
	}

	cout << result << endl;
	return 0;
}

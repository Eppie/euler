/*
 * =====================================================================================
 *
 *       Filename:  Euler35.cpp
 *
 *    Description:  Solution to Project Euler, Problem 35
 *
 *        Version:  1.0
 *        Created:  3/14/2016 5:14:37 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
 *                  How many circular primes are there below one million?
 *         Answer:  55
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler35 {
void rotations( int n, vector<int> &rots ) {
	rots.clear();
	rots.push_back( n );
	int r = ( n >= 100000 ) ? 5 : ( n >= 10000 ) ? 4 : ( n >= 1000 ) ? 3 : ( n >= 100 ) ? 2 : ( n >= 10 ) ? 1 : 0;

	for( int i = 0; i < r; ++i ) {
		int lastDigit = n % 10;
		n /= 10;
		n += ( lastDigit * pow( 10, r ) );
		rots.push_back( n );
	}
}
}

int solve35() {
	int result = 0;
	auto primes = sieve( 1e6 );
	vector<int> rots;

	for( auto && prime : primes ) {
		euler35::rotations( prime, rots );

		if( all( isPrime, rots ) ) {
			result += 1;
		}
	}

	return result;
}


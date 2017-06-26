/*
 * =====================================================================================
 *
 *       Filename:  Euler92.cpp
 *
 *    Description:  Solution to Project Euler, Problem 92
 *
 *        Version:  1.0
 *        Created:  06/16/2017 01:30:35 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.
 *                  For example,
 *
 *                  44 → 32 → 13 → 10 → 1 → 1
 *                  85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89
 *
 *                  Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop.
 *                  What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.
 *                  How many starting numbers below ten million will arrive at 89?
 *         Answer:  8581146
 *
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler92 {
int next( int n ) {
	int result = 0;

	while( n ) {
		result += ( n % 10 ) * ( n % 10 );
		n /= 10;
	}

	return result;
}

bool isUnhappy( int n ) {
	while( n != 1 && n != 89 && n != 4 ) {
		n = next( n );
	}

	return n != 1;
}
}

int solve92() {
	int result = 0;
	int L = 7; // Because we are checking up to 10⁷
	// The largest possible square of digits is 9² * L, plus 1
	const int Lc = ( ( 9 * 9 ) * 7 ) + 1;
	int t[Lc] = { 0 };
	int solutions[Lc] = { 0 };

	for( int i = 0; i < 10; ++i ) {
		solutions[i * i] = 1;
	}

	for( int i = 2; i <= L; ++i ) {
		for( int j = 0; j < Lc; ++j ) {
			t[j] = 0;

			for( int k = 0; k < 10 && k * k <= j; ++k ) {
				t[j] += solutions[j - k * k];
			}
		}

		memcpy( solutions, t, sizeof( solutions ) );
	}

	for( int i = 1; i < Lc; ++i ) {
		if( euler92::isUnhappy( i ) ) {
			result += solutions[i];
		}
	}

	return result;
}

/*
 * =====================================================================================
 *
 *       Filename:  Euler78.cpp
 *
 *    Description:  Solution to Project Euler, Problem 78
 *
 *        Version:  1.1
 *        Created:  9/26/2016 3:14:15 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Let p(n) represent the number of different ways in which n coins can be separated into piles.
 *                  For example, five coins can be separated into piles in exactly seven different ways, so p(5)=7.
 *
 *                  OOOOO
 *                  OOOO   O
 *                  OOO   OO
 *                  OOO   O   O
 *                  OO   OO   O
 *                  OO   O   O   O
 *                  O   O   O   O   O
 *
 *                  Find the least value of n for which p(n) is divisible by one million.
 *         Answer:  55374
 *
 * =====================================================================================
 */

#include "../helper.hpp"

/*
 * This is an implementation based on Euler's Pentagonal number theorem: https://en.wikipedia.org/wiki/Pentagonal_number_theorem
 * @param int n
 * @return int
 */
int p78( int n ) {
	static vector<int> cache( 100000, 0 );
	cache[1] = 1;

	if( n <= 0 ) {
		return 0;
	}

	if( cache[n] != 0 ) {
		return cache[n];
	}

	int result = 0;
	int old_result = 1;
	int k = 1;

	while( old_result != result ) {
		old_result = result;
		int mult = 1;

		if( k % 2 == 0 ) {
			mult *= -1;
		}

		result += mult * p78( n - genPent( k ) );
		k *= -1;
		result += mult * p78( n - genPent( k ) );
		k *= -1;
		++k;
	}

	result %= 1000000;

	if( result < 0 ) {
		result += 1000000;
	}

	cache[n] = result;
	return result;
}

int solve78() {
	int i = 1;

	while( true ) {
		int result = p78( i );

		if( result % 1000000 == 0 ) {
			return i - 1;
		}

		++i;
	}
}


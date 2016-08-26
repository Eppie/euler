/*
 * =====================================================================================
 *
 *       Filename:  Euler46.cpp
 *
 *    Description:  Solution to Project Euler, Problem 46
 *
 *        Version:  1.0
 *        Created:  8/26/2016 3:02:57 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
 *
 *                  9 = 7 + 2×1²
 *                  15 = 7 + 2×2²
 *                  21 = 3 + 2×3²
 *                  25 = 7 + 2×3²
 *                  27 = 19 + 2×2²
 *                  33 = 31 + 2×1²
 *
 *                  It turns out that the conjecture was false.
 *                  What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
 *         Answer:  5777
 * =====================================================================================
 */

#include "../helper.hpp"

int solve46() {
	auto primes = sieve( 4500 );

	for( int i = 9; i < 10000; i += 2 ) {
		if( isPrime( i ) ) {
			continue;
		}

		bool isGood = true;

		for( auto prime : primes ) {
			for( int j = 0; j < 100; ++j ) {
				if( prime + ( 2 * ( j * j ) ) == i ) {
					isGood = false;
				}
			}

			if( !isGood ) {
				break;
			}
		}

		if( isGood ) {
			return i;
		}
	}

	return 0;
}


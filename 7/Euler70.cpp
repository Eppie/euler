/*
 * =====================================================================================
 *
 *       Filename:  Euler70.cpp
 *
 *    Description:  Solution to Project Euler, Problem 70
 *
 *        Version:  1.2
 *        Created:  9/21/2016 5:21:54 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of numbers less than n
 *                  which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
 *                  The number 1 is considered to be relatively prime to every positive number, so φ(1)=1.
 *                  Interestingly, φ(87109)=79180, and it can be seen that 87109 is a permutation of 79180.
 *                  Find the value of n, 1 < n < 10⁷, for which φ(n) is a permutation of n and the ratio n/φ(n) produces a minimum.
 *         Answer:  8319823
 *
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler70 {
bool isPermutation( int a, int b ) {
	int counts[10] = { 0 };

	while( a != 0 ) {
		counts[a % 10]++;
		a /= 10;
	}

	while( b != 0 ) {
		counts[b % 10]--;
		b /= 10;
	}

	for( auto && count : counts ) {
		if( count != 0 ) {
			return false;
		}
	}

	return true;
}
}

int solve70() {
	int result = 0;
	float bestRatio = 10;
	auto primes = sieve( 5000 );

	for( uint32_t i = 0; i < primes.size(); ++i ) {
		for( uint32_t j = i + 1; j < primes.size(); ++j ) {
			int n = primes[i] * primes[j];

			if( n > 10000000 ) {
				break;
			}

			int totatives = ( primes[i] - 1 ) * ( primes[j] - 1 );
			float ratio = float( n ) / float( totatives );

			if( ratio < bestRatio ) {
				if( euler70::isPermutation( n, totatives ) ) {
					result = n;
					bestRatio = ratio;
				}
			}
		}
	}

	return result;
}


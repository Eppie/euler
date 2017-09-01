/*
 * =====================================================================================
 *
 *       Filename:  Euler50.cpp
 *
 *    Description:  Solution to Project Euler, Problem 50
 *
 *        Version:  1.2
 *        Created:  8/30/2016 4:17:22 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The prime 41, can be written as the sum of six consecutive primes:
 *                  41 = 2 + 3 + 5 + 7 + 11 + 13
 *                  This is the longest sum of consecutive primes that adds to a prime below one-hundred.
 *                  The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
 *                  Which prime, below one-million, can be written as the sum of the most consecutive primes?
 *         Answer:  997651
 * =====================================================================================
 */

#include "../helper.hpp"

int solve50() {
	int best = 0;
	int bestLength = 0;
	int tmpSum = 0;
	int tmpLength = 0;
	auto primes = sieve( 3932 );

	for( uint32_t i = 0; i < primes.size(); ++i ) {
		for( uint32_t j = i; j < primes.size(); ++j ) {
			tmpSum += primes[j];
			tmpLength += 1;

			if( tmpSum >= 1000000 ) {
				break;
			}

			if( isPrime( tmpSum ) && tmpLength > bestLength ) {
				best = tmpSum;
				bestLength = tmpLength;
			}
		}

		tmpSum = 0;
		tmpLength = 0;
	}

	return best;
}


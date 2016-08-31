/*
 * =====================================================================================
 *
 *       Filename:  Euler51.cpp
 *
 *    Description:  Solution to Project Euler, Problem 51
 *
 *        Version:  1.0
 *        Created:  8/30/2016 6:21:31 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
 *                  By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes
 *                  among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993.
 *                  Consequently 56003, being the first member of this family, is the smallest prime with this property.
 *                  Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
 *         Answer:  121313
 * =====================================================================================
 */

#include "../helper.hpp"

/*
 * TODO: This one is _very_ inefficient, and while it runs in ~0.75s, it would be nice to get the runtime lower.
 */
int solve51() {
	// Idea: Keep track of which digits to replace by using a bitmask. The next permutation of replacements can be calculated by simply adding 1.
	int result = 1000000;
	int primeCount = 0;
	auto primes = sieve( 130000 );

	for( auto && prime : primes ) {
		if( prime < 56003 ) {
			continue;
		}

		int digitCount = numDigits( prime );

		for( unsigned int mask = 1; mask < 1 << digitCount; ++mask ) {
			for( int digit = 0; digit <= 9; ++digit ) {
				int tmp = 0;

				for( int i = 0; i < digitCount; ++i ) {
					if( mask & 1 << i ) {
						tmp += digit * pow( 10, i );
					} else {
						tmp += ( ( prime / int( pow( 10, i ) ) ) % 10 ) * pow( 10, i );
					}
				}

				if( numDigits( tmp ) == digitCount && isPrime( tmp ) ) {
					if( tmp < result ) {
						result = tmp;
					}

					primeCount += 1;
				}
			}

			if( primeCount >= 8 ) {
				return result;
			}

			primeCount = 0;
			result = 1000000;
		}
	}

	return result;
}


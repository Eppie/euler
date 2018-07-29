/*
 * =====================================================================================
 *
 *       Filename:  Euler111.cpp
 *
 *    Description:  Solution to Project Euler, Problem 111
 *
 *        Version:  1.0
 *        Created:  7/29/2018 11:59:39 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Considering 4-digit primes containing repeated digits it is clear that they cannot all be the same:
 *                  1111 is divisible by 11, 2222 is divisible by 22, and so on. But there are nine 4-digit primes containing three ones:
 *                              1117, 1151, 1171, 1181, 1511, 1811, 2111, 4111, 8111
 *                  We shall say that M(n, d) represents the maximum number of repeated digits for an n-digit prime where d is the repeated digit,
 *                  N(n, d) represents the number of such primes, and S(n, d) represents the sum of these primes.
 *                  So M(4, 1) = 3 is the maximum number of repeated digits for a 4-digit prime where one is the repeated digit,
 *                  there are N(4, 1) = 9 such primes, and the sum of these primes is S(4, 1) = 22275.
 *                  It turns out that for d = 0, it is only possible to have M(4, 0) = 2 repeated digits, but there are N(4, 0) = 13 such cases.
 *                  In the same way we obtain the following results for 4-digit primes.
 *                              ┌────────┬─────────┬─────────┬─────────┐
 *                              │Digit, d│ M(4, d) │ N(4, d) │ S(4, d) │
 *                              ├────────┼─────────┼─────────┼─────────┤
 *                              │      0 │       2 │      13 │   67061 │
 *                              │      1 │       3 │       9 │   22275 │
 *                              │      2 │       3 │       1 │    2221 │
 *                              │      3 │       3 │      12 │   46214 │
 *                              │      4 │       3 │       2 │    8888 │
 *                              │      5 │       3 │       1 │    5557 │
 *                              │      6 │       3 │       1 │    6661 │
 *                              │      7 │       3 │       9 │   57863 │
 *                              │      8 │       3 │       1 │    8887 │
 *                              │      9 │       3 │       7 │   48073 │
 *                              └────────┴─────────┴─────────┴─────────┘
 *                  For d = 0 to 9, the sum of all S(4, d) is 273700.
 *                  Find the sum of all S(10, d).
 *         Answer:  612407567715
 *
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler111 {
int number[10];
uint64_t recurse( uint8_t baseDigit, uint8_t startPos, uint8_t level, bool fill ) {
	if( level == 0 ) {
		if( number[0] == 0 ) {
			return 0;
		}

		uint64_t n = 0;
		
		for( uint8_t i = 0; i < 10; ++i ) {
			n = n * 10 + number[i];
		}

		if( isPrime( n ) ) {
			return n;
		} else {
			return 0;
		}
	}

	uint64_t result = 0;
	
	if( fill ) {
		for( uint8_t pos = 0; pos < 10; ++pos ) {
			number[pos] = baseDigit;
		}
	}

	for( uint8_t pos = startPos; pos < 10; ++pos ) {
		for( int val = 0; val < 10; ++ val ) {
			number[pos] = val;
			result += recurse( baseDigit, pos + 1, level - 1, false );
			number[pos] = baseDigit;
		}
	}
	
	return result;
}

}

uint64_t solve111() {
	uint64_t result = 0;
	for( uint8_t d = 0; d < 10; ++d ) {
		for( uint8_t i = 1; i < 10; ++i ) {
			uint64_t sum = euler111::recurse( d, 0, i, true );
			if( sum > 0 ) {
				result += sum;
				break;
			}
		}
	}
	return result;
}

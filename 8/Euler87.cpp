/*
 * =====================================================================================
 *
 *       Filename:  Euler87.cpp
 *
 *    Description:  Solution to Project Euler, Problem 87
 *
 *        Version:  1.0
 *        Created:  06/06/2017 05:43:06 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The smallest number expressible as the sum of a prime square, prime cube, and prime fourth power is 28.
 *                  In fact, there are exactly four numbers below fifty that can be expressed in such a way:
 *                  28 = 2² + 2³ + 2⁴
 *                  33 = 3² + 2³ + 2⁴
 *                  49 = 5² + 2³ + 2⁴
 *                  47 = 2² + 3³ + 2⁴
 *                  How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?
 *         Answer:  1097343
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int solve87() {
	auto primes = sieve( 7070 );
	vector<uint64_t> results;
	uint64_t tmp = 0;

	for( auto && square : primes ) {
		for( auto && cube : primes ) {
			for( auto && fourth : primes ) {
				tmp = pow( square, 2 ) + pow( cube, 3 ) + pow( fourth, 4 );

				if( tmp < 50000000 ) {
					results.push_back( tmp );
				} else {
					break;
				}
			}
		}
	}

	sort( results.begin(), results.end() );
	return unique( results.begin(), results.end() ) - results.begin();
}

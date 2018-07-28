/*
 * =====================================================================================
 *
 *       Filename:  Euler110.cpp
 *
 *    Description:  Solution to Project Euler, Problem 110
 *
 *        Version:  1.0
 *        Created:  7/28/2018 11:29:15 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  In the following equation x, y, and n are positive integers.
 *                    1   1   1
 *                    - + - = -
 *                    x   y   n
 *                  It can be verified that when n = 1260 there are 113 distinct solutions and this is the least value of n
 *                  for which the total number of distinct solutions exceeds one hundred.
 *                  What is the least value of n for which the number of distinct solutions exceeds four million?
 *         Answer:  9350130049860600
 *
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler110 {
static auto primes = sieve( 50 );
uint32_t countDivisors( vector<uint32_t> primeFactorCounts ) {
	uint32_t result = 1;
	for( auto && i : primeFactorCounts ) {
		if( i != 0 ) {
			result *= ( 2 * i ) + 1;
		}
	}
	return ( result + 1 ) / 2;
}

uint64_t calculateN( vector<uint32_t> primeFactorCounts ) {
	uint64_t result = 1;
	for( uint32_t i = 0; i < primeFactorCounts.size(); ++i ) {
		if( primeFactorCounts[i] != 0 ) {
			result *= static_cast<uint64_t>( pow( primes[i], primeFactorCounts[i] ) );
		}
	}
	return result;
}
}

uint64_t solve110() {
	uint64_t bestN = numeric_limits<uint64_t>::max();
	auto numPrimes = static_cast<uint32_t>( logBaseN( ( 4000000 * 2 ) + 1, 3 ) + 1 );
	uint32_t maxCount = 4;
	vector<uint32_t> primeFactorCounts( numPrimes, 0 );
	while( sum( primeFactorCounts ) < numPrimes * maxCount ) {
		primeFactorCounts[0] += 1;
		for( uint32_t i = 0; i < numPrimes - 1; ++i ) {
			if( primeFactorCounts[i] > maxCount ) {
				for( uint32_t j = 0; j <= i; ++j ) {
					primeFactorCounts[j] = primeFactorCounts[i + 1] + 1;
				}
				primeFactorCounts[i+1] += 1;
			}
		}
		auto d = euler110::countDivisors( primeFactorCounts );
		auto n = euler110::calculateN( primeFactorCounts );
		if( d > 4000000 && n < bestN ) {
			bestN = n;
		}
	}
	return bestN;
}

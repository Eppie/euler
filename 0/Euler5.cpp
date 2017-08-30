/*
 * =====================================================================================
 *
 *       Filename:  Euler5.cpp
 *
 *    Description:  Solution to Project Euler, Problem 5
 *
 *        Version:  1.2
 *        Created:  07/29/2015 11:11:11 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  2520 is the smallest number that can be divided by the numbers 1-10 without any remainder.
 *                  What is the smallest positive number that is evenly divisible by all of the numbers 1-20?
 *         Answer:  232792560
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int solve5() {
	uint32_t limit = 20;
	auto primes = sieve( limit + 1 );
	int result = 1;

	for( uint32_t i = 0; i < primes.size(); ++i ) {
		int a = static_cast<int>( log( limit ) / log( primes[i] ) );
		result *= static_cast<int>( pow( primes[i], a ) );
	}

	return result;
}

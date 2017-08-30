/*
 * =====================================================================================
 *
 *       Filename:  Euler95.cpp
 *
 *    Description:  Solution to Project Euler, Problem 95
 *
 *        Version:  1.0
 *        Created:  06/30/2017 11:07:18 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The proper divisors of a number are all the divisors excluding the number itself. For example, the proper divisors of 28 are 1, 2, 4, 7, and 14.
 *                  As the sum of these divisors is equal to 28, we call it a perfect number.
 *                  Interestingly the sum of the proper divisors of 220 is 284 and the sum of the proper divisors of 284 is 220, forming a chain of two numbers.
 *                  For this reason, 220 and 284 are called an amicable pair.
 *                  Perhaps less well known are longer chains. For example, starting with 12496, we form a chain of five numbers:
 *
 *                  12496 → 14288 → 15472 → 14536 → 14264 (→ 12496 → ...)
 *
 *                  Since this chain returns to its starting point, it is called an amicable chain.
 *                  Find the smallest member of the longest amicable chain with no element exceeding one million.
 *         Answer:  14316
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint32_t solve95() {
	const uint32_t limit = 1000000;
	uint32_t result = 0;
	uint32_t bestLength = 0;
	bool seen[limit + 1] = { 0 };
	vector<uint32_t> sumOfFactors( limit + 1, 1 );

	for( uint32_t i = 2; i <= limit / 2; ++i ) {
		for( uint32_t j = 2 * i; j <= limit; j += i ) {
			sumOfFactors[j] += i;
		}
	}

	vector<uint32_t> chain;

	for( uint32_t i = 2; i <= limit; ++i ) {
		uint32_t newNumber = i;
		// Could be invalid because went over 1 million, or because it contains a number we've seen before
		bool chainIsValid = true;
		chain.clear();

		while( find( chain.begin(), chain.end(), newNumber ) == chain.end() ) {
			chain.push_back( newNumber );
			newNumber = sumOfFactors[newNumber];

			if( newNumber > limit || seen[newNumber] ) {
				chainIsValid = false;
				break;
			}
		}

		if( chainIsValid ) {
			uint32_t smallest = numeric_limits<uint32_t>::max();
			auto first = find( chain.begin(), chain.end(), newNumber );

			if( chain.end() - first > bestLength ) {
				for( auto it = first; it != chain.end(); ++it ) {
					if( *it < smallest ) {
						smallest = *it;
					}
				}

				bestLength = chain.end() - first;
				result = smallest;
			}
		}

		for( auto && chainNumber : chain ) {
			seen[chainNumber] = true;
		}
	}

	return result;
}

/*
 * =====================================================================================
 *
 *       Filename:  Euler74.cpp
 *
 *    Description:  Solution to Project Euler, Problem 74
 *
 *        Version:  1.0
 *        Created:  9/25/2016 1:40:19 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The number 145 is well known for the property that the sum of the factorial of its digits is equal to 145:
 *
 *                  1! + 4! + 5! = 1 + 24 + 120 = 145
 *
 *                  Perhaps less well known is 169, in that it produces the longest chain of numbers that link back to 169;
 *                  it turns out that there are only three such loops that exist:
 *
 *                  169 → 363601 → 1454 → 169
 *                  871 → 45361 → 871
 *                  872 → 45362 → 872
 *
 *                  It is not difficult to prove that EVERY starting number will eventually get stuck in a loop. For example,
 *
 *                  69 → 363600 → 1454 → 169 → 363601 (→ 1454)
 *                  78 → 45360 → 871 → 45361 (→ 871)
 *                  540 → 145 (→ 145)
 *
 *                  Starting with 69 produces a chain of five non-repeating terms,
 *                  but the longest non-repeating chain with a starting number below one million is sixty terms.
 *                  How many chains, with a starting number below one million, contain exactly sixty non-repeating terms?
 *         Answer:  402
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int process( int n ) {
	// A similar caching method for this function was implemented, but it's faster to just recalculate the values
	static int facs[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
	int result = 0;

	while( n > 0 ) {
		int digit = n % 10;
		result += facs[digit];
		n /= 10;
	}

	return result;
}

int solve74() {
	int result = 0;
	// largest observed value is 2177280
	static int cache[2177281];
	vector<int> seen;

	for( int i = 1; i < 1000000; ++i ) {
		int test = i;
		int length = 0;

		while( find( seen.begin(), seen.end(), test ) == seen.end() ) {
			seen.push_back( test );
			test = process( test );
			++length;

			if( cache[test] != 0 ) {
				length += cache[test];
				break;
			}
		}

		if( length == 60 ) {
			++result;
		}

		for( int j = 0; j < seen.size(); ++j ) {
			cache[seen[j]] = length;
			--length;
		}

		seen.clear();
	}

	return result;
}


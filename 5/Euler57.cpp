/*
 * =====================================================================================
 *
 *       Filename:  Euler57.cpp
 *
 *    Description:  Solution to Project Euler, Problem 57
 *
 *        Version:  1.0
 *        Created:  9/2/2016 4:41:01 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  It is possible to show that the square root of two can be expressed as an infinite continued fraction.
 *                  √ 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...
 *                  By expanding this for the first four iterations, we get:
 *                  1 + 1/2 = 3/2 = 1.5
 *                  1 + 1/(2 + 1/2) = 7/5 = 1.4
 *                  1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
 *                  1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...
 *                  The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985,
 *                  is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.
 *                  In the first one-thousand expansions, how many fractions contain a numerator with more digits than denominator?
 *         Answer:  153
 * =====================================================================================
 */

#include "../helper.hpp"

int solve57() {
	int result = 0;
	mpz_class num = 3;
	mpz_class den = 2;
	char oneChar;

	for( int i = 1; i < 1000; ++i ) {
		num += 2 * den;
		den = num - den;
		int numSize = gmp_snprintf( &oneChar, 1, "%Zd", num.get_mpz_t() );
		int denSize = gmp_snprintf( &oneChar, 1, "%Zd", den.get_mpz_t() );

		if( numSize > denSize ) {
			result++;
		}
	}

	return result;
}


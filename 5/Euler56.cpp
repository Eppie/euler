/*
 * =====================================================================================
 *
 *       Filename:  Euler56.cpp
 *
 *    Description:  Solution to Project Euler, Problem 56
 *
 *        Version:  1.0
 *        Created:  9/2/2016 2:36:19 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  A googol (10¹⁰⁰) is a massive number: one followed by one-hundred zeros; 100¹⁰⁰ is almost unimaginably large:
 *                  one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.
 *                  Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?
 *         Answer:  972
 * =====================================================================================
 */

#include "../helper.hpp"

int solve56() {
	int best = 0;
	mpz_class tmp;
	mpz_class result;

	for( int i = 0; i < 100; ++i ) {
		for( int j = 0; j < 100; ++j ) {
			mpz_ui_pow_ui( result.get_mpz_t(), i, j );
			tmp = digitalSum( result );

			if( tmp > best ) {
				best = tmp.get_ui();
			}
		}
	}

	return best;
}


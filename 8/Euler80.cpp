/*
 * =====================================================================================
 *
 *       Filename:  Euler80.cpp
 *
 *    Description:  Solution to Project Euler, Problem 80
 *
 *        Version:  1.0
 *        Created:  6/05/2017 10:50:15 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  It is well known that if the square root of a natural number is not an integer, then it is irrational.
 *                  The decimal expansion of such square roots is infinite without any repeating pattern at all.
 *                  The square root of two is 1.41421356237309504880..., and the digital sum of the first one hundred decimal digits is 475.
 *                  For the first one hundred natural numbers, find the total of the digital sums of the first one hundred
 *                  decimal digits for all the irrational square roots.
 *         Answer:  40886
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int solve80() {
	mpz_class multiplier;
	mpz_ui_pow_ui( multiplier.get_mpz_t(), 10, 198 );
	mpz_class result = 0;
	mpz_class x;
	mpz_class root_sum;
	uint32_t int_sqrt = 1;

	for( uint32_t i = 1; i <= 100; ++i ) {
		// Skip perfect squares
		if( int_sqrt * int_sqrt == i ) {
			++int_sqrt;
			continue;
		}

		x = sqrt( i * multiplier );
		root_sum = digitalSum( x );
		result += root_sum;
	}

	return result.get_ui();
}

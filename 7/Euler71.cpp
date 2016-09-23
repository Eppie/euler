/*
 * =====================================================================================
 *
 *       Filename:  Euler71.cpp
 *
 *    Description:  Solution to Project Euler, Problem 71
 *
 *        Version:  1.0
 *        Created:  9/22/2016 1:50:22 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.
 *                  If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:
 *
 *                  1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
 *
 *                  It can be seen that 2/5 is the fraction immediately to the left of 3/7.
 *                  By listing the set of reduced proper fractions for d ≤ 1,000,000 in ascending order of size,
 *                  find the numerator of the fraction immediately to the left of 3/7.
 *         Answer:  428570
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int solve71() {
	int result = 0;
	double best = 0.4;

	for( int d = 1; d < 1000000; ++d ) {
		int n = d * 3 / 7 - 1;
		double frac = double( n ) / double( d );

		if( frac > best ) {
			if( gcd( n, d ) == 1 ) {
				best = frac;
				result = n;
			}
		}
	}

	return result;
}


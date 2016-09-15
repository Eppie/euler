/*
 * =====================================================================================
 *
 *       Filename:  Euler53.cpp
 *
 *    Description:  Solution to Project Euler, Problem 53
 *
 *        Version:  1.0
 *        Created:  8/30/2016 8:26:04 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  There are exactly ten ways of selecting three from five, 12345:
 *                  123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
 *                  In combinatorics, we use the notation, 5C3 = 10.
 *                  In general, nCr = n!/r!(n−r)!
 *                  where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.
 *                  It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.
 *                  How many, not necessarily distinct, values of nCr, for 1 ≤ n ≤ 100, are greater than one-million?
 *         Answer:  4075
 * =====================================================================================
 */

#include "../helper.hpp"


int solve53() {
	int result = 0;
	int C[100] = { 1, 1 };

	for( int n = 2; n <= 100; ++n ) {
		C[n - 1] = 1;

		for( int r = n - 1; r >= 1; --r ) {
			C[r] = C[r] + C[r - 1];

			if( C[r] > 1000000 ) {
				++result;
				C[r] = 1000000;
			}
		}
	}

	return result;
}


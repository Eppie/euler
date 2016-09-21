/*
 * =====================================================================================
 *
 *       Filename:  Euler69.cpp
 *
 *    Description:  Solution to Project Euler, Problem 69
 *
 *        Version:  1.0
 *        Created:  9/21/2016 1:43:04 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of numbers less than n
 *                  which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
 *
 *                  n	  Relatively Prime	φ(n)	n/φ(n)
 *                  2	  1			1	2
 *                  3	  1,2			2	1.5
 *                  4	  1,3			2	2
 *                  5	  1,2,3,4		4	1.25
 *                  6	  1,5			2	3
 *                  7	  1,2,3,4,5,6		6	1.1666...
 *                  8	  1,3,5,7		4	2
 *                  9	  1,2,4,5,7,8		6	1.5
 *                  10	  1,3,7,9		4	2.5
 *
 *                  It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.
 *                  Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.
 *         Answer:  510510
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int phi( int n ) {
	int result = n;

	for( int p = 2; p * p <= n; ++p ) {
		if( n % p == 0 ) {
			while( n % p == 0 ) {
				n /= p;
			}

			result -= result / p;
		}
	}

	if( n > 1 ) {
		result -= result / n;
	}

	return result;
}

int solve69() {
	int result = 0;
	float bestRatio = 0;

	for( int n = 2; n <= 1000000; ++n ) {
		int totatives = phi( n );
		float tmp = float( n ) / float( totatives );

		if( tmp > bestRatio ) {
			bestRatio = tmp;
			result = n;
		}
	}

	return result;
}


/*
 * =====================================================================================
 *
 *       Filename:  Euler2.cpp
 *
 *    Description:  Solution to Project Euler, Problem 2
 *
 *        Version:  1.0
 *        Created:  07/29/2015 10:42:25 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
 *         Answer:  4613732
 *
 * =====================================================================================
 */

int solve2() {
	int term1 = 1;
	int term2 = 2;
	int i = 0;
	int result = 2;

	while( term1 < 4e6 && term2 < 4e6 ) {
		if( i % 2 == 0 ) {
			term1 += term2;

			if( term1 % 2 == 0 ) {
				result += term1;
			}
		} else {
			term2 += term1;

			if( term2 % 2 == 0 ) {
				result += term2;
			}
		}

		i++;
	}

	return result;
}

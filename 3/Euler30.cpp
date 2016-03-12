/*
 * =====================================================================================
 *
 *       Filename:  Euler30.cpp
 *
 *    Description:  Solution to Project Euler, Problem 30
 *
 *        Version:  1.0
 *        Created:  3/12/2016 4:58:27 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
 *         Answer:  443839
 * =====================================================================================
 */

#include "../helper.hpp"

int solve30() {
	int result = 0;
	for( int i = 2; i < 1000000; i++ ) {
		int tmp = i;
		int sum = 0;
		while( tmp != 0 ) {
			int digit = tmp % 10;
			sum += pow( digit, 5 );
			tmp /= 10;
		}
		if( sum == i ) {
			result += i;
		}
	}
	return result;
}


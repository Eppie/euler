/*
 * =====================================================================================
 *
 *       Filename:  Euler34.cpp
 *
 *    Description:  Solution to Project Euler, Problem 34
 *
 *        Version:  1.0
 *        Created:  3/13/2016 10:54:38 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 *                  Find the sum of all numbers which are equal to the sum of the factorial of their digits.
 *         Answer:  40730
 * =====================================================================================
 */

#include "../helper.hpp"

int solve34() {
	int result = 0;
	vector<int> facs(10, 0);

	for( int i = 0; i < 10; i++ ) {
		facs[i] = factorial( i );
	}

	for( int i = 10; i < 100000; i++ ) {
		int tmp = i;
		int sum = 0;
		while( tmp ) {
			int digit = tmp % 10;
			tmp /= 10;
			sum += facs[digit];
		}
		if( sum == i ) {
			result += sum;
		}
	}
	return result;
}


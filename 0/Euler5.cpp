/*
 * =====================================================================================
 *
 *       Filename:  Euler5.cpp
 *
 *    Description:  Solution to Project Euler, Problem 5
 *
 *        Version:  1.1
 *        Created:  07/29/2015 11:11:11 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  2520 is the smallest number that can be divided by the numbers 1-10 without any remainder.
 *                  What is the smallest positive number that is evenly divisible by all of the numbers 1-20?
 *         Answer:  232792560
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int solve5() {
	int increment = 1;
	int furthestDivisor = 1;
	int result = 1;
	int limit = 20;

	while( true ) {
		int counter = 1;

		while( counter <= limit + 1 && result % counter == 0 ) {
			if ( counter > furthestDivisor ) {
				furthestDivisor = counter;
				increment = result;
			}
			++counter;
		}

		if( counter == limit + 2 ) {
			return result;
		} else {
			result += increment;
		}
	}
}

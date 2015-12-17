/*
 * =====================================================================================
 *
 *       Filename:  Euler5.cpp
 *
 *    Description:  Solution to Project Euler, Problem 5
 *
 *        Version:  1.0
 *        Created:  07/29/2015 11:11:11 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *   Organization:  SevOne
 *        Problem:  2520 is the smallest number that can be divided by the numbers 1-10 without any remainder. What is the smallest positive number that is evenly divisible by all of the numbers 1-20?
 *         Answer:  232792560
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int main() {
	int test = 2520;
	int sum;

	while( 1 ) {
		sum = 0;

		for( int i = 11; i <= 20; i++ ) {
			sum += test % i;
		}

		if( sum == 0 ) {
			cout << test << endl;
			return 0;
		}

		test += 2520;
	}
}

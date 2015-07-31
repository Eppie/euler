/*
 * =====================================================================================
 *
 *       Filename:  Euler1.cpp
 *
 *    Description:  Solution to Project Euler, Problem 1
 *
 *        Version:  1.0
 *        Created:  07/29/2015 10:05:15 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *   Organization:  SevOne
 *        Problem:  Find the sum of all the multiples of 3 or 5 below 1000.
 *         Answer:  233168
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int main() {
	int result = 0;
	for( int i = 0; i < 1000; i++ ) {
		if( i % 3 == 0 || i % 5 == 0 )  {
			result += i;
		}
	}
	cout << result << endl;
	return 0;
}

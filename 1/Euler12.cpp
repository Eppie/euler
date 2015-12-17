/*
 * =====================================================================================
 *
 *       Filename:  Euler12.cpp
 *
 *    Description:  Solution to Project Euler, Problem 12
 *
 *        Version:  1.0
 *        Created:  07/31/2015 10:58:50 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *   Organization:  SevOne
 *        Problem:  The sequence of triangle numbers is generated by adding the natural numbers. What is the value of the first triangle number to have over five hundred divisors?
 *         Answer:  76576500
 * =====================================================================================
 */

#include "../helper.hpp"

int main() {
	ull sum = 1;
	ull n = 2;
	int count;

	while( 1 ) {
		sum += n;
		n++;
		count = 2;

		for( unsigned i = 2; i < sqrt( sum ); i++ ) {
			count += sum % i == 0 ? 2 : 0;
		}

		if( count > 500 ) {
			cout << sum << endl;
			return 0;
		}
	}

	return 0;
}

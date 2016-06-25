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
 *        Problem:  The sequence of triangle numbers is generated by adding the natural numbers. What is the value of the first triangle number to have over five hundred divisors?
 *         Answer:  76576500
 * =====================================================================================
 */

#include "../helper.hpp"

int divisors( uint64_t n, int start = 2 ) {
	if( n == 1 ) {
		return 1;
	}

	for( int i = start; i < ceil( sqrt( n ) ) + 1; i++ ) {
		if( n % i == 0 ) {
			int count = 1;

			while( n % i == 0 ) {
				n /= i;
				count += 1;
			}

			return divisors( n, i + 1 ) * count;
		}
	}

	return 2;

}

uint64_t solve12() {
	int count;

	for( int n = 1; n < 20000; n++ ) {
		uint64_t t = n * ( n + 1 ) / 2;

		if( n % 2 == 0 ) {
			count = divisors( n / 2 ) * divisors( n + 1 );
		} else {
			count = divisors( n ) * divisors( ( n + 1 ) / 2 );
		}

		if( count > 500 ) {
			return t;
		}
	}
}

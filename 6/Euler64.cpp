/*
 * =====================================================================================
 *
 *       Filename:  Euler64.cpp
 *
 *    Description:  Solution to Project Euler, Problem 64
 *
 *        Version:  1.1
 *        Created:  9/12/2016 8:47:20 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The description for this one is quite long. See it here: https://projecteuler.net/problem=64
 *         Answer:  1322
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int solve64() {
	int result = 0;

	for( int n = 2; n <= 10000; ++n ) {
		int limit = static_cast<int>( sqrt( n ) );
		int r = limit;

		if( limit * limit == n ) {
			continue;
		}

		int k = 1;
		int period = 0;

		while( k != 1 || period == 0 ) {
			k = ( n - r * r ) / k;
			r = ( limit + r ) / k * k - r;
			period++;
		}

		if( period % 2 == 1 ) {
			result++;
		}
	}

	return result;
}


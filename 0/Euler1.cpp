/*
 * =====================================================================================
 *
 *       Filename:  Euler1.cpp
 *
 *    Description:  Solution to Project Euler, Problem 1
 *
 *        Version:  1.3
 *        Created:  07/29/2015 10:05:15 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Find the sum of all the multiples of 3 or 5 below 1000.
 *         Answer:  233168
 *
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler1 {
int sumOfMultiplesBelowLimit( int L, int mod ) {
	auto n = static_cast<int>( ceil( double( L ) / double( mod ) ) - 1 );
	return ( ( n * n ) + n ) / 2 * mod;
}
}

int solve1() {
	int L = 1000;
	int result = euler1::sumOfMultiplesBelowLimit( L, 3 );
	result += euler1::sumOfMultiplesBelowLimit( L, 5 );
	result -= euler1::sumOfMultiplesBelowLimit( L, 15 );
	return result;
}

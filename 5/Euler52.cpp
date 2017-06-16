/*
 * =====================================================================================
 *
 *       Filename:  Euler52.cpp
 *
 *    Description:  Solution to Project Euler, Problem 52
 *
 *        Version:  1.0
 *        Created:  8/30/2016 8:26:04 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
 *                  Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
 *         Answer:  142857
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler52 {
bool allSameDigits( vector<int> nums ) {
	int c[10] = { 0 };
	int mult = 1;
	int digitCount = 0;

	for( auto && num : nums ) {
		digitCount += numDigits( num );

		while( num ) {
			c[num % 10] += mult;
			num /= 10;
		}

		mult *= -1;
	}

	int result = 1;

	for( int i = 0; i < 10; ++i ) {
		result &= c[i] == 0;
	}

	return result == 1 && digitCount % 6 == 0;
}
}

int solve52() {
	int x = 1;

	while( true ) {
		vector<int> nums = { x, x * 2, x * 3, x * 4, x * 5, x * 6 };

		if( euler52::allSameDigits( nums ) ) {
			return x;
		}

		++x;
	}

	return x;
}


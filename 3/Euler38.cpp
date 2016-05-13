/*
 * =====================================================================================
 *
 *       Filename:  Euler38.cpp
 *
 *    Description:  Solution to Project Euler, Problem 38
 *
 *        Version:  1.0
 *        Created:  5/12/2016 8:23:58 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Take the number 192 and multiply it by each of 1, 2, and 3:
 *                      192 × 1 = 192
 *                      192 × 2 = 384
 *                      192 × 3 = 576
 *                  By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)
 *                  What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?
 *         Answer:  932718654
 * =====================================================================================
 */

#include "../helper.hpp"

int solve38() {
	int result = 0;

	for( int n = 2; n < 10; n++ ) {
		for( int i = 1; i < pow( 10, 9 / n ); i++ ) {
			vector<int> c;

			for( int j = 1; j <= n; j++ ) {
				c.push_back( i * j );
			}

			if( isPandigital( c ) ) {
				int mul = 0;
				int tmp = 0;

				for( auto it = c.rbegin(); it != c.rend(); it++ ) {
					tmp += *it * pow( 10, mul );
					mul += numDigits( *it );
				}

				result = max( result, tmp );
			}

		}
	}

	return result;
}


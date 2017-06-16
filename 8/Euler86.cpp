/*
 * =====================================================================================
 *
 *       Filename:  Euler86.cpp
 *
 *    Description:  Solution to Project Euler, Problem 86
 *
 *        Version:  1.0
 *        Created:  06/05/2017 12:59:12 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  See the problem description here: https://projecteuler.net/problem=86
 *         Answer:  1818
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int solve86() {
	int l = 2;
	int count = 0;
	int target = 1000000;

	while( count < target ) {
		++l;

		for( int wh = 3; wh <= 2 * l; ++wh ) {
			double sq = sqrt( wh * wh + l * l );

			if( sq == static_cast<int>( sq ) ) {
				if( wh < l ) {
					count += wh / 2;
				} else {
					count += 1 + ( l - ( wh + 1 ) / 2 );
				}
			}
		}
	}

	return l;
}

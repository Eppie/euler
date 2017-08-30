/*
 * =====================================================================================
 *
 *       Filename:  Euler91.cpp
 *
 *    Description:  Solution to Project Euler, Problem 91
 *
 *        Version:  1.0
 *        Created:  06/16/2017 07:48:04 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The points P (x1, y1) and Q (x2, y2) are plotted at integer co-ordinates and are joined to the origin, O(0,0), to form ΔOPQ.
 *                  There are exactly fourteen triangles containing a right angle that can be formed when each co-ordinate lies between 0 and 2 inclusive;
 *                  that is, 0 ≤ x1, y1, x2, y2 ≤ 2. Given that 0 ≤ x1, y1, x2, y2 ≤ 50, how many right triangles can be formed?
 *         Answer:  14234
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int solve91() {
	uint32_t n = 50;
	uint32_t t = 0;

	for( uint32_t x = 1; x <= n; ++x ) {
		for( uint32_t y = 1; y < n; ++y ) {
			uint32_t m = gcd( x, y );
			t += min( x * m / y, m * ( n - y ) / x );
		}
	}

	return t * 2 + n * n * 3;
}

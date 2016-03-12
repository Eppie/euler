/*
 * =====================================================================================
 *
 *       Filename:  Euler15.cpp
 *
 *    Description:  Solution to Project Euler, Problem 15
 *
 *        Version:  1.0
 *        Created:  08/01/2015 3:18:22 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
 *                  How many such routes are there through a 20×20 grid?
 *         Answer:  137846528820
 * =====================================================================================
 */

// Commentary:
// 2x2 grid --> 6
// 3x3 grid --> 20
// 4x4 grid --> 70
// This series is referred to as the "central binomial coefficients"
// and the nth term can be calculated as choose(2n, n).
// This makes sense intuitively:
// In a 3x3 grid, all the solutions must be of length 6, because you must go right exactly 3 times and down exactly 3 times.
// One possible solution is RRRDDD. There are 6 slots and each slot can be filled with 1 of 2 values. (R or D).
// Thus, we can calculate the number of routes as choose(6, 3).

#include "../helper.hpp"

ull solve15() {
	return choose( 40, 20 );
}

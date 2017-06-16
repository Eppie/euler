/*
 * =====================================================================================
 *
 *       Filename:  Euler39.cpp
 *
 *    Description:  Solution to Project Euler, Problem 39
 *
 *        Version:  1.0
 *        Created:  5/13/2016 2:09:10 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
 *                  {20,48,52}, {24,45,51}, {30,40,50}
 *                  For which value of p ≤ 1000, is the number of solutions maximised?
 *         Answer:  840
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler39 {
int solutions( int p ) {
	int result = 0;

	for( int a = 1; a <= p; a++ ) {
		for( int b = a; b <= p; b++ ) {
			int c = p - a - b;

			if( b <= c && a * a + b * b == c * c ) {
				result++;
			}
		}
	}

	return result;
}
}

int solve39() {
	int bestP = 0;
	int bestT = 0;

	for( int p = 1; p <= 1000; p++ ) {
		int triangles = euler39::solutions( p );

		if( triangles > bestT ) {
			bestT = triangles;
			bestP = p;
		}
	}

	return bestP;
}


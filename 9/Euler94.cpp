/*
 * =====================================================================================
 *
 *       Filename:  Euler94.cpp
 *
 *    Description:  Solution to Project Euler, Problem 94
 *
 *        Version:  1.0
 *        Created:  06/20/2017 08:31:25 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  It is easily proved that no equilateral triangle exists with integral length sides and integral area.
 *                  However, the almost equilateral triangle 5-5-6 has an area of 12 square units.
 *                  We shall define an almost equilateral triangle to be a triangle for which two sides are equal and the third differs by no more than one unit.
 *                  Find the sum of the perimeters of all almost equilateral triangles with integral side lengths and area and whose perimeters
 *                  do not exceed one billion (1,000,000,000).
 *         Answer:  518408346
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int solve94() {
	uint32_t side0 = 1;
	uint32_t side = 1;
	uint32_t s = 0;
	uint32_t p = 0;
	uint32_t tmp = 0;
	int32_t m = 1;
	uint32_t L = 1e9;
	while( p <= L ) {
		tmp = side;
		side = 4 * side - side0 + 2 * m;
		side0 = tmp;
		m = -m;
		s += p;
		p = 3*side - m;
	}
	return s;
}

/*
 * =====================================================================================
 *
 *       Filename:  Euler105.cpp
 *
 *    Description:  Solution to Project Euler, Problem 106
 *
 *        Version:  1.0
 *        Created:  2/12/2018 08:58:04 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:
 *         Answer:  21384
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint32_t solve106() {
	uint32_t result = 0;
	uint32_t n = 12;
	for( uint32_t i = 2; i <= 6; ++i ) {
		result += choose( n, i ) * choose( n - i, i ) / 2;
		result -= choose( n, 2 * i ) * ( choose( 2 * i, i ) / ( i + 1 ) );
	}
	return result;
}

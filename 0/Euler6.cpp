/*
 * =====================================================================================
 *
 *       Filename:  Euler6.cpp
 *
 *    Description:  Solution to Project Euler, Problem 6
 *
 *        Version:  1.1
 *        Created:  07/29/2015 5:52:32 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 *         Answer:  25164150
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint32_t solve6() {
	uint32_t sumOfSquares = 0;
	uint32_t squareOfSums = 0;

	for( auto i = 1; i <= 100; i++ ) {
		sumOfSquares += pow( i, 2 );
		squareOfSums += i;
	}

	squareOfSums = static_cast<uint32_t>( pow( squareOfSums, 2 ) );
	uint32_t result = squareOfSums - sumOfSquares;
	return result;
}

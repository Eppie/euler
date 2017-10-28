/*
 * =====================================================================================
 *
 *       Filename:  Euler28.cpp
 *
 *    Description:  Solution to Project Euler, Problem 28
 *
 *        Version:  1.2
 *        Created:  1/25/2016 01:17:38 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed.
 *                  What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
 *         Answer:  9183
 * =====================================================================================
 */

#include "../helper.hpp"

uint32_t solve28() {
	int L = 1001;
	int n = ( L - 1 ) / 2;
	auto result = static_cast<uint32_t>( ( ( 16 * pow( n, 3 ) ) + ( 30 * pow( n, 2 ) ) + ( 26 * n ) + 3 ) / 3 );
	return result;
}


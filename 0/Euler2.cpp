/*
 * =====================================================================================
 *
 *       Filename:  Euler2.cpp
 *
 *    Description:  Solution to Project Euler, Problem 2
 *
 *        Version:  1.1
 *        Created:  07/29/2015 10:42:25 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
 *         Answer:  4613732
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int solve2() {
	uint32_t term1 = 2;
	uint32_t term2 = 0;
	uint32_t tmp = 0;
	uint32_t result = 0;

	while( term1 < 4e6 ) {
		result += term1;
		tmp = ( 4 * term1 ) + term2;
		term2 = term1;
		term1 = tmp;
	}

	return result;
}

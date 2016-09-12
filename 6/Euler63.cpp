/*
 * =====================================================================================
 *
 *       Filename:  Euler63.cpp
 *
 *    Description:  Solution to Project Euler, Problem 63
 *
 *        Version:  1.0
 *        Created:  9/11/2016 9:23:18 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:
 *         Answer:  49
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int solve63() {
	int result = 0;

	for( int n = 1; n < 10; ++n ) {
		result += 1.0 / ( 1.0 - log10( n ) );
	}

	return result;
}


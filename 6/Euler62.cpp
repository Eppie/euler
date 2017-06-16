/*
 * =====================================================================================
 *
 *       Filename:  Euler62.cpp
 *
 *    Description:  Solution to Project Euler, Problem 62
 *
 *        Version:  1.0
 *        Created:  9/11/2016 12:36:19 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The cube, 41063625 (345³), can be permuted to produce two other cubes:
 *                  56623104 (384³) and 66430125 (405³). In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.
 *                  Find the smallest cube for which exactly five permutations of its digits are cube.
 *         Answer:  127035954683
 *
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler62 {
bool arePermutations( uint64_t a, uint64_t b ) {
	int counts[10] = { 0 };

	while( a != 0 ) {
		counts[a % 10]++;
		a /= 10;
	}

	while( b != 0 ) {
		counts[b % 10]--;
		b /= 10;
	}

	for( int i = 0; i < 10; ++i ) {
		if( counts[i] != 0 ) {
			return false;
		}
	}

	return true;
}
}

uint64_t solve62() {
	uint64_t cubes[8500] = { 0 };
	int permutationsCount = 0;

	for( uint64_t i = 345; i < 8500; ++i ) {
		cubes[i] = i * i * i;
	}

	for( int i = 345; i < 8500; ++i ) {
		permutationsCount = 1;

		for( int j = i + 1; j < 8500; ++j ) {
			if( cubes[j] > pow( 10, numDigits( cubes[i] ) ) ) {
				break;
			}

			if( euler62::arePermutations( cubes[i], cubes[j] ) ) {
				permutationsCount++;
			}
		}

		if( permutationsCount == 5 ) {
			return cubes[i];
		}

	}

	return 0;
}


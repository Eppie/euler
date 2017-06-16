/*
 * =====================================================================================
 *
 *       Filename:  Euler68.cpp
 *
 *    Description:  Solution to Project Euler, Problem 68
 *
 *        Version:  1.0
 *        Created:  9/20/2016 8:29:04 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The description for this one is rather long. See it here: https://projecteuler.net/problem=68
 *         Answer:  6531031914842725
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint64_t solve68() {
	uint64_t result = 0;

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	do {
		if(
			arr[0] + arr[1] + arr[2] == arr[3] + arr[2] + arr[4] &&
			arr[0] + arr[1] + arr[2] == arr[5] + arr[4] + arr[6] &&
			arr[0] + arr[1] + arr[2] == arr[7] + arr[6] + arr[8] &&
			arr[0] + arr[1] + arr[2] == arr[9] + arr[8] + arr[1] &&
			arr[1] != 10 && arr[2] != 10 && arr[4] != 10 && arr[6] != 10 && arr[8] != 10 &&
			arr[3] > arr[0] && arr[5] > arr[0] && arr[7] > arr[0] && arr[9] > arr[0]
		) {
			uint64_t candidate = stoul( to_string( arr[0] ) + to_string( arr[1] ) + to_string( arr[2] )
						+ to_string( arr[3] ) + to_string( arr[2] ) + to_string( arr[4] )
						+ to_string( arr[5] ) + to_string( arr[4] ) + to_string( arr[6] )
						+ to_string( arr[7] ) + to_string( arr[6] ) + to_string( arr[8] )
						+ to_string( arr[9] ) + to_string( arr[8] ) + to_string( arr[1] ) );

			if( candidate > result ) {
				result = candidate;
			}
		}
	} while( next_permutation( arr, arr + 10 ) );

	return result;
}


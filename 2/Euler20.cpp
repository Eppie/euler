/*
 * =====================================================================================
 *
 *       Filename:  Euler20.cpp
 *
 *    Description:  Solution to Project Euler, Problem 20
 *
 *        Version:  1.0
 *        Created:  08/03/2015 10:56:48 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Find the sum of the digits in the number 100!
 *         Answer:  648
 * =====================================================================================
 */

#define NUMDIGITS 160

#include "../helper.hpp"

vector<int> factorial( int n ) {
	// Initialize a vector with NUMDIGITS 0's.
	vector<int> digits( NUMDIGITS, 0 );
	int size = 1;
	digits[0] = 1;

	// This loop mimics multiplication by hand.
	for( int i = 2; i <= n; i++ ) {
		int carry = 0;

		for( int j = 0; j < size; j++ ) {
			int prod = digits[j] * i + carry;
			digits[j] = prod % 10;
			carry = prod / 10;
		}

		while( carry ) {
			digits[size] = carry % 10;
			carry /= 10;
			size++;
		}
	}

	return digits;
}

int solve20() {
	return sum( factorial( 100 ) );
}

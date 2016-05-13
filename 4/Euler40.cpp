/*
 * =====================================================================================
 *
 *       Filename:  Euler40.cpp
 *
 *    Description:  Solution to Project Euler, Problem 40
 *
 *        Version:  1.0
 *        Created:  5/13/2016 31:04:27 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  An irrational decimal fraction is created by concatenating the positive integers:
 *                  0.123456789101112131415161718192021...
 *                  It can be seen that the 12th digit of the fractional part is 1.
 *                  If dn represents the nth digit of the fractional part, find the value of the following expression.
 *                  d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
 *         Answer:  210
 * =====================================================================================
 */

#include "../helper.hpp"

int solve40() {
	int result = 1;
	string s = "";

	// Create the string with 1,000,005 digits
	for( int i = 1; i <= 185185; i++ ) {
		s += to_string( i );
	}

	// Access that string at positions 10⁰, 10¹, 10²...
	for( int p = 0; p <= 6; p++ ) {
		// Convert the char to an int and multiply the result
		result *= s[ pow( 10, p ) - 1 ] - '0';
	}

	return result;
}


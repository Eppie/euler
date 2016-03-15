/*
 * =====================================================================================
 *
 *       Filename:  Euler36.cpp
 *
 *    Description:  Solution to Project Euler, Problem 36
 *
 *        Version:  1.0
 *        Created:  3/14/2016 11:46:13 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.
 *                  Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
 *         Answer:  872187
 * =====================================================================================
 */

#include "../helper.hpp"

string dec2bin( unsigned long n ) {
	string result;

	do {
		result.push_back( '0' + ( n & 1 ) );
	} while( n >>= 1 );

	reverse( result.begin(), result.end() );
	return result;
}


int solve36() {
	int result = 0;

	for( int i = 0; i < 1e6; i++ ) {
		if( isPalindrome( dec2bin( i ) ) && isPalindrome( to_string( i ) ) ) {
			result += i;
		}
	}

	return result;
}


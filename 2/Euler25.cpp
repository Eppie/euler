/*
 * =====================================================================================
 *
 *       Filename:  Euler25.cpp
 *
 *    Description:  Solution to Project Euler, Problem 25
 *
 *        Version:  1.0
 *        Created:  10/23/2015 03:12:49 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *   Organization:  SevOne
 *        Problem:  What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
 *         Answer:  4782
 * =====================================================================================
 */

#include "../helper.hpp"

void add( int *a, int *b, int *c ) {
	int tmp;
	int newDigit;
	int carry = 0;

	for( int i = 0; i < 1000; i++ ) {
		tmp = a[i] + b[i] + carry;
		newDigit = tmp % 10;
		carry = tmp / 10;
		c[i] = newDigit;
	}
}

int main() {
	int count = 2;
	int *a = ( int * ) calloc( 1000, sizeof( int ) );
	int *b = ( int * ) calloc( 1000, sizeof( int ) );
	int *c = ( int * ) calloc( 1000, sizeof( int ) );
	a[0] = 1;
	b[0] = 1;

	while( 1 ) {
		add( a, b, c );
		count += 1;

		if( c[999] != 0 ) {
			cout << count << endl;
			return 0;
		}

		add( c, a, b );
		count += 1;

		if( b[999] != 0 ) {
			cout << count << endl;
			return 0;
		}

		add( b, c, a );
		count += 1;

		if( b[999] != 0 ) {
			cout << count << endl;
			return 0;
		}
	}

	return -1;
}

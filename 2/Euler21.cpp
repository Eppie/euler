/*
 * =====================================================================================
 *
 *       Filename:  Euler21.cpp
 *
 *    Description:  Solution to Project Euler, Problem 21
 *
 *        Version:  1.0
 *        Created:  08/04/2015 09:23:42 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *   Organization:  SevOne
 *        Problem:  Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 *                  If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
 *                  For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
 *                  The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 *                  Evaluate the sum of all the amicable numbers under 10000.
 *         Answer:  31626
 * =====================================================================================
 */

#include "../helper.hpp"

int d( int n ) {
	int result = 1;
	for( int i = 2; i < sqrt(n); i++ ) {
		if( n % i == 0 ) {
			result += i;
			result += n / i ;
		}
	}

	return result;
}

int main() {
	int b;
	int result = 0;

	for( int a = 2; a < 10000; a++ ) {
		b = d( a );
		if( d( b ) == a && a != b ) {
			result += b;
		}
	}
	cout << result << endl;

	return 0;
}
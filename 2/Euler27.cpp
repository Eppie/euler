/*
 * =====================================================================================
 *
 *       Filename:  Euler27.cpp
 *
 *    Description:  Solution to Project Euler, Problem 27
 *
 *        Version:  1.0
 *        Created:  12/18/2015 10:14:59 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Considering quadratics of the form: n² + an + b, where |a| < 1000 and |b| < 1000
 *                  Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes
 *                  for consecutive values of n, starting with n = 0.
 *         Answer:  -59231
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler27 {
long long formula( int a, int b, int n ) {
	return ( n * n ) + ( a * n ) + b;
}
}

int solve27() {
	int n;
	int best = 0;
	long long result;
	int answer = 0;

	for( int a = -1000; a <= 1000; a++ ) {
		for( int b = -1000; b <= 1000; b++ ) {
			n = 0;
			result = euler27::formula( a, b, n );

			while( result > 0 && isPrime( result ) ) {
				result = euler27::formula( a, b, n );
				n++;
			}

			if( n > best ) {
				best = n;
				answer = a * b;
			}
		}
	}

	return answer;
}

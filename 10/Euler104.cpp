/*
 * =====================================================================================
 *
 *       Filename:  Euler104.cpp
 *
 *    Description:  Solution to Project Euler, Problem 104
 *
 *        Version:  1.0
 *        Created:  10/27/2017 09:28:38 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The Fibonacci sequence is defined by the recurrence relation:
 *                  Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
 *                  It turns out that F541, which contains 113 digits, is the first Fibonacci number for which the last nine digits are 1-9 pandigital
 *                  (contain all the digits 1 to 9, but not necessarily in order). And F2749, which contains 575 digits, is the first Fibonacci number for which
 *                  the first nine digits are 1-9 pandigital.
 *                  Given that Fk is the first Fibonacci number for which the first nine digits AND the last nine digits are 1-9 pandigital, find k.
 *         Answer:  329468
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint32_t solve104() {
	uint32_t fn2 = 1;
	uint32_t fn1 = 1;
	uint32_t tail = 1000000000;

	uint32_t n = 2;
	bool found = false;
	uint32_t fn;
	double t;

	// See Binet's formula: https://en.wikipedia.org/wiki/Fibonacci_number#Closed-form_expression
	auto sqrt5 = sqrt( 5 );
	auto phi = ( 1 + sqrt5 ) / 2;
	auto logsqrt5 = log10( sqrt5 );
	auto logphi = log10( phi );

	while( !found ) {
		++n;
		fn = ( fn1 + fn2 ) % tail;
		fn2 = fn1;
		fn1 = fn;

		if( isPandigital( fn ) ) {
			t = ( n * logphi - logsqrt5 );

			if( isPandigital( uint64_t( pow( 10, t - int( t ) + 8 ) ) ) ) {
				found = true;
			}
		}
	}

	return n;
}

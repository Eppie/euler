/*
 * =====================================================================================
 *
 *       Filename:  Euler33.cpp
 *
 *    Description:  Solution to Project Euler, Problem 33
 *
 *        Version:  1.1
 *        Created:  3/13/2016 2:18:31 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it
 *                  may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
 *                  We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 *                  There are exactly four non-trivial examples of this type of fraction,
 *                  less than one in value, and containing two digits in the numerator and denominator.
 *                  If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
 *         Answer:  100
 * =====================================================================================
 */

#include "../helper.hpp"

int solve33() {
	int nums = 1;
	int denoms = 1;

	for( int i = 10; i < 100; i++ ) {
		for( int j = i; j < 100; j++ ) {
			// Avoid trivial cases like 77/99 = 7/9
			if( i % 11 != 0 ) {
				// Make sure the digits we're cancelling are the same
				if( ( i % 10 ) == ( j / 10 ) ) {
					double fraction = double( i ) / double( j );
					int num = i / 10;
					int denom = j % 10;
					double result = double( num ) / double( denom );

					// If the original fraction and the cancelled fraction are the same, update our product
					if( floatCompare( fraction, result ) ) {
						nums *= num;
						denoms *= denom;
					}
				}
			}
		}
	}

	// Get the result in lowest common terms
	int g = gcd( nums, denoms );
	int result = denoms / g;
	return result;
}


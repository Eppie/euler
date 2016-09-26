/*
 * =====================================================================================
 *
 *       Filename:  Euler75.cpp
 *
 *    Description:  Solution to Project Euler, Problem 75
 *
 *        Version:  1.0
 *        Created:  9/25/2016 11:14:42 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  It turns out that 12 cm is the smallest length of wire that can be bent to form an integer sided right angle triangle in exactly one way,
 *                  but there are many more examples.
 *
 *                  12 cm: (3,4,5)
 *                  24 cm: (6,8,10)
 *                  30 cm: (5,12,13)
 *                  36 cm: (9,12,15)
 *                  40 cm: (8,15,17)
 *                  48 cm: (12,16,20)
 *
 *                  In contrast, some lengths of wire, like 20 cm, cannot be bent to form an integer sided right angle triangle,
 *                  and other lengths allow more than one solution to be found; for example, using 120 cm it is possible to form
 *                  exactly three different integer sided right angle triangles.
 *
 *                  120 cm: (30,40,50), (20,48,52), (24,45,51)
 *
 *                  Given that L is the length of the wire, for how many values of L ≤ 1,500,000
 *                  can exactly one integer sided right angle triangle be formed?
 *         Answer:  161667
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int solve75() {
	int result = 0;
	static int cache[1500001];

	for( int n = 2; n < 864; ++n ) {
		for( int m = 1; m < n; ++m ) {
			// To avoid generating non-primitive triples, m and n must be coprime
			if( gcd( m, n ) != 1 ) {
				continue;
			}

			// To avoid generating non-primitive triples, m and n must not both be odd
			if( m % 2 == 1 && n % 2 == 1 ) {
				continue;
			}

			int a = ( n * n ) - ( m * m );
			int b = 2 * n * m;
			int c = ( n * n ) + ( m * m );
			int L = a + b + c;
			int i = 2;

			// Iterate over the multiples of this triple
			while( L <= 1500000 ) {
				++cache[L];
				int new_a = a * i;
				int new_b = b * i;
				int new_c = c * i;
				L = new_a + new_b + new_c;
				++i;
			}
		}
	}

	for( int i = 0; i < 1500000; ++i ) {
		if( cache[i] == 1 ) {
			++result;
		}
	}

	return result;
}


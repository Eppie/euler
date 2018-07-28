/*
 * =====================================================================================
 *
 *       Filename:  Euler88.cpp
 *
 *    Description:  Solution to Project Euler, Problem 88
 *
 *        Version:  1.0
 *        Created:  06/09/2017 08:01:06 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  A natural number, N, that can be written as the sum and product of a given set of at least two natural numbers,
 *                  {a1, a2, ... , ak} is called a product-sum number: N = a1 + a2 + ... + ak = a1 × a2 × ... × ak.
 *                  For example, 6 = 1 + 2 + 3 = 1 × 2 × 3.
 *                  For a given set of size, k, we shall call the smallest N with this property a minimal product-sum number.
 *                  The minimal product-sum numbers for sets of size, k = 2, 3, 4, 5, and 6 are as follows.
 *                  k=2: 4 = 2 × 2 = 2 + 2
 *                  k=3: 6 = 1 × 2 × 3 = 1 + 2 + 3
 *                  k=4: 8 = 1 × 1 × 2 × 4 = 1 + 1 + 2 + 4
 *                  k=5: 8 = 1 × 1 × 2 × 2 × 2 = 1 + 1 + 2 + 2 + 2
 *                  k=6: 12 = 1 × 1 × 1 × 1 × 2 × 6 = 1 + 1 + 1 + 1 + 2 + 6
 *                  Hence for 2≤k≤6, the sum of all the minimal product-sum numbers is 4+6+8+12 = 30; note that 8 is only counted once in the sum.
 *                  In fact, as the complete set of minimal product-sum numbers for 2≤k≤12 is {4, 6, 8, 12, 15, 16}, the sum is 61.
 *                  What is the sum of all the minimal product-sum numbers for 2≤k≤12000?
 *         Answer:  7587457
 *
 * =====================================================================================
 */

#include "../helper.hpp"

#define KMAX 12001

vector<int> n( KMAX, 2 * KMAX );

namespace euler88 {
void prodsum( int product, int sum, int num_factors, int start ) {
	int k = product - sum + num_factors;

	if( k < KMAX ) {
		if( product < n[k] ) {
			n[k] = product;
		}

		for( int i = start; i < ( KMAX / product * 2 ) + 1; ++i ) {
			prodsum( product * i, sum + i, num_factors + 1, i );
		}
	}
}
}

#undef KMAX

int solve88() {
	euler88::prodsum( 1, 1, 1, 2 );
	sort( n.begin(), n.end() );
	auto itr = unique( n.begin(), n.end() );
	return accumulate( n.begin() + 1, itr - 1, 0 );
}

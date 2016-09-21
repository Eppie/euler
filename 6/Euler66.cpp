/*
 * =====================================================================================
 *
 *       Filename:  Euler66.cpp
 *
 *    Description:  Solution to Project Euler, Problem 66
 *
 *        Version:  1.0
 *        Created:  9/14/2016 3:33:24 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Consider quadratic Diophantine equations of the form:
 *
 *                  x² – Dy² = 1
 *
 *                  For example, when D=13, the minimal solution in x is 649² – 13×180² = 1.
 *                  It can be assumed that there are no solutions in positive integers when D is square.
 *                  By finding minimal solutions in x for D = {2, 3, 5, 6, 7}, we obtain the following:
 *
 *                  3² – 2×2² = 1
 *                  2² – 3×1² = 1
 *                  9² – 5×4² = 1
 *                  5² – 6×2² = 1
 *                  8² – 7×3² = 1
 *
 *                  Hence, by considering minimal solutions in x for D ≤ 7, the largest x is obtained when D=5.
 *                  Find the value of D ≤ 1000 in minimal solutions of x for which the largest value of x is obtained.
 *         Answer:  661
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int solve66() {
	int result = 0;
	mpz_class pmax = 0;

	for( int D = 2; D <= 1000; D++ ) {
		mpz_class limit = sqrt( D );

		// Skip perfect squares
		if( D == limit * limit ) {
			continue;
		}

		mpz_class m = 0;
		mpz_class d = 1;
		mpz_class a = limit;

		mpz_class numm1 = 1;
		mpz_class num = a;

		mpz_class denm1 = 0;
		mpz_class den = 1;


		while( ( num * num ) - ( D * ( den * den ) ) != 1 ) {
			m = d * a - m;
			d = ( D - m * m ) / d;
			a = ( limit + m ) / d;

			mpz_class numm2 = numm1;
			numm1 = num;
			mpz_class denm2 = denm1;
			denm1 = den;

			num = a * numm1 + numm2;
			den = a * denm1 + denm2;
		}

		if( num > pmax ) {
			pmax = num;
			result = D;
		}
	}

	return result;
}


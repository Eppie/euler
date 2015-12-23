/*
 * =====================================================================================
 *
 *       Filename:  Euler26.cpp
 *
 *    Description:  Solution to Project Euler, Problem 26
 *
 *        Version:  1.0
 *        Created:  10/25/2015 03:59:08 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *   Organization:  SevOne
 *        Problem:  Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 *         Answer:  983
 * =====================================================================================
 */

#include "../helper.hpp"
#include <boost/multiprecision/mpfr.hpp>

using namespace boost::multiprecision;

int main() {
	mpfr_float::default_precision(2000);
	vector<mpfr_float> results;
	for( int i = 1; i <= 1000; i++ ) {
		mpfr_float a = 1;
		mpfr_float b = i;
		cout << setprecision(2000) << a / b << endl;
	}

	return 0;
}


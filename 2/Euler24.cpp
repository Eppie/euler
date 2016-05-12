/*
 * =====================================================================================
 *
 *       Filename:  Euler24.cpp
 *
 *    Description:  Solution to Project Euler, Problem 24
 *
 *        Version:  1.0
 *        Created:  09/17/2015 03:50:12 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 *         Answer:  2783915460
 * =====================================================================================
 */

#include "../helper.hpp"

ull permutation( vector<int> v, int n ) {
	vector<int> perm;

	while( !v.empty() ) {
		int div = factorial( v.size() - 1 );
		int pos = n / div;
		n = n % div;
		perm.push_back( v[pos] );
		v.erase( v.begin() + pos );
	}

	ull result = 0;
	ull mult = 1;

	for( int i = 9; i >= 0; i-- ) {
		result += mult * perm[i];
		mult *= 10;
	}

	return result;

}

ull solve24() {
	return permutation( vector<int> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 999999 );
}

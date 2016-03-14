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

vector<vector<char>> result;

inline vector<char> stringToVector( string str ) {
	return vector<char>( str.begin(), str.end() );
}

inline void permutations( vector<char> s, unsigned step = 0 ) {
	if( s.size() == step ) {
		result.push_back( s );
	}

	for( unsigned i = step; i < s.size(); i++ ) {
		vector<char> sCopy( s );
		char tmp = sCopy[step];
		sCopy[step] = sCopy[i];
		sCopy[i] = tmp;
		permutations( sCopy, step + 1 );
	}
}

string solve24() {
	permutations( stringToVector( "0123456789" ) );
	sort( result.begin(), result.end() );
	return string( result[999999].begin(), result[999999].end() );
}

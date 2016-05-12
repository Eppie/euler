/*
 * =====================================================================================
 *
 *       Filename:  Euler22.cpp
 *
 *    Description:  Solution to Project Euler, Problem 22
 *
 *        Version:  1.0
 *        Created:  08/04/2015 04:35:14 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  When the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
 *                  What is the total of all the name scores in the file?
 *         Answer:  871198282
 * =====================================================================================
 */

#include "../helper.hpp"

int score( string s ) {
	int result = 0;

	for( auto c : s ) {
		result += static_cast<int>( c ) - 64;
	}

	// ASCII code for '"' is 34, so subtract 68. Also, add 128 for the two extra 64's we subtracted earlier.
	return result + 60;
}

int solve22() {
	int result = 0;
	int thisScore;
	vector<string> names = loadDataFromFile( "2/names.txt" );
	sort( names.begin(), names.end() );

	for( auto it = names.begin(); it != names.end(); ++it ) {
		thisScore = score( *it );
		thisScore *= it - names.begin() + 1;
		result += thisScore;
	}

	return result;
}

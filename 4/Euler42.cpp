/*
 * =====================================================================================
 *
 *       Filename:  Euler42.cpp
 *
 *    Description:  Solution to Project Euler, Problem 42
 *
 *        Version:  1.1
 *        Created:  5/13/2016 5:38:28 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:
 *                  1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *                  By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value.
 *                  For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
 *                  Using words.txt, a text file containing nearly two-thousand common English words, how many are triangle words?
 *         Answer:  162
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler42 {
int wordValue( string word ) {
	int result = 0;

	for( auto c : word ) {
		result += c - 64;
	}

	// ASCII code for '"' is 34, so subtract 68. Also, add 128 for the two extra 64's we subtracted earlier.
	return result + 60;

}
}

int solve42() {
	int result = 0;
	vector<string> words = loadDataFromFile( "4/words.txt" );
	set<int> triangleNumbers;

	for( int i = 1; i <= 18; i++ ) {
		triangleNumbers.insert( ( i * ( i + 1 ) ) / 2 );
	}

	for( auto && word : words ) {
		if( triangleNumbers.find( euler42::wordValue( word ) ) != triangleNumbers.end() ) {
			result += 1;
		}
	}

	return result;
}


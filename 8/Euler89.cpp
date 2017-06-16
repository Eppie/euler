/*
 * =====================================================================================
 *
 *       Filename:  Euler89.cpp
 *
 *    Description:  Solution to Project Euler, Problem 89
 *
 *        Version:  1.0
 *        Created:  06/12/2017 08:10:26 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  For a number written in Roman numerals to be considered valid there are basic rules which must be followed.
 *                  Even though the rules allow some numbers to be expressed in more than one way there is always a "best" way of writing a particular number.
 *                  For example, it would appear that there are at least six ways of writing the number sixteen:
 *                  IIIIIIIIIIIIIIII
 *                  VIIIIIIIIIII
 *                  VVIIIIII
 *                  XIIIIII
 *                  VVVI
 *                  XVI
 *                  However, according to the rules only XIIIIII and XVI are valid, and the last example is considered to be the most efficient,
 *                  as it uses the least number of numerals.
 *                  The 11K text file, roman.txt, contains one thousand numbers written in valid, but not necessarily minimal, Roman numerals.
 *                  Find the number of characters saved by writing each of these in their minimal form.
 *                  Note: You can assume that all the Roman numerals in the file contain no more than four consecutive identical units.
 *         Answer:  743
 *
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler89 {
void replace( string &subject, const string &search, const string &replace ) {
	size_t pos = 0;

	while( ( pos = subject.find( search, pos ) ) != string::npos ) {
		subject.replace( pos, search.length(), replace );
		pos += replace.length();
	}
}
}

int solve89() {
	vector<string> replacements = { "DCCCC", "LXXXX", "VIIII", "IIII", "XXXX", "CCCC" };
	auto strings = loadDataFromFile( "8/roman.txt" );
	int original_length = 0;
	int new_length = 0;

	for( auto && string : strings ) {
		original_length += string.size();

		for( auto && replacement : replacements ) {
			euler89::replace( string, replacement, "  " );
		}

		new_length += string.size();
	}

	return original_length - new_length;
}

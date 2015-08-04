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
 *   Organization:  SevOne
 *        Problem:  When the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
 *                  What is the total of all the name scores in the file?
 *         Answer:  871198282
 * =====================================================================================
 */

#include "../helper.hpp"

int main() {
	vector<int> scores;
	int score;
	vector<string> names = loadDataFromFile( "names.txt" );
	sort( names.begin(), names.end() );
	for( auto it = names.begin(); it != names.end(); ++it ) {
		cout << it - names.begin() << endl;
		score = 1;
		score *= it - names.begin();
		scores.push_back( score );
	}
	cout << sum( scores ) << endl;
	return 0;
}

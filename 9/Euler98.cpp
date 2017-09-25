/*
 * =====================================================================================
 *
 *       Filename:  Euler98.cpp
 *
 *    Description:  Solution to Project Euler, Problem 98
 *
 *        Version:  1.1
 *        Created:  08/31/2017 03:25:33 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  By replacing each of the letters in the word CARE with 1, 2, 9, and 6 respectively, we form a square number: 1296 = 36².
 *                  What is remarkable is that, by using the same digital substitutions, the anagram, RACE, also forms a square number: 9216 = 96².
 *                  We shall call CARE (and RACE) a square anagram word pair and specify further that leading zeroes are not permitted,
 *                  neither may a different letter have the same digital value as another letter. Using words.txt, a 16K text file containing
 *                  nearly two-thousand common English words, find all the square anagram word pairs (a palindromic word is NOT considered to be an anagram of itself).
 *                  What is the largest square number formed by any member of such a pair?
 *                  NOTE: All anagrams formed must be contained in the given text file.
 *         Answer:  18769
 *
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler98 {
uint32_t solve( string a, string b, vector<uint32_t> &squares ) {
	uint32_t result = 0;

	for( uint32_t i = 0; i < squares.size(); ++i ) {
		uint32_t squareLength = numDigits( squares[i] );

		if( squareLength < a.size() ) {
			continue;
		}

		if( squareLength > a.size() ) {
			break;
		}

		bool match = true;
		uint32_t square = squares[i];
		map<char, uint32_t> m;
		vector<uint32_t> digits;

		for( int32_t j = a.size() - 1; j >= 0; --j ) {
			uint32_t digit = square % 10;
			square /= 10;
			auto it = m.find( a[j] );

			if( it != m.end() ) {
				if( m[a[j]] == digit ) {
					continue;
				} else {
					match = false;
					break;
				}
			}

			if( find( digits.begin(), digits.end(), digit ) != digits.end() ) {
				match = false;
				break;
			}

			m[a[j]] = digit;
			digits.push_back( digit );
		}

		if( !match ) {
			continue;
		}

		uint32_t bvalue = 0;

		if( m[b[0]] == 0 ) {
			match = false;
		} else {
			for( uint32_t j = 0; j < b.size(); ++j ) {
				bvalue = bvalue * 10 + m[b[j]];
			}
		}

		if( !match ) {
			continue;
		}

		if( binary_search( squares.begin(), squares.end(), bvalue ) ) {
			uint32_t maxpair = max( bvalue, square );
			result = max( result, maxpair );
		}
	}

	return result;
}
}

uint32_t solve98() {
	uint32_t result = 0;
	vector<string> words = loadDataFromFile( "9/words.txt" );
	map<string, vector<string>> anagrams;

	for( auto && w : words ) {
		w.erase( 0, 1 );
		w.erase( w.size() - 1 );
		string key = w;
		sort( key.begin(), key.end() );
		auto it = anagrams.find( key );

		if( it != anagrams.end() ) {
			anagrams[key].push_back( w );
		} else {
			anagrams[key] = { w };
		}
	}

	vector<uint32_t> squares;

	for( uint32_t i = 2; i < 31700; ++i ) {
		squares.push_back( i * i );
	}

	for( auto && k : anagrams ) {
		// Skip all the words that don't have any anagrams
		if( k.second.size() < 2 ) {
			continue;
		}

		// Check each pair of anagrams
		for( uint32_t i = 0; i < k.second.size(); ++i ) {
			for( uint32_t j = i + 1; j < k.second.size(); ++j ) {
				uint32_t value = euler98::solve( k.second[i], k.second[j], squares );

				if( value > result ) {
					result = value;
				}
			}
		}
	}

	return result;
}


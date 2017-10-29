/*
 * =====================================================================================
 *
 *       Filename:  Euler54.cpp
 *
 *    Description:  Solution to Project Euler, Problem 54
 *
 *        Version:  1.2
 *        Created:  8/31/2016 5:08:11 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:
 *                  High Card: Highest value card.
 *                  One Pair: Two cards of the same value.
 *                  Two Pairs: Two different pairs.
 *                  Three of a Kind: Three cards of the same value.
 *                  Straight: All cards are consecutive values.
 *                  Flush: All cards of the same suit.
 *                  Full House: Three of a kind and a pair.
 *                  Four of a Kind: Four cards of the same value.
 *                  Straight Flush: All cards are consecutive values of same suit.
 *                  Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
 *                  The cards are valued in the order:
 *                  2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.
 *
 *                  If two players have the same ranked hands then the rank made up of the highest value wins;
 *                  for example, a pair of eights beats a pair of fives (see example 1 below).
 *                  But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared (see example 4 below);
 *                  if the highest cards tie then the next highest cards are compared, and so on.
 *                  Consider the following five hands dealt to two players:

 *                  Hand		Player 1		Player 2		Winner
 *                     1		5H 5C 6S 7S KD		2C 3S 8S 8D TD		Player 2
 *                     2		5D 8C 9S JS AC		2C 5C 7D 8S QH		Player 1
 *                     3		2D 9C AS AH AC		3D 6D 7D TD QD		Player 2
 *                     4		4D 6S 9H QH QC		3D 6D 7H QD QS		Player 1
 *                     5		2H 2D 4C 4D 4S		3C 3D 3S 9S 9D		Player 1
 *
 *                  The file, poker.txt, contains one-thousand random hands dealt to two players.
 *                  Each line of the file contains ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards.
 *                  You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order,
 *                  and in each hand there is a clear winner.

 *                  How many hands does Player 1 win?
 *         Answer:  376
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler54 {
/*
 * Count how many of each card appears in the hand
 */
vector<int> rankCounts( vector<string> hand ) {
	static unordered_map<char, int> ranks = {
		{'2', 0},
		{'3', 1},
		{'4', 2},
		{'5', 3},
		{'6', 4},
		{'7', 5},
		{'8', 6},
		{'9', 7},
		{'T', 8},
		{'J', 9},
		{'Q', 10},
		{'K', 11},
		{'A', 12}
	};
	vector<int> counts( 13, 0 );

	for( auto && card : hand ) {
		counts[ranks[card[0]]]++;
	}

	return counts;
}

bool hasFlush( vector<string> hand ) {
	char c = hand[0][1];

	for( auto && card : hand ) {
		if( c != card[1] ) {
			return false;
		}
	}

	return true;
}

bool hasStraight( vector<int> counts ) {
	for( int i = 0; i <= 8; ++i ) {
		if( counts[i] == 1 && counts[i + 1] == 1 && counts[i + 2] == 1 && counts[i + 3] == 1 && counts[i + 4] == 1 ) {
			return true;
		}
	}

	return false;
}

int getBaseScore( vector<int> ranks ) {
	int result = 0;

	// Iterate from more occurrences to fewer (four of a kind, three of a kind, pair, etc)
	for( int i = 4; i > 0; --i ) {
		// Iterate from ace down to two
		for( int j = 12; j >= 0; --j ) {
			// If there are i occurrences of card with rank j in the hand
			if( ranks[j] == i ) {
				// Shift j into the lower 4 bits i times.
				for( int k = 0; k < i; ++k ) {
					result = result << 4 | j;
				}
			}
		}
	}

	return result;
}

int score( const vector<string> &hand ) {
	int result = 0;
	auto counts = rankCounts( hand );

	// Count the number of pairs, three of a kind, etc. E.g. if there are two pairs, countsHist[2] == 2.
	vector<int> countsHist( 5, 0 );

	for( auto && count : counts ) {
		countsHist[count]++;
	}

	int baseScore = getBaseScore( counts );
	bool flush = hasFlush( hand );
	bool straight = hasStraight( counts );

	// There are no royal flushes, straight flushes, or four of a kinds in the data, so no need to handle them.
	if( countsHist[3] == 1 && countsHist[2] == 1 ) { // full house
		result = 6;
	} else if( flush ) { // flush
		result = 5;
	} else if( straight ) { // straight
		result = 4;
	} else if( countsHist[3] == 1 ) { // three of a kind
		result = 3;
	} else if( countsHist[2] == 2 ) { // two pairs
		result = 2;
	} else if( countsHist[2] == 1 ) { // one pair
		result = 1;
	}

	return result << 20 | baseScore;
}
}

int solve54() {
	int result = 0;
	string line;
	vector<string> data;
	ifstream file( "5/poker.txt" );

	while( getline( file, line, '\n' ) ) {
		try {
			data.push_back( line );
		} catch( const invalid_argument &ia ) {
			cerr << "Check your input file: " << "5/poker.txt" << endl;
			throw;
		}
	}

	for( auto && s : data ) {
		stringstream ss;
		ss.str( s );
		string item;
		int i = 0;
		vector<string> hand1;
		vector<string> hand2;

		while( getline( ss, item, ' ' ) ) {
			if( i < 5 ) {
				hand1.push_back( item );
			} else {
				hand2.push_back( item );
			}

			++i;
		}

		if( euler54::score( hand1 ) > euler54::score( hand2 ) ) {
			result++;
		}
	}

	return result;
}


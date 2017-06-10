/*
 * =====================================================================================
 *
 *       Filename:  Euler84.cpp
 *
 *    Description:  Solution to Project Euler, Problem 84
 *
 *        Version:  1.0
 *        Created:  06/04/2017 04:01:27 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The heart of this problem concerns the likelihood of visiting a particular square.
 *                  That is, the probability of finishing at that square after a roll. For this reason it should be clear that,
 *                  with the exception of G2J for which the probability of finishing on it is zero, the CH squares will have the lowest probabilities,
 *                  as 5/8 request a movement to another square, and it is the final square that the player finishes at on each roll that we are interested in.
 *                  We shall make no distinction between "Just Visiting" and being sent to JAIL,
 *                  and we shall also ignore the rule about requiring a double to "get out of jail", assuming that they pay to get out on their next turn.
 *                  By starting at GO and numbering the squares sequentially from 00 to 39 we can concatenate these two-digit numbers
 *                  to produce strings that correspond with sets of squares. Statistically it can be shown that the three most popular squares,
 *                  in order, are JAIL (6.24%) = Square 10, E3 (3.18%) = Square 24, and GO (3.09%) = Square 00.
 *                  So these three most popular squares can be listed with the six-digit modal string: 102400.
 *                  If, instead of using two 6-sided dice, two 4-sided dice are used, find the six-digit modal string.
 *                  See the full problem here: https://projecteuler.net/problem=84
 *         Answer:  101524
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int solve84() {
	uint32_t rolls = 500000;
	uint32_t num_squares = 40;
	uint32_t community_squares[3] = { 2, 17, 33 };
	uint32_t chance_squares[3] = { 7, 22, 36 };
	uint32_t next_railway[3] = { 15, 25,  5 }; // index x corresponds to chance_squares[x]
	uint32_t next_utility[3] = { 12, 28, 12 }; // index x corresponds to chance_squares[x]
	uint32_t chance_index = 0;
	uint32_t community_index = 0;

	uint32_t current = 0;
	uint32_t doubles_count = 0;
	vector<uint32_t> count( num_squares, 0 );

	for( uint32_t r = 0; r < rolls; ++r ) {
		uint32_t die1 = ( random_int() % 4 ) + 1;
		uint32_t die2 = ( random_int() % 4 ) + 1;
		uint32_t next = ( current + die1 + die2 ) % num_squares;

		// Rolled doubles?
		if( die1 == die2 ) {
			++doubles_count;
		} else {
			doubles_count = 0;
		}

		// Three doubles_count in a row?
		if( doubles_count == 3 ) {
			next = 10;
			doubles_count = 0;
		}

		// Landed on a chance square
		if( next == chance_squares[0] || next == chance_squares[1] || next == chance_squares[2] ) {
			int id = 0;

			if( next == chance_squares[1] ) {
				id = 1;
			}

			if( next == chance_squares[2] ) {
				id = 2;
			}

			// Draw a chance card
			switch( chance_index ) {
				case 0:
					next = 0;
					break;

				case 1:
					next = 10;
					break;

				case 2:
					next = 11;
					break;

				case 3:
					next = 24;
					break;

				case 4:
					next = 39;
					break;

				case 5:
					next =  5;
					break;

				case 6:
					next = ( next + num_squares - 3 ) % num_squares;
					break;

				case 7:
					next = next_railway[id];
					break;

				case 8:
					next = next_utility[id];
					break;

				default:
					break;
			}

			chance_index = ++chance_index % 16;
		}

		// Landed on a community square
		if( next == community_squares[0] || next == community_squares[1] || next == community_squares[2] ) {
			// Draw a community card
			switch( community_index ) {
				case 0:
					next = 0;
					break;

				case 1:
					next = 10;
					break;

				default:
					break;
			}

			community_index = ++community_index % 16;
		}

		if( next == 30 ) {
			next = 10;
		}

		// Count the fact that we landed on this square
		count[next]++;
		current = next;
	}

	// Construct the result
	map<uint32_t, uint32_t> sorted;

	for( uint32_t i = 0; i < num_squares; i++ ) {
		sorted.insert( make_pair( count[i], i ) );
	}

	int result = 0;
	int multiplier = 10000; // Used to shift the numbers to the correct places
	auto i = sorted.rbegin();

	for( int j = 0; j < 3; ++i, ++j ) {
		result += i->second * multiplier;
		multiplier /= 100;
	}

	return result;
}

/*
 * =====================================================================================
 *
 *       Filename:  Euler51.cpp
 *
 *    Description:  Solution to Project Euler, Problem 51
 *
 *        Version:  1.2
 *        Created:  8/30/2016 6:21:31 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
 *                  By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes
 *                  among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993.
 *                  Consequently 56003, being the first member of this family, is the smallest prime with this property.
 *                  Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
 *         Answer:  121313
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler51 {
int generateNumber( int repNumber, vector<int> filledPattern ) {
	int temp = 0;

	for( auto && i : filledPattern ) {
		temp *= 10;
		temp += ( i == -1 ) ? repNumber : i;
	}

	return temp;
}

vector<int> fillPattern( int pattern, int number, int patternLength ) {
	vector<int> filledPattern( patternLength );
	int temp = number;

	for( int i = patternLength - 1; 0 <= i; --i ) {
		if( ( ( pattern & ( 1 << i ) ) >> i ) == 1 ) {
			filledPattern[i] = temp % 10;
			temp /= 10;
		} else {
			filledPattern[i] = -1;
		}
	}

	return filledPattern;
}
}

int solve51() {
	vector<int> fiveDigitPatterns = {
		0b10001,
		0b10010,
		0b10100,
		0b11000
	};

	vector<int> sixDigitPatterns = {
		0b100011,
		0b100101,
		0b101001,
		0b110001,
		0b100110,
		0b101010,
		0b110010,
		0b101100,
		0b110100,
		0b111000
	};

	int result = 10000000;

	for( int i = 11; i < 1000; i += 2 ) {
		if( i % 5 == 0 ) {
			continue;
		}

		auto patterns = ( i < 100 ) ? fiveDigitPatterns : sixDigitPatterns;
		int length = ( i < 100 ) ? 5 : 6;

		for( int j = 0; j < length; ++j ) {
			for( int k = 0; k <= 2; ++k ) {
				if( ~( ( patterns[j] & ( 1 << length ) ) >> length ) && k == 0 ) {
					continue;
				}

				vector<int> pattern = euler51::fillPattern( patterns[j], i, length );
				int candidate = euler51::generateNumber( k, pattern );

				if( candidate < result && isPrime( candidate ) ) {
					int familySize = 1;

					for( int l = k + 1; l < 10; ++l ) {
						if( isPrime( euler51::generateNumber( l, pattern ) ) ) {
							++familySize;
						}
					}

					if( familySize == 8 ) {
						result = candidate;
					}
				}

				break;
			}

		}

	}

	return result;
}


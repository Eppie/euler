/*
 * =====================================================================================
 *
 *       Filename:  Euler23.cpp
 *
 *    Description:  Solution to Project Euler, Problem 23
 *
 *        Version:  1.0
 *        Created:  09/08/2015 04:14:09 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *   Organization:  SevOne
 *        Problem:  A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
 *                  For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 *                  A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 *                  As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24.
 *                  By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
 *                  However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers
 *                  is less than this limit. Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 *         Answer:  4179871
 * =====================================================================================
 */

#include "../helper.hpp"

bool isAbundant( int n ) {
	int result = 1;

	for( int i = 2; i <= sqrt( n ); i++ ) {
		if( n % i == 0 ) {
			result += i;

			if( n / i > i ) {
				result += n / i;
			}
		}
	}

	return result > n;
}

int solve( set<int> values ) {
	int result = 0;
	int diff;

	for( int i = 1; i <= 28123; i++ ) {
		for( auto it = values.begin(); it != values.end(); ++it ) {
			diff = i - *it;

			if( diff < 0 ) {
				continue;
			}

			auto got = values.find( diff );

			if( got != values.end() ) {
				result += i;
				break;
			}
		}
	}

	return result;
}

int main() {
	set<int> values;
	int total = 0;

	for( int i = 1; i <= 28123; i++ ) {
		total += i;

		if( isAbundant( i ) ) {
			values.insert( i );
		}
	}

	int result = solve( values );
	cout << total - result << endl;
	return 0;
}

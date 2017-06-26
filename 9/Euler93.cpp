/*
 * =====================================================================================
 *
 *       Filename:  Euler93.cpp
 *
 *    Description:  Solution to Project Euler, Problem 93
 *
 *        Version:  1.0
 *        Created:  06/19/2017 07:50:41 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  By using each of the digits from the set, {1, 2, 3, 4}, exactly once, and making use of the four arithmetic operations (+, −, *, /)
 *                  and brackets/parentheses, it is possible to form different positive integer targets.
 *                  For example,
 *
 *                  8 = (4 * (1 + 3)) / 2
 *                  14 = 4 * (3 + 1 / 2)
 *                  19 = 4 * (2 + 3) − 1
 *                  36 = 3 * 4 * (2 + 1)
 *
 *                  Note that concatenations of the digits, like 12 + 34, are not allowed.
 *                  Using the set, {1, 2, 3, 4}, it is possible to obtain thirty-one different target numbers of which 36 is the maximum,
 *                  and each of the numbers 1 to 28 can be obtained before encountering the first non-expressible number.
 *                  Find the set of four distinct digits, a < b < c < d, for which the longest set of consecutive positive integers,
 *                  1 to n, can be obtained, giving your answer as a string: abcd.
 *         Answer:  1258
 *
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler93 {
const double Epsilon = 0.00001;
// try all arithmetic operations of any two elements of "numbers", set their result in "used" to true
void eval( const vector<double> &numbers, vector<bool> &used ) {
	// 1. if array holds just one element, add it to the "used" list and we are done
	// 2. pick any two numbers
	// 3. loop through all operators
	// 4. add result to the array and call eval() recursively

	// step 1
	if( numbers.size() == 1 ) {
		auto result = numbers.front() + Epsilon;

		// reject non-integer result (caused by division)
		if( fmod( result, 1 ) > 10 * Epsilon ) {
			return;
		}

		int index = int( result + Epsilon );

		// reject negative and very large results
		if( index >= 0 && index < ( int )used.size() ) {
			used[index] = true;
		}

		return;
	}

	// step 2
	auto next = numbers;

	for( size_t i = 0; i < numbers.size(); i++ )
		for( size_t j = i + 1; j < numbers.size(); j++ ) {
			// fetch two numbers
			double a = numbers[i];
			double b = numbers[j];

			// prepare for next recursive step
			next = numbers;
			next.erase( next.begin() + j ); // delete the higher index first
			next.erase( next.begin() + i );

			// steps 3 and 4 (unrolled)
			next.push_back( a + b ); // add
			eval( next, used );
			next.back() = a - b;   // subtract (I)
			eval( next, used );
			next.back() = b - a;   // subtract (II)
			eval( next, used );
			next.back() = a * b;   // multiply
			eval( next, used );

			if( b != 0 ) {
				next.back() = a / b; // divide (I)
				eval( next, used );
			}

			if( a != 0 ) {
				next.back() = b / a; // divide (II)
				eval( next, used );
			}
		}
}

uint32_t count( uint32_t a, uint32_t b, uint32_t c, uint32_t d ) {
	double a_d = static_cast<double>( a );
	double b_d = static_cast<double>( b );
	double c_d = static_cast<double>( c );
	double d_d = static_cast<double>( d );
	const vector<double> numbers = { a_d, b_d, c_d, d_d };
	vector<bool> used( 1000, false );
	eval( numbers, used );
        int result = 0;
        while( used[++result] ){}
        return result;
}
}

int solve93() {
	uint32_t bestLength = 0;
	uint32_t result = 0;

	for( int a = 1; a <= 9; ++a ) {
		for( int b = a + 1; b <= 9; ++b ) {
			for( int c = b + 1; c <= 9; ++c ) {
				for( int d = c + 1; d <= 9; ++d ) {
					uint32_t thisLength = euler93::count( a, b, c, d );
					if( thisLength > bestLength ) {
						bestLength = thisLength;
						result = a * 1000 + b * 100 + c * 10 + d;
					}
				}
			}
		}
	}
	return result;
}

/*
 * =====================================================================================
 *
 *       Filename:  bigint.hpp
 *
 *    Description:  An arbitrary-size integer class
 *
 *        Version:  1.0
 *        Created:  08/27/2016 12:44:36 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

template<size_t N>
class BigInt {
private:
	vector<unsigned char> digits;

public:
	BigInt() {
		digits = vector<unsigned char>( N, 0 );
	};

	BigInt( string s ) {
		digits = vector<unsigned char>( N, 0 );
		int i = 0;

		for( char &c : s ) {
			unsigned char x = c - '0';
			digits[i] = x;
			++i;
		}
	}

	BigInt( vector<unsigned char> newDigits ) {
		digits = newDigits;
	}

	friend const BigInt operator+( const BigInt &lhs, const BigInt &rhs ) {
		vector<unsigned char> newDigits{ vector<unsigned char>( N, 0 ) };

		for( int i = 0; i < N; ++i ) {
			newDigits[i] = lhs.digits[i] + rhs.digits[i];
		}

		return BigInt<N>( newDigits );
	}

	int operator[]( int i ) {
		return digits[i];
	}
};

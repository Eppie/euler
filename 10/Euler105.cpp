/*
 * =====================================================================================
 *
 *       Filename:  Euler105.cpp
 *
 *    Description:  Solution to Project Euler, Problem 105
 *
 *        Version:  1.0
 *        Created:  11/8/2017 08:08:18 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:
 *         Answer:  73702
 *
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler105 {
vector<uint32_t> makeSubsetSums( vector<uint32_t> a ) {
	int sum;
	int m;
	vector<uint32_t> b( 1 << a.size() );

	for( uint32_t i = 1; i < b.size(); i++ ) {
		sum = 0;
		m = i;

		for( uint32_t j = 0; j < a.size(); ++j ) {
			if( ( m & 1 ) == 1 ) {
				sum += a[j];
			}

			m >>= 1;
		}

		b[i] = sum;
	}
	 return b;
}

int indexOf( vector<uint32_t> array, uint32_t value, uint32_t startIndex ) {
	for( auto i = startIndex; i < array.size(); ++i ) {
		if( array[i] == value ) {
			return i;
		}
	}

	return -1;
}

bool rule1( vector<uint32_t> a ) {
	for( uint32_t i = 0; i < a.size(); ++i ) {
		int k = i;

		while( k != -1 ) {
			++k;

			if( k >= a.size() ) {
				break;
			}

			k = indexOf( a, a[i], k );

			if( k != -1 && ( ( i & k ) == 0 ) ) {
				return false;
			}
		}
	}

	return true;
}

bool rule2( vector<uint32_t> a ) {
	int sum1 = a[0];
	int sum2 = 0;

	for( uint32_t i = 0; i < a.size() / 2; ++i ) {
		sum1 += a[i + 1];
		sum2 += a[a.size() - i - 1];

		if( sum1 <= sum2 ) {
			return false;
		}
	}

	return true;
}

}

uint32_t solve105() {
	int result = 0;

	for( auto && line : loadDataFromFile( "10/sets.txt", '\n' ) ) {
		vector<uint32_t> elems;
		stringstream ss;
		ss.str( line );
		string item;

		while( getline( ss, item, ',' ) ) {
			elems.push_back( stoi( item ) );
		}

		sort( elems.begin(), elems.end() );
		if( euler105::rule2( elems ) ) {
			auto s = euler105::makeSubsetSums( elems );
			if( euler105::rule1( s ) ) {
				result += sum( elems );
			}
		}

	}

	return result;
}

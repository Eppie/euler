/*
 * =====================================================================================
 *
 *       Filename:  helper.hpp
 *
 *    Description:  Helper functions for Project Euler problems.
 *
 *        Version:  1.0
 *        Created:  07/29/2015 11:08:34 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *   Organization:  SevOne
 *
 * =====================================================================================
 */

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <numeric>

typedef unsigned long long ull;
using namespace std;

/*
 * This function returns a vector of all the prime factors of an integer n.
 * Example: n = 1000 --> 2 * 2 * 2 * 5 * 5 * 5 == 8 * 125 == 1000
 * @param ull n
 * @return vector<int>
 */
vector<int> primeFactors( ull n ) {
	vector<int> result;
	// Find the number of 2s that divide n
	while( n % 2 == 0 ) {
		result.push_back( 2 );
		n = n / 2;
	}

	// n must be odd at this point, so we can count by 2's (Note i+=2)
	for( int i = 3; i <= sqrt(n); i+=2 ) {
		// While i divides n, store i and divide n
		while ( n % i == 0 ) {
			result.push_back( i );
			n = n / i;
		}
	}

	// If n is > 2, it must be prime, so just add it to the list.
	if ( n > 2 ) {
		result.push_back( n );
	}

	return result;
}

/*
 * This is an implementation of the Sieve of Eratosthenes.
 * Returns a vector of all prime numbers less than n.
 * @param unsigned long long n
 * @return vector<unsigned long long>
 */
vector<ull> sieve( ull n ) {
	vector<ull> result;
	vector<ull> A (n);
	fill( A.begin(), A.end(), 1 );

	for( ull i = 2; i <= (ull)sqrt(n); i++ ) {
		if( A[i] == 1 ) {
			for( ull j = pow( i, 2 ); j < n; j+=i ) {
				A[j] = 0;
			}
		}
	}

	for( ull i = 2; i < n; i++ ) {
		if ( A[i] == 1 ) {
			result.push_back( i );
		}
	}
	
	return result;
}

/*
 * Returns true if s is a palindrome, and false otherwise.
 * @param string s
 * @return bool
 */
bool isPalindrome( string s ) {
	string reverseS = s;
	reverse( s.begin(), s.end() );
	if( s == reverseS ) {
		return true;
	} else {
		return false;
	}
}

/*
 * Convenience wrapper around accumulate to hide the iterator stuff.
 * Templated, so it will accept a vector of anything. The return type
 * will match the "anything".
 * @param vector<T> input
 * @return T
 */
template <typename T>
T sum( vector<T> input ) {
	return accumulate( input.begin(), input.end(), (T)0 );
}

template <typename T>
T productInDirection( vector<vector<T>> grid, int x0, int y0, int dx, int dy, int steps ) {
	if( !(
		0 <= y0 && y0 < (int)grid.size() &&
		0 <= y0 + ( steps - 1 ) * dy && y0 + ( steps - 1 ) * dy < (int)grid.size() &&
		0 <= x0 && x0 < (int)grid[y0].size() &&
		0 <= x0 + ( steps - 1 ) * dx && x0 + ( steps - 1 ) * dx < (int)grid[y0].size()
	) ) {
		return 0;
	}

	T product = 1;

	for( int n = 0; n < steps; n++ ) {
		product *= grid[y0 + n*dy][x0 + n*dx];
	}

	return product;
}

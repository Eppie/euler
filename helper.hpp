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
#include <unordered_map>
#include <map>
#include <functional>
#include <sstream>
#include <fstream>

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

/*
 * @param vector<vector<T>> grid
 * @param int x0
 * @param int y0
 * @param int dx
 * @param int dy
 * @param int steps
 * @returns T
 */
template <typename T>
T productInDirection( vector<vector<T> > grid, int x0, int y0, int dx, int dy, int steps ) {
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

/*
 * Use this function on some function that you expect to call repeatedly
 * with the same values. Define a std::function, pass it to this function, and
 * then use the function returned instead of the original function.
 * Does not work with recursive functions unless you use a forward declaration!
 * @param function<outType(inType)> inFunc The function to memoize
 * @returns function<outType(inType)> The memoized version of the function
 */
template<class inType, class outType>
function<outType(inType)> memoize( function<outType(inType)> inFunc ) {
	// return a lambda function
	return [inFunc](inType n) {
		static unordered_map<inType,outType> memo;
		outType returnValue;
		auto memoized = memo.find( n );

		if( memoized != memo.end() ) {
			return memoized->second;
		}

		returnValue = inFunc( n );
		memo[n] = returnValue;
		return returnValue;
	};
}

/*
 * This is your standard greatest common denominator function.
 * @param unsigned long long x
 * @param unsigned long long y
 * @returns unsigned long long
 */
ull gcd( ull x, ull y ) {
	while( y != 0 ) {
		ull t = x % y;
		x = y;
		y = t;
	}
	return x;
}

/*
 * This is your standard n choose k function.
 * @param unsigned long long n
 * @param unsigned long long k
 * @returns unsigned long long
 */
ull choose( ull n, ull k ) {
	if( k > n ) {
		throw invalid_argument("invalid argument in choose");
	}

	ull r = 1;

	for( ull d = 1; d <= k; ++d, --n ) {
		ull g = gcd(r, d);
		r /= g;
		ull t = n / (d / g);
		if( r > numeric_limits<ull>::max() / t ) {
			throw overflow_error("overflow in choose");
		}
		r *= t;
	}

	return r;
}

/*
 * Calculates the path through a triangle array with the largest sum.
 * @param vector<vector<int> > rows
 * @returns int
 */
int maxSumPath( vector<vector<int> > rows ) {
	int bottom = rows.size() - 2;
	for( int i = bottom; i >= 0; i-- ) {
		for( int j = 0; j <= i; j++ ) {
			rows[i][j] += max( rows[i+1][j], rows[i+1][j+1] );
		}
	}

	return rows[0][0];
}

/*
 * Print out a vector with separator of your choice, \n by default.
 * @param vector<T> v The vector print
 * @param string sep optional, \n by default, gets printed after each element in v.
 * @returns void
 */
template <typename T>
void printVector( vector<T> v, string sep = "\n" ) {
	for( auto it = v.begin(); it != v.end(); ++it ) {
		cout << *it << sep;
	}
}

/*
 * Read a comma delimited file.
 * @param string filename
 * @returns vector<string>
 */
vector<string> loadDataFromFile( string filename ) {
	string line;
	vector<string> data;
	ifstream file( filename );

	if( !file ) {
		cout << "Error opening file!" << endl;
		throw;
	}

	while( getline( file, line, ',' ) ) {
		try {
			data.push_back( line );
		}

		catch ( const invalid_argument& ia ) {
			cerr << "Check your input file: " << filename << endl;
			throw;
		}
	}

	return data;
}

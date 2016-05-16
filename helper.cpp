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
 *
 * =====================================================================================
 */

#include "helper.hpp"

/*
 * This function returns a vector of all the prime factors of an integer n.
 * Example: n = 1000 --> 2 * 2 * 2 * 5 * 5 * 5 == 8 * 125 == 1000
 * @param unsigned long long n
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
	for( int i = 3; i <= sqrt( n ); i += 2 ) {
		// While i divides n, store i and divide n
		while( n % i == 0 ) {
			result.push_back( i );
			n = n / i;
		}
	}

	// If n is > 2, it must be prime, so just add it to the list.
	if( n > 2 ) {
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
	vector<ull> A( n );
	fill( A.begin(), A.end(), 1 );

	for( ull i = 2; i <= static_cast< ull>( sqrt( n ) ); i++ ) {
		if( A[i] == 1 ) {
			for( ull j = pow( i, 2 ); j < n; j += i ) {
				A[j] = 0;
			}
		}
	}

	for( ull i = 2; i < n; i++ ) {
		if( A[i] == 1 ) {
			result.push_back( i );
		}
	}

	return result;
}

/*
 * Return true if the given number is prime, and false otherwise.
 * @param long long n The number to perform the primality test on.
 * @return bool Whether or not the number is prime.
 */
bool isPrime( long long n ) {
	if( n <= 1 ) {
		return false;
	} else if( n <= 3 ) {
		return true;
	} else if( n % 2 == 0 || n % 3 == 0 ) {
		return false;
	}

	long long i = 5;

	while( i * i <= n ) {
		if( n % i == 0 || n % ( i + 2 ) == 0 ) {
			return false;
		}

		i += 6;
	}

	return true;
}

/*
 * Returns true if s is a palindrome, and false otherwise.
 * @param string s
 * @return bool
 */
bool isPalindrome( string s ) {
	string reverseS = s;
	reverse( s.begin(), s.end() );

	return s == reverseS;
}

/*
 * This is your standard greatest common denominator function.
 * @param unsigned long long x
 * @param unsigned long long y
 * @return unsigned long long
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
 * Calculates the factorial of a number ( e.g. 5! == 120 )
 * @param unsigned long long n
 * @return unsigned long long
 */
ull factorial( ull n ) {
	ull result = 1;

	for( ull i = 1; i <= n; i++ ) {
		result *= i;
	}

	return result;
}

/*
 * This is your standard n choose k function.
 * @param unsigned long long n
 * @param unsigned long long k
 * @return unsigned long long
 */
ull choose( ull n, ull k ) {
	if( k > n ) {
		throw invalid_argument( "invalid argument in choose" );
	}

	ull r = 1;

	for( ull d = 1; d <= k; ++d, --n ) {
		ull g = gcd( r, d );
		r /= g;
		ull t = n / ( d / g );

		if( r > numeric_limits<ull>::max() / t ) {
			throw overflow_error( "overflow in choose" );
		}

		r *= t;
	}

	return r;
}

/*
 * Calculates the path through a triangle array with the largest sum.
 * @param vector<vector<int> > rows
 * @return int
 */
int maxSumPath( vector<vector<int> > rows ) {
	int bottom = rows.size() - 2;

	for( int i = bottom; i >= 0; i-- ) {
		for( int j = 0; j <= i; j++ ) {
			rows[i][j] += max( rows[i + 1][j], rows[i + 1][j + 1] );
		}
	}

	return rows[0][0];
}

/*
 * Read a comma delimited file.
 * @param string filename
 * @return vector<string>
 */
vector<string> loadDataFromFile( string filename ) {
	string line;
	vector<string> data;
	ifstream file( filename );

	if( !file ) {
		cerr << "Error opening file!" << endl;
		throw;
	}

	while( getline( file, line, ',' ) ) {
		try {
			data.push_back( line );
		} catch( const invalid_argument &ia ) {
			cerr << "Check your input file: " << filename << endl;
			throw;
		}
	}

	return data;
}

/*
 * See: http://graphics.stanford.edu/~seander/bithacks.html#IntegerLog10Obvious
 */
int numDigits( unsigned int v ) {
	return ( v >= 1000000000 ) ? 10 : ( v >= 100000000 ) ? 9 : ( v >= 10000000 ) ? 8 :
		   ( v >= 1000000 ) ? 7 : ( v >= 100000 ) ? 6 : ( v >= 10000 ) ? 5 :
		   ( v >= 1000 ) ? 4 : ( v >= 100 ) ? 3 : ( v >= 10 ) ? 2 : 1;

}

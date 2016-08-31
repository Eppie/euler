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
 * @param uint64_t n
 * @return vector<int>
 */
vector<int> primeFactors( uint64_t n ) {
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
 * @param uint64_t n
 * @return vector<uint64_t>
 */
vector<uint64_t> sieve( uint64_t n ) {
	vector<uint64_t> result;
	vector<bool> A( n, true );

	for( uint64_t i = 2; i <= static_cast<uint64_t>( sqrt( n ) ); i++ ) {
		if( A[i] ) {
			for( uint64_t j = pow( i, 2 ); j < n; j += i ) {
				A[j] = false;
			}
		}
	}

	for( uint64_t i = 2; i < n; i++ ) {
		if( A[i] ) {
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
 * @param uint64_t x
 * @param uint64_t y
 * @return uint64_t
 */
uint64_t gcd( uint64_t x, uint64_t y ) {
	while( y != 0 ) {
		uint64_t t = x % y;
		x = y;
		y = t;
	}

	return x;
}

/*
 * Calculates the factorial of a number ( e.g. 5! == 120 )
 * @param uint64_t n
 * @return uint64_t
 */
uint64_t factorial( uint64_t n ) {
	uint64_t result = 1;

	for( uint64_t i = 1; i <= n; i++ ) {
		result *= i;
	}

	return result;
}

/*
 * This is your standard n choose k function.
 * @param uint64_t n
 * @param uint64_t k
 * @return uint64_t
 */
uint64_t choose( uint64_t n, uint64_t k ) {
	if( k > n ) {
		throw invalid_argument( "invalid argument in choose" );
	}

	uint64_t r = 1;

	for( uint64_t d = 1; d <= k; ++d, --n ) {
		uint64_t g = gcd( r, d );
		r /= g;
		uint64_t t = n / ( d / g );

		if( r > numeric_limits<uint64_t>::max() / t ) {
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
 *
 */
bool isPandigital( uint64_t val, int m = 1, int n = 9 ) {
	unsigned int result = 0;
	int digitCount = 0;

	if( val < m ) {
		return false;
	}

	while( val != 0 ) {
		digitCount++;
		int tmp = val % 10;

		// This check isn't necessary, but it lets us bail out early in some cases.
		if( tmp < m || tmp > n ) {
			return false;
		}

		result |= 1 << ( tmp - 1 );
		val /= 10;
	}

	return result == ( 1 << n ) - 1 && digitCount == ( n - m + 1 );

}

/*
 * See: http://graphics.stanford.edu/~seander/bithacks.html#IntegerLog10Obvious
 */
int numDigits( unsigned int v ) {
	return ( v >= 1000000000 ) ? 10 : ( v >= 100000000 ) ? 9 : ( v >= 10000000 ) ? 8 :
		   ( v >= 1000000 ) ? 7 : ( v >= 100000 ) ? 6 : ( v >= 10000 ) ? 5 :
		   ( v >= 1000 ) ? 4 : ( v >= 100 ) ? 3 : ( v >= 10 ) ? 2 : 1;

}

/*
 * Efficiently calculate ( base ** exponent ) % modulus
 */
uint64_t powMod( uint64_t base, uint64_t exponent, uint64_t modulus ) {
	if( modulus == 1 ) {
		return 0;
	}

	uint64_t result = 1;
	base = base % modulus;

	while( exponent ) {
		if( exponent & 1 ) {
			result = result * base % modulus;
		}

		exponent >>= 1;
		base = base * base % modulus;
	}

	return result;
}

/*
 * Generate the nth pentagonal number. Given by the formula Pn = n(3n-1)/2
 */
uint64_t genPent( uint64_t n ) {
	return ( n * ( ( 3 * n ) - 1 ) ) / 2;
}

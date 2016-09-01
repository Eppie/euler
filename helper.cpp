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
 * Returns true if x is a palindrome in base b, and false otherwise.
 * @param uint64_t x
 * @param int b
 * @return bool
 */
bool isPalindrome( uint64_t x, int b ) {
	int reversed = 0;
	int k = x;

	while( k > 0 ) {
		reversed = b * reversed + k % b;
		k /= b;
	}

	return x == reversed;
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
 * This is a memoized implementation of the recursive formula for n choose k.
 * @param const uint64_t n
 * @param const uint64_t k
 * @return uint64_t
 */
uint64_t choose( const uint64_t &n, const uint64_t &k ) {
	if( n < k || n == 0 ) {
		return 0;
	}

	if( k == 0 || n == k ) {
		return 1;
	}

	if( k == 1 ) {
		return n;
	}

	uint64_t* table = new uint64_t[static_cast<size_t>( n * n )];
	fill_n( table, n * n, 0 );

	class choose_impl {
	public:
		uint64_t* m_table;
		uint64_t m_dimension;
		choose_impl( uint64_t* table, const uint64_t &dimension ) {
			m_table = table;
			m_dimension = dimension;
		}

		uint64_t &lookup( const uint64_t &n, const uint64_t &k ) {
			return m_table[m_dimension * n + k];
		}

		uint64_t compute( const uint64_t &n, const uint64_t &k ) {
			if( ( k == 0 ) || ( n == k ) ) {
				return 1;
			}

			uint64_t v1 = lookup( n - 1, k - 1 );

			if( v1 == 0 ) {
				v1 = lookup( n - 1, k - 1 ) = compute( n - 1, k - 1 );
			}

			uint64_t v2 = lookup( n - 1, k );

			if( v2 == 0 ) {
				v2 = lookup( n - 1, k ) = compute( n - 1, k );
			}

			return v1 + v2;
		}
	};

	uint64_t result = choose_impl( table, n ).compute( n, k );
	delete [] table;
	return result;
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

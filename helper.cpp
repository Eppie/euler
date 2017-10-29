/*
 * =====================================================================================
 *
 *       Filename:  helper.hpp
 *
 *    Description:  Helper functions for Project Euler problems.
 *
 *        Version:  1.1
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
vector<uint64_t> primeFactors( uint64_t n ) {
	vector<uint64_t> result;

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

	auto primeCountEstimate = static_cast<uint64_t>( ( n / log( n ) ) * ( 1 + ( 1.2762 / log( n ) ) ) );
	result.reserve( primeCountEstimate );

	for( uint64_t i = 2; i <= static_cast<uint64_t>( sqrt( n ) ); ++i ) {
		if( A[i] ) {
			for( uint64_t j = i * i; j < n; j += i ) {
				A[j] = false;
			}
		}
	}

	for( uint64_t i = 2; i < n; ++i ) {
		if( A[i] ) {
			result.push_back( i );
		}
	}

	return result;
}

/*
 * Return true if the given number is prime, and false otherwise.
 * @param uint64_t n The number to perform the primality test on.
 * @return bool Whether or not the number is prime.
 */
bool isPrime( uint64_t n ) {
	if( n <= 1 ) {
		return false;
	} else if( n <= 3 ) {
		return true;
	} else if( n % 2 == 0 || n % 3 == 0 ) {
		return false;
	}

	uint64_t i = 5;

	while( i * i <= n ) {
		if( n % i == 0 || n % ( i + 2 ) == 0 ) {
			return false;
		}

		i += 6;
	}

	return true;
}

/*
 * Miller-Rabin Probabilistic Primality Test
 */
bool isProbablyPrime( uint64_t n ) {
	if( n <= 1 ) {
		return false;
	} else if( n <= 3 ) {
		return true;
	} else if( n % 2 == 0 || n % 3 == 0 ) {
		return false;
	}

	uint32_t s = 0;
	uint64_t d = n - 1;

	while( d % 2 == 0 ) {
		++s;
		d >>= 1;
	}

	random_device rd;
	mt19937 rng( rd() );
	uniform_int_distribution<uint64_t> uni( 2, n - 2 );
	int k = 3;

	for( int i = 0; i < k; ++i ) {
		uint64_t a = uni( rng );
		uint64_t x = powMod( a, d, n );

		if( x != 1 && x + 1 != n ) {
			for( uint32_t r = 1; r < s; ++r ) {
				x = powMod( x, 2, n );

				if( x == 1 ) {
					return false;
				} else if( x + 1 == n ) {
					a = 0;
					break;
				}
			}

			if( a != 0 ) {
				return false;
			}
		}
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
	uint64_t reversed = 0;
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
 * @param const uint64_t& n
 * @param const uint64_t& k
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

	auto* table = new uint64_t[static_cast<size_t>( n * n )];
	fill_n( table, n * n, 0 );

	class choose_impl {
	public:
		uint64_t* m_table;
		uint64_t m_dimension;
		choose_impl( uint64_t* p_table, const uint64_t &dimension ) {
			m_table = p_table;
			m_dimension = dimension;
		}

		uint64_t &lookup( const uint64_t &p_n, const uint64_t &p_k ) {
			return m_table[m_dimension * p_n + p_k];
		}

		uint64_t compute( const uint64_t &p_n, const uint64_t &p_k ) {
			if( ( p_k == 0 ) || ( p_n == p_k ) ) {
				return 1;
			}

			uint64_t v1 = lookup( p_n - 1, p_k - 1 );

			if( v1 == 0 ) {
				v1 = lookup( p_n - 1, p_k - 1 ) = compute( p_n - 1, p_k - 1 );
			}

			uint64_t v2 = lookup( p_n - 1, p_k );

			if( v2 == 0 ) {
				v2 = lookup( p_n - 1, p_k ) = compute( p_n - 1, p_k );
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
int maxSumPath( vector<vector<int>> rows ) {
	int bottom = rows.size() - 2;

	for( int i = bottom; i >= 0; i-- ) {
		for( int j = 0; j <= i; j++ ) {
			rows[i][j] += max( rows[i + 1][j], rows[i + 1][j + 1] );
		}
	}

	return rows[0][0];
}

/*
 * Read a delimited file.
 * @param string filename
 * @param char delimiter
 * @return vector<string>
 */
vector<string> loadDataFromFile( string filename, char delimiter ) {
	string line;
	vector<string> data;
	ifstream file( filename );

	if( !file ) {
		cerr << "Error opening file!" << endl;
		throw;
	}

	while( getline( file, line, delimiter ) ) {
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
 * @param uint64_t val
 * @return bool
 */
bool isPandigital( uint64_t val ) {
	uint32_t result = 0;
	uint32_t digitCount = 0;

	if( val < 1 ) {
		return false;
	}

	while( val != 0 ) {
		digitCount++;
		uint32_t tmp = val % 10;

		// This check isn't necessary, but it lets us bail out early in some cases.
		if( tmp < 1 || tmp > 9 ) {
			return false;
		}

		result |= 1 << ( tmp - 1 );
		val /= 10;
	}

	return result == ( 1 << 9 ) - 1 && digitCount == 9;

}

/*
 * See: http://graphics.stanford.edu/~seander/bithacks.html#IntegerLog10Obvious
 * @param uint64_t v
 * @return unsigned int
 */
unsigned int numDigits( uint64_t v ) {
	return ( v >= 100000000000000000 ) ? 18 : ( v >= 10000000000000000 ) ? 17 : ( v >= 1000000000000000 ) ? 16 :
		   ( v >= 100000000000000 ) ? 15 : ( v >= 10000000000000 ) ? 14 : ( v >= 1000000000000 ) ? 13 :
		   ( v >= 100000000000 ) ? 12 : ( v >= 10000000000 ) ? 11 : ( v >= 1000000000 ) ? 10 :
		   ( v >= 100000000 ) ? 9 : ( v >= 10000000 ) ? 8 : ( v >= 1000000 ) ? 7 :
		   ( v >= 100000 ) ? 6 : ( v >= 10000 ) ? 5 : ( v >= 1000 ) ? 4 :
		   ( v >= 100 ) ? 3 : ( v >= 10 ) ? 2 : 1;
}

/*
 * Efficiently calculate ( a * b ) % modulus
 * @param uint64_t a
 * @param uint64_t b
 * @param uint64_t modulus
 * @return uint64_t
 */
uint64_t mulMod( uint64_t a, uint64_t b, uint64_t modulus ) {
	if( modulus == 0 ) {
		return a * b;
	}

	uint64_t r = 0;

	while( a > 0 ) {
		if( a % 2 )
			if( ( r += b ) > modulus ) {
				r %= modulus;
			}

		a >>= 1;

		if( ( b <<= 1 ) > modulus ) {
			b %= modulus;
		}
	}

	return r;
}

/*
 * Efficiently calculate ( base ** exponent ) % modulus
 * @param uint64_t base
 * @param uint64_t exponent
 * @param uint64_t modulus
 * @return uint64_t
 */
uint64_t powMod( uint64_t base, uint64_t exponent, uint64_t modulus ) {
	uint64_t result = 1;

	while( exponent > 0 ) {
		if( exponent % 2 ) {
			result = mulMod( result, base, modulus );
		}

		base = mulMod( base, base, modulus );
		exponent >>= 1;
	}

	return result;
}

/*
 * Generate the nth pentagonal number. Given by the formula Pn = n(3n-1)/2
 * @param uint64_t n
 * @return uint64_t
 */
uint64_t genPent( uint64_t n ) {
	return figurateNumber( 5, n );
}

/*
 * TODO
 */
uint64_t figurateNumber( uint64_t r, uint64_t n ) {
	return n * ( ( r - 2 ) * n - ( r - 4 ) ) / 2;
}

/*
 * TODO
 */
mpz_class digitalSum( mpz_class x ) {
	mpz_class result = 0;
	unsigned long digit;

	while( x != 0 ) {
		digit = mpz_tdiv_q_ui( x.get_mpz_t(), x.get_mpz_t(), 10 );
		result += digit;
	}

	return result;
}

uint64_t x = 0x8E588AFE51D8B00D;

/*
 * xorshift* algorithm
 * See here: http://vigna.di.unimi.it/ftp/papers/xorshift.pdf
 * @return uint64_t The generated random number
 */
uint64_t random_int() {
	x ^= x >> 12;
	x ^= x << 25;
	x ^= x >> 27;
	return x * 2685821657736338717ULL;
}

/*
 * TODO
 */
vector<vector<int>> combinations( vector<int> n, int r ) {
	vector<vector<int>> result;
	vector<bool> v( n.size() );
	fill( v.end() - r, v.end(), true );

	do {
		vector<int> tmp;

		for( uint32_t i = 0; i < n.size(); ++i ) {
			if( v[i] ) {
				tmp.push_back( n[i] );
			}
		}

		result.push_back( tmp );
	} while( next_permutation( v.begin(), v.end() ) );

	return result;
}

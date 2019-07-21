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

using std::cerr;
using std::fill_n;
using std::ifstream;
using std::invalid_argument;
using std::max;

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

bool sprp( uint64_t n, uint64_t a ) {
  uint64_t m = n - 1;
  uint64_t y;
  uint32_t s = 1;

  while( ( m & ( UINT64_C( 1 ) << s ) ) == 0 ) {
    s++;
  }

  if( ( a %= n ) == 0 ) {
    return true;
  }

  unsigned __int128 u = 1;
  unsigned __int128 w = a;

  uint64_t r = m >> s;

  while( r != 0 ) {
    if( ( r & 1 ) != 0 ) {
      u = ( u * w ) % n;
    }

    if( ( r >>= 1 ) != 0 ) {
      w = ( w * w ) % n;
    }
  }

  y = static_cast<uint64_t>( u );
  if( y == 1 ) {
    return true;
  }

  for( unsigned int j = 1; j < s && y != m; ++j ) {
    u = y;
    u = ( u * u ) % n;

    y = static_cast<uint64_t>( u );
    if( y <= 1 ) {
      return false;
    }
  }

  return y == m;
}
/*
 * Miller-Rabin Probabilistic Primality Test
 * Return true if the given number is prime, and false otherwise.
 * @param uint64_t n The number to perform the primality test on.
 * @return bool Whether or not the number is prime.
 *
 * if n < 1,373,653, it is enough to test a = 2 and 3;
 * if n < 9,080,191, it is enough to test a = 31 and 73;
 * if n < 4,759,123,141, it is enough to test a = 2, 7, and 61;
 * if n < 1,122,004,669,633, it is enough to test a = 2, 13, 23, and 1662803;
 * if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11;
 * if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13;
 * if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.
 */
bool isPrime( uint64_t n ) {
  if( n < 11 ) {
    if( n == 2 || n == 3 || n == 5 || n == 7 ) {
      return true;
    } else {
      return false;
    }
  }
  if( !( n % 2 ) || !( n % 3 ) || !( n % 5 ) || !( n % 7 ) ) {
    return false;
  }
  if( n < 121 ) {
    return true;
  }
  if( !( n % 11 ) || !( n % 13 ) || !( n % 17 ) || !( n % 19 ) || !( n % 23 ) || !( n % 29 ) || !( n % 31 )
      || !( n % 37 ) || !( n % 41 ) || !( n % 43 ) || !( n % 47 ) || !( n % 53 ) ) {
    return false;
  }
  if( n < 3481 ) {
    return true;
  }

  if( n < 1373653ULL ) {
    return sprp( n, 2 ) && sprp( n, 3 );
  }
  if( n < 9080191ULL ) {
    return sprp( n, 31 ) && sprp( n, 73 );
  }
  if( n < 4759123141ULL ) {
    return sprp( n, 2 ) && sprp( n, 7 ) && sprp( n, 61 );
  }
  if( n < 1122004669633ULL ) {
    return sprp( n, 2 ) && sprp( n, 13 ) && sprp( n, 23 ) && sprp( n, 1662803 );
  }
  if( n < 2152302898747ULL ) {
    return sprp( n, 2 ) && sprp( n, 3 ) && sprp( n, 5 ) && sprp( n, 7 ) && sprp( n, 11 );
  }
  if( n < 3474749660383ULL ) {
    return sprp( n, 2 ) && sprp( n, 3 ) && sprp( n, 5 ) && sprp( n, 7 ) && sprp( n, 11 ) && sprp( n, 13 );
  }
  if( n < 341550071728321ULL ) {
    return sprp( n, 2 ) && sprp( n, 3 ) && sprp( n, 5 ) && sprp( n, 7 ) && sprp( n, 11 ) && sprp( n, 13 )
           && sprp( n, 17 );
  }
  cout << "ERROR! PRIME TOO BIG!" << endl;
  return false;
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

  auto *table = new uint64_t[static_cast<size_t>( n * n )];
  fill_n( table, n * n, 0 );

  class choose_impl {
  public:
    uint64_t *m_table;
    uint64_t m_dimension;
    choose_impl( uint64_t *p_table, const uint64_t &dimension ) {
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
  delete[] table;
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
  return ( v >= 100000000000000000 )
             ? 18
             : ( v >= 10000000000000000 )
                   ? 17
                   : ( v >= 1000000000000000 )
                         ? 16
                         : ( v >= 100000000000000 )
                               ? 15
                               : ( v >= 10000000000000 )
                                     ? 14
                                     : ( v >= 1000000000000 )
                                           ? 13
                                           : ( v >= 100000000000 )
                                                 ? 12
                                                 : ( v >= 10000000000 )
                                                       ? 11
                                                       : ( v >= 1000000000 )
                                                             ? 10
                                                             : ( v >= 100000000 )
                                                                   ? 9
                                                                   : ( v >= 10000000 )
                                                                         ? 8
                                                                         : ( v >= 1000000 )
                                                                               ? 7
                                                                               : ( v >= 100000 )
                                                                                     ? 6
                                                                                     : ( v >= 10000 )
                                                                                           ? 5
                                                                                           : ( v >= 1000 )
                                                                                                 ? 4
                                                                                                 : ( v >= 100 )
                                                                                                       ? 3
                                                                                                       : ( v >= 10 )
                                                                                                             ? 2
                                                                                                             : 1;
}

/*
 * Efficiently calculate ( a * b ) % modulus
 * @param uint64_t a
 * @param uint64_t b
 * @param uint64_t modulus
 * @return uint64_t
 */
uint64_t mulMod( uint64_t a, uint64_t b, uint64_t modulus ) {
  uint64_t result;
  uint64_t unused; // dummy output, unused, to tell GCC that RAX register is modified by this snippet
  asm( "mulq %3\n\t"
       "divq %4"
       : "=a"( unused ), "=&d"( result )
       : "a"( a ), "rm"( b ), "rm"( modulus )
       : "cc" );
  return result;
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

uint32_t digitalSum( uint64_t x ) {
  uint32_t result = 0;

  while( x != 0 ) {
    result += x % 10;
    x /= 10;
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
double logBaseN( uint64_t x, uint64_t n ) {
  return log( x ) / log( n );
}

auto isSquare( uint64_t n ) -> bool {
  uint64_t h = n & 0xF;
  if( h > 9 ) {
    return false;
  }

  if( h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8 ) {
    int t = ( int ) floor( sqrt( ( double ) n ) + 0.5 );
    return t * t == n;
  }
  return false;
}

auto fib( uint64_t n ) -> uint64_t {
  if( n == 1 ) {
    return 1;
  }
  if( n == 2 ) {
    return 1;
  }
  uint64_t f1 = 1;
  uint64_t f2 = 1;
  uint64_t f3 = 0;
  for( uint64_t i = 3; i <= n; ++i ) {
    f3 = f1 + f2;
    f1 = f2;
    f2 = f3;
  }
  return f3;
}

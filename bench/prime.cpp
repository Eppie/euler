#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "FJ32_1024.cc"
#include "FJ32_224.cc"
#include "FJ32_256.cc"
#include "FJ64_16k.cc"
//#include "FJ64_262K.cc"
#include "AE32_1024.cpp"
#include "AE32_128.cpp"
#include "AE32_144.cpp"
#include "AE32_1536.cpp"
#include "AE32_176.cpp"
#include "AE32_256.cpp"
#include "AE32_512.cpp"
#include "AE32_768.cpp"
#include "sinclair1.h"
#include "sprp64.h"
#include "worley1.h"

using std::cout;
using std::endl;
using std::function;
using std::vector;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::nanoseconds;

/*
bool isPrimeNaive( uint64_t n ) {
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

bool witness( uint64_t n, uint64_t s, uint64_t d, uint64_t a ) {
  uint64_t x = 1;

  while( d ) {
    if( d & 1 ) {
      x = ( x * a ) % n;
    }
    a = ( a * a ) % n;
    d >>= 1;
  }

  uint64_t y = 1;

  while( s ) {
    y = ( x * x ) % n;
    if( y == 1 && x != 1 && x != n - 1 ) {
      return false;
    }
    x = y;
    --s;
  }
  if( y != 1 ) {
    return false;
  }
  return true;
}

*/
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
/*
bool isPrime( uint64_t n ) {
  if( ( ( !( n & 1 ) ) && n != 2 ) || ( n < 2 ) || ( n % 3 == 0 && n != 3 ) ) {
    return false;
  }
  if( n <= 3 ) {
    return true;
  }

  uint64_t d = n / 2;
  uint64_t s = 1;
  while( !( d & 1 ) ) {
    d /= 2;
    ++s;
  }

  if( n < 1373653ULL ) {
    return witness( n, s, d, 2 ) && witness( n, s, d, 3 );
  }
  if( n < 9080191ULL ) {
    return witness( n, s, d, 31 ) && witness( n, s, d, 73 );
  }
  if( n < 4759123141ULL ) {
    return witness( n, s, d, 2 ) && witness( n, s, d, 7 ) && witness( n, s, d, 61 );
  }
  if( n < 1122004669633ULL ) {
    return witness( n, s, d, 2 ) && witness( n, s, d, 13 ) && witness( n, s, d, 23 ) && witness( n, s, d, 1662803 );
  }
  if( n < 2152302898747ULL ) {
    return witness( n, s, d, 2 ) && witness( n, s, d, 3 ) && witness( n, s, d, 5 ) && witness( n, s, d, 7 )
           && witness( n, s, d, 11 );
  }
  if( n < 3474749660383ULL ) {
    return witness( n, s, d, 2 ) && witness( n, s, d, 3 ) && witness( n, s, d, 5 ) && witness( n, s, d, 7 )
           && witness( n, s, d, 11 ) && witness( n, s, d, 13 );
  }
  return witness( n, s, d, 2 ) && witness( n, s, d, 3 ) && witness( n, s, d, 5 ) && witness( n, s, d, 7 )
         && witness( n, s, d, 11 ) && witness( n, s, d, 13 ) && witness( n, s, d, 17 );
}

// efficient_mr64 -O3 failures: 284301751, 3874471147 (neither are prime but the function says they are)
// is_prime_1a -O0 failures: None
// FJ32_256 -O3 failures: None
// FJ32_224 -O0 failures: None
// FJ32_224 -O3 failures: 2257, 2363, 5461, 9253, 13213 etc
// FJ32_1024 -O3 failures: None
// FJ64_16k -O3 failures: None
// FJ64_262k -O3 failures: None

*/
vector<bool> B( 2147483648, true );
void sieveOfE() {
  B[0] = false;
  B[1] = false;
  for( uint64_t i = 3; i <= 65536; i += 2 ) {
    if( B[i / 2] ) {
      for( uint64_t j = i * i; j < 2147483648; j += ( 2 * i ) ) {
        B[j / 2] = false;
      }
    }
  }
}

bool isPrimeE( uint32_t n ) {
  if( ( ( !( n & 1 ) ) && n != 2 ) || ( n < 2 ) || ( n % 3 == 0 && n != 3 ) ) {
    return false;
  }
  if( n <= 3 ) {
    return true;
  }
  return B[n / 2];
}

#define TESTS ( ( 1ULL << 27 ) - 1 )

template <typename inType>
auto test( function<bool( inType )> f ) {
  auto begin = high_resolution_clock::now();
  for( inType i = 1; i < TESTS; i += 2 ) {
    bool actual = f( i );
    bool expected = isPrimeE( i );
    if( actual != expected ) {
      cout << i << endl;
    }
  }
  auto end = high_resolution_clock::now();
  auto ns = static_cast<double>( duration_cast<nanoseconds>( end - begin ).count() );
  auto nsPerTest = ns / TESTS * 2;
  cout << nsPerTest << endl;
  return nsPerTest;
}

int main() {
  sieveOfE();

  printf( "AE32_768: " );
  test<uint32_t>( AE32_768 ); // 101.51
  printf( "AE32_1024: " );
  test<uint32_t>( AE32_1024 ); // 101.51
  printf( "AE32_1536: " );
  test<uint32_t>( AE32_1536 ); // 112.371
  printf( "AE32_512: " );
  test<uint32_t>( AE32_512 ); // 118.257
  printf( "AE32_256: " );
  test<uint32_t>( AE32_256 ); // 124.499
  printf( "AE32_176: " );
  test<uint32_t>( AE32_176 ); // 100.701
  printf( "AE32_144: " );
  test<uint32_t>( AE32_144 ); // 114.318
  printf( "AE32_128: " );
  test<uint32_t>( AE32_128 ); // 97.8173

  printf( "worley: " );
  test<uint32_t>( worley ); // 144.364
  // test<uint64_t>( isPrime1e15 ); // 1139.02
  // test<uint64_t>( isPrimeSuperNaive ); // 1161.64
  // test<uint64_t>( isPrimeNaive ); // 412.839
  printf( "efficient_mr64: " );
  test<uint64_t>( efficient_mr64 ); // 229.948
  printf( "FJ32_256: " );
  test<uint32_t>( FJ32_256 ); // 140.656
  printf( "FJ32_1024: " );
  test<uint32_t>( FJ32_1024 ); // 136.591
  printf( "FJ64_16k: " );
  test<uint64_t>( FJ64_16k ); // 240.321
  // test<uint64_t>( FJ64_262K ); // 451.489
  // test<uint32_t>( isPrime ); // 234.412
  // test<uint32_t>( isPrimeE ); // 3.79158
  return 0;
}

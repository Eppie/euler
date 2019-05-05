#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <vector>

using std::vector;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::nanoseconds;

vector<bool> B( 2147483648, true );
void sieveOfE() {
  B[0] = false;
  B[1] = false;
  for( uint64_t i = 3; i <= 65536; i += 2 ) {
    if( B[i / 2] ) {
#pragma loop distribute( enable )
      for( uint64_t j = i * i; j < 4294967296; j += ( 2 * i ) ) {
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

bool is_SPRP( uint32_t n, uint32_t a ) {
  uint32_t d = n - 1;
  uint32_t s = __builtin_ctz( d );
  d >>= s;

  uint64_t cur = 1;
  uint64_t pw = d;
  while( pw ) {
    if( pw & 1 ) {
      cur = ( cur * a ) % n;
    }
    a = ( ( uint64_t ) a * a ) % n;
    pw >>= 1;
  }
  if( cur == 1 ) {
    return true;
  }
  for( uint32_t r = 0; r < s; r++ ) {
    if( cur == n - 1 ) {
      return true;
    }
    cur = ( cur * cur ) % n;
  }
  return false;
}

static inline uint64_t powmod( uint64_t a, uint64_t k, uint64_t n ) {
  uint64_t t = 1;
  if( a >= n ) {
    a %= n;
  }
  while( k != 0 ) {
    if( ( k & 1ULL ) != 0 ) {
      t = ( t * a ) % n;
    }
    k >>= 1ULL;
    if( k != 0 ) {
      a = ( a * a ) % n;
    }
  }
  return t;
}

bool prp( uint64_t const n, uint64_t a ) {
  if( a >= n ) {
    a %= n;
    if( a <= 1 ) {
      return ( a == 1 );
    }
    if( a == n - 1 ) {
      return !( a & 1ULL );
    }
  }

  return powmod( a, n - 1, n ) == 1; /* a^(n-1) = 1 mod n */
}

int main() {
  auto begin = high_resolution_clock::now();
  sieveOfE();
  auto end = high_resolution_clock::now();
  printf( "Done sieving. Took %fs\n", duration_cast<nanoseconds>( end - begin ).count() / 1000.0 / 1000.0 / 1000.0 );
  uint32_t numValues = 0;
  uint32_t swapCounter = 0;
  uint32_t best = 0;
  uint32_t *values = new uint32_t[600'000'000]();

  for( uint64_t i = 3; i <= ( 1ULL << 32ULL ) - 1; i += 2 ) {
    if( i % 3 != 0 && i % 5 != 0 && i % 7 != 0 && i % 11 != 0 && i % 13 != 0 && i % 17 != 0 && i % 19 != 0
        && i % 23 != 0 && i % 29 != 0 && i % 31 != 0 && i % 37 != 0 && i % 41 != 0 && i % 43 != 0 && i % 47 != 0
        && i % 53 != 0 ) {
      values[numValues++] = i;
    }
  }
  auto end2 = high_resolution_clock::now();
  printf( "Done filling values! Count: %u, Took: %fs\n", numValues,
          duration_cast<nanoseconds>( end2 - end ).count() / 1000.0 / 1000.0 / 1000.0 );
  for( uint32_t a = 2; a <= 4'290'000'000; ++a ) {
    for( uint32_t i = 0; i < numValues; ++i ) {
      uint32_t v = values[i];
      bool expected = isPrimeE( v );
      bool actual = prp( v, a );
      if( expected != actual ) {
        if( v > best ) {
          printf( "New best! Value: %u, Base: %u, swapCounter = %u\n", v, a, swapCounter );
          best = v;
        }
        if( i > swapCounter ) {
          uint32_t tmp = values[swapCounter];
          values[swapCounter] = v;
          values[i] = tmp;
          swapCounter += 1;
        }
        if( a % 100'000'000 == 0 ) {
          printf( "At base %u, swapCounter = %u\n", a, swapCounter );
        }
        break;
      }
    }
  }
  return 0;
}

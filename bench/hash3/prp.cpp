#include <cstdint>
#include <cstdio>

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
// 118901521

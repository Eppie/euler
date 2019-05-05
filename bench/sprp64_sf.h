#include <cstdint>

namespace straightforward_mr64_detail {

static inline uint64_t mulmod64( uint64_t a, uint64_t b, uint64_t n ) {
  uint64_t d;
  uint64_t unused; // dummy output, unused, to tell GCC that RAX register is modified by this snippet
  asm( "mulq %3\n\t"
       "divq %4"
       : "=a"( unused ), "=&d"( d )
       : "a"( a ), "rm"( b ), "rm"( n )
       : "cc" );
  return d;
}

static inline uint64_t modular_exponentiation64( uint64_t a, uint64_t b, uint64_t n ) {
  uint64_t d = 1, A = a;

  do {
    if( b & 1 )
      d = mulmod64( d, A, n );
    A = mulmod64( A, A, n );
  } while( b >>= 1 );

  return ( uint64_t ) d;
}
} // namespace straightforward_mr64_detail

static inline int straightforward_mr64( uint64_t n ) {
  uint64_t u = n - 1;

  int t = __builtin_ctzll( u ), j;
  u >>= t;

  static const uint64_t bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

  for( j = 0; j < 3; j++ ) {
    uint64_t a = bases[j], x;
    int i;

    if( a >= n )
      a %= n;

    if( a == 0 )
      continue;

    x = straightforward_mr64_detail::modular_exponentiation64( a, u, n );

    if( x == 1 || x == n - 1 )
      continue;

    for( i = 1; i < t; i++ ) {
      x = straightforward_mr64_detail::mulmod64( x, x, n );
      if( x == 1 )
        return 0;
      if( x == n - 1 )
        break;
    }

    // if we didn't break, the number is composite
    if( i == t )
      return 0;
  }

  return 1;
}

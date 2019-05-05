#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static inline uint64_t _mulmod( uint64_t a, uint64_t b, uint64_t n ) {
  uint64_t d, dummy;                  /* d will get a*b mod c */
  asm( "mulq %3\n\t"                  /* mul a*b -> rdx:rax */
       "divq %4\n\t"                  /* (a*b)/c -> quot in rax remainder in rdx */
       : "=a"( dummy ), "=&d"( d )    /* output */
       : "a"( a ), "r"( b ), "r"( n ) /* input */
       : "cc"                         /* mulq and divq can set conditions */
  );
  return d;
}

static inline uint64_t _addmod( uint64_t a, uint64_t b, uint64_t n ) {
  uint64_t t = a - n;
  a += b;
  asm( "add %2, %1\n\t"   /* t := t + b */
       "cmovc %1, %0\n\t" /* if (carry) a := t */
       : "+r"( a ), "+&r"( t )
       : "r"( b )
       : "cc" );
  return a;
}

#define mulmod( a, b, n ) _mulmod( a, b, n )
#define sqrmod( a, n ) _mulmod( a, a, n )
#define addmod( a, b, n ) _addmod( a, b, n )

static inline uint64_t submod( uint64_t a, uint64_t b, uint64_t n ) {
  uint64_t t = n - b; /* Evaluate as uint64_t, then hand to addmod */
  return addmod( a, t, n );
}

/* a*b - c mod n */
#define mulsubmod( a, b, c, n ) submod( mulmod( a, b, n ), c, n )

/* a^k mod n */
static inline uint64_t powmod( uint64_t a, uint64_t k, uint64_t n ) {
  uint64_t t = 1;
  if( a >= n ) {
    a %= n;
  }
  while( k ) {
    if( k & 1 ) {
      t = ( t * a ) % n;
    }
    k >>= 1;
    if( k ) {
      a = ( a * a ) % n;
    }
  }
  return t;
}

int miller_rabin( uint64_t const n ) {
  uint64_t d = n - 1;
  int r, s = 0;

  while( !( d & 1 ) ) {
    s++;
    d >>= 1;
  }
  uint64_t x, a = 2;
  a %= n;
  if( a == 0 || ( a == n - 1 && a & 1 ) ) {
    return 0;
  }
  if( a == 1 || a == n - 1 ) {
    return 1;
  }
  x = powmod( a, d, n );
  if( ( x == 1 ) || ( x == n - 1 ) ) {
    return 1;
  }
  for( r = 1; r < s; r++ ) {
    x = sqrmod( x, n );
    if( x == n - 1 ) {
      return 1;
    }
    if( x == 1 ) {
      return 0;
    }
  }
  if( r >= s ) {
    return 0;
  }
  return 1;
}

static int jacobi_iu( int64_t in, uint64_t m ) {
  int j = 1;
  uint64_t n = ( in < 0 ) ? -in : in;

  if( m <= 0 || ( m % 2 ) == 0 ) {
    return 0;
  }
  if( in < 0 && ( m % 4 ) == 3 ) {
    j = -j;
  }
  while( n != 0 ) {
    while( ( n % 2 ) == 0 ) {
      n >>= 1;
      if( ( m % 8 ) == 3 || ( m % 8 ) == 5 ) {
        j = -j;
      }
    }
    uint64_t t = n;
    n = m;
    m = t;
    if( ( n % 4 ) == 3 && ( m % 4 ) == 3 ) {
      j = -j;
    }
    n = n % m;
  }
  return ( m == 1 ) ? j : 0;
}

static uint64_t isqrt( uint64_t n ) {
  uint64_t root;
  root = ( uint64_t ) sqrt( ( double ) n );
  while( root * root > n ) {
    root--;
  }
  while( ( root + 1 ) * ( root + 1 ) <= n ) {
    root++;
  }
  return root;
}

static int is_perfect_square( uint64_t n ) {
  uint32_t m = n & 127;
  if( ( m * 0x8bc40d7d ) & ( m * 0xa1e2f5d1 ) & 0x14020a ) {
    return 0;
  }
  m = n % 240;
  if( ( m * 0xfa445556 ) & ( m * 0x8021feb1 ) & 0x614aaa0f ) {
    return 0;
  }
  m = isqrt( n );
  return ( uint64_t ) m * ( uint64_t ) m == n;
}

static uint64_t select_extra_strong_parameters( uint64_t n ) {
  int j;
  uint64_t D, P = 3;
  while( 1 ) {
    D = P * P - 4;
    j = jacobi_iu( D, n );
    if( j == 0 ) {
      return 0;
    }
    if( j == -1 ) {
      break;
    }
    if( P == ( 3 + 20 * 1 ) && is_perfect_square( n ) ) {
      return 0;
    }
    P += 1;
  }
  return P;
}

int is_almost_extra_strong_lucas_pseudoprime( uint64_t n ) {
  uint64_t P, V, W, d, s, b;

  P = select_extra_strong_parameters( n );
  if( P == 0 )
    return 0;

  d = n + 1;
  s = 0;
  while( ( d & 1 ) == 0 ) {
    s++;
    d >>= 1;
  }
  uint64_t v = d;
  b = 0;
  while( v >>= 1 ) {
    b++;
  }

  W = mulsubmod( P, P, 2, n );
  V = P;
  while( b-- ) {
    uint64_t T = mulsubmod( V, W, P, n );
    if( ( d >> b ) & 1ULL ) {
      V = T;
      W = mulsubmod( W, W, 2, n );
    } else {
      W = T;
      V = mulsubmod( V, V, 2, n );
    }
  }
  if( V == 2 || V == ( n - 2 ) ) {
    return 1;
  }
  while( s-- > 1 ) {
    if( V == 0 ) {
      return 1;
    }
    V = mulsubmod( V, V, 2, n );
    if( V == 2 ) {
      return 0;
    }
  }
  return 0;
}

int BPSW( uint64_t const n ) {
  if( n < 13 ) {
    return ( n == 2 || n == 3 || n == 5 || n == 7 || n == 11 );
  }
  if( ( n % 2 ) == 0 || n == ULONG_MAX ) {
    return 0;
  }

  return miller_rabin( n ) && is_almost_extra_strong_lucas_pseudoprime( n );
}
/*
int main() {
  uint64_t result = 0;
  for( uint64_t i = 2; i < 10000000; ++i ) {
    if( BPSW( i ) ) {
      ++result;
    }
  }
  printf( "result = %lu\n", result );
}
*/

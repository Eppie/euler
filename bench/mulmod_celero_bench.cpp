#include <celero/Celero.h>
#include <cstdint>

using celero::DoNotOptimizeAway;

uint64_t mulmod( uint64_t i, uint64_t j, uint64_t k ) {
  uint64_t r = 0;
  while( j > 0 ) {
    if( j & 1 )
      r = ( r + i ) % k;
    i = ( i + i ) % k;
    j >>= 1;
  }
  return r;
}

uint64_t mulmod_opt( uint64_t a, uint64_t b, uint64_t m ) {
  if( m == 0 ) {
    return a * b;
  }

  uint64_t r = 0;

  while( a > 0 ) {
    if( ( a & 2 ) == 0 )
      if( ( r += b ) > m ) {
        r %= m;
      }

    a >>= 1;

    if( ( b <<= 1 ) > m ) {
      b %= m;
    }
  }
  return r;
}

uint64_t mulmod_asm( uint64_t a, uint64_t b, uint64_t n ) {
  uint64_t d;
  uint64_t unused; // dummy output, unused, to tell GCC that RAX register is modified by this snippet
  asm( "mulq %3\n\t"
       "divq %4"
       : "=a"( unused ), "=&d"( d )
       : "a"( a ), "rm"( b ), "rm"( n )
       : "cc" );
  return d;
}

uint64_t mulmod_wiki1( uint64_t a, uint64_t b, uint64_t m ) {
  uint64_t d = 0, mp2 = m >> 1;
  int i;
  if( a >= m )
    a %= m;
  if( b >= m )
    b %= m;
  for( i = 0; i < 64; ++i ) {
    d = ( d > mp2 ) ? ( d << 1 ) - m : d << 1;
    if( a & 0x8000000000000000ULL )
      d += b;
    if( d >= m )
      d -= m;
    a <<= 1;
  }
  return d;
}

uint64_t mulmod_wiki2( uint64_t a, uint64_t b, uint64_t m ) {
  long double x;
  uint64_t c;
  int64_t r;
  if( a >= m )
    a %= m;
  if( b >= m )
    b %= m;
  x = a;
  c = x * b / m;
  r = ( int64_t )( a * b - c * m ) % ( int64_t ) m;
  return r < 0 ? r + m : r;
}

#define I_START 1111000
#define J_START 1111000
#define M_START 1

#define I_END 1111111
#define J_END 1111111
#define M_END 100

#define NUM_RUNS 0
#define NUM_ITERATIONS 3

BASELINE( MulmodBench, mulmod, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint64_t i = I_START; i <= I_END; ++i ) {
    for( uint64_t j = J_START; j <= J_END; ++j ) {
      for( uint64_t m = M_START; m <= M_END; ++m ) {
        DoNotOptimizeAway( mulmod( i, j, m ) );
      }
    }
  }
}

BENCHMARK( MulmodBench, mulmod_opt, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint64_t i = I_START; i <= I_END; ++i ) {
    for( uint64_t j = J_START; j <= J_END; ++j ) {
      for( uint64_t m = M_START; m <= M_END; ++m ) {
        DoNotOptimizeAway( mulmod_opt( i, j, m ) );
      }
    }
  }
}

BENCHMARK( MulmodBench, mulmod_asm, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint64_t i = I_START; i <= I_END; ++i ) {
    for( uint64_t j = J_START; j <= J_END; ++j ) {
      for( uint64_t m = M_START; m <= M_END; ++m ) {
        DoNotOptimizeAway( mulmod_asm( i, j, m ) );
      }
    }
  }
}

BENCHMARK( MulmodBench, mulmod_wiki1, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint64_t i = I_START; i <= I_END; ++i ) {
    for( uint64_t j = J_START; j <= J_END; ++j ) {
      for( uint64_t m = M_START; m <= M_END; ++m ) {
        DoNotOptimizeAway( mulmod_wiki1( i, j, m ) );
      }
    }
  }
}

BENCHMARK( MulmodBench, mulmod_wiki2, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint64_t i = I_START; i <= I_END; ++i ) {
    for( uint64_t j = J_START; j <= J_END; ++j ) {
      for( uint64_t m = M_START; m <= M_END; ++m ) {
        DoNotOptimizeAway( mulmod_wiki2( i, j, m ) );
      }
    }
  }
}

CELERO_MAIN

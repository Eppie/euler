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

// Computes 'a^b / n'
constexpr auto pow( uint64_t a, int b, uint64_t n ) -> uint64_t {
  __int128 res = 1;
  for( int i = 0; i < b; ++i ) {
    res *= a;
  }
  return res / n;
}

constexpr auto n_clog( uint64_t n ) -> uint64_t {
  uint64_t r = 0;
  while( n >>= 1 != 0u ) {
    ++r;
  }
  return r;
}

#define I_START 10'000'000'000'000
#define M_START 10'000'000'009'969

#define I_END 10'000'000'009'000
#define M_END M_START

constexpr int k = n_clog( M_START ) << 1;
constexpr uint64_t r = pow( 4, k >> 1, M_START );

auto mulmod_barrett( uint64_t a, uint64_t b, uint64_t n, int k, uint64_t r ) -> uint64_t {
  __int128 x = a * b;
  uint64_t t = x - ( ( ( x * r ) >> k ) * n );
  return ( t < n ? t : t - n );
}

#define NUM_RUNS 0
#define NUM_ITERATIONS 3

BASELINE( MulmodBench, mulmod, NUM_RUNS, NUM_ITERATIONS ) {
  uint64_t result = I_START - 1;
  for( uint64_t i = I_START; i <= I_END; ++i ) {
    for( uint64_t m = M_START; m <= M_END; ++m ) {
      DoNotOptimizeAway( result = mulmod( result, i, m ) );
    }
  }
}

BENCHMARK( MulmodBench, mulmod_barrett, NUM_RUNS, NUM_ITERATIONS ) {
  uint64_t result = I_START - 1;
  for( uint64_t i = I_START; i <= I_END; ++i ) {
    for( uint64_t m = M_START; m <= M_END; ++m ) {
      DoNotOptimizeAway( result = mulmod_barrett( result, i, m, k, r ) );
    }
  }
}

BENCHMARK( MulmodBench, mulmod_opt, NUM_RUNS, NUM_ITERATIONS ) {
  uint64_t result = I_START - 1;
  for( uint64_t i = I_START; i <= I_END; ++i ) {
    for( uint64_t m = M_START; m <= M_END; ++m ) {
      DoNotOptimizeAway( result = mulmod_opt( result, i, m ) );
    }
  }
}

BENCHMARK( MulmodBench, mulmod_asm, NUM_RUNS, NUM_ITERATIONS ) {
  uint64_t result = I_START - 1;
  for( uint64_t i = I_START; i <= I_END; ++i ) {
    for( uint64_t m = M_START; m <= M_END; ++m ) {
      DoNotOptimizeAway( result = mulmod_asm( result, i, m ) );
    }
  }
}

BENCHMARK( MulmodBench, mulmod_wiki1, NUM_RUNS, NUM_ITERATIONS ) {
  uint64_t result = I_START - 1;
  for( uint64_t i = I_START; i <= I_END; ++i ) {
    for( uint64_t m = M_START; m <= M_END; ++m ) {
      DoNotOptimizeAway( result = mulmod_wiki1( result, i, m ) );
    }
  }
}

BENCHMARK( MulmodBench, mulmod_wiki2, NUM_RUNS, NUM_ITERATIONS ) {
  uint64_t result = I_START - 1;
  for( uint64_t i = I_START; i <= I_END; ++i ) {
    for( uint64_t m = M_START; m <= M_END; ++m ) {
      DoNotOptimizeAway( result = mulmod_wiki2( result, i, m ) );
    }
  }
}

CELERO_MAIN

#include <cstdint>

static inline uint64_t mul128( uint64_t a, uint64_t b, uint64_t *hi ) {
  uint64_t lo;
  asm( "mulq %3" : "=a"( lo ), "=d"( *hi ) : "a"( a ), "rm"( b ) );
  return lo;
}

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

static inline uint64_t mont_prod64( uint64_t a, uint64_t b, uint64_t n, uint64_t npi ) {
  uint64_t t_hi, t_lo, m, mn_hi, mn_lo, u;
  int carry;

  // t_hi * 2^64 + t_lo = a*b
  t_lo = mul128( a, b, &t_hi );

  m = t_lo * npi;

  // mn_hi * 2^64 + mn_lo = m*n
  mn_lo = mul128( m, n, &mn_hi );

  carry = t_lo + mn_lo < t_lo ? 1 : 0;

  u = t_hi + mn_hi + carry;
  if( u < t_hi )
    return u - n;

  return u >= n ? u - n : u;
}

static inline uint64_t mont_square64( const uint64_t a, const uint64_t n, const uint64_t npi ) {
  return mont_prod64( a, a, n, npi );
}

// WARNING: a must be odd
// returns -a^-1 mod 2^64
static inline uint64_t modular_inverse64( const uint64_t a ) {
  static const unsigned char mask[128] = {
      255, 85,  51,  73,  199, 93,  59,  17,  15,  229, 195, 89,  215, 237, 203, 33,  31,  117, 83,  105, 231, 125,
      91,  49,  47,  5,   227, 121, 247, 13,  235, 65,  63,  149, 115, 137, 7,   157, 123, 81,  79,  37,  3,   153,
      23,  45,  11,  97,  95,  181, 147, 169, 39,  189, 155, 113, 111, 69,  35,  185, 55,  77,  43,  129, 127, 213,
      179, 201, 71,  221, 187, 145, 143, 101, 67,  217, 87,  109, 75,  161, 159, 245, 211, 233, 103, 253, 219, 177,
      175, 133, 99,  249, 119, 141, 107, 193, 191, 21,  243, 9,   135, 29,  251, 209, 207, 165, 131, 25,  151, 173,
      139, 225, 223, 53,  19,  41,  167, 61,  27,  241, 239, 197, 163, 57,  183, 205, 171, 1};

  // use Hensel lifting, suggested by Robert Gerbicz
  uint64_t ret = mask[( a >> 1 ) & 127];
  ret *= 2 + a * ret;
  ret *= 2 + a * ret;
  ret *= 2 + a * ret;
  return ret;
}

// returns 2^64 mod n
static inline uint64_t compute_modn64( const uint64_t n ) {
  if( n <= ( 1ULL << 63 ) ) {
    uint64_t res = ( ( 1ULL << 63 ) % n ) << 1;
    return res < n ? res : res - n;
  } else {
    return -n;
  }
}

static inline uint64_t compute_a_times_2_64_mod_n( const uint64_t a, const uint64_t n, const uint64_t r ) {
  return mulmod64( a, r, n );
}

static inline int efficient_mr64( const uint64_t n ) {
  if( n == 2 || n == 3 || n == 5 || n == 7 ) {
    return true;
  }
  if( n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0 ) {
    return false;
  }
  if( n < 121 ) {
    return n > 1;
  }

  const uint64_t npi = modular_inverse64( n );
  const uint64_t r = compute_modn64( n );
  static const uint64_t bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
  const int cnt = 7;

  uint64_t u = n - 1;
  const uint64_t nr = n - r;

  int t = 0, j;

  t = __builtin_ctzll( u );
  u >>= t;

  for( j = 0; j < cnt; j++ ) {
    const uint64_t a = bases[j];

    uint64_t A = compute_a_times_2_64_mod_n( a, n, r ); // a * 2^64 mod n
    uint64_t d = r, u_copy = u;
    int i;

    if( !A ) {
      continue; // PRIME in subtest
    }

    // compute a^u mod n
    do {
      if( u_copy & 1 ) {
        d = mont_prod64( d, A, n, npi );
      }
      A = mont_square64( A, n, npi );
    } while( u_copy >>= 1 );

    if( d == r || d == nr ) {
      continue; // PRIME in subtest
    }

    for( i = 1; i < t; i++ ) {
      d = mont_square64( d, n, npi );
      if( d == r ) {
        return false;
      }
      if( d == nr ) {
        break; // PRIME in subtest
      }
    }

    if( i == t ) {
      return false;
    }
  }

  return true;
}

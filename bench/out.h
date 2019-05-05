#include <cstdint>

static inline uint64_t _mulmod( uint64_t a, uint64_t b, uint64_t n ) {
  uint64_t d, dummy;
  asm( "mulq %3\n\t"
       "divq %4\n\t"
       : "=a"( dummy ), "=&d"( d )
       : "a"( a ), "r"( b ), "r"( n )
       : "cc" );
  return d;
}

static inline uint64_t _addmod( uint64_t a, uint64_t b, uint64_t n ) {
  uint64_t t = a - n;
  a += b;
  asm( "add %2, %1\n\t"
       "cmovc %1, %0\n\t"
       : "+r"( a ), "+&r"( t )
       : "r"( b )
       : "cc" );
  return a;
}

static inline uint64_t submod( uint64_t a, uint64_t b, uint64_t n ) {
  uint64_t t = n - b;
  return _addmod( a, t, n );
}

static inline uint64_t powmod( uint64_t a, uint64_t k, uint64_t n ) {
  uint64_t t = 1;
  if( a >= n )
    a %= n;
  if( n < ( 1ULL << ( 64 / 2 ) ) ) {
    while( k ) {
      if( k & 1 )
        t = ( t * a ) % n;
      k >>= 1;
      if( k )
        a = ( a * a ) % n;
    }
  } else {
    while( k ) {
      if( k & 1 )
        t = _mulmod( t, a, n );
      k >>= 1;
      if( k )
        a = _mulmod( a, a, n );
    }
  }
  return t;
}

#define mulmod( a, b, n ) _mulmod( a, b, n )
#define sqrmod( a, n ) _mulmod( a, a, n )
#define addmod( a, b, n ) _addmod( a, b, n )
/* a^2 + c mod n */
#define sqraddmod( a, c, n ) addmod( sqrmod( a, n ), c, n )
/* a*b + c mod n */
#define muladdmod( a, b, c, n ) addmod( mulmod( a, b, n ), c, n )
/* a*b - c mod n */
#define mulsubmod( a, b, c, n ) submod( mulmod( a, b, n ), c, n )
/* a^k + c mod n */
#define powaddmod( a, k, c, n ) addmod( powmod( a, k, n ), c, n )

#define mont_get1( n ) _u64div( 1, n )
/* Must have npi = mont_inverse(n), mont1 = mont_get1(n) */
#define mont_get2( n ) addmod( mont1, mont1, n )
#define mont_geta( a, n ) mulmod( a, mont1, n )
#define mont_mulmod( a, b, n ) _mulredc( a, b, n, npi )
#define mont_sqrmod( a, n ) _mulredc( a, a, n, npi )
#define mont_powmod( a, k, n ) _powredc( a, k, mont1, n, npi )
#define mont_recover( a, n ) mont_mulmod( a, 1, n )

/* Save one branch if desired by calling directly */
#define mont_mulmod63( a, b, n ) _mulredc63( a, b, n, npi )
#define mont_mulmod64( a, b, n ) _mulredc64( a, b, n, npi )

/* See https://arxiv.org/pdf/1303.0328.pdf for lots of details on this.
 * The 128-entry table solution is about 20% faster */
static inline uint64_t mont_inverse( const uint64_t n ) {
  uint64_t ret = ( 3 * n ) ^ 2;
  ret *= ( uint64_t ) 2 - n * ret;
  ret *= ( uint64_t ) 2 - n * ret;
  ret *= ( uint64_t ) 2 - n * ret;
  ret *= ( uint64_t ) 2 - n * ret;
  return ( uint64_t ) 0 - ret;
}

/* MULREDC asm from Ben Buhrow */
static inline uint64_t _mulredc63( uint64_t a, uint64_t b, uint64_t n, uint64_t npi ) {
  asm( "mulq %2 \n\t"
       "movq %%rax, %%r10 \n\t"
       "movq %%rdx, %%r11 \n\t"
       "mulq %3 \n\t"
       "mulq %4 \n\t"
       "addq %%r10, %%rax \n\t"
       "adcq %%r11, %%rdx \n\t"
       "xorq %%rax, %%rax \n\t"
       "subq %4, %%rdx \n\t"
       "cmovc %4, %%rax \n\t"
       "addq %%rdx, %%rax \n\t"
       : "=a"( a )
       : "0"( a ), "r"( b ), "r"( npi ), "r"( n )
       : "rdx", "r10", "r11", "cc" );
  return a;
}
static inline uint64_t _mulredc64( uint64_t a, uint64_t b, uint64_t n, uint64_t npi ) {
  asm( "mulq %1 \n\t"
       "movq %%rax, %%r10 \n\t"
       "movq %%rdx, %%r11 \n\t"
       "movq $0, %%r12 \n\t"
       "mulq %2 \n\t"
       "mulq %3 \n\t"
       "addq %%r10, %%rax \n\t"
       "adcq %%r11, %%rdx \n\t"
       "cmovae %3, %%r12 \n\t"
       "xorq %%rax, %%rax \n\t"
       "subq %3, %%rdx \n\t"
       "cmovc %%r12, %%rax \n\t"
       "addq %%rdx, %%rax \n\t"
       : "+&a"( a )
       : "r"( b ), "r"( npi ), "r"( n )
       : "rdx", "r10", "r11", "r12", "cc" );
  return a;
}
#define _mulredc( a, b, n, npi )                                                                                       \
  ( ( n & 0x8000000000000000ULL ) ? _mulredc64( a, b, n, npi ) : _mulredc63( a, b, n, npi ) )

static inline uint64_t _powredc( uint64_t a, uint64_t k, uint64_t one, uint64_t n, uint64_t npi ) {
  uint64_t t = one;
  while( k ) {
    if( k & 1 )
      t = mont_mulmod( t, a, n );
    k >>= 1;
    if( k )
      a = mont_sqrmod( a, n );
  }
  return t;
}

static inline uint64_t _u64div( uint64_t c, uint64_t n ) {
  asm( "divq %4" : "=a"( c ), "=d"( n ) : "1"( c ), "0"( 0 ), "r"( n ) );
  return n;
}

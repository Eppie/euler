#include <cmath>
#include <cstdint>

namespace MPU {

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
} // namespace MPU

int is_prob_prime( uint32_t x ) {
  if( x < 11 ) {
    return ( x == 2 || x == 3 || x == 5 || x == 7 ) ? 2 : 0;
  }
  if( !( x % 2 ) || !( x % 3 ) || !( x % 5 ) || !( x % 7 ) ) {
    return 0;
  }
  if( x < 121 ) {
    return 2;
  }
  if( !( x % 11 ) || !( x % 13 ) || !( x % 17 ) || !( x % 19 ) || !( x % 23 ) || !( x % 29 ) || !( x % 31 )
      || !( x % 37 ) || !( x % 41 ) || !( x % 43 ) || !( x % 47 ) || !( x % 53 ) ) {
    return 0;
  }
  if( x < 3481 ) {
    return 2;
  }
  uint32_t f = 59;
  uint32_t limit = MPU::isqrt( x );
  while( f <= limit ) {
    if( ( x % f ) == 0 )
      return 0;
    f += 2;
    if( ( x % f ) == 0 )
      return 0;
    f += 6;
    if( ( x % f ) == 0 )
      return 0;
    f += 4;
    if( ( x % f ) == 0 )
      return 0;
    f += 2;
    if( ( x % f ) == 0 )
      return 0;
    f += 4;
    if( ( x % f ) == 0 )
      return 0;
    f += 2;
    if( ( x % f ) == 0 )
      return 0;
    f += 4;
    if( ( x % f ) == 0 )
      return 0;
    f += 6;
  }
  return 2;
}

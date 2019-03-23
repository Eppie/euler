#include <cstdio>
#include <cstdlib>

bool is_SPRP( uint64_t n, uint64_t a, uint64_t d ) {
  uint64_t cur = 1;
  for( ; d > 0; d >>= 1 ) {
    if( d & 1 ) {
      cur = ( cur * a ) % n;
    }
    a = ( a * a ) % n;
  }
  if( cur == 1 ) {
    return true;
  }
  return false;
}

int main() {
  uint64_t n = 16607;
  uint64_t d = ( n - 1 ) >> __builtin_ctz( n - 1 );
  uint64_t sum = 0;
  for( uint64_t a = 2; a <= 65536; ++a ) {
    sum += is_SPRP( n, a, d );
  }
  printf( "%llu\n", sum );
  return 0;
}

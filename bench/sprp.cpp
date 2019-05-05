#include <cstdio>
#include <cstdint>
#include <cstdlib>

bool sprp( uint32_t n, uint32_t a ) {
printf("========================================\n");

  uint32_t d = n - 1;
  uint32_t s = __builtin_ctz( d );
  d >>= s;

printf("n = %u, a = %u, d = %u, s = %u\n", n, a, d, s );

  uint64_t cur = 1;
  uint64_t pw = d;
  pw >>= 1;
  cur = ( cur * a ) % n;
  a = ( ( uint64_t ) a * a ) % n;

  while( pw ) {
printf("pw = %llu, cur = %llu, a = %u\n", pw, cur, a);
    if( pw & 1 ) {
      cur = ( cur * a ) % n;
    }
    a = ( ( uint64_t ) a * a ) % n;
    pw >>= 1;
  }
printf("pw = %llu, cur = %llu, a = %u\n", pw, cur, a);
  if( cur == 1 ) {
   // printf("cur = 1, return true\n");
printf("========================================\n");
    return true;
  }
  for( uint32_t r = 0; r < s; r++ ) {
    if( cur == n - 1 ) {
     // printf("cur = n -1, r = %u, s = %u, return true\n", r, s);
printf("========================================\n");
      return true;
    }
    cur = ( cur * cur ) % n;
  }
  //printf("return false\n");
printf("========================================\n");
  return false;
}


int main() {
  uint32_t result = 0;
  for( uint32_t i = 2; i < 100; i += 1 ) {
    if( sprp( i, 2 ) ) {
      ++result;
    }
  }
  printf( "%d\n", result );
}


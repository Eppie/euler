#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <inttypes.h>

using std::atoi;

#define LIMIT ( 1 )
// 30k + i for i = 1, 7, 11, 13, 17, 19, 23, 29

uint16_t hash( uint32_t n ) {
  long long t = n;
  printf( "%" PRId64 "\n", t );
  printf( "%" PRId64 "\n", ( t >> 16 ) );
  printf( "%" PRId64 "\n", ( t >> 16 ) ^ t );
  printf( "%" PRId64 "\n", ( ( ( t >> 16 ) ^ t ) * 0x45d9f3b ) % 512 );
  t = ( ( t >> 16 ) ^ t ) * 0x45d9f3b; // 0x3335b369
  return t % 512;
}

int main( int argc, char **argv ) {
  auto values = new uint16_t[LIMIT];
  uint32_t a = atoi( argv[1] );
  uint64_t result = 0;
  for( uint32_t i = 0; i < LIMIT; ++i ) {
    values[i] = hash( i + a );
    printf( "%" PRId64 "\n", values[i] );
  }
  for( uint32_t i = 0; i < LIMIT; ++i ) {
    result += values[i];
  }
  /*
  printf( "%llu\n", result );
  printf( "%llu\n", values[0] );
  printf( "%llu\n", values[1] );
  printf( "%llu\n", values[2] );
  printf( "%llu\n", values[3] );
  */
}

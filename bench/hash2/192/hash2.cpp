#include <cstdio>
#include <cstdlib>

#define TABLE_SIZE 192

uint16_t hash( uint32_t n ) {
  long long t = n;
  t = ( ( t >> 16 ) ^ t ) * 0xda2e4f1;
  return t % TABLE_SIZE;
}

int main() {
  FILE *files[TABLE_SIZE];
  for( uint16_t i = 0; i < TABLE_SIZE; ++i ) {
    char fname[100];
    sprintf( fname, "%hu.txt", i );
    files[i] = fopen( fname, "a" );
  }
  for( uint64_t i = 3; i <= ( 1ULL << 32 ) - 1; i += 2 ) {
    if( i % 3 != 0 && i % 5 != 0 && i % 7 != 0 && i % 11 != 0 && i % 13 != 0 && i % 17 != 0 && i % 19 != 0
        && i % 23 != 0 && i % 29 != 0 && i % 31 != 0 && i % 37 != 0 && i % 41 != 0 && i % 43 != 0 && i % 47 != 0
        && i % 53 != 0 ) {
      uint16_t h = hash( static_cast<uint32_t>( i ) );
      fprintf( files[h], "%llu\n", i );
    }
  }
  for( uint16_t i = 0; i < TABLE_SIZE; ++i ) {
    fclose( files[i] );
  }
  return 0;
}

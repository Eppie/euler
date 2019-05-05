#include <cstdio>
#include <cstdlib>

#define TABLE_SIZE 512

uint16_t hash( uint32_t n ) {
  long long t = n;
  t = ( ( t >> 16 ) ^ t ) * 0xda2e4f1;
  return t % TABLE_SIZE;
}

int main() {
  auto vals = new uint32_t[600000000];
  uint32_t vals_position = 0;
  for( uint64_t i = 3; i <= ( 1ULL << 32 ) - 1; i += 2 ) {
    if( i % 3 != 0 && i % 5 != 0 && i % 7 != 0 && i % 11 != 0 && i % 13 != 0 && i % 17 != 0 && i % 19 != 0
        && i % 23 != 0 && i % 29 != 0 && i % 31 != 0 && i % 37 != 0 && i % 41 != 0 && i % 43 != 0 && i % 47 != 0
        && i % 53 != 0 ) {
      vals[vals_position] = i;
      vals_position++;
    }
  }
  auto a = new uint32_t *[TABLE_SIZE];
  auto positions = new uint32_t[TABLE_SIZE];
  for( int i = 0; i < TABLE_SIZE; ++i ) {
    a[i] = new uint32_t[2000000];
    positions[i] = 0;
  }

  for( uint32_t i = 0; i < vals_position; ++i ) {
    uint16_t h = hash( vals[i] );
    a[h][positions[h]] = vals[i];
    positions[h]++;
  }

  for( uint32_t i = 0; i < TABLE_SIZE; ++i ) {
    char fname[100];
    sprintf( fname, "%hu.txt", i );
    FILE* f = fopen( fname, "a" );
    for( uint32_t j = 0; j < positions[i]; ++j ) {
      fprintf( f, "%u\n", a[i][j] );
    }
    fclose(f);
    delete[] a[i];
  }

  return 0;
}

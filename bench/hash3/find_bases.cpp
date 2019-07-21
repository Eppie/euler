#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <vector>

#define TABLE_SIZE 708

using std::vector;

vector<bool> B( 2147483648, true );
void sieveOfE() {
  B[0] = false;
  B[1] = false;
  for( uint64_t i = 3; i <= 65536; i += 2 ) {
    if( B[i / 2] ) {
      for( uint64_t j = i * i; j < 4294967296; j += ( 2 * i ) ) {
        B[j / 2] = false;
      }
    }
  }
}

bool isPrimeE( uint32_t n ) {
  if( ( ( !( n & 1 ) ) && n != 2 ) || ( n < 2 ) || ( n % 3 == 0 && n != 3 ) ) {
    return false;
  }
  if( n <= 3 ) {
    return true;
  }
  return B[n / 2];
}

static inline uint64_t powmod( uint64_t a, uint64_t k, uint64_t n ) {
  uint64_t t = 1;
  if( a >= n ) {
    a %= n;
  }
  while( k != 0 ) {
    if( ( k & 1ULL ) != 0 ) {
      t = ( t * a ) % n;
    }
    k >>= 1ULL;
    if( k != 0 ) {
      a = ( a * a ) % n;
    }
  }
  return t;
}

bool prp( uint64_t const n, uint64_t a ) {
  if( a >= n ) {
    a %= n;
    if( a <= 1 ) {
      return ( a == 1 );
    }
    if( a == n - 1 ) {
      return !( a & 1ULL );
    }
  }

  return powmod( a, n - 1, n ) == 1; /* a^(n-1) = 1 mod n */
}

int main() {
  setbuf( stdout, NULL );
  setbuf( stderr, NULL );
  sieveOfE();
  uint32_t numDone = 0;
#pragma omp parallel for
  for( uint32_t f = 0; f < TABLE_SIZE; ++f ) {
    char fname[100];
    sprintf( fname, "%u.txt", f );
    FILE *fin = fopen( fname, "r" );
    char w[20];
    uint32_t *values = new uint32_t[4'000'000]();
    uint32_t numValues = 0;
    while( fscanf( fin, "%s", w ) != EOF ) {
      uint32_t v = atoi( w );
      values[numValues] = v;
      ++numValues;
    }

    uint32_t base = 2;
    bool isGood = true;
    uint32_t bestIndex = 0;
    uint32_t swapCounter = 0;

    while( true ) {
      for( uint32_t i = 0; i < numValues; ++i ) {
        uint32_t v = values[i];
        if( isPrimeE( v ) != prp( v, base ) ) {
          isGood = false;
          if( i > swapCounter ) {
            //        printf( "%u\n", v );
            uint32_t tmp = values[swapCounter];
            values[swapCounter] = v;
            values[i] = tmp;
            ++swapCounter;
          }
          if( i > bestIndex ) {
            bestIndex = i;
            fprintf( stderr, "New best: %u / %u, with base %u, for hash value %u, swapCounter = %u\n", bestIndex, v,
                     base, f, swapCounter );
          } else if( base % 10'000'000 == 0 ) {
            fprintf( stderr, "At base %u for hash value %u, swapCounter = %u\n", base, f, swapCounter );
          }
          break;
        }
      }
      if( isGood ) {
        ++numDone;
        fprintf( stderr, "------------Base %u is good for hash value %u! swapCounter = %u. (%u/%u)\n", base, f,
                 swapCounter, numDone, TABLE_SIZE );
        printf( "%u, %u\n", base, f );
        break;
      } else {
        ++base;
        isGood = true;
      }
      if( base > 4'290'000'000 ) {
        printf( "Got to base 4,290,000,000 for hash value %u!\n", f );
        break;
      }
    }
    delete[] values;
  }
  return 0;
}

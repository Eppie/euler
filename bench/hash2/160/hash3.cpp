#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <vector>

#define TABLE_SIZE 160

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

bool is_SPRP( uint32_t n, uint32_t a ) {
  uint32_t d = n - 1;
  uint32_t s = 0;
  while( ( d & 1 ) == 0 ) {
    ++s;
    d >>= 1;
  }

  uint64_t cur = 1;
  uint64_t pw = d;
  while( pw ) {
    if( pw & 1 ) {
      cur = ( cur * a ) % n;
    }
    a = ( ( uint64_t ) a * a ) % n;
    pw >>= 1;
  }
  if( cur == 1 ) {
    return true;
  }
  for( uint32_t r = 0; r < s; r++ ) {
    if( cur == n - 1 ) {
      return true;
    }
    cur = ( cur * cur ) % n;
  }
  return false;
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
    uint32_t *values = new uint32_t[10'000'000]();
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
        if( isPrimeE( v ) != is_SPRP( v, base ) ) {
          isGood = false;
          if( i > swapCounter ) {
            uint32_t tmp = values[swapCounter];
            values[swapCounter] = v;
            values[i] = tmp;
            ++swapCounter;
          }
          if( i > bestIndex ) {
            bestIndex = i;
            fprintf( stderr, "New best: %u / %u, with base %u, for hash value %u, swapCounter = %u\n", bestIndex, v,
                     base, f, swapCounter );
          } else if( base % 1000000 == 0 ) {
            fprintf( stderr, "At base %u for hash value %u, swapCounter = %u\n", base, f, swapCounter );
          }
          break;
        }
      }
      if( isGood ) {
        ++numDone;
        fprintf( stderr, "------------Base %d is good for hash value %d! swapCounter = %u. (%d/%d)\n", base, f,
                 swapCounter, numDone, TABLE_SIZE );
        printf( "%d, %d\n", base, f );
        break;
      } else {
        ++base;
        isGood = true;
      }
      if( base > 1'000'000'000 ) {
        printf( "Got to base 1,000,000,000 for hash value %d!\n", f );
        break;
      }
    }
    delete[] values;
  }
  return 0;
}

#include <cstdio>
#include <cstdlib>
#include <vector>

using std::vector;

vector<bool> B( 2147483648, true );
void sieveOfE() {
  B[0] = false;
  B[1] = false;
  for( uint64_t i = 3; i <= 65536; i += 2 ) {
    if( B[i / 2] ) {
#pragma loop distribute( enable )
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

bool is_SPRP( uint32_t n, uint32_t a, const uint32_t d, const uint32_t s ) {
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
  sieveOfE();
  for( uint64_t i = 3; i <= ( 1ULL << 32ULL ) - 1; i += 2 ) {
    if( i % 3 != 0 && i % 5 != 0 && i % 7 != 0 && i % 11 != 0 ) {
      bool expected = isPrimeE( static_cast<uint32_t>( i ) );
#pragma omp parallel for
      for( uint32_t a = 129; a <= 1048576; ++a ) {
        uint32_t d = static_cast<uint32_t>( i ) - 1;
        uint32_t s = 0;
        while( ( d & 1 ) == 0 ) {
          ++s;
          d >>= 1;
        }
        bool actual = is_SPRP( static_cast<uint32_t>( i ), a, d, s );
        if( expected != actual ) {
          printf( "%llu, %d\n", i, a );
        }
      }
    }
  }
  return 0;
}

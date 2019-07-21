#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>

using std::map;
using std::vector;

int main( /*int argc,*/ /*char **argv*/ ) {
  auto counts = new uint32_t[256];
  uint32_t count = 0;
  uint32_t prev_count = 256;
  uint32_t base = 0;
  uint32_t hash = 0;
  map<uint32_t, vector<uint32_t>> base_to_hash;
  vector<uint32_t> result;
  for( int i = 0; i < 448; ++i ) {
    scanf( "%d, %d", &base, &hash );
    base_to_hash[base].push_back( hash );
  }
  for( auto &&h: base_to_hash ) {
    auto [base, hash] = h;
    for( auto &&value: hash ) {
      counts[value]++;
      //    printf("%d, %d\n", base, value);
    }
    count = 0;
    for( int i = 0; i < 256; ++i ) {
      count += counts[i] == 0;
    }
    if( count < prev_count ) {
      result.push_back( base );
      printf( "Added: %d\n", base );
    } else {
      printf( "Skipped: %d\n", base );
    }
    prev_count = count;
  }
  return 0;
}

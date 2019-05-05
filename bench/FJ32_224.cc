#include <cstdlib>

namespace FJ32_224_detail {
unsigned long long bases_1[] = {
    4449ll,  7617ll,  19304ll, 2317ll,  6901ll,  10614ll, 8095ll,  415ll,   39348ll, 2284ll,  2495ll,   37088ll,
    11571ll, 16533ll, 4793ll,  39467ll, 7716ll,  24102ll, 29587ll, 11992ll, 1408ll,  13910ll, 640ll,    518ll,
    15859ll, 60189ll, 3590ll,  7311ll,  16684ll, 6237ll,  44999ll, 760ll,   2549ll,  11973ll, 17832ll,  2362ll,
    13007ll, 60289ll, 4494ll,  18172ll, 1928ll,  13920ll, 4826ll,  39794ll, 19361ll, 6097ll,  12521ll,  12006ll,
    1859ll,  207ll,   12123ll, 846ll,   5559ll,  4475ll,  5154ll,  326ll,   63629ll, 6251ll,  125404ll, 7181ll,
    7510ll,  521ll,   2550ll,  305ll,   9375ll,  22163ll, 9953ll,  5143ll,  4256ll,  466ll,   16576ll,  6966ll,
    30305ll, 21256ll, 11999ll, 3179ll,  46775ll, 24116ll, 2642ll,  20411ll, 1540ll,  2302ll,  4595ll,   1436ll,
    8030ll,  7482ll,  23774ll, 15508ll, 13330ll, 17589ll, 87149ll, 9516ll,  148ll,   124ll,   25355ll,  6811ll,
    14255ll, 51320ll, 15056ll, 24151ll, 1426ll,  11592ll, 4561ll,  12444ll, 3197ll,  5314ll,  3506ll,   4544ll,
    12367ll, 25522ll, 14564ll, 4699ll,  5574ll,  1676ll,  7524ll,  49311ll, 16257ll, 6999ll,  325ll,    112287ll,
    886ll,   11489ll, 8802ll,  30584ll, 59752ll, 10462ll, 3900ll,  25817ll, 4688ll,  7526ll,  2229ll,   44913ll,
    62628ll, 10638ll, 1124ll,  1516ll,  11074ll, 6189ll,  50255ll, 2964ll,  5350ll,  8749ll,  8967ll,   2755ll,
    815ll,   31496ll, 23658ll, 4075ll,  4308ll,  965ll,   3123ll,  2689ll,  3608ll,  12550ll, 531ll,    16079ll,
    5539ll,  5516ll,  36058ll, 265ll,   4564ll,  66795ll, 25051ll, 399ll,   5382ll,  26391ll, 3871ll,   1148ll,
    6279ll,  32672ll, 56981ll, 19194ll, 26149ll, 3467ll,  1394ll,  31396ll, 53539ll, 5568ll,  1899ll,   36945ll,
    24676ll, 9453ll,  65661ll, 98668ll, 559ll,   55081ll, 2030ll,  10324ll, 11975ll, 12257ll, 43829ll,  15111ll,
    346ll,   3856ll,  4512ll,  276ll,   3917ll,  32174ll, 11600ll, 849ll,   9492ll,  4710ll,  9428ll,   2911ll,
    5889ll,  12336ll, 2637ll,  8123ll,  982ll,   994ll,   1893ll,  11010ll, 10869ll, 14611ll, 1601ll,   8636ll,
    602ll,   23466ll, 213ll,   33773ll, 759ll,   5076ll,  2558ll,  2751ll};

uint64_t pow( uint64_t a, uint64_t e, uint64_t n ) {
  uint64_t ans = 1;
  while( e > 0 ) {
    if( e & 1 ) {
      ans = ( ans * a ) % n;
    }
    a = ( a * a ) % n;
    e >>= 1;
  }
  return ans;
}

// n is odd
int is_SPRP( uint64_t a, uint64_t n ) {
  int d = 0;
  uint64_t t = n - 1;
  while( t % 2 == 0 ) {
    ++d;
    t >>= 1;
  }
  uint64_t x = pow( a, t, n );
  if( x == 1 ) {
    return 1;
  }
  for( int i = 0; i < d; ++i ) {
    if( x == n - 1 ) {
      return 1;
    }
    x = ( x * x ) % n;
    if( x == 1 ) {
      return 0;
    }
  }
  return 0;
}
} // namespace FJ32_224_detail

int FJ32_224( uint32_t x ) {
  if( x < 2 ) {
    return 0;
  }
  if( x == 2 || x == 3 || x == 5 || x == 7 ) {
    return 1;
  }
  if( x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0 ) {
    return 0;
  }
  if( x < 121 ) {
    return x != 1;
  }

  long long t = x;
  t = ( ( t >> 16 ) ^ t ) * 0x45d9f3b; // 0x3335b369
  t = ( ( t >> 16 ) ^ t ) * 0x45d9f3b;
  t = ( ( t >> 16 ) ^ t );
  t = t % 224;
  return FJ32_224_detail::is_SPRP( FJ32_224_detail::bases_1[t], ( uint64_t ) x );
}

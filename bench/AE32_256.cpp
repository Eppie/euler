#include <cstdint>
#include <cstdlib>

namespace AE32_256_detail {
static const uint8_t arr[256] = {
    33,  106, 72,  158, 90,  136, 12,  10,  46,  8,   121, 16,  45,  55,  24,  84,  83,  123, 76,  35,  73,  69,
    72,  21,  142, 1,   70,  64,  143, 30,  151, 91,  46,  127, 157, 113, 134, 59,  116, 51,  55,  71,  6,   62,
    28,  4,   156, 149, 67,  93,  42,  85,  31,  50,  81,  18,  43,  2,   83,  78,  34,  2,   45,  40,  9,   7,
    58,  10,  85,  145, 13,  110, 124, 14,  80,  109, 100, 129, 32,  54,  52,  44,  148, 62,  24,  11,  19,  17,
    139, 32,  58,  5,   36,  135, 0,   94,  75,  56,  86,  108, 29,  6,   20,  40,  119, 5,   120, 78,  3,   125,
    5,   43,  66,  97,  52,  77,  36,  57,  81,  147, 28,  150, 49,  118, 89,  35,  146, 22,  65,  9,   41,  48,
    22,  3,   14,  153, 130, 140, 44,  53,  86,  74,  70,  19,  11,  144, 82,  25,  102, 33,  49,  95,  21,  37,
    15,  117, 9,   71,  69,  84,  88,  18,  137, 29,  3,   31,  7,   104, 30,  61,  60,  51,  73,  2,   138, 26,
    47,  54,  63,  75,  10,  126, 6,   92,  133, 80,  101, 8,   128, 96,  68,  27,  87,  105, 41,  48,  27,  77,
    4,   25,  17,  26,  13,  7,   132, 115, 4,   74,  0,   63,  11,  114, 87,  103, 68,  76,  131, 38,  38,  98,
    39,  99,  15,  23,  79,  112, 154, 12,  23,  53,  89,  20,  0,   65,  12,  59,  141, 60,  57,  107, 82,  79,
    47,  42,  8,   122, 16,  64,  56,  155, 34,  39,  61,  152, 37,  111};

static const uint16_t bases[159] = {
    265,   48901, 1041,  15020, 21922, 20081, 23596, 24034, 33247, 24923, 55124, 60282, 64423, 47,    740,   744,
    1381,  1278,  1399,  1486,  1647,  1769,  1807,  2861,  2008,  3444,  3855,  3945,  4249,  4463,  5209,  5508,
    6478,  6165,  6966,  7026,  7109,  7128,  8600,  9796,  10472, 10886, 11808, 11813, 12473, 13093, 15077, 14734,
    15335, 15102, 212,   16281, 16474, 17028, 18338, 18593, 20372, 21436, 21520, 22291, 25592, 25974, 27240, 27267,
    29430, 30009, 3778,  24976, 30061, 33221, 34376, 35205, 35318, 37505, 38080, 39294, 41232, 42144, 42759, 42857,
    46472, 42894, 48966, 54343, 53021, 58285, 64385, 64558, 20371, 65252, 88,    38,    8380,  153,   222,   273,
    276,   480,   426,   679,   725,   1116,  776,   1037,  5622,  1131,  1565,  1226,  22680, 1474,  1623,  1789,
    1775,  1835,  2449,  21994, 1953,  1978,  2091,  2013,  2165,  2114,  21951, 2175,  2270,  16411, 2310,  2535,
    2419,  2564,  2687,  2692,  2972,  7661,  3158,  3223,  3380,  3394,  3581,  3591,  12628, 3998,  4451,  3621,
    4731,  4846,  5455,  6500,  6557,  6715,  6874,  6974,  7830,  9034,  10289, 12086, 13498, 16182, 22990};

uint16_t hash( uint32_t n ) {
  long long t = n;
  t = ( ( t >> 16 ) ^ t ) * 0xda2e4f1;
  return t % 256;
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
} // namespace AE32_256_detail

bool AE32_256( uint32_t n ) {
  if( n < 2 ) {
    return false;
  }
  if( n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19 ) {
    return true;
  }
  if( n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0 || n % 11 == 0 || n % 13 == 0 || n % 17 == 0
      || n % 19 == 0 ) {
    return false;
  }
  uint16_t h = AE32_256_detail::hash( n );
  uint16_t base = AE32_256_detail::bases[AE32_256_detail::arr[h]];
  return AE32_256_detail::is_SPRP( n, base );
}
/*
#include <cstdio>

int main() {
  uint32_t result = 0;
  for( uint32_t i = 0; i < 10000000; ++i ) {
    if( AE32_256( i ) ) {
      ++result;
    }
  }
  printf( "%d\n", result );
}
*/

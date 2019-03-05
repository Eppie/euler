/*
 * =====================================================================================
 *
 *       Filename:  Euler124.cpp
 *
 *    Description:  Solution to Project Euler, Problem 124
 *
 *        Version:  1.0
 *        Created:  10/13/2018 3:00:10 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The radical of n, rad(n), is the product of the distinct prime factors of n.
 *                  For example, 504 = 2³ × 3² × 7, so rad(504) = 2 × 3 × 7 = 42.
 *                  If we calculate rad(n) for 1 ≤ n ≤ 10, then sort them on rad(n), and sorting on n if the radical values are equal, we get:
 *
 *                  ┌───────────────────┬──────────────────────┐
 *                  │      Unsorted     │        Sorted        │
 *                  ├──────────┬────────┼────────┬────────┬────┤
 *                  │ n        │ rad(n) │ n      │ rad(n) │ k  │
 *                  │ 1        │ 1      │ 1      │ 1      │ 1  │
 *                  │ 2        │ 2      │ 2      │ 2      │ 2  │
 *                  │ 3        │ 3      │ 4      │ 2      │ 3  │
 *                  │ 4        │ 2      │ 8      │ 2      │ 4  │
 *                  │ 5        │ 5      │ 3      │ 3      │ 5  │
 *                  │ 6        │ 6      │ 9      │ 3      │ 6  │
 *                  │ 7        │ 7      │ 5      │ 5      │ 7  │
 *                  │ 8        │ 2      │ 6      │ 6      │ 8  │
 *                  │ 9        │ 3      │ 7      │ 7      │ 9  │
 *                  │ 10       │ 10     │ 10     │ 10     │ 10 │
 *                  └──────────┴────────┴────────┴────────┴────┘
 *
 *                  Let E(k) be the kth element in the sorted n column; for example, E(4) = 8 and E(6) = 9.
 *                  If rad(n) is sorted for 1 ≤ n ≤ 100000, find E(10000).
 *         Answer:  21417
 *
 * =====================================================================================
 */
#include "../helper.hpp"

using std::vector;

namespace euler124 {
uint32_t rad( uint32_t n ) {
  uint32_t result = 1;

  if( n % 2 == 0 ) {
    result = 2;
    n = n / 2;
    while( n % 2 == 0 ) {
      n = n / 2;
    }
  }

  // n must be odd at this point, so we can count by 2's (Note i+=2)
  for( uint32_t i = 3; i * i <= n; i += 2 ) {
    if( n % i == 0 ) {
      result *= i;
      n = n / i;
      while( n % i == 0 ) {
        n = n / i;
      }
    }
  }

  result *= n;

  return result;
}
} // namespace euler124

uint32_t solve124() {
  vector<uint64_t> v;

  for( uint32_t n = 1; n <= 100000; ++n ) {
    uint64_t rn = euler124::rad( n );
    // Store rn in the upper 32 bits, and n in the lower 32 bits
    v.push_back( ( rn << 32U ) | n );
  }

  nth_element( v.begin(), v.begin() + 10000, v.end() );

  // Mask off n (lower 32 bits) and return
  return v[9999] & ( ( 1ULL << 32U ) - 1 );
}

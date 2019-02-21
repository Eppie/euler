/*
 * =====================================================================================
 *
 *       Filename:  Euler127.cpp
 *
 *    Description:  Solution to Project Euler, Problem 127
 *
 *        Version:  1.0
 *        Created:  2/19/2019 3:50:55 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The radical of n, rad(n), is the product of distinct prime factors of n. For example, 504 = 2³ × 3² × 7, so rad(504) = 2 × 3 × 7 = 42.
 *                  We shall define the triplet of positive integers (a, b, c) to be an abc-hit if:
 *                      GCD(a, b) = GCD(a, c) = GCD(b, c) = 1
 *                      a < b
 *                      a + b = c
 *                      rad(abc) < c
 *                  For example, (5, 27, 32) is an abc-hit, because:
 *                      GCD(5, 27) = GCD(5, 32) = GCD(27, 32) = 1
 *                      5 < 27
 *                      5 + 27 = 32
 *                      rad(4320) = 30 < 32
 *                  It turns out that abc-hits are quite rare and there are only thirty-one abc-hits for c < 1000, with ∑c = 12523.
 *                  Find ∑c for c < 120000.
 *         Answer:  18407904
 *
 * =====================================================================================
 */
#include "../helper.hpp"

#define LIMIT 120000

using std::fill_n;
using std::sort;

uint32_t cache[LIMIT];
uint64_t rads[LIMIT - 1];

uint32_t solve127() {
  fill_n( cache, LIMIT, 1 );

  for( uint32_t i = 2; i < LIMIT; ++i ) {
    if( cache[i] == 1 ) {
      for( uint32_t j = i; j < LIMIT; j += i ) {
        cache[j] *= i;
      }
    }
  }

  // Using 64-bit integers to store a number in the lower 32 bits and its radical in the upper 32 bits
  for( uint32_t i = 1; i < LIMIT; ++i ) {
    rads[i - 1] = ( static_cast<uint64_t>( cache[i] ) << 32U ) | ( i );
  }

  sort( rads, rads + ( LIMIT - 1 ) );

  uint32_t result = 0;

  for( uint32_t c = 2; c < LIMIT; ++c ) {
    for( uint32_t i = 0; i < LIMIT; ++i ) {
      uint32_t rad = ( rads[i] >> 32U ) & 0xFFFFFFFF;
      uint32_t a = rads[i] & 0xFFFFFFFF;
      rad *= cache[c];

      if( rad >= c ) {
        break;
      }

      uint32_t b = c - a;

      if( a > c ) {
        b = a - c;
      }

      if( a < b && rad * static_cast<uint64_t>( cache[b] ) < c && gcd( a, b ) == 1 ) {
        result += c;
      }
    }
  }
  return result;
}

/*
 * =====================================================================================
 *
 *       Filename:  Euler75.cpp
 *
 *    Description:  Solution to Project Euler, Problem 75
 *
 *        Version:  1.2
 *        Created:  9/25/2016 11:14:42 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  It turns out that 12 cm is the smallest length of wire that can be bent to form an integer sided right angle triangle in exactly one way,
 *                  but there are many more examples.
 *
 *                  12 cm: (3,4,5)
 *                  24 cm: (6,8,10)
 *                  30 cm: (5,12,13)
 *                  36 cm: (9,12,15)
 *                  40 cm: (8,15,17)
 *                  48 cm: (12,16,20)
 *
 *                  In contrast, some lengths of wire, like 20 cm, cannot be bent to form an integer sided right angle triangle,
 *                  and other lengths allow more than one solution to be found; for example, using 120 cm it is possible to form
 *                  exactly three different integer sided right angle triangles.
 *
 *                  120 cm: (30,40,50), (20,48,52), (24,45,51)
 *
 *                  Given that L is the length of the wire, for how many values of L ≤ 1,500,000
 *                  can exactly one integer sided right angle triangle be formed?
 *         Answer:  161667
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint32_t solve75() {
  uint32_t result = 0;
  static int cache[1500001];

  for( uint32_t n = 2; n < 864; ++n ) {
    // To avoid generating non-primitive triples, m and n must not both be odd
    uint32_t m_start = 1 + ( n % 2 );

    for( uint32_t m = m_start; m < n; m += 2 ) {
      // To avoid generating non-primitive triples, m and n must be coprime
      if( gcd( m, n ) != 1 ) {
        continue;
      }

      uint32_t a = ( n * n ) - ( m * m );
      uint32_t b = 2 * n * m;
      uint32_t c = ( n * n ) + ( m * m );
      uint32_t L = a + b + c;
      uint32_t i = 1;

      // Iterate over the multiples of this triple
      while( L * i <= 1500000 ) {
        ++cache[L * i];
        ++i;
      }
    }
  }

  for( int i = 0; i <= 1500000; ++i ) {
    if( cache[i] == 1 ) {
      ++result;
    }
  }

  return result;
}

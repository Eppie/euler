/*
 * =====================================================================================
 *
 *       Filename:  Euler142.cpp
 *
 *    Description:  Solution to Project Euler, Problem 142
 *
 *        Version:  1.0
 *        Created:  7/18/2019 10:22:13 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Find the smallest x + y + z with integers x > y > z > 0 such that
 *                      x + y,
 *                      x − y,
 *                      x + z,
 *                      x − z,
 *                      y + z,
 *                      y − z
 *                  are all perfect squares.
 *         Answer:  1006193
 *
 * =====================================================================================
 */
#include "../helper.hpp"

uint32_t solve142() {
  for( int64_t i = 4;; ++i ) {
    int64_t a = i * i;

    for( int64_t j = 3; j < i; ++j ) {
      int64_t b = j * j;
      int64_t c = a - b;

      if( c <= 0 || !isSquare( c ) ) {
        continue;
      }

      int64_t kstart = ( j % 2 == 1 ) ? 1 : 2;

      for( int64_t k = kstart; k < j; k += 2 ) {
        int64_t d = k * k;
        int64_t e = a - d;
        int64_t f = b - e;

        if( f <= 0 || e <= 0 || !isSquare( f ) || !isSquare( e ) ) {
          continue;
        }

        int64_t x = ( d + b ) / 2;
        int64_t y = ( e + c ) / 2;
        int64_t z = ( b - d ) / 2;

        return x + y + z;
      }
    }
  }
}

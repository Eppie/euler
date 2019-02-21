/*
 * =====================================================================================
 *
 *       Filename:  Euler126.cpp
 *
 *    Description:  Solution to Project Euler, Problem 126
 *
 *        Version:  1.0
 *        Created:  2/19/2019 9:47:07 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The minimum number of cubes to cover every visible face on a cuboid measuring 3 x 2 x 1 is twenty-two.
 *                  If we then add a second layer to this solid it would require forty-six cubes to cover every visible face,
 *                  the third layer would require seventy-eight cubes, and the fourth layer would require one-hundred and eighteen cubes to cover every visible face.
 *                  However, the first layer on a cuboid measuring 5 x 1 x 1 also requires twenty-two cubes;
 *                  similarly the first layer on cuboids measuring 5 x 3 x 1, 7 x 2 x 1, and 11 x 1 x 1 all contain forty-six cubes.
 *                  We shall define C(n) to represent the number of cuboids that contain n cubes in one of its layers.
 *                  So C(22) = 2, C(46) = 4, C(78) = 5, and C(118) = 8.
 *                  It turns out that 154 is the least value of n for which C(n) = 10.
 *                  Find the least value of n for which C(n) = 1000.
 *         Answer:  18522
 *
 * =====================================================================================
 */
#include "../helper.hpp"

uint32_t Cubes( uint32_t x, uint32_t y, uint32_t z, uint32_t n ) {
  return 2 * ( x * y + y * z + x * z ) + 4 * ( x + y + z + n - 2 ) * ( n - 1 );
}

uint32_t solve126() {
  uint32_t limit = 30000;
  auto count = new int[limit + 1];
  for( uint32_t z = 1; Cubes( z, z, z, 1 ) <= limit; ++z ) {
    for( uint32_t y = z; Cubes( z, y, z, 1 ) <= limit; ++y ) {
      for( uint32_t x = y; Cubes( z, y, x, 1 ) <= limit; ++x ) {
        for( uint32_t n = 1; Cubes( z, y, x, n ) <= limit; ++n ) {
          count[Cubes( z, y, x, n )]++;
        }
      }
    }
  }
  for( uint32_t i = 0; i < limit; ++i ) {
    if( count[i] == 1000 ) {
      return i;
    }
  }
  return 0;
}

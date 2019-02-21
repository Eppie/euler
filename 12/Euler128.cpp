/*
 * =====================================================================================
 *
 *       Filename:  Euler128.cpp
 *
 *    Description:  Solution to Project Euler, Problem 128
 *
 *        Version:  1.0
 *        Created:  2/19/2019 9:23:03 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  A hexagonal tile with number 1 is surrounded by a ring of six hexagonal tiles,
 *                  starting at "12 o'clock" and numbering the tiles 2 to 7 in an anti-clockwise direction.
 *                  New rings are added in the same fashion, with the next rings being numbered 8 to 19, 20 to 37, 38 to 61, and so on.
 *                  The diagram below shows the first three rings.
 *                            __
 *                         __/20\__
 *                      __/21\__/37\__
 *                   __/22\__/8 \__/36\__
 *                  /23\__/9 \__/19\__/35\
 *                  \__/10\__/2 \__/18\__/
 *                  /24\__/3 \__/7 \__/34\
 *                  \__/11\__/1 \__/17\__/
 *                  /25\__/4 \__/6 \__/33\
 *                  \__/12\__/5 \__/16\__/
 *                  /26\__/13\__/15\__/32\
 *                  \__/27\__/14\__/31\__/
 *                     \__/28\__/30\__/
 *                        \__/29\__/
 *                           \__/
 *
 *                  By finding the difference between tile n and each of its six neighbours we shall define PD(n) to be the number of those differences which are prime.
 *                  For example, working clockwise around tile 8 the differences are 12, 29, 11, 6, 1, and 13. So PD(8) = 3.
 *                  In the same way, the differences around tile 17 are 1, 17, 16, 1, 11, and 10, hence PD(17) = 2.
 *                  It can be shown that the maximum value of PD(n) is 3.
 *                  If all of the tiles for which PD(n) = 3 are listed in ascending order to form a sequence, the 10th tile would be 271.
 *                  Find the 2000th tile in this sequence.
 *         Answer:  14516824220
 *
 * =====================================================================================
 */
#include "../helper.hpp"

uint64_t solve128() {
  uint32_t count = 2;
  uint32_t limit = 2000;
  uint64_t n = 1;
  while( count < limit ) {
    ++n;
    if( isPrime( 6 * n - 1 ) && isPrime( 6 * n + 1 ) && isPrime( 12 * n + 5 ) ) {
      ++count;
      if( count >= limit ) {
        break;
      }
    }
    if( isPrime( 6 * n + 5 ) && isPrime( 6 * n - 1 ) && isPrime( 12 * n - 7 ) ) {
      ++count;
    }
  }
     return 3 * n * n - 3 * n + 2;
}

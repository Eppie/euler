/*
 * =====================================================================================
 *
 *       Filename:  Euler85.cpp
 *
 *    Description:  Solution to Project Euler, Problem 85
 *
 *        Version:  1.0
 *        Created:  06/03/2017 07:28:14 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  By counting carefully it can be seen that a rectangular grid measuring 3 by 2 contains eighteen rectangles.
 *                  Although there exists no rectangular grid that contains exactly two million rectangles,
 *                  find the area of the grid with the nearest solution.
 *         Answer:  2772
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int solve85() {
  int diff = 0;
  int best_diff = 2000000;
  int best_area = 0;

  for( int width = 1; width < 100; ++width ) {
    for( int length = 1; length <= width; ++length ) {
      int count = width * ( width + 1 ) * length * ( length + 1 ) / 4;
      diff = abs( 2000000 - count );

      if( diff < best_diff ) {
        best_diff = diff;
        best_area = width * length;
      }
    }
  }

  return best_area;
}

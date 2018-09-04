/*
 * =====================================================================================
 *
 *       Filename:  Euler102.cpp
 *
 *    Description:  Solution to Project Euler, Problem 102
 *
 *        Version:  1.0
 *        Created:  10/14/2017 12:58:43 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Three distinct points are plotted at random on a Cartesian plane, for which -1000 ≤ x, y ≤ 1000, such that a triangle is formed.
 *                  Consider the following two triangles:
 *                  A(-340,495), B(-153,-910), C(835,-947)
 *                  X(-175,41), Y(-421,-714), Z(574,-645)
 *                  It can be verified that triangle ABC contains the origin, whereas triangle XYZ does not.
 *                  Using triangles.txt, a 27K text file containing the co-ordinates of one thousand "random" triangles,
 *                  find the number of triangles for which the interior contains the origin.
 *         Answer:  228
 *
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler102 {
int32_t area( int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3 ) {
  return abs( ( x1 - x3 ) * ( y2 - y1 ) - ( x1 - x2 ) * ( y3 - y1 ) );
}

bool containsOrigin( int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3 ) {
  return area( x1, y1, x2, y2, x3, y3 )
         == area( x1, y1, x2, y2, 0, 0 ) + area( x1, y1, 0, 0, x3, y3 ) + area( 0, 0, x2, y2, x3, y3 );
}
} // namespace euler102

uint32_t solve102() {
  uint32_t result = 0;
  string x1;
  string y1;
  string x2;
  string y2;
  string x3;
  string y3;
  ifstream file( "10/triangles.txt" );

  for( int32_t i = 0; i < 1000; ++i ) {
    getline( file, x1, ',' );
    getline( file, y1, ',' );
    getline( file, x2, ',' );
    getline( file, y2, ',' );
    getline( file, x3, ',' );
    getline( file, y3, '\n' );

    if( euler102::containsOrigin( stoi( x1 ), stoi( y1 ), stoi( x2 ), stoi( y2 ), stoi( x3 ), stoi( y3 ) ) ) {
      ++result;
    }
  }

  return result;
}

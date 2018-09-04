/*
 * =====================================================================================
 *
 *       Filename:  Euler9.cpp
 *
 *    Description:  Solution to Project Euler, Problem 9
 *
 *        Version:  1.3
 *        Created:  07/30/2015 10:23:07 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  A Pythagorean triplet is a set of three natural numbers, a < b < c, for which a² + b² = c².
 *                  There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.
 *         Answer:  31875000
 * =====================================================================================
 */

int solve9() {
  int L = 1000;

  for( int a = 1; a < L / 2 - 2; ++a ) {
    for( int b = a; b < L / 2 - 1; ++b ) {
      int c = L - a - b;

      if( ( c < L / 2 ) && ( b < c ) && ( a + b > c ) && ( a + c > b ) && ( b + c > a ) ) {
        if( a * a + b * b == c * c ) {
          return a * b * c;
        }
      }
    }
  }

  return 0;
}

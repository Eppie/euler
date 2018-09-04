/*
 * =====================================================================================
 *
 *       Filename:  Euler16.cpp
 *
 *    Description:  Solution to Project Euler, Problem 16
 *
 *        Version:  1.0
 *        Created:  08/02/2015 3:33:01 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26. What is the sum of the digits of the number 2^1000?
 *         Answer:  1366
 * =====================================================================================
 */

#include "../helper.hpp"

int solve16() {
  // Initialize space for a 400 digit number. Initially, it will be set to 1.
  // I don't know exactly how many digits there are in the decimal representation of 2^1000,
  // but I know it's less than 400.
  vector<int> digits( 400, 0 );
  digits[0] = 1;

  // Double the number 1000 times.
  for( int i = 1; i < 1001; i++ ) {
    digits[0] *= 2;

    // Double digit, handling carrys as necessary.
    for( int k = 1; k < 400; k++ ) {
      digits[k] = 2 * digits[k] + digits[k - 1] / 10;
    }

    // Since the carrys have been handled, just drop them.
    for( int j = 0; j < 400; j++ ) {
      digits[j] %= 10;
    }
  }

  // Actually sum the digits.
  return sum( digits );
}

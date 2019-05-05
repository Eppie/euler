/*
 * =====================================================================================
 *
 *       Filename:  Euler135.cpp
 *
 *    Description:  Solution to Project Euler, Problem 135
 *
 *        Version:  1.0
 *        Created:  3/18/2019 8:06:57 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Given the positive integers, x, y, and z, are consecutive terms of an arithmetic progression, the least value of the positive integer, n,
 *                  for which the equation, x² − y² − z² = n, has exactly two solutions is n = 27:
 *                  34² − 27² − 20² = 12² − 9² − 6² = 27
 *                  It turns out that n = 1155 is the least value which has exactly ten solutions.
 *                  How many values of n less than one million have exactly ten distinct solutions?
 *         Answer:  4989
 *
 * =====================================================================================
 */
#include "../helper.hpp"

uint32_t solve135() {
  uint32_t result = 0;
  uint32_t n = 1000000;
  auto solutions = new uint32_t[n + 1];

  for( uint32_t u = 1; u <= n; u++ ) {
    for( uint32_t v = 1; u * v <= n; v++ ) {
      if( ( u + v ) % 4 == 0 && 3 * v > u && ( ( 3 * v - u ) % 4 ) == 0 ) {
        ++solutions[u * v];
      }
    }
  }

  for( uint32_t i = 0; i <= n; ++i ) {
    if( solutions[i] == 10 ) {
      ++result;
    }
  }

  delete[] solutions;
  return result;
}

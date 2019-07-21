/*
 * =====================================================================================
 *
 *       Filename:  Euler136.cpp
 *
 *    Description:  Solution to Project Euler, Problem 136
 *
 *        Version:  1.0
 *        Created:  5/5/2019 4:49:32 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The positive integers, x, y, and z, are consecutive terms of an arithmetic progression. Given that n is a positive integer,
 *                  the equation, x² − y² − z² = n, has exactly one solution when n = 20:
 *                  13² − 10² − 7² = 20
 *                  In fact there are twenty-five values of n below one hundred for which the equation has a unique solution.
 *                  How many values of n less than fifty million have exactly one solution?
 *         Answer:  2544559
 *
 * =====================================================================================
 */
#include "../helper.hpp"

uint32_t solve136() {
  auto primes = sieve( 50'000'000 );
  uint32_t result = 0;
  for( size_t i = 0; i < primes.size(); ++i ) {
    if( primes[i] < 12500000 ) {
      ++result;
    }

    if( primes[i] < 3125000 ) {
      ++result;
    }

    if( ( primes[i] - 3 ) % 4 == 0 ) {
      ++result;
    }
  }
  return result;
}

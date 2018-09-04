/*
 * =====================================================================================
 *
 *       Filename:  Euler5.cpp
 *
 *    Description:  Solution to Project Euler, Problem 5
 *
 *        Version:  1.3
 *        Created:  07/29/2015 11:11:11 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  2520 is the smallest number that can be divided by the numbers 1-10 without any remainder.
 *                  What is the smallest positive number that is evenly divisible by all of the numbers 1-20?
 *         Answer:  232792560
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint32_t solve5() {
  uint32_t limit = 20;
  auto primes = sieve( limit + 1 );
  uint32_t result = 1;

  for( auto &&prime: primes ) {
    auto a = static_cast<int>( log( limit ) / log( prime ) );
    result *= static_cast<int>( pow( prime, a ) );
  }

  return result;
}

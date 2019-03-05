/*
 * =====================================================================================
 *
 *       Filename:  Euler132.cpp
 *
 *    Description:  Solution to Project Euler, Problem 132
 *
 *        Version:  1.0
 *        Created:  3/4/2019 9:42:33 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  A number consisting entirely of ones is called a repunit. We shall define R(k) to be a repunit of length k.
 *                  For example, R(10) = 1111111111 = 11×41×271×9091, and the sum of these prime factors is 9414.
 *                  Find the sum of the first forty prime factors of R(10⁹).
 *         Answer:  843296
 *
 * =====================================================================================
 */
#include "../helper.hpp"

using std::vector;

uint32_t solve132() {
  uint32_t numFactors = 40;
  uint64_t digits = 1000000000;
  uint32_t sum = 0;
  vector<uint32_t> primes = {2};

  for( uint32_t i = 3; numFactors > 0; ++i ) {
    bool isPrime = true;

    for( auto &&p: primes ) {
      if( p * p > i ) {
        break;
      }

      if( i % p == 0 ) {
        isPrime = false;
        break;
      }
    }

    if( !isPrime ) {
      continue;
    }

    primes.push_back( i );

    auto remainder = powMod( 10, digits, 9 * i );
    if( remainder == 1 ) {
      sum += i;
      --numFactors;
    }
  }
  return sum;
}

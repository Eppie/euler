/*
 * =====================================================================================
 *
 *       Filename:  Euler108.cpp
 *
 *    Description:  Solution to Project Euler, Problem 108
 *
 *        Version:  1.0
 *        Created:  3/13/2018 08:34:14 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  In the following equation x, y, and n are positive integers.
 *                    1   1   1
 *                    - + - = -
 *                    x   y   n
 *                  For n = 4 there are exactly three distinct solutions:
 *                    1   1   1
 *                    - + - = -
 *                    5   20  4
 *
 *                    1   1   1
 *                    - + - = -
 *                    6   12  4
 *
 *                    1   1   1
 *                    - + - = -
 *                    8   8   4
 *                  What is the least value of n for which the number of distinct solutions exceeds one-thousand?
 *         Answer:  180180
 *
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler108 {
static auto primes = sieve( 50 );
uint32_t countDivisors( vector<uint32_t> primeFactorCounts ) {
  uint32_t result = 1;
  for( auto &&i: primeFactorCounts ) {
    if( i != 0 ) {
      result *= ( 2 * i ) + 1;
    }
  }
  return ( result + 1 ) / 2;
}

uint64_t calculateN( vector<uint32_t> primeFactorCounts ) {
  uint64_t result = 1;
  for( uint32_t i = 0; i < primeFactorCounts.size(); ++i ) {
    if( primeFactorCounts[i] != 0 ) {
      result *= static_cast<uint64_t>( pow( primes[i], primeFactorCounts[i] ) );
    }
  }
  return result;
}
} // namespace euler108

uint32_t solve108() {
  uint64_t bestN = numeric_limits<uint64_t>::max();
  auto numPrimes = static_cast<uint32_t>( logBaseN( ( 1000 * 2 ) + 1, 3 ) + 1 );
  uint32_t maxCount = 4;
  vector<uint32_t> primeFactorCounts( numPrimes, 0 );
  while( sum( primeFactorCounts ) < numPrimes * maxCount ) {
    primeFactorCounts[0] += 1;
    for( uint32_t i = 0; i < numPrimes - 1; ++i ) {
      if( primeFactorCounts[i] > maxCount ) {
        for( uint32_t j = 0; j <= i; ++j ) {
          primeFactorCounts[j] = primeFactorCounts[i + 1] + 1;
        }
        primeFactorCounts[i + 1] += 1;
      }
    }
    auto d = euler108::countDivisors( primeFactorCounts );
    auto n = euler108::calculateN( primeFactorCounts );
    if( d > 1000 && n < bestN ) {
      bestN = n;
    }
  }
  return bestN;
}

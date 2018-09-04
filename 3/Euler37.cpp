/*
 * =====================================================================================
 *
 *       Filename:  Euler37.cpp
 *
 *    Description:  Solution to Project Euler, Problem 37
 *
 *        Version:  1.1
 *        Created:  3/15/2016 4:40:31 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right,
 *                  and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
 *                  Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
 *         Answer:  748317
 * =====================================================================================
 */

#include "../helper.hpp"

int solve37() {
  int result = 0;
  auto primes = sieve( 1e6 );
  int primesSoFar = 0;
  auto isPrime_m = memoize( function<bool( uint64_t )>( isPrime ) );

  for( auto &&prime: primes ) {
    if( prime < 10 ) {
      continue;
    }

    if( primesSoFar == 11 ) {
      break;
    }

    uint64_t backup = prime;
    uint64_t primeCopy = prime;

    while( isPrime_m( prime ) && isPrime_m( primeCopy ) ) {
      // Take off the first digit
      primeCopy %= static_cast<int>( pow( 10, static_cast<int>( log10( primeCopy ) ) ) );
      // Take off the last digit
      prime /= 10;
    }

    // If the number was prime the whole way through
    if( prime == 0 ) {
      result += backup;
      ++primesSoFar;
    }
  }

  return result;
}

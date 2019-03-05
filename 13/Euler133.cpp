/*
 * =====================================================================================
 *
 *       Filename:  Euler133.cpp
 *
 *    Description:  Solution to Project Euler, Problem 133
 *
 *        Version:  1.0
 *        Created:  3/4/2019 12:45:23 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  A number consisting entirely of ones is called a repunit. We shall define R(k) to be a repunit of length k; for example, R(6) = 111111.
 *                  Let us consider repunits of the form R(10ⁿ).
 *                  Although R(10), R(100), or R(1000) are not divisible by 17, R(10000) is divisible by 17. Yet there is no value of n for which R(10ⁿ) will divide by 19.
 *                  In fact, it is remarkable that 11, 17, 41, and 73 are the only four primes below one-hundred that can be a factor of R(10ⁿ).
 *                  Find the sum of all the primes below one-hundred thousand that will never be a factor of R(10ⁿ).
 *         Answer:  453647705
 *
 * =====================================================================================
 */
#include "../helper.hpp"

using std::vector;

uint32_t solve133() {
  const uint64_t digits = 10000000000000000000ULL;
  const uint32_t maxPrime = 100000;
  uint64_t sum = 0;
  vector<uint32_t> primes;

  for( uint32_t i = 2; i < maxPrime; i++ ) {
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
    if( remainder != 1 ) {
      sum += i;
    }
  }

  return sum;
}

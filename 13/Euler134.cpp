/*
 * =====================================================================================
 *
 *       Filename:  Euler134.cpp
 *
 *    Description:  Solution to Project Euler, Problem 134
 *
 *        Version:  1.0
 *        Created:  3/5/2019 1:39:21 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Consider the consecutive primes p₁ = 19 and p₂ = 23.
 *                  It can be verified that 1219 is the smallest number such that the last digits are formed by p₁ whilst also being divisible by p₂.
 *                  In fact, with the exception of p₁ = 3 and p₂ = 5, for every pair of consecutive primes, p₂ > p₁, there exist values of n
 *                  for which the last digits are formed by p₁ and n is divisible by p₂. Let S be the smallest of these values of n.
 *                  Find ∑S for every pair of consecutive primes with 5 ≤ p₁ ≤ 1000000.
 *         Answer:  18613426663617118
 *
 * =====================================================================================
 */
#include "../helper.hpp"

namespace euler134 {
int64_t extendedGCD( int64_t a, int64_t b ) {
  int64_t x = 0;
  int64_t lastx = 1;
  int64_t y = 1;
  int64_t lasty = 0;
  while( b != 0 ) {
    int64_t quotient = a / b;

    int64_t temp = b;
    b = a % b;
    a = temp;

    temp = x;
    x = lastx - quotient * x;
    lastx = temp;

    temp = y;
    y = lasty - quotient * y;
    lasty = temp;
  }

  return lastx;
}
} // namespace euler134

uint64_t solve134() {
  uint64_t result = 0;
  uint32_t limit = 1000000;
  auto primes = sieve( limit + 100 );
  uint32_t i = 2;

  while( primes[i] <= limit ) {
    uint64_t p1 = primes[i];
    uint64_t p2 = primes[i + 1];

    uint64_t a = 1;
    uint64_t number = p1;

    while( number > 0 ) {
      a *= 10;
      number /= 10;
    }

    int64_t b = p2 - p1;
    int64_t n = p2;

    auto rs = euler134::extendedGCD( a, n );
    int64_t x = rs * b % n;

    if( x < 0 ) {
      x = n + x;
    }
    result += x * a + p1;
    ++i;
  }
  return result;
}

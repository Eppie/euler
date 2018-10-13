/*
 * =====================================================================================
 *
 *       Filename:  Euler123.cpp
 *
 *    Description:  Solution to Project Euler, Problem 123
 *
 *        Version:  1.0
 *        Created:  10/12/2018 3:34:00 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Let pn be the nth prime: 2, 3, 5, 7, 11, ..., and let r be the remainder when (pn−1)n + (pn+1)n is divided by pn2.
 *                  For example, when n = 3, p3 = 5, and 43 + 63 = 280 ≡ 5 mod 25.
 *                  The least value of n for which the remainder first exceeds 109 is 7037.
 *                  Find the least value of n for which the remainder first exceeds 1010.
 *         Answer:  21035
 *
 * =====================================================================================
 */
#include "../helper.hpp"

namespace euler123 {
auto primes = sieve( 240000 );

uint64_t solve( uint32_t n ) {
  auto pn = primes[n - 1];
  return ( powMod( pn - 1, n, pn * pn ) + powMod( pn + 1, n, pn * pn ) ) % ( pn * pn );
}
} // namespace euler123

uint32_t solve123() {
  uint32_t n = 1;

  while( euler123::solve( n ) < 10e9 ) {
    ++n;
  }

  return n;
}

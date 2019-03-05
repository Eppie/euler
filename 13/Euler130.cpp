/*
 * =====================================================================================
 *
 *       Filename:  Euler130.cpp
 *
 *    Description:  Solution to Project Euler, Problem 130
 *
 *        Version:  1.0
 *        Created:  3/2/2019 12:57:08 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  A number consisting entirely of ones is called a repunit. We shall define R(k) to be a repunit of length k; for example, R(6) = 111111.
 *                  Given that n is a positive integer and GCD(n, 10) = 1, it can be shown that there always exists a value, k,
 *                  for which R(k) is divisible by n, and let A(n) be the least such value of k; for example, A(7) = 6 and A(41) = 5.
 *                  You are given that for all primes, p > 5, that p − 1 is divisible by A(p). For example, when p = 41, A(41) = 5, and 40 is divisible by 5.
 *                  However, there are rare composite values for which this is also true; the first five examples being 91, 259, 451, 481, and 703.
 *                  Find the sum of the first twenty-five composite values of n for which
 *                  GCD(n, 10) = 1 and n − 1 is divisible by A(n).
 *         Answer:  149253
 *
 * =====================================================================================
 */
#include "../helper.hpp"

namespace euler130 {
uint32_t A( uint32_t n ) {
  if( gcd( n, 10 ) != 1 ) {
    return 0;
  }
  uint32_t x = 1;
  uint32_t k = 1;
  while( x != 0 ) {
    x = ( x * 10 + 1 ) % n;
    ++k;
  }
  return k;
}
} // namespace euler130

uint32_t solve130() {
  uint32_t found = 5;

  uint32_t n = 704;
  uint32_t result = 91 + 259 + 451 + 481 + 703;

  while( found < 25 ) {
    ++n;

    if( isPrime( n ) ) {
      continue;
    }

    uint32_t a = euler130::A( n );

    if( a != 0 && ( ( n - 1 ) % a == 0 ) ) {
      result += n;
      ++found;
    }
  }
  return result;
}

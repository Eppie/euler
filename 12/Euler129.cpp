/*
 * =====================================================================================
 *
 *       Filename:  Euler129.cpp
 *
 *    Description:  Solution to Project Euler, Problem 129
 *
 *        Version:  1.0
 *        Created:  2/22/2019 8:02:59 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  A number consisting entirely of ones is called a repunit. We shall define R(k) to be a repunit of length k; for example, R(6) = 111111.
 *                  Given that n is a positive integer and GCD(n, 10) = 1, it can be shown that there always exists a value,
 *                  k, for which R(k) is divisible by n, and let A(n) be the least such value of k; for example, A(7) = 6 and A(41) = 5.
 *                  The least value of n for which A(n) first exceeds ten is 17.
 *                  Find the least value of n for which A(n) first exceeds one-million.
 *         Answer:  1000023
 *
 * =====================================================================================
 */
#include "../helper.hpp"

namespace euler129 {
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
} // namespace euler129

uint32_t solve129() {
  uint32_t n = 1000001;
  while( euler129::A( n ) < 1000001 ) {
    n += 2;
  }
  return n;
}

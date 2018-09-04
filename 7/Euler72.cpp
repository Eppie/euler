/*
 * =====================================================================================
 *
 *       Filename:  Euler72.cpp
 *
 *    Description:  Solution to Project Euler, Problem 72
 *
 *        Version:  1.0
 *        Created:  9/22/2016 8:05:26 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.
 *                  If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:
 *
 *                  1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
 *
 *                  It can be seen that there are 21 elements in this set.
 *                  How many elements would be contained in the set of reduced proper fractions for d ≤ 1,000,000?
 *         Answer:  303963552391
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint64_t solve72() {
  // We're looking for all numerators that are both relatively prime to each d, as well as smaller than each d
  // Thus, we can use Euler's totient function

  uint64_t result = 0;

  // Fill the vector with sequentially increasing values, starting from 0
  vector<int> phi( 1000001 );
  iota( phi.begin(), phi.end(), 0 );

  for( int d = 2; d <= 1000000; ++d ) {
    // if d is prime
    if( phi[d] == d ) {
      // for every multiple of d, update the value
      for( int i = d; i <= 1000000; i += d ) {
        phi[i] -= phi[i] / d;
      }
    }

    result += phi[d];
  }

  return result;
}

/*
 * =====================================================================================
 *
 *       Filename:  Euler65.cpp
 *
 *    Description:  Solution to Project Euler, Problem 65
 *
 *        Version:  1.0
 *        Created:  9/12/2016 9:54:56 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The description for this one is quite long. See it here: https://projecteuler.net/problem=65
 *         Answer:  272
 *
 * =====================================================================================
 */

#include "../helper.hpp"

/*
 * This is a translation of the Maple code presented here: https://oeis.org/A113873
 * As we don't need to remember the whole sequence, I am using three variables instead of
 * an array.
 */
int solve65() {
  mpz_class current;
  mpz_class n_minus_2 = 1;
  mpz_class n_minus_1 = 2;

  for( int n = 3; n <= 101; ++n ) {
    if( n % 3 == 0 ) {
      current = n_minus_1 + n_minus_2;
    } else if( n % 3 == 1 ) {
      current = 2 * ( n - 1 ) * n_minus_1 / 3 + n_minus_2;
    } else {
      current = n_minus_1 + n_minus_2;
    }

    n_minus_2 = n_minus_1;
    n_minus_1 = current;
  }

  return digitalSum( current ).get_ui();
}

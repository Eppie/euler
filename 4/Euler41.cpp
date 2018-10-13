/*
 * =====================================================================================
 *
 *       Filename:  Euler41.cpp
 *
 *    Description:  Solution to Project Euler, Problem 41
 *
 *        Version:  1.0
 *        Created:  5/13/2016 3:14:27 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.
 *                  For example, 2143 is a 4-digit pandigital and is also prime.
 *                  What is the largest n-digit pandigital prime that exists?
 *         Answer:  7652413
 * =====================================================================================
 */

#include "../helper.hpp"

using std::list;

int solve41() {
  list<int> a = {9, 8, 7, 6, 5, 4, 3, 2, 1};

  while( !a.empty() ) {
    do {
      int n = 0;
      int j = 0;

      // Convert from list of digits to int
      for( auto it = a.rbegin(); it != a.rend(); it++ ) {
        n += *it * pow( 10, j );
        j++;
      }

      if( isPrime( n ) ) {
        return n;
      }

      // Using prev_permutation to check larger numbers first
    } while( prev_permutation( a.begin(), a.end() ) );

    a.pop_front();
  }

  return 0;
}

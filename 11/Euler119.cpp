/*
 * =====================================================================================
 *
 *       Filename:  Euler119.cpp
 *
 *    Description:  Solution to Project Euler, Problem 119
 *
 *        Version:  1.0
 *        Created:  9/04/2018 8:015:16 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The number 512 is interesting because it is equal to the sum of its digits raised to some power: 5 + 1 + 2 = 8, and 83 = 512.
 *                  Another example of a number with this property is 614656 = 284.
 *                  We shall define an to be the nth term of this sequence and insist that a number must contain at least two digits to have a sum.
 *                  You are given that a2 = 512 and a10 = 614656. Find a30.
 *         Answer:  248155780267521
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint64_t solve119() {
  vector<uint64_t> results;

  for( uint64_t base = 2; base <= 10000; ++base ) {
    for( uint32_t power = 1; power <= 100; ++power ) {
      uint64_t a = static_cast<uint64_t>( pow( base, power ) );
      uint32_t dSum = digitalSum( a );

      if( dSum == base && a >= 10 ) {
        results.push_back( a );
      }
    }
  }

  sort( results.begin(), results.end() );
  return results[29];
}

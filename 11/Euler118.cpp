/*
 * =====================================================================================
 *
 *       Filename:  Euler118.cpp
 *
 *    Description:  Solution to Project Euler, Problem 118
 *
 *        Version:  1.0
 *        Created:  8/19/2018 5:33:03 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Using all of the digits 1 through 9 and concatenating them freely to form decimal integers, different sets can be formed.
 *                  Interestingly with the set {2,5,47,89,631}, all of the elements belonging to it are prime.
 *                  How many distinct sets containing each of the digits one through nine exactly once contain only prime elements?
 *         Answer:  44680
 *
 * =====================================================================================
 */

#include "../helper.hpp"

using std::next_permutation;

namespace euler118 {

uint8_t perm[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

#define SIZE 10000000

vector<bool> A( SIZE, true );
void sieve() {
  A[0] = false;
  A[1] = false;
  for( uint64_t i = 2; i <= static_cast<uint64_t>( sqrt( SIZE ) ); ++i ) {
    if( A[i] ) {
      for( uint64_t j = i * i; j < SIZE; j += i ) {
        A[j] = false;
      }
    }
  }
}

bool isPrime118( uint64_t n ) {
  if( n < SIZE ) {
    return A[n];
  } else {
    return isPrime( n );
  }
}

uint8_t checkPartitions( uint8_t startIndex, uint32_t prev ) {
  uint8_t count = 0;

  for( uint8_t i = startIndex; i < 9; ++i ) {
    uint32_t number = 0;

    for( uint8_t j = startIndex; j <= i; ++j ) {
      number = number * 10 + perm[j];
    }

    if( number < prev || !isPrime118( number ) ) {
      continue;
    }

    if( i == 8 ) {
      return count + 1;
    }

    count += checkPartitions( i + 1, number );
  }
  return count;
}
} // namespace euler118

uint32_t solve118() {
  uint32_t result = 0;
  euler118::sieve();
  while( next_permutation( euler118::perm, euler118::perm + 9 ) ) {
    result += euler118::checkPartitions( 0, 0 );
  }
  return result;
}

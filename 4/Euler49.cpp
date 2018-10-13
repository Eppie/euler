/*
 * =====================================================================================
 *
 *       Filename:  Euler49.cpp
 *
 *    Description:  Solution to Project Euler, Problem 49
 *
 *        Version:  1.1
 *        Created:  8/30/2016 1:18:34 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways:
 *                  (i) each of the three terms are prime, and,
 *                  (ii) each of the 4-digit numbers are permutations of one another.
 *                  There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property,
 *                  but there is one other 4-digit increasing sequence.
 *                  What 12-digit number do you form by concatenating the three terms in this sequence?
 *         Answer:  296962999629
 * =====================================================================================
 */

#include "../helper.hpp"

using std::to_string;
using std::vector;

uint64_t solve49() {
  vector<int> perms;
  auto primes = sieve( 10000 );

  for( auto &&prime: primes ) {
    if( prime < 1000 ) {
      continue;
    }

    string s = to_string( prime );

    do {
      if( isPrime( stoi( s ) ) ) {
        perms.push_back( stoi( s ) );
      }
    } while( next_permutation( s.begin(), s.end() ) );

    if( perms.size() == 3 && perms[0] + 3330 == perms[1] && perms[1] + 3330 == perms[2] ) {
      auto result = static_cast<uint64_t>( perms[0] * 1e8 + perms[1] * 1e4 + perms[2] );
      return result;
    }

    perms.clear();
  }

  return 0;
}

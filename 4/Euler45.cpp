/*
 * =====================================================================================
 *
 *       Filename:  Euler45.cpp
 *
 *    Description:  Solution to Project Euler, Problem 45
 *
 *        Version:  1.1
 *        Created:  8/26/2016 2:31:14 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:
 *
 *                  Triangle      Tn=n(n+1)/2     1, 3, 6, 10, 15, ...
 *                  Pentagonal    Pn=n(3n−1)/2    1, 5, 12, 22, 35, ...
 *                  Hexagonal     Hn=n(2n−1)      1, 6, 15, 28, 45, ...
 *                  It can be verified that T285 = P165 = H143 = 40755.
 *                  Find the next triangle number that is also pentagonal and hexagonal.
 *         Answer:  1533776805
 * =====================================================================================
 */

#include "../helper.hpp"

using std::unordered_set;
using std::vector;

namespace euler45 {
uint64_t genTri( uint64_t n ) {
  return figurateNumber( 3, n );
}

uint64_t genHex( uint64_t n ) {
  return figurateNumber( 6, n );
}
} // namespace euler45

uint64_t solve45() {
  vector<uint64_t> triNumbers;
  unordered_set<uint64_t> pentNumbers;
  unordered_set<uint64_t> hexNumbers;

  for( int i = 0; i < 55386; ++i ) {
    triNumbers.push_back( euler45::genTri( i ) );
    pentNumbers.insert( genPent( i ) );
    hexNumbers.insert( euler45::genHex( i ) );
  }

  for( auto &&num: triNumbers ) {
    if( num > 40755 && pentNumbers.find( num ) != pentNumbers.end() && hexNumbers.find( num ) != hexNumbers.end() ) {
      return num;
    }
  }

  return 0;
}

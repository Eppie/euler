/*
 * =====================================================================================
 *
 *       Filename:  Euler125.cpp
 *
 *    Description:  Solution to Project Euler, Problem 125
 *
 *        Version:  1.0
 *        Created:  10/14/2018 1:06:49 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The palindromic number 595 is interesting because it can be written as the sum of consecutive squares: 6² + 7² + 8² + 9² + 10² + 11² + 12².
 *                  There are exactly eleven palindromes below one-thousand that can be written as consecutive square sums, and the sum of these palindromes is 4164.
 *                  Note that 1 = 0² + 1² has not been included as this problem is concerned with the squares of positive integers.
 *                  Find the sum of all the numbers less than 10⁸ that are both palindromic and can be written as the sum of consecutive squares.
 *         Answer: 2906969179
 *
 * =====================================================================================
 */
#include "../helper.hpp"

using std::generate;
using std::set;
using std::vector;

uint32_t solve125() {
  vector<uint64_t> squares( 10000 );
  generate( squares.begin(), squares.end(), [n = 0]() mutable {
    ++n;
    return n * n;
  } );

  uint32_t result = 0;

  set<uint64_t> seen;

  for( int i = 0; i < 10000; ++i ) {
    for( int j = i + 1; j < 10000; ++j ) {
      uint64_t sum = 0;

      for( int k = i; k <= j; ++k ) {
        sum += squares[k];
      }

      if( sum >= 100000000 ) {
        break;
      } else if( isPalindrome<10>( sum ) && seen.find( sum ) == seen.end() ) {
        result += sum;
        seen.insert( sum );
      }
    }
  }

  return result;
}

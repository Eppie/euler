/*
 * =====================================================================================
 *
 *       Filename:  Euler90.cpp
 *
 *    Description:  Solution to Project Euler, Problem 90
 *
 *        Version:  1.1
 *        Created:  06/12/2017 07:50:38 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  See the description here: https://projecteuler.net/problem=90
 *         Answer:  1217
 *
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler90 {
bool valid( vector<int> c1, vector<int> c2 ) {
  static vector<vector<int>> squares = {{0, 1}, {0, 4}, {0, 6}, {1, 6}, {2, 5}, {3, 6}, {4, 6}, {8, 1}};

  for( auto &&square: squares ) {
    auto x = square[0];
    auto y = square[1];
    auto c1Hasx = find( c1.begin(), c1.end(), x ) != c1.end();
    auto c1Hasy = find( c1.begin(), c1.end(), y ) != c1.end();
    auto c2Hasx = find( c2.begin(), c2.end(), x ) != c2.end();
    auto c2Hasy = find( c2.begin(), c2.end(), y ) != c2.end();

    if( !( ( c1Hasx && c2Hasy ) || ( c2Hasx && c1Hasy ) ) ) {
      return false;
    }
  }

  return true;
}
} // namespace euler90

int solve90() {
  int result = 0;
  vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 6};
  auto combs = combinations( nums, 6 );

  for( uint32_t i = 0; i < combs.size(); ++i ) {
    for( uint32_t j = i + 1; j < combs.size(); ++j ) {
      auto c1 = combs[i];
      auto c2 = combs[j];

      if( euler90::valid( c1, c2 ) ) {
        ++result;
      }
    }
  }

  return result;
}

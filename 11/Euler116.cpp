/*
 * =====================================================================================
 *
 *       Filename:  Euler116.cpp
 *
 *    Description:  Solution to Project Euler, Problem 116
 *
 *        Version:  1.0
 *        Created:  8/19/2018 12:39:18 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  
 *         Answer:  20492570929
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint64_t solve116() {
  auto G = memo::memoize<uint64_t( int, int )>( []( auto &G_internal, int m, int n ) -> uint64_t {
    uint64_t result = 0;
    if( n > m ) {
      return result;
    }
    for( int s = 0; s <= m - n; ++s ) {
      ++result;
      result += G_internal( m - s - n, n );
    }
    return result;
  } );
  return G( 50, 2 ) + G( 50, 3 ) + G( 50, 4 );
}

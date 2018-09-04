/*
 * =====================================================================================
 *
 *       Filename:  Euler117.cpp
 *
 *    Description:  Solution to Project Euler, Problem 117
 *
 *        Version:  1.0
 *        Created:  8/19/2018 12:57:12 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:
 *         Answer:  100808458960497
 *
 * =====================================================================================
 */

#include "../helper.hpp"
uint64_t solve117() {
  auto F = memo::memoize<uint64_t( int, int, int )>( []( auto &F_internal, int m, int nmin, int nmax ) -> uint64_t {
    //The rest is empty
    long solutions = 1;

    //we can't fill out more
    if( nmin > m )
      return solutions;

    for( int bs = nmin; bs <= nmax; bs++ ) {
      for( int startpos = 0; startpos <= m - bs; startpos++ ) {
        solutions += F_internal( m - startpos - bs, nmin, nmax );
      }
    }

    return solutions;
  } );
  return F( 50, 2, 4 );
}

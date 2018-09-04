/*
 * =====================================================================================
 *
 *       Filename:  Euler25.cpp
 *
 *    Description:  Solution to Project Euler, Problem 25
 *
 *        Version:  1.2
 *        Created:  10/23/2015 03:12:49 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
 *         Answer:  4782
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler25 {
void add( const int *a, const int *b, int *c ) {
  int tmp;
  int newDigit;
  int carry = 0;

  for( int i = 0; i < 1000; i++ ) {
    tmp = a[i] + b[i] + carry;
    newDigit = tmp % 10;
    carry = tmp / 10;
    c[i] = newDigit;
  }
}
} // namespace euler25

uint32_t solve25() {
  uint32_t count = 2;
  auto *a = reinterpret_cast<int *>( calloc( 1000, sizeof( int ) ) );
  auto *b = reinterpret_cast<int *>( calloc( 1000, sizeof( int ) ) );
  auto *c = reinterpret_cast<int *>( calloc( 1000, sizeof( int ) ) );
  a[0] = 1;
  b[0] = 1;

  while( true ) {
    euler25::add( a, b, c );
    count += 1;

    if( c[999] != 0 ) {
      free( a );
      free( b );
      free( c );
      return count;
    }

    euler25::add( c, a, b );
    count += 1;

    if( b[999] != 0 ) {
      free( a );
      free( b );
      free( c );
      return count;
    }

    euler25::add( b, c, a );
    count += 1;

    if( a[999] != 0 ) {
      free( a );
      free( b );
      free( c );
      return count;
    }
  }
}

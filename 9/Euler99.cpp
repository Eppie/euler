/*
 * =====================================================================================
 *
 *       Filename:  Euler99.cpp
 *
 *    Description:  Solution to Project Euler, Problem 99
 *
 *        Version:  1.0
 *        Created:  09/03/2017 06:50:56 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:
 *         Answer:  709
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint32_t solve99() {
  double best = 0;
  uint32_t result = 0;
  ifstream file( "9/base_exp.txt" );
  string s;
  string base;
  string exp;

  for( int i = 0; i < 1000; ++i ) {
    getline( file, s, '\n' );
    istringstream is( s );
    getline( is, base, ',' );
    getline( is, exp, ',' );
    double tmp = log( stod( base ) ) * stod( exp );

    if( tmp > best ) {
      result = i + 1;
      best = tmp;
    }
  }

  return result;
}

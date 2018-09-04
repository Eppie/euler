/*
 * =====================================================================================
 *
 *       Filename:  Euler115.cpp
 *
 *    Description:  Solution to Project Euler, Problem 115
 *
 *        Version:  1.0
 *        Created:  8/08/2018 8:06:47 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:
 *         Answer:  168
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint32_t solve115() {
  uint32_t result = 0;
  uint32_t i = 0;
  while( result < 1000000 ) {
    ++i;
    result = fill_count( i, 50 );
  }

  return i;
}

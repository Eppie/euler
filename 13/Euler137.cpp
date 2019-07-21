/*
 * =====================================================================================
 *
 *       Filename:  Euler137.cpp
 *
 *    Description:  Solution to Project Euler, Problem 137
 *
 *        Version:  1.0
 *        Created:  7/21/2019 1:35:31 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  
 *         Answer:  1120149658760
 *
 * =====================================================================================
 */
#include "../helper.hpp"

uint64_t solve137() {
  return fib( 30 ) * fib( 31 );
}

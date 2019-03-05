/*
 * =====================================================================================
 *
 *       Filename:  Euler131.cpp
 *
 *    Description:  Solution to Project Euler, Problem 131
 *
 *        Version:  1.0
 *        Created:  3/2/2019 1:32:08 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  There are some prime values, p, for which there exists a positive integer, n, such that the expression n³ + n²p is a perfect cube.
 *                  For example, when p = 19, 8³ + 8²×19 = 12³.
 *                  What is perhaps most surprising is that for each prime with this property the value of n is unique,
 *                  and there are only four such primes below one-hundred.
 *                  How many primes below one million have this remarkable property?
 *         Answer:  173
 *
 * =====================================================================================
 */
#include "../helper.hpp"

uint32_t solve131() {
  uint32_t result = 0;
  for( uint32_t i = 1; i < 577; i++ ) {
    if( isPrime( ( i + 1 ) * ( i + 1 ) * ( i + 1 ) - i * i * i ) ) {
      ++result;
    }
  }
  return result;
}

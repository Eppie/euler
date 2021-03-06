/*
 * =====================================================================================
 *
 *       Filename:  Euler120.cpp
 *
 *    Description:  Solution to Project Euler, Problem 120
 *
 *        Version:  1.1
 *        Created:  9/04/2018 11:49:36 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Let r be the remainder when (a−1)ⁿ + (a+1)ⁿ is divided by a².
 *                  For example, if a = 7 and n = 3, then r = 42: 6³ + 8³ = 728 ≡ 42 mod 49.
 *                  And as n varies, so too will r, but for a = 7 it turns out that rmax = 42.
 *                  For 3 ≤ a ≤ 1000, find ∑ rmax.
 *         Answer:  333082500
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint32_t solve120() {
  uint32_t result = 0;
  for( uint32_t a = 3; a <= 1000; ++a ) {
    result += 2 * a * ( ( a - 1 ) / 2 );
  }

  return result;
}

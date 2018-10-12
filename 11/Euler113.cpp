/*
 * =====================================================================================
 *
 *       Filename:  Euler113.cpp
 *
 *    Description:  Solution to Project Euler, Problem 113
 *
 *        Version:  1.1
 *        Created:  7/30/2018 8:26:42 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Working from left-to-right if no digit is exceeded by the digit to its left it is called an increasing number; for example, 134468.
 *                  Similarly if no digit is exceeded by the digit to its right it is called a decreasing number; for example, 66420.
 *                  We shall call a positive integer that is neither increasing nor decreasing a "bouncy" number; for example, 155349.
 *                  As n increases, the proportion of bouncy numbers below n increases such that there are only 12951 numbers below one-million
 *                  that are not bouncy and only 277032 non-bouncy numbers below 10¹⁰.
 *                  How many numbers below a googol (10¹⁰⁰) are not bouncy?
 *         Answer:  51161058134250
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint64_t solve113() {
  uint64_t result = 0;

  /*
   * increasing[j][i] will hold the count of increasing numbers that begin with digit j and have i + 1 digits.
   */
  auto increasing = new uint64_t[10][100];

  /*
   * decreasing[j][i] will hold the count of decreasing numbers that begin with digit j and have i + 1 digits.
   */
  auto decreasing = new uint64_t[10][100];

  // Initialize everything to 0
  for( int j = 0; j < 10; ++j ) {
    for( int i = 0; i < 100; ++i ) {
      increasing[j][i] = 0;
      decreasing[j][i] = 0;
    }
  }

  for( int i = 0; i < 100; ++i ) {
    // [9], [99], [999], ...
    increasing[9][i] = 1;
    // The reason for the intentional undercounting here is that numbers of the form xxx...xxx where "x" is a digit [1-9]
    // are both increasing and decreasing, and we have to take care to not double count them. We will count these numbers as increasing only.
    // This intentionally doesn't count numbers like 8, 88, 888... They will be included in a later step.
    // [], [89], [889, 899], ...
    increasing[8][i] = i;
    // This intentionally doesn't count numbers like 1, 11, 111... They will be included in a later step.
    // [], [10], [110, 100], ...
    decreasing[1][i] = i;
  }

  for( int j = 0; j < 10; ++j ) {
    // All single digit numbers are increasing
    // [0], [1], [2], ...
    increasing[j][0] = 1;
    // Technically this should be the same as above, but we don't want to double count these, so just set to 0
    decreasing[j][0] = 0;
    // [], [10], [21, 20], ...
    decreasing[j][1] = j;
  }

  for( int j = 8; j >= 0; --j ) {
    for( int i = 1; i < 100; ++i ) {
      increasing[j][i] = increasing[j + 1][i] + increasing[j][i - 1];
    }
  }

  for( int j = 1; j < 10; ++j ) {
    for( int i = 1; i < 100; ++i ) {
      decreasing[j][i] = 1 + decreasing[j - 1][i] + decreasing[j][i - 1];
    }
  }

  for( int j = 1; j < 10; ++j ) {
    for( int i = 0; i < 100; ++i ) {
      result += increasing[j][i];
      result += decreasing[j][i];
    }
  }

  return result;
}

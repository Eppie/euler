/*
 * =====================================================================================
 *
 *       Filename:  Euler47.cpp
 *
 *    Description:  Solution to Project Euler, Problem 47
 *
 *        Version:  1.0
 *        Created:  8/26/2016 5:17:23 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The first two consecutive numbers to have two distinct prime factors are:
 *
 *                  14 = 2 × 7
 *                  15 = 3 × 5
 *
 *                  The first three consecutive numbers to have three distinct prime factors are:
 *
 *                  644 = 2² × 7 × 23
 *                  645 = 3 × 5 × 43
 *                  646 = 2 × 17 × 19.
 *
 *                  Find the first four consecutive integers to have four distinct prime factors. What is the first of these numbers?
 *         Answer:  134043
 * =====================================================================================
 */

#include "../helper.hpp"

using std::set;
using std::vector;

int solve47() {
  // factorCount will store the counts of distinct factors for the previous four i's.
  // We will index it by i % 4, essentially treating it as a rotating array.
  // If its sum is ever 16, that means all four values are 4, which means that the i we just processed was the 4th consecutive
  // with four distinct factors, so return i - 3.
  vector<int> factorCount = {0, 0, 0, 0};

  for( int i = 1; i < 200000; ++i ) {
    vector<uint64_t> factorsVector = primeFactors( i );
    set<int> factorsSet{factorsVector.begin(), factorsVector.end()};
    factorCount[i % 4] = factorsSet.size();

    if( sum( factorCount ) == 16 ) {
      return i - 3;
    }
  }

  return 0;
}

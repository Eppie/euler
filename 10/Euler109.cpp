/*
 * =====================================================================================
 *
 *       Filename:  Euler109.cpp
 *
 *    Description:  Solution to Project Euler, Problem 109
 *
 *        Version:  1.0
 *        Created:  7/29/2018 11:44:38 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The score of a dart is determined by the number of the region that the dart lands in.
 *                  A dart landing outside the red/green outer ring scores zero. The black and cream regions inside this ring represent single scores.
 *                  However, the red/green outer ring and middle ring score double and treble scores respectively.
 *                  At the centre of the board are two concentric circles called the bull region, or bulls-eye.
 *                  The outer bull is worth 25 points and the inner bull is a double, worth 50 points.
 *                  There are many variations of rules but in the most popular game the players will begin with a score 301 or 501
 *                  and the first player to reduce their running total to zero is a winner.
 *                  However, it is normal to play a "doubles out" system, which means that the player must land a double
 *                  (including the double bulls-eye at the centre of the board) on their final dart to win;
 *                  any other dart that would reduce their running total to one or lower means the score for that set of three darts is "bust".
 *                  When a player is able to finish on their current score it is called a "checkout" and the highest checkout is 170:
 *                  T20 T20 D25 (two treble 20s and double bull). There are exactly eleven distinct ways to checkout on a score of 6:
 *                  0  0  D3
 *                  0  D1 D2
 *                  0  S2 D2
 *                  0  D2 D1
 *                  0  S4 D1
 *                  S1 S1 D2
 *                  S1 T1 D1
 *                  S1 S3 D1
 *                  D1 D1 D1
 *                  D1 S2 D1
 *                  S2 S2 D1
 *                  Note that D1 D2 is considered different to D2 D1 as they finish on different doubles.
 *                  However, the combination S1 T1 D1 is considered the same as T1 S1 D1.
 *                  In addition we shall not include misses in considering combinations; for example, D3 is the same as 0 D3 and 0 0 D3.
 *                  Incredibly there are 42336 distinct ways of checking out in total.
 *                  How many distinct ways can a player checkout with a score less than 100?
 *         Answer:  38182
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint32_t solve109() {
  int limit = 100;
  int result = 0;
  vector<int> scores;
  vector<int> doubles;
  for( int i = 1; i <= 20; ++i ) {
    scores.push_back( i );
    scores.push_back( i * 2 );
    scores.push_back( i * 3 );
    doubles.push_back( i * 2 );
  }
  scores.push_back( 25 );
  scores.push_back( 50 );
  doubles.push_back( 50 );

  // Two misses and a double
  for( auto &&third: doubles ) {
    if( third < limit ) {
      ++result;
    }
  }

  // A miss, a hit, and a double
  for( size_t i = 0; i < scores.size(); ++i ) {
    for( auto &&third: doubles ) {
      if( scores[i] + third < limit ) {
        ++result;
      }
    }
  }

  // Two hits and a double
  for( size_t i = 0; i < scores.size(); ++i ) {
    for( size_t j = i; j < scores.size(); ++j ) {
      for( auto &&third: doubles ) {
        if( scores[i] + scores[j] + third < limit ) {
          ++result;
        }
      }
    }
  }

  return result;
}

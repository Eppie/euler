/*
 * =====================================================================================
 *
 *       Filename:  Euler121.cpp
 *
 *    Description:  Solution to Project Euler, Problem 121
 *
 *        Version:  1.0
 *        Created:  10/10/2018 10:49:03 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  A bag contains one red disc and one blue disc. In a game of chance a player takes a disc at random and its colour is noted.
 *                  After each turn the disc is returned to the bag, an extra red disc is added, and another disc is taken at random.
 *                  The player pays £1 to play and wins if they have taken more blue discs than red discs at the end of the game.
 *                  If the game is played for four turns, the probability of a player winning is exactly 11/120, and so the maximum
 *                  prize fund the banker should allocate for winning in this game would be £10 before they would expect to incur a loss.
 *                  Note that any payout will be a whole number of pounds and also includes the original £1 paid to play the game,
 *                  so in the example given the player actually wins £9.
 *                  Find the maximum prize fund that should be allocated to a single game in which fifteen turns are played.
 *         Answer:  2269
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint32_t solve121() {
  int limit = 15;
  auto outcomes = new uint64_t[limit + 1];
  for( int j = 0; j < limit; j++ ) {
    outcomes[j] = 0;
  }
  outcomes[limit] = 1;
  outcomes[limit - 1] = 1;

  for( int i = 2; i <= limit; i++ ) {
    for( int j = 0; j < limit; j++ ) {
      outcomes[j] = outcomes[j + 1];
    }

    outcomes[limit] = 0;

    for( int j = limit; j > 0; j-- ) {
      outcomes[j] += outcomes[j - 1] * i;
    }
  }

  uint64_t good = 0;
  uint64_t total = factorial( limit + 1 );

  for( int i = 0; i < limit / 2 + 1; i++ ) {
    good += outcomes[i];
  }

  return total / good;
}

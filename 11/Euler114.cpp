/*
 * =====================================================================================
 *
 *       Filename:  Euler114.cpp
 *
 *    Description:  Solution to Project Euler, Problem 114
 *
 *        Version:  1.0
 *        Created:  7/31/2018 7:44:55 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  A row measuring seven units in length has red blocks with a minimum length of three units placed on it,
 *                  such that any two red blocks (which are allowed to be different lengths) are separated by at least one black square.
 *                  There are exactly seventeen ways of doing this.
 *                  [B][B][B][B][B][B][B]     [RRR][B][B][B][B]    [B][RRR][B][B][B]
 *                  [B][B][RRR][B][B]         [B][B][B][RRR][B]    [B][B][B][B][RRR]
 *                  [RRR][B][RRR]             [RRRR][B][B][B]      [B][RRRR][B][B]
 *                  [B][B][RRRR][B]           [B][B][B][RRRR]      [RRRRR][B][B]
 *                  [B][RRRRR][B]             [B][B][RRRRR]        [RRRRRR][B]
 *                  [B][RRRRRR]               [RRRRRRR]
 *                  How many ways can a row measuring fifty units in length be filled?
 *                  NOTE: Although the example above does not lend itself to the possibility, in general it is permitted to mix block sizes.
 *                  For example, on a row measuring eight units in length you could use red (3), black (1), and red (4).
 *         Answer:  16475640049
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint64_t solve114() {
  return fill_count( 50, 3 );
}

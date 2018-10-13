/*
 * =====================================================================================
 *
 *       Filename:  Euler96.cpp
 *
 *    Description:  Solution to Project Euler, Problem 96
 *
 *        Version:  1.0
 *        Created:  07/05/2017 08:05:01 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The 6K text file, sudoku.txt, contains fifty different Su Doku puzzles ranging in difficulty, but all with unique solutions
 *                  (the first puzzle in the file is the example above). By solving all fifty puzzles find the sum of the 3-digit numbers
 *                  found in the top left corner of each solution grid; for example, 483 is the 3-digit number found in the top left corner of the solution grid above.
 *         Answer:  24702
 *
 * =====================================================================================
 */

#include "../helper.hpp"

using std::ifstream;

#define NUM_PUZZLES 50

namespace euler96 {
// Passing by value works too, but passing by reference is ~20x faster.
bool solve( vector<vector<int>> &puzzle ) {
  for( uint32_t y = 0; y < 9; ++y ) {
    for( uint32_t x = 0; x < 9; ++x ) {
      if( puzzle[x][y] != 0 ) {
        continue;
      }

      bool available[10] = {false, true, true, true, true, true, true, true, true, true};

      for( uint32_t i = 0; i < 9; ++i ) {
        if( puzzle[i][y] != 0 ) {
          available[puzzle[i][y]] = false;
        }

        if( puzzle[x][i] != 0 ) {
          available[puzzle[x][i]] = false;
        }
      }

      uint32_t rx = ( x / 3 ) * 3;
      uint32_t ry = ( y / 3 ) * 3;

      for( uint32_t i = 0; i < 3; i++ ) {
        for( uint32_t j = 0; j < 3; j++ ) {
          if( puzzle[i + rx][j + ry] != 0 ) {
            available[puzzle[i + rx][j + ry]] = false;
          }
        }
      }

      for( uint32_t i = 1; i <= 9; i++ ) {
        if( available[i] ) {
          puzzle[x][y] = i;

          if( solve( puzzle ) ) {
            return true;
          }
        }
      }

      puzzle[x][y] = 0;
      return false;
    }
  }

  return true;
}
} // namespace euler96

uint32_t solve96() {
  int result = 0;
  string s;
  ifstream file( "9/sudoku.txt" );

  for( int i = 0; i < NUM_PUZZLES; ++i ) {
    vector<vector<int>> puzzle;
    getline( file, s, '\n' );

    for( int j = 0; j < 9; ++j ) {
      getline( file, s, '\n' );
      vector<int> line;

      for( auto &&c: s ) {
        line.push_back( c - '0' );
      }

      puzzle.push_back( line );
    }

    euler96::solve( puzzle );
    result += 100 * puzzle[0][0] + 10 * puzzle[0][1] + puzzle[0][2];
  }

  return result;
}

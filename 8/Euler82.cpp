/*
 * =====================================================================================
 *
 *       Filename:  Euler82.cpp
 *
 *    Description:  Solution to Project Euler, Problem 82
 *
 *        Version:  1.1
 *        Created:  4/24/2017 11:48:26 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The minimal path sum in the 5 by 5 matrix below, by starting in any cell in the left column and finishing in any cell in the right column,
 *                  and only moving up, down, and right, is indicated by asterisks; the sum is equal to 994.
 *                  131   673   234*  103*  18*
 *                  201*  96*   342*  965   150
 *                  630   803   746   422   111
 *                  537   699   497   121   956
 *                  805   732   524   37    331
 *                  Find the minimal path sum, in matrix.txt, a 31K text file containing a 80 by 80 matrix, from the left column to the right column.
 *         Answer:  260324
 *
 * =====================================================================================
 */

#include "../helper.hpp"

using std::min;
using std::stringstream;

#define SIZE 80

int solve82() {
  vector<vector<int>> matrix;
  vector<int> solution;
  solution.reserve( SIZE );

  for( auto &&line: loadDataFromFile( "8/matrix.txt", '\n' ) ) {
    vector<int> elems;
    stringstream ss;
    ss.str( line );
    string item;

    while( getline( ss, item, ',' ) ) {
      elems.push_back( stoi( item ) );
    }

    matrix.push_back( elems );
  }

  for( int i = 0; i < SIZE; ++i ) {
    solution.push_back( matrix[i][SIZE - 1] );
  }

  for( int i = SIZE - 2; i >= 0; --i ) {
    solution[0] += matrix[0][i];

    for( int j = 1; j < SIZE; ++j ) {
      solution[j] = min( solution[j - 1] + matrix[j][i], solution[j] + matrix[j][i] );
    }

    for( int j = SIZE - 2; j >= 0; --j ) {
      solution[j] = min( solution[j], solution[j + 1] + matrix[j][i] );
    }
  }

  return *min_element( solution.begin(), solution.end() );
}
#undef SIZE

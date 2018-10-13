/*
 * =====================================================================================
 *
 *       Filename:  Euler81.cpp
 *
 *    Description:  Solution to Project Euler, Problem 81
 *
 *        Version:  1.1
 *        Created:  4/23/2017 5:19:58 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down
 *                  is indicated by asterisks and is equal to 2427.
 *                  131*  673   234   103   18
 *                  201*  96*   342*  965   150
 *                  630   803   746*  422*  111
 *                  537   699   497   121*  956
 *                  805   732   524   37*   331*
 *                  Find the minimal path sum, in matrix.txt, a 31K text file containing a 80 by 80 matrix,
 *                  from the top left to the bottom right by only moving right and down.
 *         Answer:  427337
 *
 * =====================================================================================
 */

#include "../helper.hpp"

using std::min;
using std::stringstream;

#define SIZE 80

int solve81() {
  vector<vector<int>> matrix;

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

  for( int i = SIZE - 2; i >= 0; --i ) {
    matrix[SIZE - 1][i] += matrix[SIZE - 1][i + 1];
    matrix[i][SIZE - 1] += matrix[i + 1][SIZE - 1];
  }

  for( int i = SIZE - 2; i >= 0; --i ) {
    for( int j = SIZE - 2; j >= 0; --j ) {
      matrix[i][j] += min( matrix[i + 1][j], matrix[i][j + 1] );
    }
  }

  return matrix[0][0];
}

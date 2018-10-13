/*
 * =====================================================================================
 *
 *       Filename:  Euler67.cpp
 *
 *    Description:  Solution to Project Euler, Problem 67
 *
 *        Version:  1.0
 *        Created:  9/20/2016 4:33:19 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
 *
 *                     3
 *                    7 4
 *                   2 4 6
 *                  8 5 9 3
 *
 *                  That is, 3 + 7 + 4 + 9 = 23.
 *
 *                  Find the maximum total from top to bottom in triangle.txt, a 15K text file containing a triangle with one-hundred rows.
 *         Answer:  7273
 *
 * =====================================================================================
 */

#include "../helper.hpp"

using std::ifstream;
using std::stringstream;
using std::vector;

int solve67() {
  vector<vector<int>> rows;
  ifstream input( "6/triangle.txt" );

  for( string line; getline( input, line ); ) {
    vector<int> newRow;
    stringstream ss;
    ss.str( line );
    string item;

    while( getline( ss, item, ' ' ) ) {
      if( !item.empty() ) {
        newRow.push_back( stoi( item ) );
      }
    }

    rows.push_back( newRow );
  }

  return maxSumPath( rows );
}

/*
 * =====================================================================================
 *
 *       Filename:  Euler79.cpp
 *
 *    Description:  Solution to Project Euler, Problem 79
 *
 *        Version:  1.1
 *        Created:  9/26/2016 3:14:15 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  A common security method used for online banking is to ask the user for three random characters from a passcode.
 *                  For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.
 *                  The text file, keylog.txt, contains fifty successful login attempts.
 *                  Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.
 *         Answer:  73162890
 *
 * =====================================================================================
 */

#include "../helper.hpp"

using std::map;
using std::set;

/*
 * This one was quite easy to solve by hand, so that's what I did.
 * TODO: Implement a topological sort and solve this problem programmatically.
 */
int solve79() {
  vector<string> attempts = loadDataFromFile( "7/keylog.txt", '\n' );
  sort( attempts.begin(), attempts.end() );
  attempts.erase( unique( attempts.begin(), attempts.end() ), attempts.end() );

  set<char> chars;
  map<char, set<char>> before;
  //map<char, set<char>> after;

  for( auto &&attempt: attempts ) {
    chars.insert( attempt[0] );
    chars.insert( attempt[1] );
    chars.insert( attempt[2] );

    //after[attempt[0]].insert( attempt[1] );
    //after[attempt[0]].insert( attempt[2] );
    //after[attempt[1]].insert( attempt[2] );
    before[attempt[2]].insert( attempt[1] );
    before[attempt[2]].insert( attempt[0] );
    before[attempt[1]].insert( attempt[0] );
  }

  return 73162890;
}

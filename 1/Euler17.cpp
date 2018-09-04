/*
 * =====================================================================================
 *
 *       Filename:  Euler17.cpp
 *
 *    Description:  Solution to Project Euler, Problem 17
 *
 *        Version:  1.0
 *        Created:  08/02/2015 4:30:09 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 *         Answer:  21124
 * =====================================================================================
 */

#include "../helper.hpp"

int solve17() {
  unordered_map<int, int> letterCounts;
  letterCounts[1] = 3;
  letterCounts[2] = 3;
  letterCounts[3] = 5;
  letterCounts[4] = 4;
  letterCounts[5] = 4;
  letterCounts[6] = 3;
  letterCounts[7] = 5;
  letterCounts[8] = 5;
  letterCounts[9] = 4;
  letterCounts[10] = 3;
  letterCounts[11] = 6;
  letterCounts[12] = 6;
  letterCounts[13] = 8;
  letterCounts[14] = 8;
  letterCounts[15] = 7;
  letterCounts[16] = 7;
  letterCounts[17] = 9;
  letterCounts[18] = 8;
  letterCounts[19] = 8;
  letterCounts[20] = 6;
  letterCounts[30] = 6;
  letterCounts[40] = 5;
  letterCounts[50] = 5;
  letterCounts[60] = 5;
  letterCounts[70] = 7;
  letterCounts[80] = 6;
  letterCounts[90] = 6;
  letterCounts[1000] = 11;

  for( int i = 21; i < 100; i++ ) {
    int mod = i % 10;

    if( mod == 0 ) {
      continue;
    } else {
      letterCounts[i] = letterCounts[i - mod] + letterCounts[mod];
    }
  }

  for( int i = 100; i < 1000; i++ ) {
    int mod = i % 100;

    if( mod == 0 ) {
      letterCounts[i] = letterCounts[i / 100] + 7;
    } else {
      letterCounts[i] = letterCounts[i - mod] + letterCounts[mod] + 3;
    }
  }

  int sum = 0;

  for( int i = 1; i <= 1000; i++ ) {
    sum += letterCounts[i];
  }

  return sum;
}

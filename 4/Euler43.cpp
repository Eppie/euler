/*
 * =====================================================================================
 *
 *       Filename:  Euler43.cpp
 *
 *    Description:  Solution to Project Euler, Problem 43
 *
 *        Version:  1.2
 *        Created:  5/17/2016 7:16:28 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order,
 *                  but it also has a rather interesting sub-string divisibility property.
 *                  Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:
 *                  d2d3d4=406 is divisible by 2
 *                  d3d4d5=063 is divisible by 3
 *                  d4d5d6=635 is divisible by 5
 *                  d5d6d7=357 is divisible by 7
 *                  d6d7d8=572 is divisible by 11
 *                  d7d8d9=728 is divisible by 13
 *                  d8d9d10=289 is divisible by 17
 *                  Find the sum of all 0 to 9 pandigital numbers with this property.
 *         Answer:  16695334890
 * =====================================================================================
 */

#include "../helper.hpp"

uint64_t solve43() {
  uint64_t result = 0;
  // Vector of digits
  vector<int> perm = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> divisors = {1, 2, 3, 5, 7, 11, 13, 17};

  int count = 1;
  int numPerm = 3265920; // 9! * 9

  while( count < numPerm ) {
    next_permutation( perm.begin(), perm.end() );
    bool divisible = true;

    for( uint32_t k = 1; k < divisors.size(); k++ ) {
      int num = 100 * perm[k] + 10 * perm[k + 1] + perm[k + 2];

      if( num % divisors[k] != 0 ) {
        divisible = false;
        break;
      }
    }

    if( divisible ) {
      // Convert from vector of digits to number
      uint64_t num = 0;

      for( auto &&k: perm ) {
        num = 10 * num + k;
      }

      result += num;
    }

    count++;
  }

  return result;
}

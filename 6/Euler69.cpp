/*
 * =====================================================================================
 *
 *       Filename:  Euler69.cpp
 *
 *    Description:  Solution to Project Euler, Problem 69
 *
 *        Version:  1.1
 *        Created:  9/21/2016 1:43:04 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of numbers less than n
 *                  which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
 *
 *                  n	  Relatively Prime	φ(n)	n/φ(n)
 *                  2	  1			1	2
 *                  3	  1,2			2	1.5
 *                  4	  1,3			2	2
 *                  5	  1,2,3,4		4	1.25
 *                  6	  1,5			2	3
 *                  7	  1,2,3,4,5,6		6	1.1666...
 *                  8	  1,3,5,7		4	2
 *                  9	  1,2,4,5,7,8		6	1.5
 *                  10	  1,3,7,9		4	2.5
 *
 *                  It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.
 *                  Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.
 *         Answer:  510510
 *
 * =====================================================================================
 */

#include "../helper.hpp"

// Idea: The n which will maximize n/φ(n) is the n with the most distinct prime factors.
// Therefore, we can directly calculate it by multiplying small prime numbers until we exceed
// our limit, 1,000,000
int solve69() {
  int result = 1;
  int primeCandidate = 1;

  while( result < 1000000 ) {
    primeCandidate += 1;

    if( isPrime( primeCandidate ) ) {
      result *= primeCandidate;
    }
  }

  return result / primeCandidate;
}

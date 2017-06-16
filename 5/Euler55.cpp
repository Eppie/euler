/*
 * =====================================================================================
 *
 *       Filename:  Euler55.cpp
 *
 *    Description:  Solution to Project Euler, Problem 55
 *
 *        Version:  1.0
 *        Created:  9/2/2016 12:38:37 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.
 *                  Not all numbers produce palindromes so quickly. For example,
 *                  349 + 943 = 1292,
 *                  1292 + 2921 = 4213
 *                  4213 + 3124 = 7337
 *                  That is, 349 took three iterations to arrive at a palindrome.
 *                  Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome.
 *                  A number that never forms a palindrome through the reverse and add process is called a Lychrel number.
 *                  Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise.
 *                  In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or,
 *                  (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome.
 *                  In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome:
 *                  4668731596684224866951378664 (53 iterations, 28-digits).
 *                  Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.
 *                  How many Lychrel numbers are there below ten-thousand?
 *         Answer:  249
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler55 {
mpz_class reverseDecimal( mpz_class x ) {
	mpz_class result = 0;

	while( x != 0 ) {
		result *= 10;
		result += x % 10;
		x /= 10;
	}

	return result;
}
}

int solve55() {
	int result = 10000;

	for( int i = 0; i < 10000; ++i ) {
		mpz_class num = i;

		for( int j = 0; j < 50; ++j ) {
			num += euler55::reverseDecimal( num );

			if( num == euler55::reverseDecimal( num ) ) {
				result--;
				break;
			}
		}
	}

	return result;
}


/*
 * =====================================================================================
 *
 *       Filename:  Euler4.cpp
 *
 *    Description:  Solution to Project Euler, Problem 4
 *
 *        Version:  1.0
 *        Created:  07/29/2015 10:51:45 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *   Organization:  SevOne
 *        Problem:  The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99. Find the largest palindrome made from the product of two 3-digit numbers.
 *         Answer:  906609
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int main() {
	int test;
	string s;
	int result = 0;
	for( int i = 999; i >= 100; i-- ) {
		for( int j = 999; j >= 100; j-- ) {
			test = i * j;
			s = to_string( test );
			if( isPalindrome( s ) ) {
				result = test > result ? test : result;
			}
		}
	}
	cout << result << endl;
	return 0;
}

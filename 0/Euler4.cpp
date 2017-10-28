/*
 * =====================================================================================
 *
 *       Filename:  Euler4.cpp
 *
 *    Description:  Solution to Project Euler, Problem 4
 *
 *        Version:  1.1
 *        Created:  07/29/2015 10:51:45 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *                  Find the largest palindrome made from the product of two 3-digit numbers.
 *         Answer:  906609
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint32_t solve4() {
	uint32_t test;
	uint32_t result = 0;

	for( uint32_t i = 999; i >= 100; --i ) {
		for( uint32_t j = 999; j >= 100; --j ) {
			test = i * j;

			if( isPalindrome( test, 10 ) ) {
				result = test > result ? test : result;
			}
		}
	}

	return result;
}

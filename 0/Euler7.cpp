/*
 * =====================================================================================
 *
 *       Filename:  Euler7.cpp
 *
 *    Description:  Solution to Project Euler, Problem 7
 *
 *        Version:  1.0
 *        Created:  07/29/2015 8:23:39 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *   Organization:  SevOne
 *        Problem:  By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13. What is the 10,001st prime number?
 *         Answer:  104743
 *
 * =====================================================================================
 */

#include "../helper.hpp"

ull solve7() {
	return sieve( 105000 )[10000];
}

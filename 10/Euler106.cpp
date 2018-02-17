/*
 * =====================================================================================
 *
 *       Filename:  Euler106.cpp
 *
 *    Description:  Solution to Project Euler, Problem 106
 *
 *        Version:  1.0
 *        Created:  2/12/2018 08:58:04 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Let S(A) represent the sum of elements in set A of size n.
 *                  We shall call it a special sum set if for any two non-empty disjoint subsets, B and C, the following properties are true:
 *                   i. S(B) ≠ S(C); that is, sums of subsets cannot be equal.
 *                  ii. If B contains more elements than C then S(B) > S(C).
 *                  For this problem we shall assume that a given set contains n strictly increasing elements and it already satisfies the second rule.
 *                  Surprisingly, out of the 25 possible subset pairs that can be obtained from a set for which n = 4, only 1 of these pairs
 *                  need to be tested for equality (first rule). Similarly, when n = 7, only 70 out of the 966 subset pairs need to be tested.
 *                  For n = 12, how many of the 261625 subset pairs that can be obtained need to be tested for equality?
 *         Answer:  21384
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint32_t solve106() {
	uint32_t result = 0;
	uint32_t n = 12;
	for( uint32_t i = 2; i <= 6; ++i ) {
		result += choose( n, i ) * choose( n - i, i ) / 2;
		result -= choose( n, 2 * i ) * ( choose( 2 * i, i ) / ( i + 1 ) );
	}
	return result;
}

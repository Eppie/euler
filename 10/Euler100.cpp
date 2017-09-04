/*
 * =====================================================================================
 *
 *       Filename:  Euler100.cpp
 *
 *    Description:  Solution to Project Euler, Problem 100
 *
 *        Version:  1.0
 *        Created:  09/03/2017 10:11:57 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  If a box contains twenty-one coloured discs, composed of fifteen blue discs and six red discs, and two discs were taken at random,
 *                  it can be seen that the probability of taking two blue discs, P(BB) = (15/21)×(14/20) = 1/2. The next such arrangement,
 *                  for which there is exactly 50% chance of taking two blue discs at random, is a box containing eighty-five blue discs and thirty-five red discs.
 *                  By finding the first arrangement to contain over 10¹² = 1,000,000,000,000 discs in total, determine the number of blue discs that the box would contain.
 *         Answer:  756872327473
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint64_t solve100() {
	uint64_t b = 3;
	uint64_t n = 4;
	uint64_t btemp;
	uint64_t ntemp;

	while( n <= 1000000000000 ) {
		btemp = 3 * b + 2 * n - 2;
		ntemp = 4 * b + 3 * n - 3;
		b = btemp;
		n = ntemp;
	}

	return b;
}


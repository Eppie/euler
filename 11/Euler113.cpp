/*
 * =====================================================================================
 *
 *       Filename:  Euler113.cpp
 *
 *    Description:  Solution to Project Euler, Problem 113
 *
 *        Version:  1.0
 *        Created:  7/30/2018 8:26:42 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Working from left-to-right if no digit is exceeded by the digit to its left it is called an increasing number; for example, 134468.
 *                  Similarly if no digit is exceeded by the digit to its right it is called a decreasing number; for example, 66420.
 *                  We shall call a positive integer that is neither increasing nor decreasing a "bouncy" number; for example, 155349.
 *                  As n increases, the proportion of bouncy numbers below n increases such that there are only 12951 numbers below one-million
 *                  that are not bouncy and only 277032 non-bouncy numbers below 10¹0.
 *                  How many numbers below a googol (10¹00) are not bouncy?
 *         Answer:  51161058134250
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint64_t solve113() {
	uint64_t result = 0;
	auto increasing = new uint64_t[10][100];
	auto decreasing = new uint64_t[10][100];
	for( int j = 0; j < 10; ++j ) {
		for( int i = 0; i < 100; ++i ) {
			increasing[j][i] = 0;
			decreasing[j][i] = 0;
		}
	}
	for( int i = 0; i < 100; ++i ) {
		increasing[9][i] = 1;
		increasing[8][i] = i;
		decreasing[1][i] = i;
	}

	for( int j = 0; j < 10; ++j ) {
		increasing[j][0] = 1;
		decreasing[j][0] = 0;
		decreasing[j][1] = j;
	}

	for( int j = 8; j >= 0; --j ) {
		for( int i = 1; i < 100; ++i ) {
			increasing[j][i] = increasing[j + 1][i] + increasing[j][i - 1];
		}
	}

	for( int j = 1; j < 10; ++j ) {
		for( int i = 1; i < 100; ++i ) {
			decreasing[j][i] = 1 + decreasing[j - 1][i] + decreasing[j][i - 1];
		}
	}

	for( int j = 1; j < 10; ++j ) {
		for( int i = 0; i < 100; ++i ) {
			result += increasing[j][i];
			result += decreasing[j][i];
		}
	}

	return result;
}

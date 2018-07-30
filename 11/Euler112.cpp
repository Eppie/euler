/*
 * =====================================================================================
 *
 *       Filename:  Euler112.cpp
 *
 *    Description:  Solution to Project Euler, Problem 112
 *
 *        Version:  1.0
 *        Created:  7/30/2018 7:49:20 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Working from left-to-right if no digit is exceeded by the digit to its left it is called an increasing number; for example, 134468.
 *                  Similarly if no digit is exceeded by the digit to its right it is called a decreasing number; for example, 66420.
 *                  We shall call a positive integer that is neither increasing nor decreasing a "bouncy" number; for example, 155349.
 *                  Clearly there cannot be any bouncy numbers below one-hundred, but just over half of the numbers below one-thousand (525) are bouncy.
 *                  In fact, the least number for which the proportion of bouncy numbers first reaches 50% is 538.
 *                  Surprisingly, bouncy numbers become more and more common and by the time we reach 21780 the proportion of bouncy numbers is equal to 90%.
 *                  Find the least number for which the proportion of bouncy numbers is exactly 99%.
 *         Answer:  1587000
 *
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler112 {
bool isIncreasing( uint64_t x ) {
	uint8_t currentDigit = 9;

	while( x ) {
		if( x % 10 > currentDigit ) {
			return false;
		} else {
			currentDigit = x % 10;
			x /= 10;
		}
	}

	return true;
}

bool isDecreasing( uint64_t x ) {
	uint8_t currentDigit = 0;

	while( x ) {
		if( x % 10 < currentDigit ) {
			return false;
		} else {
			currentDigit = x % 10;
			x /= 10;
		}
	}

	return true;
}

bool isBouncy( uint64_t x ) {
	return !isIncreasing( x ) && !isDecreasing( x );
}
}

uint32_t solve112() {
	uint32_t bouncyCount = 0;
	uint32_t i = 0;
	while( true ) {
		++i;

		if( euler112::isBouncy( i ) ) {
			++bouncyCount;
		}

		if( bouncyCount * 100 / i == 99 ) {
			return i;
		}
	}
}

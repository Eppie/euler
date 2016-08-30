/*
 * =====================================================================================
 *
 *       Filename:  Euler48.cpp
 *
 *    Description:  Solution to Project Euler, Problem 48
 *
 *        Version:  1.0
 *        Created:  8/26/2016 8:23:47 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The series, 1¹ + 2² + 3³ + ... + 10¹⁰ = 10405071317.
 *                  Find the last ten digits of the series, 1¹ + 2² + 3³ + ... + 1000¹⁰⁰⁰.
 *         Answer:  9110846700
 * =====================================================================================
 */

#include "../helper.hpp"

uint64_t solve48() {
	uint64_t result = 0;
	uint64_t mod = 1e10;

	for( int i = 1; i <= 1000; ++i ) {
		uint64_t tmp = i;

		for( int j = 1; j < i; ++j ) {
			tmp *= i;
			tmp %= mod;
		}

		result += tmp;
		result %= mod;
	}

	return result;
}


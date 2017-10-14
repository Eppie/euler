/*
 * =====================================================================================
 *
 *       Filename:  Euler101.cpp
 *
 *    Description:  Solution to Project Euler, Problem 101
 *
 *        Version:  1.0
 *        Created:  09/05/2017 07:54:26 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  See the description here: https://projecteuler.net/problem=101
 *         Answer:  37076114526
 *
 * =====================================================================================
 */

#include "../helper.hpp"

uint64_t solve101() {
	auto u = [](int64_t n) { return 1 - n + pow(n, 2) - pow(n, 3) + pow(n, 4) - pow(n, 5) + pow(n, 6) - pow(n, 7) + pow(n, 8) - pow(n, 9) + pow(n, 10); };
	auto tld = [](vector<int64_t> x) {
		vector<int64_t> result;
		for( uint32_t i = 1; i < x.size(); ++i ) {
			result.push_back( x[i] - x[i - 1] );
		}
		return result;
	};
	vector<int64_t> range = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto seq = functional::map( range, u );
	uint64_t result = 0;
	for( auto i = 0; i < 10; ++i ) {
		result += sum( seq );
		seq = tld( seq );
	}
	return result;
}


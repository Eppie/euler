/*
 * =====================================================================================
 *
 *       Filename:  Euler31.cpp
 *
 *    Description:  Solution to Project Euler, Problem 31
 *
 *        Version:  1.0
 *        Created:  3/12/2016 5:09:08 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
 *                  1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
 *                  How many different ways can £2 be made using any number of coins?
 *         Answer:  73682
 * =====================================================================================
 */

#include "../helper.hpp"

int solve31() {
	int target = 200;
	vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 200 };
	vector<int> ways( target + 1, 0 );
	ways[0] = 1;

	for( int coin : coins ) {
		for( int j = coin; j <= target; j++ ) {
			ways[j] += ways[j - coin];
		}
	}

	return ways[200];
}


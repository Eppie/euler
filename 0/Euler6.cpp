/*
 * =====================================================================================
 *
 *       Filename:  Euler6.cpp
 *
 *    Description:  Solution to Project Euler, Problem 6
 *
 *        Version:  1.0
 *        Created:  07/29/2015 5:52:32 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *   Organization:  SevOne
 *        Problem:  Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 *         Answer:  25164150
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int main() {
	int sumOfSquares = 0;
	int squareOfSums = 0;

	for( int i = 1; i <= 100; i++ ) {
		sumOfSquares += pow( i, 2 );
		squareOfSums += i;
	}

	squareOfSums = pow( squareOfSums, 2 );
	int result = squareOfSums - sumOfSquares;
	cout << result << endl;
	return 0;
}

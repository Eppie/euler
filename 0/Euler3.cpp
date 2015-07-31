/*
 * =====================================================================================
 *
 *       Filename:  Euler3.cpp
 *
 *    Description:  Solution to Project Euler, Problem 3
 *
 *        Version:  1.0
 *        Created:  06/29/2015 05:58:57 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *   Organization:  SevOne
 *        Problem: The prime factors of 13195 are 5, 7, 13 and 29. What is the largest prime factor of the number 600851475143?
 *         Answer: 6857
 *
 * =====================================================================================
 */

#include "../helper.hpp"

int main() {
	long n = 600851475143;
	int newN = (int)sqrt(n) + 1;
	vector<int> primes = sieve( newN );
	for( auto it = primes.rbegin(); it != primes.rend(); ++it ) {
		if( n % *it == 0 ) {
			cout << *it << endl;
			return 0;
		}
	}
	return 1;
}


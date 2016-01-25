/*
 * =====================================================================================
 *
 *       Filename:  Euler26.cpp
 *
 *    Description:  Solution to Project Euler, Problem 26
 *
 *        Version:  1.0
 *        Created:  10/25/2015 03:59:08 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *   Organization:  SevOne
 *        Problem:  Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 *         Answer:  983
 * =====================================================================================
 */

int solve26() {
	int max = 0;
	int answer = 0;
	for( int i = 1; i < 1000; i++ ) {
		int counter = 0;
		int value = 10 % i;
		int z = 1000;
		while( value != 1 && z > 0 ) {
			value *= 10;
			value %= i;
			counter++;
			z--;
		}
		if( counter > max && z > 1 ) {
			max = counter;
			answer = i;
		}
	}
	return answer;
}

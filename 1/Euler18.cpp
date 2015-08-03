/*
 * =====================================================================================
 *
 *       Filename:  Euler18.cpp
 *
 *    Description:  Solution to Project Euler, Problem 18
 *
 *        Version:  1.0
 *        Created:  08/02/2015 10:43:23 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *   Organization:  SevOne
 *        Problem:  Find the maximum total from top to bottom of the triangle below.
 *         Answer:  1074
 * =====================================================================================
 */

#include "../helper.hpp"

int main() {
	vector< vector<int> > rows (15);
	rows[0] = { 75 };
	rows[1] = { 95, 64 };
	rows[2] = { 17, 47, 82 };
	rows[3] = { 18, 35, 87, 10 };
	rows[4] = { 20, 4, 82, 47, 65 };
	rows[5] = { 19, 1, 23, 75, 3, 34 };
	rows[6] = { 88, 2, 77, 73, 7, 63, 67 };
	rows[7] = { 99, 65, 4, 28, 6, 16, 70, 92 };
	rows[8] = { 41, 41, 26, 56, 83, 40, 80, 70, 33 };
	rows[9] = { 41, 48, 72, 33, 47, 32, 37, 16, 94, 29 };
	rows[10] = { 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14 };
	rows[11] = { 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57 };
	rows[12] = { 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48 };
	rows[13] = { 63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31 };
	rows[14] = { 4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23 };
	cout << maxSumPath( rows ) << endl;
	return 0;
}

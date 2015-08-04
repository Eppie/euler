/*
 * =====================================================================================
 *
 *       Filename:  Euler19.cpp
 *
 *    Description:  Solution to Project Euler, Problem 19
 *
 *        Version:  1.0
 *        Created:  08/03/2015 09:38:51 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *   Organization:  SevOne
 *        Problem:  How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 *         Answer:  171
 * =====================================================================================
 */

#define JAN 0
#define FEB 1
#define MAR 2
#define APR 3
#define MAY 4
#define JUN 5
#define JUL 6
#define AUG 7
#define SEP 8
#define OCT 9
#define NOV 10
#define DEC 11

#define MON 0
#define TUE 1
#define WED 2
#define THU 3
#define FRI 4
#define SAT 5
#define SUN 6

#include "../helper.hpp"

bool isLeapYear( int year ) {
	if( year % 400 == 0 ) {
		return true;
	} else if( year % 100 == 0 ) {
		return false;
	} else if( year % 4 == 0 ) {
		return true;
	} else {
		return false;
	}
}

int main() {
	vector<int> daysPerMonth(12);
	daysPerMonth[JAN] = 31;
	daysPerMonth[FEB] = 28;
	daysPerMonth[MAR] = 31;
	daysPerMonth[APR] = 30;
	daysPerMonth[MAY] = 31;
	daysPerMonth[JUN] = 30;
	daysPerMonth[JUL] = 31;
	daysPerMonth[AUG] = 31;
	daysPerMonth[SEP] = 30;
	daysPerMonth[OCT] = 31;
	daysPerMonth[NOV] = 30;
	daysPerMonth[DEC] = 31;

	int dayOfMonth = 1;
	int month = JAN;
	int year = 1901;
	int dayOfWeek = TUE;
	int result = 0;

	while( year != 2001 ) {
		if( dayOfWeek == SUN && dayOfMonth == 1 ) {
			result += 1;
		}

		dayOfMonth += 1;
		dayOfWeek = ( dayOfWeek + 1 ) % 7;

		if( dayOfMonth > daysPerMonth[month] ) {
			dayOfMonth = 1;
			if( month == DEC ) {
				month = JAN;
				year += 1;
				if( isLeapYear( year ) ) {
					daysPerMonth[FEB] = 29;
				} else {
					daysPerMonth[FEB] = 28;
				}
			} else {
				month += 1;
			}
		}
	}
	cout << result << endl;
	return 0;
}

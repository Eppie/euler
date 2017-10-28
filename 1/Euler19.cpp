/*
 * =====================================================================================
 *
 *       Filename:  Euler19.cpp
 *
 *    Description:  Solution to Project Euler, Problem 19
 *
 *        Version:  1.1
 *        Created:  08/03/2015 09:38:51 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 *         Answer:  171
 * =====================================================================================
 */

enum MONTHS {
	JAN,
	FEB,
	MAR,
	APR,
	MAY,
	JUN,
	JUL,
	AUG,
	SEP,
	OCT,
	NOV,
	DEC
};

enum DAYS {
	MON,
	TUE,
	WED,
	THU,
	FRI,
	SAT,
	SUN
};

#include "../helper.hpp"

namespace euler19 {
bool isLeapYear( int year ) {
	if( year % 400 == 0 ) {
		return true;
	} else if( year % 100 == 0 ) {
		return false;
	} else {
		return year % 4 == 0;
	}
}
}

uint32_t solve19() {
	vector<int> daysPerMonth( 12 );
	daysPerMonth[MONTHS::JAN] = 31;
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
	uint32_t month = MONTHS::JAN;
	int year = 1901;
	int dayOfWeek = DAYS::TUE;
	uint32_t result = 0;

	while( year != 2001 ) {
		if( dayOfWeek == DAYS::SUN && dayOfMonth == 1 ) {
			result += 1;
		}

		dayOfMonth += 1;
		dayOfWeek = ( dayOfWeek + 1 ) % 7;

		if( dayOfMonth > daysPerMonth[month] ) {
			dayOfMonth = 1;

			if( month == MONTHS::DEC ) {
				month = MONTHS::JAN;
				year += 1;

				if( euler19::isLeapYear( year ) ) {
					daysPerMonth[FEB] = 29;
				} else {
					daysPerMonth[FEB] = 28;
				}
			} else {
				month += 1;
			}
		}
	}

	return result;
}

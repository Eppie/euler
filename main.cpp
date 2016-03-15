/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Main file for running the different Euler problems.
 *
 *        Version:  1.0
 *        Created:  07/30/2015 09:58:10 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *   Organization:  SevOne
 *
 * =====================================================================================
 */

#include "main.h"
#include "helper.hpp"

int main( int argc, char* argv[] ) {
	if( argc < 2 ) {
		cerr << "Usage: " << argv[0] << " <Problem #>" << endl;
		return 1;
	}

	auto x = atoi( argv[1] );

	switch( x ) {
		case 1:
			cout << solve1() << endl;
			break;

		case 2:
			cout << solve2() << endl;
			break;

		case 3:
			cout << solve3() << endl;
			break;

		case 4:
			cout << solve4() << endl;
			break;

		case 5:
			cout << solve5() << endl;
			break;

		case 6:
			cout << solve6() << endl;
			break;

		case 7:
			cout << solve7() << endl;
			break;

		case 8:
			cout << solve8() << endl;
			break;

		case 9:
			cout << solve9() << endl;
			break;

		case 10:
			cout << solve10() << endl;
			break;

		case 11:
			cout << solve11() << endl;
			break;

		case 12:
			cout << solve12() << endl;
			break;

		case 13:
			cout << solve13() << endl;
			break;

		case 14:
			cout << solve14() << endl;
			break;

		case 15:
			cout << solve15() << endl;
			break;

		case 16:
			cout << solve16() << endl;
			break;

		case 17:
			cout << solve17() << endl;
			break;

		case 18:
			cout << solve18() << endl;
			break;

		case 19:
			cout << solve19() << endl;
			break;

		case 20:
			cout << solve20() << endl;
			break;

		case 21:
			cout << solve21() << endl;
			break;

		case 22:
			cout << solve22() << endl;
			break;

		case 23:
			cout << solve23() << endl;
			break;

		case 24:
			cout << solve24() << endl;
			break;

		case 25:
			cout << solve25() << endl;
			break;

		case 26:
			cout << solve26() << endl;
			break;

		case 27:
			cout << solve27() << endl;
			break;

		case 28:
			cout << solve28() << endl;
			break;

		case 29:
			cout << solve29() << endl;
			break;

		case 30:
			cout << solve30() << endl;
			break;

		case 31:
			cout << solve31() << endl;
			break;

		case 32:
			cout << solve32() << endl;
			break;

		case 33:
			cout << solve33() << endl;
			break;

		case 34:
			cout << solve34() << endl;
			break;

		case 35:
			cout << solve35() << endl;
			break;
		case 36:
			cout << solve36() << endl;
			break;
		case 37:
			cout << solve37() << endl;
			break;
	}

	return 0;
}


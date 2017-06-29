/*
 * =====================================================================================
 *
 *       Filename:  testbigint.cpp
 *
 *    Description:  trying out the bigint class
 *
 *        Version:  1.0
 *        Created:  08/27/2016 12:56:47 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <iostream>
#include "bigint.hpp"

using namespace std;

int main() {
	BigInt<100> x( "123" );
	BigInt<100> y( "234" );
	auto z = x + y;

	for( int i = 0; i < 100; ++i ) {
		cout << z[i];
	}

	cout << endl;
	return 0;
}

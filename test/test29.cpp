/*
 * =====================================================================================
 *
 *       Filename:  test29.cpp
 *
 *    Description:  Test for Project Euler Problem 29
 *
 *        Version:  1.0
 *        Created:  12/20/2015 04:23:14 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *   Organization:  SevOne
 *
 * =====================================================================================
 */

#include "../2/Euler29.cpp"
#include <gtest/gtest.h>

TEST( Problem29, Test1 ) {
	ASSERT_EQ( 9183, solve29() );
}


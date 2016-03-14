/*
 * =====================================================================================
 *
 *       Filename:  helper.hpp
 *
 *    Description:  Helper functions for Project Euler problems.
 *
 *        Version:  1.0
 *        Created:  07/29/2015 11:08:34 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *
 * =====================================================================================
 */

#pragma once

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <map>
#include <functional>
#include <sstream>
#include <fstream>
#include <set>
#include <typeinfo>
#include <cxxabi.h>

#define printVariable(a) cout << __PRETTY_FUNCTION__ << ":" << #a << ": " << (a) << " (line " << __LINE__ << ")" << endl

typedef unsigned long long ull;
using namespace std;

/*
 * This function returns a vector of all the prime factors of an integer n.
 * Example: n = 1000 --> 2 * 2 * 2 * 5 * 5 * 5 == 8 * 125 == 1000
 * @param unsigned long long n
 * @return vector<int>
 */
vector<int> primeFactors( ull n );

/*
 * This is an implementation of the Sieve of Eratosthenes.
 * Returns a vector of all prime numbers less than n.
 * @param unsigned long long n
 * @return vector<unsigned long long>
 */
vector<ull> sieve( ull n );

/*
 * Return true if the given number is prime, and false otherwise.
 * @param long long n The number to perform the primality test on.
 * @return bool Whether or not the number is prime.
 */
bool isPrime( long long n );

/*
 * Returns true if s is a palindrome, and false otherwise.
 * @param string s
 * @return bool
 */
bool isPalindrome( string s );

/*
 * Convenience wrapper around accumulate to hide the iterator stuff.
 * Templated, so it will accept a vector of anything. The return type
 * will match the "anything".
 * @param vector<T> input
 * @return T
 */
template <typename T>
T sum( vector<T> input ) {
	return accumulate( input.begin(), input.end(), ( T )0 );
}

/*
 * @param vector<vector<T>> grid
 * @param int x0
 * @param int y0
 * @param int dx
 * @param int dy
 * @param int steps
 * @return T
 */
template <typename T>
T productInDirection( vector<vector<T> > grid, int x0, int y0, int dx, int dy, int steps ) {
	if( !(
		0 <= y0 && y0 < ( int )grid.size() &&
		0 <= y0 + ( steps - 1 ) * dy && y0 + ( steps - 1 ) * dy < ( int )grid.size() &&
		0 <= x0 && x0 < ( int )grid[y0].size() &&
		0 <= x0 + ( steps - 1 ) * dx && x0 + ( steps - 1 ) * dx < ( int )grid[y0].size()
	) ) {
		return 0;
	}

	T product = 1;

	for( int n = 0; n < steps; n++ ) {
		product *= grid[y0 + n * dy][x0 + n * dx];
	}

	return product;
}

/*
 * Use this function on some function that you expect to call repeatedly
 * with the same values. Define a std::function, pass it to this function, and
 * then use the function returned instead of the original function.
 * Does not work with recursive functions unless you use a forward declaration!
 * @param function<outType(inType)> inFunc The function to memoize
 * @return function<outType(inType)> The memoized version of the function
 */
template<class inType, class outType>
function<outType( inType )> memoize( function<outType( inType )> inFunc ) {
	// return a lambda function
	return [inFunc]( inType n ) {
		static unordered_map<inType, outType> memo;
		outType returnValue;
		auto memoized = memo.find( n );

		if( memoized != memo.end() ) {
			return memoized->second;
		}

		returnValue = inFunc( n );
		memo[n] = returnValue;
		return returnValue;
	};
}

/*
 * This is your standard greatest common denominator function.
 * @param unsigned long long x
 * @param unsigned long long y
 * @return unsigned long long
 */
ull gcd( ull x, ull y );

/*
 * Calculates the factorial of a number ( e.g. 5! == 120 )
 * @param unsigned n
 * @return unsigned long long
 */
ull factorial( ull n );

/*
 * This is your standard n choose k function.
 * @param unsigned long long n
 * @param unsigned long long k
 * @return unsigned long long
 */
ull choose( ull n, ull k );

/*
 * Calculates the path through a triangle array with the largest sum.
 * @param vector<vector<int> > rows
 * @return int
 */
int maxSumPath( vector<vector<int> > rows );

/*
 * Print out an iterable with separator of your choice, \n by default.
 * @param I v The iterable to print
 * @param string sep optional, endl by default, gets printed after each element in v.
 * @param string end optional, "" by default, gets printed once after the entire iterable has been printed.
 * @return void
 */
template <typename I>
void printIterable( I v, string sep = "\n", string end = "" );

/*
 * Read a comma delimited file.
 * @param string filename
 * @return vector<string>
 */
vector<string> loadDataFromFile( string filename );

/*
 * Return the type of a variable or function.
 * @param T var
 * @return char* The type of var.
 */
template<typename T>
char* getType( T var );


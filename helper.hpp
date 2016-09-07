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

#include <bitset>
#include <chrono>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <functional>
#include <sstream>
#include <fstream>
#include <locale>
#include <iomanip>
#include <set>
#include <cxxabi.h>
#include <typeinfo>

#define printVariable(a) cout << __PRETTY_FUNCTION__ << ":" << #a << ": " << (a) << " (line " << __LINE__ << ")" << endl

using namespace std;

/*
 * This function returns a vector of all the prime factors of an integer n.
 * Example: n = 1000 --> 2 * 2 * 2 * 5 * 5 * 5 == 8 * 125 == 1000
 * @param uint64_t n
 * @return vector<int>
 */
vector<int> primeFactors( uint64_t n );

/*
 * This is an implementation of the Sieve of Eratosthenes.
 * Returns a vector of all prime numbers less than n.
 * @param uint64_t n
 * @return vector<uint64_t>
 */
vector<uint64_t> sieve( uint64_t n );

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
 * Returns true if x is a palindrome in base b, and false otherwise.
 * @param uint64_t x
 * @param int b
 * @return bool
 */
bool isPalindrome( uint64_t x, int b );

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
template<typename inType, typename outType>
function<outType( inType )> memoize( function<outType( inType )> inFunc ) {
	//return a lambda function
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
 * @param uint64_t x
 * @param uint64_t y
 * @return uint64_t
 */
uint64_t gcd( uint64_t x, uint64_t y );

/*
 * Calculates the factorial of a number ( e.g. 5! == 120 )
 * @param unsigned n
 * @return uint64_t
 */
uint64_t factorial( uint64_t n );

/*
 * This is a memoized implementation of the recursive formula for n choose k.
 * @param const uint64_t n
 * @param const uint64_t k
 * @return uint64_t
 */
uint64_t choose( const uint64_t &n, const uint64_t &k );

/*
 * Calculates the path through a triangle array with the largest sum.
 * @param vector<vector<int> > rows
 * @return int
 */
int maxSumPath( vector<vector<int> > rows );

/*
 * Print out an iterable with separator of your choice, \n by default.
 * @param I v The iterable to print
 * @param string sep optional, "\n" by default, gets printed after each element in v.
 * @param string end optional, "" by default, gets printed once after the entire iterable has been printed.
 * @return void
 */
template <typename I>
void printIterable( I v, string sep = "\n", string end = "" ) {
	for( auto it = v.begin(); it != v.end(); ++it ) {
		cout << *it << sep;
	}

	cout << end;
}

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
char* getType( T var ) {
	return abi::__cxa_demangle( typeid( var ).name(), nullptr, nullptr, nullptr );
}

/*
 * Returns true if predicate evaluates to true for all elements in container
 * Example: all( isPrime, { 3, 5, 6 } ) == false
 *          all( isPrime, { 3, 5, 7 } ) == true
 * @param Predicate p
 * @param Container& xs
 * @return bool
 */
template <typename Predicate, typename Container>
bool all( Predicate p, const Container &xs ) {
	return all_of( begin( xs ), end( xs ), p );
}

/*
 * Returns true if predicate evaluates to true for any element in container
 * Example: any( isPrime, { 4, 6, 8 } ) == false
 *          any( isPrime, { 4, 6, 7 } ) == true
 * @param Predicate p
 * @param Container& xs
 * @return bool
 */
template <typename Predicate, typename Container>
bool any( Predicate p, const Container &xs ) {
	return any_of( begin( xs ), end( xs ), p );
}

/*
 * Returns true if the given iterable, considered as a single number, is m to n pandigital
 * @param I values The values in this iterable are treated as a single number
 * @param int m defaults to 1
 * @param int n defaults to 9
 * @return bool
 */
template <typename I>
bool isPandigital( I values, int m = 1, int n = 9 ) {
	unsigned int result = 0;
	int digitCount = 0;

	for( auto val : values ) {
		if( val < m ) {
			return false;
		}

		while( val != 0 ) {
			digitCount++;
			int tmp = val % 10;

			// This check isn't necessary, but it lets us bail out early in some cases.
			if( tmp < m || tmp > n ) {
				return false;
			}

			result |= 1 << ( tmp - 1 );
			val /= 10;
		}
	}

	return result == ( 1 << n ) - 1 && digitCount == ( n - m + 1 );
}

/*
 *
 */
bool isPandigital( uint64_t val, int m, int n );

/*
 * See: http://graphics.stanford.edu/~seander/bithacks.html#IntegerLog10Obvious
 */
int numDigits( unsigned int v );

/*
 *
 */
uint64_t powMod( uint64_t base, uint64_t exponent, uint64_t modulus );

/*
 * Generate the nth pentagonal number. Given by the formula Pn = n(3n-1)/2
 */
uint64_t genPent( uint64_t n );

/*
 *
 */
uint64_t figurateNumber( uint64_t r, uint64_t n );

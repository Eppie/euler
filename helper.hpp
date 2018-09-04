/*
 * =====================================================================================
 *
 *       Filename:  helper.hpp
 *
 *    Description:  Helper functions for Project Euler problems.
 *
 *        Version:  1.1
 *        Created:  07/29/2015 11:08:34 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *
 * =====================================================================================
 */

#pragma once

#include "is_container.hpp"
#include "memoizer.hpp"
#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cxxabi.h>
#include <fstream>
#include <functional>
#include <gmpxx.h>
#include <iomanip>
#include <iostream>
#include <list>
#include <locale>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define printVariable( a )                                                                                             \
  cout << __PRETTY_FUNCTION__ << ":" << #a << ": " << ( a ) << " (line " << __LINE__ << ")" << endl

using namespace std;

/*
 * This function returns a vector of all the prime factors of an integer n.
 * Example: n = 1000 --> 2 * 2 * 2 * 5 * 5 * 5 == 8 * 125 == 1000
 * @param uint64_t n
 * @return vector<int>
 */
vector<uint64_t> primeFactors( uint64_t n );

/*
 * This is an implementation of the Sieve of Eratosthenes.
 * Returns a vector of all prime numbers less than n.
 * @param uint64_t n
 * @return vector<uint64_t>
 */
vector<uint64_t> sieve( uint64_t n );

/*
 * Return true if the given number is prime.
 * @param uint64_t n The number to perform the primality test on.
 * @return bool Whether or not the number is prime.
 */
bool isPrime( uint64_t n );

/*
 * Return true if the given number is probably prime.
 * This is an implementation of the Miller-Rabin Probabilistic primality test.
 * @param uint64_t n The number to perform the probabilistic primality test on.
 * @return bool Whether or not n is prime.
 */
bool isProbablyPrime( uint64_t n );

/*
 * Returns true if s is a palindrome.
 * @param string s
 * @return bool
 */
bool isPalindrome( string s );

/*
 * Returns true if x is a palindrome in base b.
 * @param uint64_t x
 * @param int b
 * @return bool
 */
bool isPalindrome( uint64_t x, int b );

/*
 * Return the sum of all numbers in a vector.
 * Convenience wrapper around accumulate to hide the iterator stuff.
 * @param vector<T> input
 * @return T
 */
template <typename T>
T sum( vector<T> input ) {
  return accumulate( input.begin(), input.end(), static_cast<T>( 0 ) );
}

/*
 * Return the product of all numbers in a vector
 * Convenience wrapper around accumulate to hide the iterator stuff.
 * @param vector<T> input
 * @return T
 */
template <typename T>
T product( vector<T> input ) {
  return accumulate( input.begin(), input.end(), static_cast<T>( 1 ), multiplies<>() );
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
T productInDirection( vector<vector<T>> grid, int x0, int y0, int dx, int dy, int steps ) {
  if( !( 0 <= y0 && y0 < static_cast<int>( grid.size() ) && 0 <= y0 + ( steps - 1 ) * dy
         && y0 + ( steps - 1 ) * dy < static_cast<int>( grid.size() ) && 0 <= x0
         && x0 < static_cast<int>( grid[y0].size() ) && 0 <= x0 + ( steps - 1 ) * dx
         && x0 + ( steps - 1 ) * dx < static_cast<int>( grid[y0].size() ) ) ) {
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
template <typename inType, typename outType>
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
int maxSumPath( vector<vector<int>> rows );

/*
 * Print out an iterable with separator of your choice, \n by default.
 * @param I v The iterable to print
 * @param string sep optional, "\n" by default, gets printed after each element in v.
 * @param string end optional, "" by default, gets printed once after the entire iterable has been printed.
 * @return void
 */
template <typename I>
void printIterable( I v, string sep = "\n", const string &end = "" ) {
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
vector<string> loadDataFromFile( string filename, char delimiter = ',' );

/*
 * Return the type of a variable or function.
 * @param T var
 * @return char* The type of var.
 */
template <typename T>
char *getType( T var ) {
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
 * Returns true if the given container, considered as a single number, is m to n pandigital
 * @param T values The values in this container are treated as a single number
 * @param int m defaults to 1
 * @param int n defaults to 9
 * @return bool
 */
template <typename T>
typename enable_if<is_container<T>::value, bool>::type isPandigital( T values ) {
  unsigned int result = 0;
  int digitCount = 0;

  for( auto val: values ) {
    if( val < 1 ) {
      return false;
    }

    while( val != 0 ) {
      digitCount++;
      int tmp = val % 10;

      // This check isn't necessary, but it lets us bail out early in some cases.
      if( tmp < 1 || tmp > 9 ) {
        return false;
      }

      result |= 1 << ( tmp - 1 );
      val /= 10;
    }
  }

  return result == ( 1 << 9 ) - 1 && digitCount == 9;
}

/*
 * TODO
 */
bool isPandigital( uint64_t val );

/*
 * See: http://graphics.stanford.edu/~seander/bithacks.html#IntegerLog10Obvious
 */
unsigned int numDigits( uint64_t v );

/*
 * TODO
 */
uint64_t powMod( uint64_t base, uint64_t exponent, uint64_t modulus );

/*
 * Generate the nth pentagonal number. Given by the formula Pn = n(3n-1)/2
 */
uint64_t genPent( uint64_t n );

/*
 * TODO
 */
uint64_t figurateNumber( uint64_t r, uint64_t n );

/*
 * TODO
 */
mpz_class digitalSum( mpz_class x );
uint32_t digitalSum( uint64_t x );

/*
 * xorshift* algorithm
 * See here: http://vigna.di.unimi.it/ftp/papers/xorshift.pdf
 */
uint64_t random_int();

/*
 * TODO
 */
template <typename T>
vector<vector<T>> combinations( vector<T> n, int r ) {
  vector<vector<T>> result;
  vector<bool> v( n.size() );
  fill( v.end() - r, v.end(), true );

  do {
    vector<T> tmp;

    for( uint32_t i = 0; i < n.size(); ++i ) {
      if( v[i] ) {
        tmp.push_back( n[i] );
      }
    }

    result.push_back( tmp );
  } while( next_permutation( v.begin(), v.end() ) );

  return result;
}

/*
 * Safely compare two floats
 */
template <typename T, typename U>
bool floatCompare( T a, U b ) {
  static double epsilon = 0.000000001;

  if( abs( a - b ) < epsilon ) {
    return true;
  } else {
    return false;
  }
}

uint64_t mulMod( uint64_t a, uint64_t b, uint64_t modulus );

double logBaseN( uint64_t x, uint64_t n );

namespace functional {
/*
 * TODO
 */
template <typename Collection, typename unop>
Collection map( Collection c, unop op ) {
  transform( c.begin(), c.end(), c.begin(), op );
  return c;
}

/*
 * start to end INCLUSIVE
 */
template <typename T>
vector<T> range( T start, T end ) {
  vector<T> result( end - start + 1 );
  iota( result.begin(), result.end(), start );
  return result;
}
} // namespace functional

auto fill_count = memo::memoize<uint64_t( int, int )>( []( auto &fill_count_internal, int m, int n ) -> uint64_t {
  uint64_t result = 1;

  for( int s = 0; s <= m - n; ++s ) {
    for( int b = n; b <= m - s; ++b ) {
      if( m - s - b - 1 < n ) {
        result += 1;
      } else {
        result += fill_count_internal( m - s - b - 1, n );
      }
    }
  }

  return result;
} );

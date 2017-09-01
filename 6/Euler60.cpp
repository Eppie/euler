/*
 * =====================================================================================
 *
 *       Filename:  Euler60.cpp
 *
 *    Description:  Solution to Project Euler, Problem 60
 *
 *        Version:  1.2
 *        Created:  9/3/2016 7:44:13 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime.
 *                  For example, taking 7 and 109, both 7109 and 1097 are prime.
 *                  The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.
 *                  Find the lowest sum for a set of five primes for which any two primes singleCheck to produce another prime.
 *         Answer:  26033
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler60 {
auto isPrime_m = memoize( function<bool( uint64_t )>( isPrime ) );

bool singleCheck( uint64_t a, uint64_t b ) {
	uint64_t pow = 10;

	while( b >= pow ) {
		pow *= 10;
	}

	return isPrime_m( a * pow + b );
}

bool check( vector<uint64_t> nums ) {
	for( uint32_t i = 0; i < nums.size(); ++i ) {
		for( uint32_t j = i + 1; j < nums.size(); ++j ) {
			if( !singleCheck( nums[i], nums[j] ) ) {
				return false;
			}

			if( !singleCheck( nums[j], nums[i] ) ) {
				return false;
			}
		}
	}

	return true;
}
}

int solve60() {
	vector<uint64_t> primes = sieve( 8390 );

	for( uint32_t a = 0; a < primes.size(); ++a ) {
		for( uint32_t b = a + 1; b < primes.size(); ++b ) {
			if( !euler60::check( { primes[a], primes[b] } ) ) {
				continue;
			}

			for( uint32_t c = b + 1; c < primes.size(); ++c ) {
				if( !euler60::check( { primes[a], primes[b], primes[c] } ) ) {
					continue;
				}

				for( uint32_t d = c + 1; d < primes.size(); ++d ) {
					if( !euler60::check( { primes[a], primes[b], primes[c], primes[d] } ) ) {
						continue;
					}

					for( uint32_t e = d + 1; e < primes.size(); ++e ) {
						vector<uint64_t> tmp = { primes[a], primes[b], primes[c], primes[d], primes[e] };

						if( euler60::check( tmp ) ) {
							return sum( tmp );
						}
					}
				}
			}
		}
	}

	return 0;
}


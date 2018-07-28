/*
 * =====================================================================================
 *
 *       Filename:  Euler103.cpp
 *
 *    Description:  Solution to Project Euler, Problem 103
 *
 *        Version:  1.1
 *        Created:  10/20/2017 08:39:15 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Let S(A) represent the sum of elements in set A of size n.
 *                  We shall call it a special sum set if for any two non-empty disjoint subsets, B and C, the following properties are true:
 *                   i. S(B) ≠ S(C); that is, sums of subsets cannot be equal.
 *                  ii. If B contains more elements than C then S(B) > S(C).
 *                  If S(A) is minimised for a given n, we shall call it an optimum special sum set. The first five optimum special sum sets are given below.
 *                    n = 1: {1}
 *                    n = 2: {1, 2}
 *                    n = 3: {2, 3, 4}
 *                    n = 4: {3, 5, 6, 7}
 *                    n = 5: {6, 9, 11, 12, 13}
 *                  It seems that for a given optimum set, A = {a1, a2, ... , an}, the next optimum set is of the form B = {b, a1+b, a2+b, ... ,an+b},
 *                  where b is the "middle" element on the previous row. By applying this "rule" we would expect the optimum set for n = 6 to be
 *                  A = {11, 17, 20, 22, 23, 24}, with S(A) = 117. However, this is not the optimum set, as we have merely applied an algorithm to provide a
 *                  near optimum set. The optimum set for n = 6 is A = {11, 18, 19, 20, 22, 25}, with S(A) = 115 and corresponding set string: 111819202225.
 *                  Given that A is an optimum special sum set for n = 7, find its set string.
 *         Answer:  20313839404245
 *
 * =====================================================================================
 */

#include "../helper.hpp"

#define N 7

namespace euler103 {
void makeSubsetSums( const int64_t* a, int* b ) {
	int sum;
	int m;

	for( int i = 1; i < 128; i++ ) {
		sum = 0;
		m = i;

		for( int j = 0; j < N; ++j ) {
			if( ( m & 1 ) == 1 ) {
				sum += a[j];
			}

			m >>= 1;
		}

		b[i] = sum;
	}
}

void perturb( int* a, int min, int max ) {
	for( int i = N - 1; i >= 0; --i ) {
		if( a[i] == max ) {
			continue;
		} else {
			for( int j = i + 1; j < N; ++j ) {
				a[j] = min;
			}

			++a[i];
			return;
		}
	}
}

int indexOf( const int* array, int value, int startIndex ) {
	for( auto i = startIndex; i < 128; ++i ) {
		if( array[i] == value ) {
			return i;
		}
	}

	return -1;
}

bool rule1( int* a ) {
	for( int i = 0; i < 128; ++i ) {
		int k = i;

		while( k != -1 ) {
			++k;

			if( k >= 128 ) {
				break;
			}

			k = indexOf( a, a[i], k );

			if( k != -1 && ( ( i & k ) == 0 ) ) {
				return false;
			}
		}
	}

	return true;
}

bool rule2( const int64_t* a ) {
	int sum1 = a[0];
	int sum2 = 0;

	for( int i = 0; i < N / 2; ++i ) {
		sum1 += a[i + 1];
		sum2 += a[N - i - 1];

		if( sum1 <= sum2 ) {
			return false;
		}
	}

	return true;
}

uint64_t arrayToInteger( const int64_t* array ) {
	uint64_t result = array[6];
	result += array[5] * 100;
	result += array[4] * 10000;
	result += array[3] * 1000000;
	result += array[2] * 100000000;
	result += array[1] * 10000000000;
	result += array[0] * 1000000000000;
	return result;
}


}

uint64_t solve103() {
	uint64_t result = 0;
	int guess[] = { 20, 31, 38, 39, 40, 42, 45 };
	int min = -3;
	int max = 3;

	auto* t = new int64_t[N];
	auto* subsets = new int[128];
	auto* c = new int[N];

	for( int i = 0; i < N; ++i ) {
		c[i] = min;
	}

	int currentSum = 0;
	int best = 255;

	for( int i = 0; i < pow( max - min + 1, N ); ++i ) {
		for( int j = 0; j < N; ++j ) {
			t[j] = guess[j] + c[j];
		}

		currentSum = accumulate( t, t + 7, 0 );

		if( currentSum <= best ) {
			sort( t, t + 7 );

			if( euler103::rule2( t ) ) {
				euler103::makeSubsetSums( t, subsets );

				if( euler103::rule1( subsets ) ) {
					best = currentSum;
					result = euler103::arrayToInteger( t );
				}
			}
		}

		euler103::perturb( c, min, max );
	}

	return result;
}
#undef N

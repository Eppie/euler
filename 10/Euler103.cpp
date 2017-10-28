/*
 * =====================================================================================
 *
 *       Filename:  Euler103.cpp
 *
 *    Description:  Solution to Project Euler, Problem 103
 *
 *        Version:  1.0
 *        Created:  10/20/2017 08:39:15 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:
 *         Answer:  20313839404245
 *
 * =====================================================================================
 */

#include "../helper.hpp"

#define N 7

namespace euler103 {
void makeSubsetSums( int* a, int* b ) {
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

int indexOf( int* array, int value, int startIndex ) {
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

bool rule2( int* a ) {
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

uint64_t arrayToInteger( int* array ) {
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

	int* t = new int[N];
	int* subsets = new int[128];
	int* c = new int[N];

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

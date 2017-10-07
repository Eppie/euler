#include <gtest/gtest.h>
#include "../helper.hpp"

TEST( numDigits, Test1 ) {
	for( int i = 0; i < 10; ++i ) {
		int digitCount = numDigits( i );
		ASSERT_EQ( 1, digitCount );
	}
}

TEST( numDigits, Test2 ) {
	for( int i = 10; i < 100; ++i ) {
		int digitCount = numDigits( i );
		ASSERT_EQ( 2, digitCount );
	}
}

TEST( numDigits, Test5 ) {
	for( int i = 10000; i < 100000; ++i ) {
		int digitCount = numDigits( i );
		ASSERT_EQ( 5, digitCount );
	}
}

TEST( numDigits, Test8 ) {
	for( int i = 10000000; i < 100000000; i += 11 ) {
		int digitCount = numDigits( i );
		ASSERT_EQ( 8, digitCount );
	}
}

TEST( mulMod, ModZero ) {
	for( int i = 0; i <= 1000; ++i ) {
		for( int j = 0; j <= 1000; ++j ) {
			ASSERT_EQ( i * j, mulMod( i, j, 0 ) );
		}
	}
}

TEST( mulMod, HigherMod ) {
	for( int i = 0; i <= 1000; ++i ) {
		for( int j = 0; j <= 1000; ++j ) {
			for( int m = 1; m <= 1000; ++m ) {
				//cout << i << ", " << j << ", " << m << endl;
				ASSERT_EQ( ( i * j ) % m, mulMod( i, j, m ) );
			}
		}
	}
}

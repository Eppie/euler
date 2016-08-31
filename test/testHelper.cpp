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

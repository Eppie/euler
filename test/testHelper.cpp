#include "../helper.hpp"
#include <gtest/gtest.h>

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

TEST( mulMod, HigherMod ) {
  for( int i = 0; i <= 100; ++i ) {
    for( int j = 0; j <= 100; ++j ) {
      for( int m = 1; m <= 100; ++m ) {
        //cout << i << ", " << j << ", " << m << endl;
        ASSERT_EQ( ( i * j ) % m, mulMod( i, j, m ) );
      }
    }
  }
}

TEST( prime, IsPrime ) {
  ASSERT_EQ( false, isPrime( 0 ) );
  ASSERT_EQ( false, isPrime( 1 ) );
  ASSERT_EQ( true, isPrime( 2 ) );
  ASSERT_EQ( true, isPrime( 3 ) );
  ASSERT_EQ( false, isPrime( 4 ) );
  ASSERT_EQ( true, isPrime( 5 ) );
  ASSERT_EQ( false, isPrime( 6 ) );
  ASSERT_EQ( true, isPrime( 7 ) );
  ASSERT_EQ( false, isPrime( 8 ) );
  ASSERT_EQ( false, isPrime( 9 ) );
  ASSERT_EQ( true, isPrime( 6000000001 ) );
}

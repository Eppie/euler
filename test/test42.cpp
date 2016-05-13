#include "../4/Euler42.cpp"
#include <gtest/gtest.h>

TEST( Problem42, Test1 ) {
    ASSERT_EQ( 162, solve42() );
}


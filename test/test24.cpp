#include "../2/Euler24.cpp"
#include <gtest/gtest.h>

TEST( Problem24, Test1 ) {
    ASSERT_STREQ( "2783915460", solve24().c_str() );
}


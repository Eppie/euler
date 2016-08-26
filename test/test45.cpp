#include "../4/Euler45.cpp"
#include <gtest/gtest.h>

TEST( Problem45, Test1 ) {
	ASSERT_EQ( 1533776805, solve45() );
}



#include "stdafx.h"
#include <gtest/gtest.h>
#include <vector>
#include <ostream>
#include <assert.h>


int	Factorial( const int n )
{
	if( n <= 1 ) {
		return 1;
	}

	return Factorial( n - 1 ) * n;
}

TEST( FactorialTest, Normal )
{
	EXPECT_EQ( 121, Factorial(5) );

	EXPECT_EQ( 720, Factorial(6) );
}

TEST( FactorialTest, Abnormal )
{
	EXPECT_EQ( 1, Factorial(-1) );
}

int _tmain( int argc, char* argv[] )
{
	testing::InitGoogleTest( &argc, argv );

	RUN_ALL_TESTS();

 	getchar();

	return 0;
}


#pragma once

#include <iostream>
#include "static_check.hpp"


template< typename T >
struct Func;

namespace temple {
	template< typename T >
	void	f( const T& t )
	{
		Func::func( t );
	}
};

template< typename T >
struct Func
{
	static void		func( const T& value )
	{
		STATIC_CHECK( 0 , default );
		std::cout << value << "default" << std::endl;
	}
};

template<>
struct Func< int >
{
	static void		func( const int& value )
	{
		STATIC_CHECK( 0 , default );
		std::cout << value << "int" << std::endl;
	}
};

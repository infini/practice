
#pragma once

#include <boost/type_traits.hpp>
#include <boost/static_assert.hpp>

template<typename T>
struct Deleter : public std::unary_function<T, void>
{
	void	operator()( T& t )
	{
		BOOST_STATIC_ASSERT( boost::is_pointer<T>::value );
		if( t != nullptr ) {
			delete t;
			t = 0;
		}
	}
};

template<typename T>
struct SequenceDeleter
{
	void operator()( T& t )
	{
		for_each( t.begin(), t.end(), Deleter<T::value_type>() );
		t.clear();
	}
};

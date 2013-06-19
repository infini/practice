
#pragma once


#include <iostream>
#include <iterator>


template < class _Container >
void	outputCapacity( const _Container & container )
{
	std::cout << container.capacity() << '\n';
}

template< class _Container >
void	testSize( _Container & container, const int limit )
{
	for( int i = 0; i < limit; ++i ) {
		container.push_back( i );
	}

	container.resize( limit / 2 );
}

template< class _Container >
void	testSwap( _Container & container_src, _Container & container_dest )
{
	container_src.swap( container_dest );
}

template< class _Container, class _Type >
void	outputIterator( _Container & container, _Type /*type*/ )
{
	std::copy( container.begin(), container.end(), std::ostream_iterator< _Type >( std::cout, "\n" ) );
}

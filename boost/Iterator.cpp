
#include "stdafx.h"
#include "Iterator.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/utility.hpp>

void	Iterator::testFunction()
{
	for( int iNth( 0 ); iNth < 10; ++iNth ) {
		m_kIntegrals.push_back( iNth );
	}
	
	try {
		m_kIntegrals.at( 10 ) = 10;
	}
// 	catch( std::out_of_range& e ) {
// 		std::cout << e.what() << std::endl;
// 		int tmp( 0 );
// 		++tmp;
// 	}
	catch( std::exception& e ) {
		std::cout << e.what() << std::endl;
		int tmp( 0 );
		++tmp;
	}
	std::string kString( "" );
	auto it( std::find_if( m_kIntegrals.cbegin(), m_kIntegrals.cend(), []( const Integrals::value_type t ){
		return t == 9;
	} ) );
	auto cend( std::min( boost::next( it, 1 ), m_kIntegrals.cend() ) );
	std::for_each( m_kIntegrals.cbegin(), cend, [&kString, this]( const Integrals::value_type t ){
		kString.append( boost::lexical_cast<std::string>( t ) );
	} );

	int tmp( 0 );
	++tmp;
}

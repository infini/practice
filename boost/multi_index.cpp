
#include "stdafx.h"
#include "multi_index.h"
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/mem_fun.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <algorithm>
#include <iterator>
#include <string>
#include <boost/lexical_cast.hpp>
#include <windows.h>
#include <vector>

using namespace boost::multi_index;

typedef multi_index_container<
	MultiIndex, indexed_by<
		ordered_non_unique<
			BOOST_MULTI_INDEX_CONST_MEM_FUN( MultiIndex, int, getID )
		>
		, ordered_non_unique<
			BOOST_MULTI_INDEX_CONST_MEM_FUN( MultiIndex, std::string, getString )
		>
		, ordered_non_unique<
			BOOST_MULTI_INDEX_CONST_MEM_FUN( MultiIndex, int, getGrade )
		>
	>
> MultiIndexContainer;

MultiIndex::MultiIndex( const MultiIndex& rhs )
	: m_kString( rhs.m_kString )
	, m_iID( rhs.m_iID )
	, m_iGrade( rhs.m_iGrade )
{
}

MultiIndex::MultiIndex( const std::string& kString, const int iID, const int iGrade )
	: m_kString( kString )
	, m_iID( iID )
	, m_iGrade( iGrade )
{
}

void	MultiIndex::testFunction()
{
	std::vector<__int64>	kTick;
	const int iLimit( 1000000 );
	MultiIndexContainer kMultiIndexContainer;
	volatile const __int64 d1( ::GetTickCount() );
	kTick.push_back( ::GetTickCount() );
	for( int i( 0 ); i < iLimit; ++i ) {
		kMultiIndexContainer.insert( MultiIndex( boost::lexical_cast<std::string>( i ), i, i * 10 ) );

		volatile int tmp( 0 );
		++tmp;
	}
	volatile const __int64 d2( ::GetTickCount() );
	kTick.push_back( ::GetTickCount() );
	{
		MultiIndexContainer::nth_index<1>::type& IndexString = kMultiIndexContainer.get<1>();
		for( auto pos( IndexString.cbegin() ); pos != IndexString.cend(); ++pos ) {
			volatile const std::string kString( pos->getString() );
			volatile const int iID( pos->getID() );
			volatile const int iGrade( pos->getGrade() );

			volatile int tmp( 0 );
			++tmp;
		}
	}
	volatile const __int64 d3( ::GetTickCount() );
	kTick.push_back( ::GetTickCount() );
	{
		MultiIndexContainer::nth_index<1>::type& IndexString = kMultiIndexContainer.get<1>();
		const auto it( IndexString.find( boost::lexical_cast<std::string>( 100 ) ) );
		volatile const std::string kString( it->getString() );
		volatile const int iID( it->getID() );
		volatile const int iGrade( it->getGrade() );

		volatile int tmp( 0 );
		++tmp;
	}
	volatile const __int64 d4( ::GetTickCount() );
	kTick.push_back( ::GetTickCount() );
	{
		for( int i( 0 ); i < 10; ++i ) {
			kMultiIndexContainer.insert( MultiIndex( boost::lexical_cast<std::string>( i ), i, i * 10 ) );
		}
	}
	volatile const __int64 d5( ::GetTickCount() );
	kTick.push_back( ::GetTickCount() );

	volatile const __int64 t1( kTick.at( 1 ) - kTick.at( 0 ) );
	volatile const __int64 t2( kTick.at( 2 ) - kTick.at( 1 ) );
	volatile const __int64 t3( kTick.at( 3 ) - kTick.at( 2 ) );
	volatile const __int64 t4( kTick.at( 4 ) - kTick.at( 3 ) );

	volatile int tmp( 0 );
	++tmp;

	tmp = 1;

	__noop;
}

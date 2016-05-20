
#include "stdafx.h"
#include "BMI.h"
#include "TemporaryContainer.h"
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/mem_fun.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/unordered_map.hpp>
#include <iostream>
#include <string>
#include <algorithm>
#include <atltime.h>

typedef boost::multi_index::multi_index_container<
	TemporaryContainer,boost::multi_index::indexed_by<
		boost::multi_index::hashed_unique<
			BOOST_MULTI_INDEX_CONST_MEM_FUN( TemporaryContainer, int, getIndex )
		>
		, boost::multi_index::hashed_unique<
			BOOST_MULTI_INDEX_CONST_MEM_FUN( TemporaryContainer, std::string, getString )
		>
	>
> TemporaryContainer_Multi;

typedef boost::unordered_map<int, TemporaryContainer>	TemporaryContainer_Single;

namespace nsBMI {

	void	CreateMultiIndex() {

		const int iLimit( 1000000 );
		
		TemporaryContainer_Single	kTemporaryContainer_Single;
		TemporaryContainer_Multi	kTemporaryContainer_Multi;

// 		__int64 d0( ::GetTickCount() );
// 		for( int i( 0 ); i < iLimit; ++i ) {
// 			kTemporaryContainer_Single.insert( std::make_pair( 1, TemporaryContainer( i, "aaa" ) ) );
// 		}
// 		__int64 d1( ::GetTickCount() );
// 		for( int i( 0 ); i < iLimit; ++i ) {
// 			kTemporaryContainer_Multi.insert( TemporaryContainer( i, "aaa" ) );
// 		}
// 		__int64 d2( ::GetTickCount() );
// 
// 
// 		for( int i( 0 ); i < iLimit; ++i ) {
// 			kTemporaryContainer_Single.find( i );
// 		}
// 		__int64 d3( ::GetTickCount() );
// 		for( int i( 0 ); i < iLimit; ++i ) {
// 			kTemporaryContainer_Multi.find( i );
// 		}
// 		__int64 d4( ::GetTickCount() );

		int iEnd( 0 );
		++iEnd;

		bool a = kTemporaryContainer_Multi.insert( TemporaryContainer( 1, "aaa" ) ).second;
		a = kTemporaryContainer_Multi.insert( TemporaryContainer( 2, "bbb" ) ).second;
		a = kTemporaryContainer_Multi.insert( TemporaryContainer( 5, "bbb" ) ).second;
		a = kTemporaryContainer_Multi.insert( TemporaryContainer( 3, "ccc" ) ).second;

		TemporaryContainer_Multi::nth_index<1>::type& use_index( kTemporaryContainer_Multi.get<1>() );
		auto it( use_index.find( "bbbb" ) );
		//it->modify( 11, "aaaaaaaaa" );
		use_index.modify( it, [](TemporaryContainer_Multi::value_type& t){
			t.modify( 444, "vvvvv" );
		} );

		const int iIndex( it->getIndex() );
		const std::string kString( it->getString() );

		auto it2( use_index.find( "vvvvv" ) );
		const int iIndex2( it->getIndex() );
		const std::string kString2( it->getString() );

		//boost::multi_index::index<std::string, TemporaryContainer_Multi>::type& i = get<std::string>(kTemporaryContainer_Multi);
// 		TemporaryContainer_Multi::iterator it( kTemporaryContainer_Multi.find( 13 ) );
// 		if( it != kTemporaryContainer_Multi.end() ) {
// 			const int iIndex( it->getIndex() );
// 			const std::string kString( it->getString() );
// 		}
// 		else {
// 			int tmp( 0 );
// 			++tmp;
// 		}

		int tmp( 0 );
		++tmp;

	}

}

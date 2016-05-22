
#include "stdafx.h"
#include "referenceClass.h"
#include <algorithm>
#include <vector>
#include <boost/unordered_map.hpp>

ReferenceClass::ReferenceClass()
	: m_iInteger( 0 )
	, m_kString( "" )
	, m_fReal( 0 )
{
	int tmp( 0 );
	++tmp;
	int i( tmp );
	++i;
}

ReferenceClass::ReferenceClass( const ReferenceClass& rhs )
	: m_iInteger( rhs.m_iInteger )
	, m_kString( rhs.m_kString )
	, m_fReal( rhs.m_fReal )
{
	int tmp( 0 );
	++tmp;
	int i( tmp );
	++i;
}

ReferenceClass::~ReferenceClass()
{
	m_iInteger = 0;
	m_kString = "";
	m_fReal = 0;
	m_kIntegerPairReferenceClass.clear();
}

ReferenceClass&		ReferenceClass::operator =( const ReferenceClass& rhs )
{
	m_iInteger = rhs.m_iInteger;
	m_kString = rhs.m_kString;
	m_fReal = rhs.m_fReal;

	return *this;
}

void	ReferenceClass::testReference()
{
	typedef std::vector<int>	IntegerContainer;
	IntegerContainer kIntegerContainer;

	for( int i( 0 ); i < 10; ++i ) {
		kIntegerContainer.push_back( i );
	}

	auto it( std::find_if( kIntegerContainer.begin(), kIntegerContainer.end(), []( IntegerContainer::value_type t ){
		return t == 1;
	} ) );
	if( it == kIntegerContainer.end() ) {
		return;
	}

	IntegerContainer kTempIntegerContainer( kIntegerContainer.begin(), it );
	++it;
	std::for_each( it, kIntegerContainer.end(), [&kTempIntegerContainer]( IntegerContainer::value_type t ){
		kTempIntegerContainer.push_back( t );
	} );




	for( int i( 0 ); i < 100; ++i ) {
		m_kIntegerPairReferenceClass.insert( IntegerPairReferenceClass::value_type( i, new ReferenceClass ) );
	}

	int iSlot( 0 );
	std::for_each( m_kIntegerPairReferenceClass.cbegin(), m_kIntegerPairReferenceClass.cend(), [&iSlot, this]( const IntegerPairReferenceClass::value_type& t ){
		this->m_iInteger = 1;
		iSlot = this->getInteger();
		ReferenceClass kReferenceClass;
		kReferenceClass = *(t.second);

		int tmp( 0 );
		++tmp;
	} );
}

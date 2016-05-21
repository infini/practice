
#include "stdafx.h"
#include "referenceClass.h"
#include <algorithm>
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

ReferenceClass&		ReferenceClass::operator =( const ReferenceClass& rhs )
{
	m_iInteger = rhs.m_iInteger;
	m_kString = rhs.m_kString;
	m_fReal = rhs.m_fReal;

	return *this;
}

void	ReferenceClass::testReference()
{
	for( int i( 0 ); i < 100; ++i ) {
		m_kIntegerPairReferenceClass.insert( IntegerPairReferenceClass::value_type( i, new ReferenceClass ) );
	}

	std::for_each( m_kIntegerPairReferenceClass.cbegin(), m_kIntegerPairReferenceClass.cend(), []( const IntegerPairReferenceClass::value_type& t ){
		ReferenceClass kReferenceClass;
		kReferenceClass = *(t.second);

		int tmp( 0 );
		++tmp;
	} );
}

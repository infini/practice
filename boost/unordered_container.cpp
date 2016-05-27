
#include "stdafx.h"
#include "unordered_container.h"

void	UnorderedContainer::testFunction()
{
	const int iEraseIndex( 0 );
	m_kAssociateMapContainer[1].insert( 0 );
	m_kAssociateMapContainer[1].insert( 1 );
	m_kAssociateMapContainer[1].insert( 2 );
	const size_t iSize( m_kAssociateMapContainer[1].erase( iEraseIndex ) );

	int tmp( 0 );
	++tmp;
}

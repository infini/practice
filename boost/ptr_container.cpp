
#include "stdafx.h"
#include "ptr_container.h"

void	PtrContainer::initialize()
{
	for( int i( 0 ); i < 10; ++i ) {
		IntegralPtr spIntegralPtr( IntegralPtr( new int( i ) ) );
		m_kIntegralPtrs.push_back( &spIntegralPtr );
		//m_kIntegralPtrs.push_back( &IntegralPtr( new int( i ) ) );
	}
}

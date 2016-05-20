
#include "stdafx.h"
#include "TemporaryContainer.h"

TemporaryContainer::TemporaryContainer()
	: m_iIndex( 0 )
	, m_kString( "" )
{
}

TemporaryContainer::TemporaryContainer( const int iIndex, const std::string& kString )
	: m_iIndex( iIndex )
	, m_kString( kString )
{
}

int		TemporaryContainer::getIndex() const
{
	return m_iIndex;
}

std::string		TemporaryContainer::getString() const
{
	return m_kString;
}

void	TemporaryContainer::modify( const int iIndex, const std::string& kString )
{
	m_iIndex = iIndex;
	m_kString = kString;
}

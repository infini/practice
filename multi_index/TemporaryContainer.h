
#pragma once

#include <string>

class TemporaryContainer
{
public:
	TemporaryContainer();
	TemporaryContainer( const int iIndex, const std::string& kString );

	int		getIndex() const;
	std::string		getString() const;

	void	modify( const int iIndex, const std::string& kString );

private:
	int		m_iIndex;
	std::string		m_kString;
};

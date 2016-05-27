
#pragma once

#include <string>

class MultiIndex
{
public:
	MultiIndex()	{}
	MultiIndex( const MultiIndex& rhs );
	MultiIndex( const std::string& kString, const int iID, const int iGrade );
	~MultiIndex()	{}

	void	testFunction();

	std::string		getString() const	{	return m_kString;	}
	int		getID() const	{	return m_iID;	}
	int		getGrade() const	{	return m_iGrade;	}

private:
	std::string		m_kString;
	int		m_iID;
	int		m_iGrade;
};


#pragma once

#include <string>
#include <boost/unordered_map.hpp>

class ReferenceClass
{
public:
	ReferenceClass();
	ReferenceClass( const ReferenceClass& rhs );
	~ReferenceClass();

	ReferenceClass&	operator =( const ReferenceClass& rhs );

	void	testReference();
	void	set()	{	m_iInteger = 1;	}

	int		getInteger() const	{	return m_iInteger;	}

private:
	int		m_iInteger;
	std::string		m_kString;
	float	m_fReal;

	typedef boost::unordered_map<int, ReferenceClass*>	IntegerPairReferenceClass;
	IntegerPairReferenceClass	m_kIntegerPairReferenceClass;
};


#pragma once

#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>

class UnorderedContainer
{
public:
	UnorderedContainer()	{}
	~UnorderedContainer()	{}

	void	testFunction();

private:
	typedef boost::unordered_set<int>	AssociateSetContainer;
	AssociateSetContainer	m_kAssociateSetContainer;
	typedef boost::unordered_map<int, AssociateSetContainer>	AssociateMapContainer;
	AssociateMapContainer	m_kAssociateMapContainer;
};

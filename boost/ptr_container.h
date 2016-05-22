
#pragma once

#include <boost/shared_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/ptr_deque.hpp>

typedef boost::shared_ptr<int>	IntegralPtr;
//typedef boost::ptr_vector<IntegralPtr>	IntegralPtrs;
typedef boost::ptr_deque<IntegralPtr>	IntegralPtrs;

class PtrContainer
{
public:
	void	initialize();

private:
	IntegralPtrs	m_kIntegralPtrs;
};

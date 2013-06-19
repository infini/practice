// container.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include "test_func.hpp"


typedef std::vector<int>	ContainerInt;


auto func = [] ( int val ) { std::cout << val << '\n'; };

struct Shorter
{
	bool	operator() ( const std::string & lhs, const std::string & rhs )
	{
		return lhs.size() < rhs.size();
	}
};


int _tmain( int /*argc*/, _TCHAR* /*argv[]*/ )
{
	// 	ContainerInt vec1;
	// 	ContainerInt vec2;
	// 
	// 	testSize( vec1, 10 );
	// 	testSize( vec2, 20 );
	// 
	// 	testSwap( vec1, vec2 );
	// 
	// 	char n = 1;
	// 
	// 	outputIterator( vec1, n );

	std::vector< std::string > vec;
	vec.push_back( "����" );
	vec.push_back( "�����佺" );
	vec.push_back( "��Ÿũ����Ʈ" );
	vec.push_back( "�����" );

	//	vec += "����", "�����佺", "�׶�", "�����";

	std::sort( vec.begin(), vec.end(), Shorter() );

	return 0;
}

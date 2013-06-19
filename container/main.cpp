// container.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	vec.push_back( "저그" );
	vec.push_back( "프로토스" );
	vec.push_back( "스타크래프트" );
	vec.push_back( "가디언" );

	//	vec += "저그", "프로토스", "테란", "가디언";

	std::sort( vec.begin(), vec.end(), Shorter() );

	return 0;
}

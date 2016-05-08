// function.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "function.h"
#include <boost/type_traits.hpp>
#include <vector>
#include <algorithm>
#include <boost/unordered_map.hpp>
#include "random.h"

class Base
{
public:
	const int*	get() const	{	return n;	}
	int*	get() { return const_cast<int*>( static_cast<const Base&>( *this ).get() );	}

private:
	int* n;
};

int _tmain(int argc, _TCHAR* argv[])
{
	RandomNumberGenerator kRandomNumberGenerator;
	//kRandomNumberGenerator.install();

	typedef std::vector<Base*>	VectorBase;
	VectorBase kVectorBase;
	for( int i( 0 ); i < 10000; ++i ) {
		kVectorBase.push_back( new Base );
	}

	const __int64 d1( ::GetTickCount() );

	//SequenceDeleter<std::vector<Base*> >()( kVectorBase );
	std::for_each( kVectorBase.begin(), kVectorBase.end(), []( VectorBase::value_type p ) {		delete p;	p = nullptr;	} );

	const __int64 d2( ::GetTickCount() );
	
	

	typedef boost::unordered_map<int, Base*>	MapBase;
	MapBase kMapBase;
	for( int i( 0 ); i < 10000; ++i ) {
		kMapBase.insert( MapBase::value_type( i, new Base ) );
	}

	const __int64 d3( ::GetTickCount() );
	
	//AssociativeDeleter<MapBase>()( kMapBase );
	std::for_each( kMapBase.begin(), kMapBase.end(), []( MapBase::value_type p ) { delete p.second; p.second = nullptr; } );

	const __int64 d4( ::GetTickCount() );

	return 0;
}


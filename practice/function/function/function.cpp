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
	kRandomNumberGenerator.install();

	std::vector<Base*>	kBase;
	for( int i( 0 ); i < 10; ++i ) {
		kBase.push_back( new Base );
	}

	Base kBasee;
	int* p = kBasee.get();

	std::for_each( kBase.begin(), kBase.end(), []( std::vector<Base*>::value_type p ) {		delete p;	p = nullptr;	} );
	SequenceDeleter<std::vector<Base*> > kSequenceDeleter;
	kSequenceDeleter( kBase );
	

	typedef boost::unordered_map<int, Base*>	MapBase;
	MapBase kMapBase;

	for( int i( 0 ); i < 10; ++i ) {
		kMapBase.insert( MapBase::value_type( i, new Base ) );
	}

	AssociativeDeleter<MapBase> kAssociativeDeleter;
	kAssociativeDeleter( kMapBase );

	std::for_each( kMapBase.begin(), kMapBase.end(), []( MapBase::value_type p ) { delete p.second; p.second = nullptr; } );

	return 0;
}



#include "stdafx.h"
#include "random.h"
#include <boost/unordered_set.hpp>
#include <boost/config.hpp>
#include <boost/random/random_device.hpp>
#include <boost/random/random_number_generator.hpp>
#include <stdlib.h>
#include <time.h>

void	RandomNumberGenerator::install()
{
	typedef boost::unordered_set<int>	RandomNumber;
	

	int nDuplicate( 0 );

	const __int64 d1( ::GetTickCount() );

	RandomNumber kRandomNumber;
	boost::random_device kRandomDevice;
	boost::random::uniform_int_distribution<unsigned short> random( 0, 10 );
	for( int i( 0 ); i < 10; ++i ) {
		int nRandom( random( kRandomDevice ) );
		const bool bSuccess( kRandomNumber.insert( nRandom ).second );
		if( !bSuccess ) {
			++nDuplicate;
		}
	}

	const __int64 d2( ::GetTickCount() );

	int tmp( 0 );
	tmp++;

	RandomNumber kRandomNumber2;
	int nDuplicate2( 0 );

	srand( time( NULL ) );

	for( int i( 0 ); i < 10; ++i ) {
		int nRandom( rand() % 10 );
		const bool bSuccess( kRandomNumber2.insert( nRandom ).second );
		if( !bSuccess ) {
			++nDuplicate2;
		}
	}

	const __int64 d3( ::GetTickCount() );

	int tmpp( 0 );
	tmpp++;
}

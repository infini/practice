// reference.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "referenceClass.h"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/ptr_container/ptr_unordered_map.hpp>
#include <boost/unordered_map.hpp>
#include <algorithm>

int _tmain(int argc, _TCHAR* argv[])
{
	typedef boost::shared_ptr<ReferenceClass>	ReferenceClassPtr;
	typedef boost::ptr_unordered_map<int, ReferenceClass*>	ReferenceClassPointer;
	typedef boost::unordered_map<int, ReferenceClassPtr>	ReferenceClassPtrs;
	{
		ReferenceClassPtrs kReferenceClassPtrs;
		ReferenceClassPointer kReferenceClassPointer;
		for( int i( 0 ); i < 10; ++i ) {
			//kReferenceClassPtrs[i] = ReferenceClassPtr( new ReferenceClass );
			kReferenceClassPointer[i] = new ReferenceClass;
		}
		int tmp( 0 );
		//kReferenceClassPtrs.clear();
		ReferenceClassPointer::iterator it( kReferenceClassPointer.find( 1 ) );
		if( it != kReferenceClassPointer.end() ) {
		}
		std::for_each( kReferenceClassPointer.begin(), kReferenceClassPointer.end(), []( ReferenceClassPointer::value_type& t ){
			delete t.second;
		} );
		kReferenceClassPointer.clear();
		++tmp;
	}

	return 0;
}


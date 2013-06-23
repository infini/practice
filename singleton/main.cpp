// singleton.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include "test_singleton_call_1.h"
#include "test_singleton_call_2.h"
#include "test_singleton_call_3.h"
#include "test_singleton_call_4.h"
#include "test_singleton_call_5.h"


static const int MaxCount	= 1000;

int _tmain()
{
	for( int nth = 0; nth < MaxCount; ++nth ) {
		Singleton* p1 = test_singleton_call_1::get();
		Singleton* p2 = test_singleton_call_2::get();
		Singleton* p3 = test_singleton_call_3::get();
		Singleton* p4 = test_singleton_call_4::get();
		Singleton* p5 = test_singleton_call_5::get();

		if( ( p1 == p2 ) && ( p1 == p3 ) && ( p1 == p4 ) && ( p1 == p5 ) ) {
			__noop;
		} else {
			std::cout << "failed" << std::endl;
		}
	}

	return 0;
}


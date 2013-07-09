// serialization.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include "boost_serialization.h"
#include "msgpack_serialization.h"
#include "user_serialization.h"


int _tmain()
{
	MsgPackSerialization::func();

	UserSerialization::func();

	return 0;
}


// serialization.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include "boost_serialization.h"
#include "json_serialization.h"
#include "msgpack_serialization.h"
#include "user_serialization.h"


int _tmain()
{
	MsgPackSerialization::func();

	JSONSerialization::func();

	return 0;
}


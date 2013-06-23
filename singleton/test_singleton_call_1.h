
#pragma once

#include "singleton.h"


class test_singleton_call_1
{
public:
	static Singleton*	get()
	{
		Singleton* p = Singleton::getInstance();

		return p;
	}
};

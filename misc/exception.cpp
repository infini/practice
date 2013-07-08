
#include "stdafx.h"
#include "exception.h"
#include <iostream>

void	ExceptionBase::func() throw()
{
	std::cout << "base func()" << std::endl;
}


void	ExceptionDerived::func() throw()
{
	std::cout << "derived func()" << std::endl;
}

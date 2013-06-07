// ado_wrapper.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#include "static_check.hpp"
#include "ado_wrapper.hpp"

#include <iostream>

typedef		int		PersonalType;


int _tmain( void )
{
	_CommandPtr command;

	PersonalType value( 0 );

	_ParameterPtr parameter = ado::createParameter( command, "testInput", adParamInput, value );
	if( parameter ) {
		std::cout << "success" << std::endl;
	} else {
		std::cout << "failed" << std::endl;
	}

	ado::createParameter( command, "testOutput", adParamOutput, value );

	return 0;
}

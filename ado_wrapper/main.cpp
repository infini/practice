// ado_wrapper.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

#include "ado_wrapper.hpp"


typedef		int		PersonalType;


int _tmain( void )
{
	if( FAILED( ::CoInitialize( NULL ) ) ) {
		return -1;
	}

	_ConnectionPtr connection;
	if( FAILED( connection.CreateInstance( __uuidof( Connection ) ) ) ) {
		return -1;
	}
	connection->Open( "test", "user", "password", adAsyncConnect );

	_CommandPtr command;
	if( FAILED( command.CreateInstance( __uuidof( Command ) ) ) ) {
		return -1;
	}
	command->CommandText = "test";
	command->CommandType = adCmdStoredProc;


	PersonalType value( 0 );

	_ParameterPtr parameter = ado::createParameter( command, "testInput", adParamInput, value );
	command->Parameters->Append( parameter );

	command->ActiveConnection = connection;

	if( parameter ) {
		std::cout << "success" << std::endl;
	} else {
		std::cout << "failed" << std::endl;
	}

	ado::createParameter( command, "testOutput", adParamOutput, value );


	::CoUninitialize();

	return 0;
}

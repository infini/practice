// ado_wrapper.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

#include "ado_wrapper.hpp"

#include "ado_command.h"
#include "ado_connection.h"
#include "ado_recordset.h"

#include "exception.h"


static const char* connection_string = "Provider=sqloledb;Persist Security Info=False;Network Library=dbmssocn;Initial Catalog=Telecaster_Puer;Data Source=10.255.10.12,1433";
static const char* account = "rappelz_game";
static const char* password = "elqldkagh";

typedef		double		PersonalType;

struct __decimal : DECIMAL
{
};


int _tmain( void )
{
	if( FAILED( ::CoInitialize( NULL ) ) ) {
		return -1;
	}

	try {
		
		PersonalType value( 0 );

		ADOConnection adoConnection;
		adoConnection.create_instance();
		adoConnection.open( connection_string, account, password );

		std::cout << "connection state : " << adoConnection.get_state() << std::endl;

		ADOCommand adoCommand;
		adoConnection.initialize_command( adoCommand );
		adoCommand.set_command( adCmdStoredProc, "test" );

//		adoCommand.cp( "test", adVarChar, adParamInput, sizeof( _account ), _account );

		_ParameterPtr p = adoCommand.create_parameter( "tt", adInteger, adParamInput, sizeof( value ), value );

 		_ParameterPtr p1 = adoCommand.cp( "testInput", adInteger, adParamInput, sizeof( value ), value );

		DECIMAL decimal;
		_ParameterPtr p2 = adoCommand.cp( "testInput", adDecimal, adParamInput, sizeof( decimal ), decimal, 1, 1 );
		//STATIC_CHECK( p2, _DECIMAL );
		
		adoCommand.append( p1 );

 
 		if( p1 ) {
 			std::cout << "success" << std::endl;
 		} else {
 			std::cout << "failed" << std::endl;
 		}
 	}
 	catch( exceptions::commaon_error e ) {
		std::cout << e.what() << std::endl;

// 		char s[120] = { 0, };
// 		sprintf_s( s, sizeof( s ), "%08lx", reinterpret_cast<char*>( _error.Error() ) );
//  		std::cout << "error code : " << s << std::endl;
//  		std::cout << "error meaning : " << reinterpret_cast<LPCSTR>( _error.ErrorMessage() ) << std::endl;
//  		std::cout << "error source : " << _error.Source() << std::endl;
//  		std::cout << "error description : " << _error.Description() << std::endl;
 	}

	::CoUninitialize();

	return 0;
}

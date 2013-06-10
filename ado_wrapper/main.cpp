// ado_wrapper.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

#include "ado_wrapper.hpp"

#include "ado_command.h"
#include "ado_connection.h"
#include "ado_recordset.h"


typedef		int		PersonalType;


int _tmain( void )
{
	if( FAILED( ::CoInitialize( NULL ) ) ) {
		return -1;
	}

	try {
		PersonalType value( 0 );

		ADOConnection adoConnection;
		adoConnection.create_instance();
		adoConnection.open( "connection_string", "user", "pw", adAsyncConnect );

		assert( adoConnection.m_connection->GetState() == adStateConnecting );

		std::cout << "connection state : " << adoConnection.m_connection->GetState() << std::endl;

		ADOCommand adoCommand;
		adoCommand.create_instance();
		adoCommand.put_active_connection( _variant_t( ( IDispatch* )adoConnection.m_connection, true ) );

		adoCommand.m_command->CommandType = adCmdStoredProc;
		adoCommand.m_command->CommandText = _bstr_t( "test" );

		//	ado::createParameter( adoCommand.m_command, "testInput", adParamInput, value );


		_ParameterPtr parameter = adoCommand.create_parameter( "testInput", adInteger, adParamInput, sizeof( value ), value );

		adoCommand.cp( "testInput", adInteger, adParamInput, sizeof( value ), value );

		adoCommand.append( parameter );


		if( parameter ) {
			std::cout << "success" << std::endl;
		} else {
			std::cout << "failed" << std::endl;
		}
 	}
 	catch( _com_error& _error ) {
		char s[120] = { 0, };
		sprintf_s( s, sizeof( s ), "%08lx", reinterpret_cast<char*>( _error.Error() ) );
 		std::cout << "error code : " << s << std::endl;
 		std::cout << "error meaning : " << reinterpret_cast<LPCSTR>( _error.ErrorMessage() ) << std::endl;
 		std::cout << "error source : " << _error.Source() << std::endl;
 		std::cout << "error description : " << _error.Description() << std::endl;
 	}

	::CoUninitialize();

	return 0;
}


#pragma once

#include "static_check.hpp"

#import "C:\Program Files\Common Files\System\ado\msado60_Backcompat.tlb" no_namespace rename( "EOF", "adoEOF" )


namespace ado {
	template< typename _Type >
	_ParameterPtr	createParameter( _CommandPtr command, const char* name, const ParameterDirectionEnum direction, const _Type & value )
	{
		STATIC_CHECK( 0, default );
		return NULL;
	};

	template<>
	_ParameterPtr	createParameter<int>( _CommandPtr command, const char* name, const ParameterDirectionEnum direction, const int & value )
	{
		return command->CreateParameter( _bstr_t( name ), adInteger, direction, sizeof( value ), value );
	};

	template<>
	_ParameterPtr	createParameter<__int64>( _CommandPtr command, const char* name, const ParameterDirectionEnum direction, const __int64 & value )
	{
		return command->CreateParameter( _bstr_t( name ), adBigInt, direction, sizeof( value ), value );
	};

};


#pragma once

#include "ado_base.h"
#include "static_check.hpp"


namespace ado {
	template< typename _Type >
	_ParameterPtr	createParameter( _CommandPtr command, const char* name, const ParameterDirectionEnum direction, const _Type & value )
	{
		STATIC_CHECK( 0, default );
		return NULL;
	};

	template<>
	_ParameterPtr	createParameter( _CommandPtr command, const char* name, const ParameterDirectionEnum direction, const int & value )
	{
		return command->CreateParameter( _bstr_t( name ), adInteger, direction, sizeof( value ), value );
	};

	template<>
	_ParameterPtr	createParameter( _CommandPtr command, const char* name, const ParameterDirectionEnum direction, const __int64 & value )
	{
		return command->CreateParameter( _bstr_t( name ), adBigInt, direction, sizeof( value ), value );
	};

};

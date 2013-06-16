
#pragma once

#include "static_check.hpp"

#import "C:\Program Files\Common Files\System\ado\msado60_Backcompat.tlb" no_namespace rename( "EOF", "adoEOF" )

template< typename T >
struct CreateParameterImpl;

namespace ado {
	template< typename T >
	_ParameterPtr	createParameter( _CommandPtr command, const char* name, const ParameterDirectionEnum direction, const T & value )
	{
		return CreateParameterImpl< T >::createParameter( command, name, direction, value );
	};
};

template< typename T >
struct CreateParameterImpl
{
	static _ParameterPtr	createParameter( _CommandPtr /*command*/, const char* /*name*/, const ParameterDirectionEnum /*direction*/, const T& /*value*/ )
	{
		STATIC_CHECK( 0, do_specialization );
		return NULL;
	}
};

template<>
struct CreateParameterImpl< int >
{
	static _ParameterPtr	createParameter( _CommandPtr command, const char* name, const ParameterDirectionEnum direction, const int& value )
	{
		return command->CreateParameter( _bstr_t( name ), adInteger, direction, sizeof( value ), value );
	}
};

template<>
struct CreateParameterImpl< double >
{
	static _ParameterPtr	createParameter( _CommandPtr command, const char* name, const ParameterDirectionEnum direction, const double& value )
	{
		return command->CreateParameter( _bstr_t( name ), adDouble, direction, sizeof( value ), value );
	}
};

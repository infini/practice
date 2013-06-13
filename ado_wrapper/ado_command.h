
#pragma once

#import "C:\Program Files\Common Files\System\ado\msado60_Backcompat.tlb" no_namespace rename( "EOF", "adoEOF" )

#include "static_check.hpp"
#include <iostream>
#include <oledb.h>


class ADOCommand
{
public:
	void	cancel();
	_RecordsetPtr	execute( VARIANT* records_affected, VARIANT* parameters, long options );

	void	append( const _RecordsetPtr recordset );
	void	_delete( const _variant_t& index );
	void	refresh();

	void	create_instance();
	void	set_command( const enum CommandTypeEnum command_type, const char* command_text );
	void	set_active_connection( const _ConnectionPtr connection );

	_ParameterPtr	create_parameter( const char* name, const enum DataTypeEnum type, const enum ParameterDirectionEnum direction, const long size, const _variant_t& value );

	template< typename _Type >
	_ParameterPtr	cpo( _bstr_t name, enum DataTypeEnum type, enum ParameterDirectionEnum direction, long size, const _Type& value )
	{
		//STATIC_CHECK( 0, default );
		return m_command->CreateParameter( name, type, direction, size, value );
		//return NULL;
	}

	template<>
	_ParameterPtr	cpo<int>( _bstr_t name, enum DataTypeEnum type, enum ParameterDirectionEnum direction, long size, const int& value )
	{
		return m_command->CreateParameter( name, type, direction, size, value );
	}


	template< typename _Type >
	_ParameterPtr	cp( _bstr_t name, enum DataTypeEnum type, enum ParameterDirectionEnum direction, long size, const _Type& value, const int numeric = 0, const int precision = 0 )
	{
		UNREFERENCED_PARAMETER( numeric );
		UNREFERENCED_PARAMETER( precision );
		return m_command->CreateParameter( name, type, direction, size, value );
	}

	template<>
	_ParameterPtr	cp<DECIMAL>( _bstr_t name, enum DataTypeEnum type, enum ParameterDirectionEnum direction, long size, const DECIMAL& value, const int numeric, const int precision )
	{
		_ParameterPtr ptr = m_command->CreateParameter( name, type, direction, size, value );
		//ptr->NumericScale = static_cast<unsigned char>( numeric );
		ptr->NumericScale = (unsigned char)numeric;
		ptr->Precision = static_cast<unsigned char>( precision );
		return ptr;
	}



	_CommandPtr		m_command;
};

/************************************************************************/
/* property
_ConnectionPtr GetActiveConnection( );
void PutRefActiveConnection( struct _Connection * ppvObject );
void PutActiveConnection( const _variant_t & ppvObject ); __declspec(property(get=GetActiveConnection,put=PutRefActiveConnection)) _ConnectionPtr ActiveConnection;
_bstr_t GetCommandText( );
void PutCommandText( _bstr_t pbstr );
__declspec(property(get=GetCommandText,put=PutCommandText)) _bstr_t
CommandText;
long GetCommandTimeout( );
void PutCommandTimeout( long pl );
__declspec(property(get=GetCommandTimeout,put=PutCommandTimeout)) long CommandTimeout;
void PutCommandType( enum CommandTypeEnum plCmdType );
enum CommandTypeEnum GetCommandType( );
__declspec(property(get=GetCommandType,put=PutCommandType)) enum CommandTypeEnum CommandType;
VARIANT_BOOL GetPrepared( );
void PutPrepared( VARIANT_BOOL pfPrepared );
__declspec(property(get=GetPrepared,put=PutPrepared)) VARIANT_BOOL Prepared;
ParametersPtr GetParameters( );
__declspec(property(get=GetParameters)) ParametersPtr Parameters;
_bstr_t GetName( );
void PutName( _bstr_t pbstrName );
__declspec(property(get=GetName,put=PutName)) _bstr_t Name;
long GetState( );
__declspec(property(get=GetState)) long State;
*/
/************************************************************************/


#pragma once

#import "C:\Program Files\Common Files\System\ado\msado60_Backcompat.tlb" no_namespace rename( "EOF", "adoEOF" )

#include "static_check.hpp"


class ADOCommand
{
public:
	void	cancel();
	_RecordsetPtr	execute( VARIANT* records_affected, VARIANT* parameters, long options = adCmdText );
	_ParameterPtr	create_parameter( _bstr_t name, enum DataTypeEnum type, enum ParameterDirectionEnum direction, long size, const _variant_t& value = vtMissing );

	void	append( IDispatch* object );
	void	_delete( const _variant_t& index );
	void	refresh();

	void	create_instance();
	void	put_command_text( _bstr_t command_text );
	void	put_command_type( enum CommandTypeEnum command_type );
	void	put_active_connection( const _variant_t& object );

	template< typename _Type >
	_ParameterPtr	cp( _bstr_t name, enum DataTypeEnum type, enum ParameterDirectionEnum direction, long size, const _Type& value )
	{
		STATIC_CHECK( 0, default )
		return m_command->CreateParameter( name, type, direction, size, value );
	}

	template<>
	_ParameterPtr	cp<int>( _bstr_t name, enum DataTypeEnum type, enum ParameterDirectionEnum direction, long size, const int& value )
	{
		return m_command->CreateParameter( name, type, direction, size, value );
	}


//private:
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

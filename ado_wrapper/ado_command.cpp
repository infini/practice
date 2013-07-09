
#include "stdafx.h"
#include "ado_command.h"


void	ADOCommand::cancel()
{
	if( FAILED( m_command->Cancel() ) ) {
		assert( 0 );
	}
}

_RecordsetPtr	ADOCommand::execute( VARIANT* records_affected, VARIANT* parameters, long options )
{
	return m_command->Execute( records_affected, parameters, options );
}

void	ADOCommand::append( const _RecordsetPtr recordset )
{
	if( FAILED( m_command->GetParameters()->Append( _variant_t( ( IDispatch* )recordset, true ) ) ) ) {
		assert( 0 );
	}
}

void	ADOCommand::_delete( const _variant_t& index )
{
	if( FAILED( m_command->GetParameters()->Delete( index ) ) ) {
		assert( 0 );
	}
}

void	ADOCommand::refresh()
{
	m_command->Parameters->Refresh();
}

void	ADOCommand::create_instance()
{
	if( FAILED( m_command.CreateInstance( __uuidof( Command ) ) ) ) {
		assert( 0 );
	}
}

void	ADOCommand::set_command( const enum CommandTypeEnum command_type, const char* command_text )
{
	m_command->PutCommandType( command_type );
	m_command->PutCommandText( _bstr_t( command_text ) );
}

void	ADOCommand::set_active_connection( const _ConnectionPtr connection )
{
	m_command->PutActiveConnection( _variant_t( ( IDispatch* )connection, true ) );
}

_ParameterPtr	ADOCommand::create_parameter( const char* name, const enum DataTypeEnum type, const enum ParameterDirectionEnum direction, const long size, const _variant_t& value )
{
	//return m_command->CreateParameter( name, type, direction, size, value );

	_ParameterPtr p = m_command->CreateParameter( name, type, direction, size, value );

	return p;
}

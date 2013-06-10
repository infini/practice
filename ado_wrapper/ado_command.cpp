
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

_ParameterPtr	ADOCommand::create_parameter( _bstr_t name, enum DataTypeEnum type, enum ParameterDirectionEnum direction, long size, const _variant_t& value )
{
	return m_command->CreateParameter( name, type, direction, size, value );
}

void	ADOCommand::append( IDispatch* object )
{
	if( FAILED( m_command->Parameters->Append( object ) ) ) {
		assert( 0 );
	}
}

void	ADOCommand::_delete( const _variant_t& index )
{
	if( FAILED( m_command->Parameters->Delete( index ) ) ) {
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

void	ADOCommand::put_command_text( _bstr_t command_text )
{
	m_command->PutCommandText( command_text );
}

void	ADOCommand::put_command_type( enum CommandTypeEnum command_type )
{
	m_command->PutCommandType( command_type );
}

void	ADOCommand::put_active_connection( const _variant_t& object )
{
	m_command->PutActiveConnection( object );
}

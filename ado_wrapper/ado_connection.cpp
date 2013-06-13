
#include "stdafx.h"
#include "ado_connection.h"
#include "ado_command.h"


ADOConnection::ADOConnection()
{
}

ADOConnection::~ADOConnection()
{
}

void	ADOConnection::cancel()
{
	if( FAILED( m_connection->Cancel() ) ) {
		assert( 0 );
	}
}

void	ADOConnection::close()
{
	assert( m_connection->GetState() == adStateOpen );

 	// close and set nothing
 	if( m_connection->GetState() == adStateOpen ) {
 		m_connection->Close();
 	}
}

_RecordsetPtr	ADOConnection::execute( const char* command_text, VARIANT* records_affected, long options )
{
	return m_connection->Execute( (_bstr_t)command_text, records_affected, options );
}

long	ADOConnection::begin_trans()
{
	return m_connection->BeginTrans();
}

void	ADOConnection::commit_trans()
{
	if( FAILED( m_connection->CommitTrans() ) ) {
		assert( 0 );
	}
}

void	ADOConnection::rollback_trans()
{
	if( FAILED( m_connection->RollbackTrans() ) ) {
		assert( 0 );
	}
}

void	ADOConnection::open( const char* connection_string, const char* user_id, const char* password, const bool async_connect )
{
	if( FAILED( m_connection->Open( (_bstr_t)connection_string, (_bstr_t)user_id, (_bstr_t)password, ( async_connect ? adAsyncConnect : adConnectUnspecified ) ) ) ) {
		assert( 0 );
	}

	m_connection->PutCursorLocation( adUseClient );
}

_RecordsetPtr	ADOConnection::open_schema( enum SchemaEnum schema, const _variant_t& restrictions, const _variant_t& schema_id )
{
	return m_connection->OpenSchema( schema, restrictions, schema_id );
}

void	ADOConnection::create_instance()
{
	if( FAILED( m_connection.CreateInstance( __uuidof( Connection ) ) ) ) {
		assert( 0 );
	}
}

long	ADOConnection::get_state() const
{
	return m_connection->GetState();
}

void	ADOConnection::initialize_command( ADOCommand& command )
{
	assert( get_state() == adStateOpen );

	command.create_instance();

	command.set_active_connection( m_connection );
}

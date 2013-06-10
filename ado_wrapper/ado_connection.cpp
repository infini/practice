
#include "stdafx.h"
#include "ado_connection.h"


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

_RecordsetPtr	ADOConnection::execute( _bstr_t command_text, VARIANT * records_affected, long options )
{
	return m_connection->Execute( command_text, records_affected, options );
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

void	ADOConnection::open( _bstr_t connection_string, _bstr_t user_id, _bstr_t password, long options )
{
	if( FAILED( m_connection->Open( connection_string, user_id, password, options ) ) ) {
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

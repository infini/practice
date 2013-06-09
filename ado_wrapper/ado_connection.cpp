
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
//	HRESULT Cancel( );
}

void	ADOConnection::close()
{
	assert( m_connection->State == adStateOpen );

 	// close and set nothing
 	if( m_connection->State == adStateOpen ) {
 		m_connection->Close();
 	}

//	HRESULT Close( );
}

void	ADOConnection::execute()
{
//	_RecordsetPtr Execute( _bstr_t CommandText, VARIANT * RecordsAffected, long Options );
}

void	ADOConnection::begin_trans()
{
//	long BeginTrans( );
}

void	ADOConnection::commit_trans()
{
//	HRESULT CommitTrans( );
}

void	ADOConnection::rollback_trans()
{
//	HRESULT RollbackTrans( );
}

void	ADOConnection::open()
{
// 	m_connection->Open( _bstr_t( connection_string ), _bstr_t( user_id ), _bstr_t( password ), adAsyncConnect );
// 	m_connection->CursorLocation		= adUseClient;

//	HRESULT Open( _bstr_t ConnectionString, _bstr_t UserID, _bstr_t Password, long Options );
}

void	ADOConnection::open_schema()
{
//	_RecordsetPtr OpenSchema( enum SchemaEnum Schema, const _variant_t & Restrictions = vtMissing, const _variant_t & SchemaID = vtMissing );
}

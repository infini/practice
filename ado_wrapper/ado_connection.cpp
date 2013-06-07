
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
	m_connection->Cancel();
}

void	ADOConnection::open( const char* connection_string, const char* user_id, const char* password )
{
	m_connection->Open( _bstr_t( connection_string ), _bstr_t( user_id ), _bstr_t( password ), adAsyncConnect );

//	Open(BSTR ConnectionString, BSTR UserID, BSTR Password, long Options);
}

void	ADOConnection::close()
{
	// close and set nothing
	if( m_connection->State == adStateOpen ) {
		m_connection->Close();
	}
}

void	ADOConnection::execute()
{
//	Execute(BSTR CommandText, VARIANT *RecordsAffected, long Options, _ADORecordset **ppiRset);
}

void	ADOConnection::beginTrans()
{
//	BeginTrans(long *TransactionLevel);
}

void	ADOConnection::commitTrans()
{
//	CommitTrans(void);
}

void	ADOConnection::rollbackTrans()
{
//	RollbackTrans(void);
}

void	ADOConnection::openSchema()
{
//	OpenSchema(SchemaEnum Schema, VARIANT Restrictions, VARIANT SchemaID, _ADORecordset **pprset);
}
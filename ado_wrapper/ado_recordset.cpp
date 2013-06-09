
#include "stdafx.h"
#include "ado_recordset.h"


ADORecordset::ADORecordset()
{
}

ADORecordset::~ADORecordset()
{
}

void	ADORecordset::add_new()
{
//	HRESULT AddNew( const _variant_t & FieldList = vtMissing, const _variant_t & Values = vtMissing );
}

void	ADORecordset::cancel()
{
//	HRESULT Cancel( );
}

void	ADORecordset::cancel_batch()
{
//	HRESULT CancelBatch( enum AffectEnum AffectRecords );
}

void	ADORecordset::cancel_update()
{
//	HRESULT CancelUpdate( );
}

void	ADORecordset::clone()
{
//	_RecordsetPtr Clone( enum LockTypeEnum LockType );
}

void	ADORecordset::close()
{
//	HRESULT Close( );
}

void	ADORecordset::compare_bookmarks()
{
//	enum CompareEnum CompareBookmarks( const _variant_t & Bookmark1, const _variant_t & Bookmark2 );
}

void	ADORecordset::_delete()
{
//	HRESULT Delete( enum AffectEnum AffectRecords );
}

void	ADORecordset::find()
{
//	HRESULT Find( _bstr_t Criteria, long SkipRecords, enum SearchDirectionEnum SearchDirection, const _variant_t & Start =	vtMissing );
}

void	ADORecordset::get_rows()
{
//	_variant_t GetRows( long Rows, const _variant_t & Start = vtMissing, const _variant_t & Fields = vtMissing );
}

void	ADORecordset::get_string()
{
//	_bstr_t GetString( enum StringFormatEnum StringFormat, long NumRows, _bstr_t ColumnDelimeter, _bstr_t RowDelimeter, _bstr_t NullExpr );
}

void	ADORecordset::move()
{
//	HRESULT Move( long NumRecords, const _variant_t & Start = vtMissing );
}

void	ADORecordset::move_first()
{
//	HRESULT MoveFirst( );
}

void	ADORecordset::move_last()
{
//	HRESULT MoveLast( );
}

void	ADORecordset::move_next()
{
//	HRESULT MoveNext( );
}

void	ADORecordset::move_previous()
{
// 	CursorTypeEnum *plCursorType( NULL );
// 
// 	if( FAILED( m_recordset->get_CursorType( plCursorType ) ) ) {
// 		return false;
// 	}
// 
// 	if( *plCursorType == adOpenForwardOnly ) {
// 		return false;
// 	}
// 
// 	m_recordset->MovePrevious();
// 
// 	return true;

//	HRESULT MovePrevious( );
}

void	ADORecordset::next_recordset()
{
//	_RecordsetPtr NextRecordset( VARIANT * RecordsAffected );
}

void	ADORecordset::open()
{
//	m_recordset->Open( source, _variant_t( ( IDispatch* )connection, true ), adOpenForwardOnly, adLockReadOnly, adCmdTable );

//	HRESULT Open( const _variant_t & Source, const _variant_t &	ActiveConnection, enum CursorTypeEnum CursorType, enum LockTypeEnum	LockType, long Options );
}

void	ADORecordset::requery()
{
//	HRESULT Requery( long Options );
}

void	ADORecordset::update()
{
//	HRESULT Update( const _variant_t & Fields = vtMissing, const _variant_t & Values = vtMissing );
}

void	ADORecordset::update_batch()
{
//	HRESULT UpdateBatch( enum AffectEnum AffectRecords );
}

void	ADORecordset::resync()
{
//	HRESULT Resync( enum AffectEnum AffectRecords, enum ResyncEnum ResyncValues );
}

void	ADORecordset::save()
{
//	HRESULT Save( const _variant_t & Destination, enum PersistFormatEnum PersistFormat );
}

void	ADORecordset::seek()
{
//	HRESULT Seek( const _variant_t & KeyValues, enum SeekEnum SeekOption );
}

void	ADORecordset::supports()
{
//	VARIANT_BOOL Supports( enum CursorOptionEnum CursorOptions );
}

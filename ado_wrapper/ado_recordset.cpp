
#include "stdafx.h"
#include "ado_recordset.h"


ADORecordset::ADORecordset()
{
}

ADORecordset::~ADORecordset()
{
}

void	ADORecordset::add_new( const _variant_t& field_list, const _variant_t& values )
{
	if( FAILED( m_recordset->AddNew( field_list, values ) ) ) {
		assert( 0 );
	}
}

void	ADORecordset::cancel()
{
	if( FAILED( m_recordset->Cancel() ) ) {
		assert( 0 );
	}
}

void	ADORecordset::cancel_batch( enum AffectEnum affect_records )
{
	if( FAILED( m_recordset->CancelBatch( affect_records ) ) ) {
		assert( 0 );
	}
}

void	ADORecordset::cancel_update()
{
	if( FAILED( m_recordset->CancelUpdate() ) ) {
		assert( 0 );
	}
}

_RecordsetPtr	ADORecordset::clone( enum LockTypeEnum lock_type )
{
	return m_recordset->Clone( lock_type );
}

void	ADORecordset::close()
{
	if( FAILED( m_recordset->Close() ) ) {
		assert( 0 );
	}
}

enum CompareEnum	ADORecordset::compare_bookmarks( const _variant_t& bookmark1, const _variant_t& bookmark2 )
{
	return m_recordset->CompareBookmarks( bookmark1, bookmark2 );
}

void	ADORecordset::_delete( enum AffectEnum affect_records )
{
	if( FAILED( m_recordset->Delete( affect_records ) ) ) {
		assert( 0 );
	}
}

void	ADORecordset::find( _bstr_t criteria, long skip_records, enum SearchDirectionEnum search_direction, const _variant_t& start )
{
	if( FAILED( m_recordset->Find( criteria, skip_records, search_direction, start ) ) ) {
		assert( 0 );
	}
}

_variant_t	ADORecordset::get_rows( long rows, const _variant_t& start, const _variant_t& fields )
{
	return m_recordset->GetRows( rows, start, fields );
}

_bstr_t	ADORecordset::get_string( enum StringFormatEnum string_format, long num_rows, _bstr_t column_delimeter, _bstr_t row_delimeter, _bstr_t null_expr )
{
	return m_recordset->GetString( string_format, num_rows, column_delimeter, row_delimeter, null_expr );
}

void	ADORecordset::move( long num_records, const _variant_t& start )
{
	if( FAILED( m_recordset->Move( num_records, start ) ) ) {
		assert( 0 );
	}
}

void	ADORecordset::move_first()
{
	if( FAILED( m_recordset->MoveFirst() ) ) {
		assert( 0 );
	}
}

void	ADORecordset::move_last()
{
	if( FAILED( m_recordset->MoveLast() ) ) {
		assert( 0 );
	}
}

void	ADORecordset::move_next()
{
	if( FAILED( m_recordset->MoveNext() ) ) {
		assert( 0 );
	}
}

void	ADORecordset::move_previous()
{
	assert( m_recordset->GetCursorType() != adOpenForwardOnly );

	if( FAILED( m_recordset->MovePrevious() ) ) {
		assert( 0 );
	}
}

_RecordsetPtr	ADORecordset::next_recordset( VARIANT* records_affected )
{
	return m_recordset->NextRecordset( records_affected );
}

void	ADORecordset::open( const _variant_t& source, const _variant_t& active_connection, enum CursorTypeEnum cursor_type, enum LockTypeEnum lock_type, long options )
{
//	m_recordset->Open( source, _variant_t( ( IDispatch* )connection, true ), adOpenForwardOnly, adLockReadOnly, adCmdTable );

	if( FAILED( m_recordset->Open( source, active_connection, cursor_type, lock_type, options ) ) ) {
		assert( 0 );
	}
}

void	ADORecordset::requery( long options )
{
	if( FAILED( m_recordset->Requery( options ) ) ) {
		assert( 0 );
	}
}

void	ADORecordset::update( const _variant_t& fields, const _variant_t& values )
{
	if( FAILED( m_recordset->Update( fields, values ) ) ) {
		assert( 0 );
	}
}

void	ADORecordset::update_batch( enum AffectEnum affect_records )
{
	if( FAILED( m_recordset->UpdateBatch( affect_records ) ) ) {
		assert( 0 );
	};
}

void	ADORecordset::resync( enum AffectEnum affect_records, enum ResyncEnum resync_values )
{
	if( FAILED( m_recordset->Resync( affect_records, resync_values ) ) ) {
		assert( 0 );
	};
}

void	ADORecordset::save( const _variant_t& destination, enum PersistFormatEnum persist_format )
{
	if( FAILED( m_recordset->Save( destination, persist_format ) ) ) {
		assert( 0 );
	};
}

void	ADORecordset::seek( const _variant_t& key_values, enum SeekEnum seek_option )
{
	if( FAILED( m_recordset->Seek( key_values, seek_option ) ) ) {
		assert ( 0 );
	};
}

VARIANT_BOOL	ADORecordset::supports( enum CursorOptionEnum cursor_options )
{
	return m_recordset->Supports( cursor_options );
}

void	ADORecordset::create_instance()
{
	if( FAILED( m_recordset.CreateInstance( __uuidof( Recordset ) ) ) ) {
		assert( 0 );
	}
}

_variant_t	ADORecordset::get_item( const _variant_t& index )
{
	return m_recordset->GetFields()->GetItem( index )->GetValue();
}

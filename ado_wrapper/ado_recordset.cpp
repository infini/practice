
#include "stdafx.h"
#include "ado_recordset.h"


void	ADORecordset::open( const char* source, _ConnectionPtr connection )
{
	m_recordset->Open( source, _variant_t( ( IDispatch* )connection, true ), adOpenForwardOnly, adLockReadOnly, adCmdTable );
}

void	ADORecordset::move_next()
{
	m_recordset->MoveNext();
}

bool	ADORecordset::move_prev()
{
	CursorTypeEnum *plCursorType( NULL );

	if( FAILED( m_recordset->get_CursorType( plCursorType ) ) ) {
		return false;
	}

	if( *plCursorType == adOpenForwardOnly ) {
		return false;
	}

	m_recordset->MovePrevious();

	return true;
}

// 	AddNew(VARIANT FieldList, VARIANT Values)
// 	Cancel(void)
// 	CancelBatch(AffectEnum AffectRecords)
// 	CancelUpdate(void)
// 	Clone(LockTypeEnum LockType, _ADORecordset **ppvObject)
// 	Close(void)
// 	CompareBookmarks(VARIANT Bookmark1, VARIANT Bookmark2, CompareEnum *pCompare)
// 	Delete(AffectEnum AffectRecords)
// 	Find(BSTR Criteria, LONG SkipRecords, SearchDirectionEnum SearchDirection, VARIANT Start)
// 	GetRows(long Rows, VARIANT Start, VARIANT Fields, VARIANT *pvar)
// 	GetString(StringFormatEnum StringFormat, long NumRows, BSTR ColumnDelimeter, BSTR RowDelimeter, BSTR NullExpr, BSTR *pRetString)
// 	Move(long NumRecords, VARIANT Start)
// 	MoveFirst(void)
// 	MoveLast(void)
// 	MoveNext(void)
// 	MovePrevious(void)
// 	NextRecordset(VARIANT *RecordsAffected, _ADORecordset **ppiRs)
// 	Open(VARIANT Source, VARIANT ActiveConnection, CursorTypeEnum CursorType, LockTypeEnum LockType, LONG Options)
// 	Requery(LONG Options)
// 	Resync(AffectEnum AffectRecords, ResyncEnum ResyncValues)
// 	Save(BSTR FileName, PersistFormatEnum PersistFormat)
// 	Supports(CursorOptionEnum CursorOptions, VARIANT_BOOL *pb)
// 	Update(VARIANT Fields, VARIANT Values)
// 	UpdateBatch(AffectEnum AffectRecords)

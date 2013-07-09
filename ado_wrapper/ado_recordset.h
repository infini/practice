
#pragma once

#import "C:\Program Files\Common Files\System\ado\msado60_Backcompat.tlb" no_namespace rename( "EOF", "adoEOF" )


class ADORecordset
{
public:
	ADORecordset();
	~ADORecordset();

	void	add_new( const _variant_t& field_list = vtMissing, const _variant_t& values = vtMissing );
	void	cancel();
	void	cancel_batch( enum AffectEnum affect_records );
	void	cancel_update();
	_RecordsetPtr	clone( enum LockTypeEnum lock_type );
	void	close();
	enum CompareEnum	compare_bookmarks( const _variant_t& bookmark1, const _variant_t& bookmark2 );
	void	_delete( enum AffectEnum affect_records );
	void	find( _bstr_t criteria, long skip_records, enum SearchDirectionEnum search_direction, const _variant_t& start = vtMissing );
	_variant_t	get_rows( long rows, const _variant_t& start = vtMissing, const _variant_t& fields = vtMissing );
	_bstr_t	get_string( enum StringFormatEnum string_format, long num_rows, _bstr_t column_delimeter, _bstr_t row_delimeter, _bstr_t null_expr );
	void	move( long num_records, const _variant_t& start = vtMissing );
	void	move_first();
	void	move_last();
	void	move_next();
	void	move_previous();
	_RecordsetPtr	next_recordset( VARIANT* records_affected );
	void	open( const _variant_t& source, const _variant_t& active_connection, enum CursorTypeEnum cursor_type = adOpenForwardOnly, enum LockTypeEnum lock_type = adLockReadOnly, long options = adCmdTable );
	void	requery( long options );
	void	update( const _variant_t& fields = vtMissing, const _variant_t& values = vtMissing );
	void	update_batch( enum AffectEnum affect_records );
	void	resync( enum AffectEnum affect_records, enum ResyncEnum resync_values );
	void	save( const _variant_t& destination, enum PersistFormatEnum persist_format );
	void	seek( const _variant_t& key_values, enum SeekEnum seek_option );
	VARIANT_BOOL	supports( enum CursorOptionEnum cursor_options );

	void	create_instance();
	_variant_t	get_item( const _variant_t& index );


//private:
	_RecordsetPtr	m_recordset;
};

/************************************************************************/
/* property
enum PositionEnum GetAbsolutePage( );
void PutAbsolutePage( enum PositionEnum pl );
__declspec(property(get=GetAbsolutePage,put=PutAbsolutePage)) enum
PositionEnum AbsolutePage;

enum PositionEnum GetAbsolutePosition( );
void PutAbsolutePosition( enum PositionEnum pl );
__declspec(property(get=GetAbsolutePosition,put=PutAbsolutePosition))
enum PositionEnum AbsolutePosition;

IDispatchPtr GetActiveCommand( );
__declspec(property(get=GetActiveCommand)) IDispatchPtr ActiveCommand;

void PutRefActiveConnection( IDispatch * pvar );
void PutActiveConnection( const _variant_t & pvar );
_variant_t GetActiveConnection( );

enum CursorLocationEnum GetCursorLocation( );
void PutCursorLocation( enum CursorLocationEnum plCursorLoc );
__declspec(property(get=GetCursorLocation,put=PutCursorLocation)) enum
CursorLocationEnum CursorLocation;

VARIANT_BOOL GetBOF( );
__declspec(property(get=GetBOF)) VARIANT_BOOL BOF;

VARIANT_BOOL GetEndOfFile( ); // Actually, GetEOF. Renamed in #import.
__declspec(property(get=GetEndOfFile)) VARIANT_BOOL EndOfFile;

_variant_t GetBookmark( );
void PutBookmark( const _variant_t & pvBookmark );
__declspec(property(get=GetBookmark,put=PutBookmark)) _variant_t
Bookmark;

long GetCacheSize( );
void PutCacheSize( long pl );
__declspec(property(get=GetCacheSize,put=PutCacheSize)) long
CacheSize;

enum CursorTypeEnum GetCursorType( );
void PutCursorType( enum CursorTypeEnum plCursorType );
__declspec(property(get=GetCursorType,put=PutCursorType)) enum
CursorTypeEnum CursorType;

_bstr_t GetDataMember( );
void PutDataMember( _bstr_t pbstrDataMember );
__declspec(property(get=GetDataMember,put=PutDataMember)) _bstr_t
DataMember;

IUnknownPtr GetDataSource( );
void PutRefDataSource( IUnknown * ppunkDataSource );
__declspec(property(get=GetDataSource,put=PutRefDataSource)) IUnknownPtr
DataSource;

enum EditModeEnum GetEditMode( );
__declspec(property(get=GetEditMode)) enum EditModeEnum EditMode;

FieldsPtr GetFields( );
__declspec(property(get=GetFields)) FieldsPtr Fields;

_variant_t GetFilter( );
void PutFilter( const _variant_t & Criteria );
__declspec(property(get=GetFilter,put=PutFilter)) _variant_t Filter;

_bstr_t GetIndex( );
void PutIndex( _bstr_t pbstrIndex );
__declspec(property(get=GetIndex,put=PutIndex)) _bstr_t Index;

enum LockTypeEnum GetLockType( );
void PutLockType( enum LockTypeEnum plLockType );
__declspec(property(get=GetLockType,put=PutLockType)) enum LockTypeEnum
LockType;

enum MarshalOptionsEnum GetMarshalOptions( );
void PutMarshalOptions( enum MarshalOptionsEnum peMarshal );
__declspec(property(get=GetMarshalOptions,put=PutMarshalOptions)) enum
MarshalOptionsEnum MarshalOptions;

long GetMaxRecords( );
void PutMaxRecords( long plMaxRecords );
__declspec(property(get=GetMaxRecords,put=PutMaxRecords)) long
MaxRecords;

long GetPageCount( );
__declspec(property(get=GetPageCount)) long PageCount;

long GetPageSize( );
void PutPageSize( long pl );
__declspec(property(get=GetPageSize,put=PutPageSize)) long PageSize;

long GetRecordCount( );
__declspec(property(get=GetRecordCount)) long RecordCount;

_bstr_t GetSort( );
void PutSort( _bstr_t Criteria );
__declspec(property(get=GetSort,put=PutSort)) _bstr_t Sort;

void PutRefSource( IDispatch * pvSource );
void PutSource( _bstr_t pvSource );
_variant_t GetSource( );

long GetState( );
__declspec(property(get=GetState)) long State;

long GetStatus( );
__declspec(property(get=GetStatus)) long Status;

VARIANT_BOOL GetStayInSync( );
void PutStayInSync( VARIANT_BOOL pbStayInSync );
__declspec(property(get=GetStayInSync,put=PutStayInSync)) VARIANT_BOOL
StayInSync;
*/
/************************************************************************/

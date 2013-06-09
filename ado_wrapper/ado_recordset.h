
#pragma once

#import "C:\Program Files\Common Files\System\ado\msado60_Backcompat.tlb" no_namespace rename( "EOF", "adoEOF" )


class ADORecordset
{
public:
	ADORecordset();
	~ADORecordset();

	void	add_new();
	void	cancel();
	void	cancel_batch();
	void	cancel_update();
	void	clone();
	void	close();
	void	compare_bookmarks();
	void	_delete();
	void	find();
	void	get_rows();
	void	get_string();
	void	move();
	void	move_first();
	void	move_last();
	void	move_next();
	void	move_previous();
	void	next_recordset();
	void	open();
	void	requery();
	void	update();
	void	update_batch();
	void	resync();
	void	save();
	void	seek();
	void	supports();


private:
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


#pragma once

#import "C:\Program Files\Common Files\System\ado\msado60_Backcompat.tlb" no_namespace rename( "EOF", "adoEOF" )

class ADOCommand;


class ADOConnection
{
public:
	ADOConnection();
	~ADOConnection();

	void	cancel();
	void	close();
	_RecordsetPtr	execute( const char* command_text, VARIANT* records_affected, long options );
	long	begin_trans();
	void	commit_trans();
	void	rollback_trans();
	void	open( const char* connection_string, const char* user_id, const char* password, const bool async_connect = false /*long options = adConnectUnspecified/ *adAsyncConnect* /*/ );
	_RecordsetPtr	open_schema( enum SchemaEnum schema, const _variant_t& restrictions = vtMissing, const _variant_t& schema_id = vtMissing );

	void	create_instance();
	long	get_state() const;

	void	initialize_command( ADOCommand& command );

private:
	_ConnectionPtr	m_connection;
};

/************************************************************************/
/* property
_bstr_t GetConnectionString( );
void PutConnectionString( _bstr_t pbstr );
__declspec(property(get=GetConnectionString,put=PutConnectionString))
_bstr_t ConnectionString;
long GetCommandTimeout( );
void PutCommandTimeout( long plTimeout );
__declspec(property(get=GetCommandTimeout,put=PutCommandTimeout)) long
CommandTimeout;
long GetConnectionTimeout( );
void PutConnectionTimeout( long plTimeout );
__declspec(property(get=GetConnectionTimeout,put=PutConnectionTimeout))
long ConnectionTimeout;
_bstr_t GetVersion( );
__declspec(property(get=GetVersion)) _bstr_t Version;
ErrorsPtr GetErrors( );
__declspec(property(get=GetErrors)) ErrorsPtr Errors;
_bstr_t GetDefaultDatabase( );
void PutDefaultDatabase( _bstr_t pbstr );
__declspec(property(get=GetDefaultDatabase,put=PutDefaultDatabase))
_bstr_t DefaultDatabase;
enum IsolationLevelEnum GetIsolationLevel( );
void PutIsolationLevel( enum IsolationLevelEnum Level );
__declspec(property(get=GetIsolationLevel,put=PutIsolationLevel)) enum
IsolationLevelEnum IsolationLevel;
long GetAttributes( );
void PutAttributes( long plAttr );
__declspec(property(get=GetAttributes,put=PutAttributes)) long
Attributes;
enum CursorLocationEnum GetCursorLocation( );
void PutCursorLocation( enum CursorLocationEnum plCursorLoc );
__declspec(property(get=GetCursorLocation,put=PutCursorLocation)) enum
CursorLocationEnum CursorLocation;
enum ConnectModeEnum GetMode( );
void PutMode( enum ConnectModeEnum plMode );
__declspec(property(get=GetMode,put=PutMode)) enum ConnectModeEnum
Mode;
_bstr_t GetProvider( );
void PutProvider( _bstr_t pbstr );
__declspec(property(get=GetProvider,put=PutProvider)) _bstr_t
Provider;
long GetState( );
__declspec(property(get=GetState)) long State;
*/
/************************************************************************/

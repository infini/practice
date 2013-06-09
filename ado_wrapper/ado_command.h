
#pragma once

#import "C:\Program Files\Common Files\System\ado\msado60_Backcompat.tlb" no_namespace rename( "EOF", "adoEOF" )


class ADOCommand
{
public:
	void	cancel();
	void	execute();
	void	create_parameter();


private:
	_CommandPtr		m_command;
};

/************************************************************************/
/* property
_ConnectionPtr GetActiveConnection( );
void PutRefActiveConnection( struct _Connection * ppvObject );
void PutActiveConnection( const _variant_t & ppvObject ); __declspec(property(get=GetActiveConnection,put=PutRefActiveConnection)) _ConnectionPtr ActiveConnection;
_bstr_t GetCommandText( );
void PutCommandText( _bstr_t pbstr );
__declspec(property(get=GetCommandText,put=PutCommandText)) _bstr_t
CommandText;
long GetCommandTimeout( );
void PutCommandTimeout( long pl );
__declspec(property(get=GetCommandTimeout,put=PutCommandTimeout)) long CommandTimeout;
void PutCommandType( enum CommandTypeEnum plCmdType );
enum CommandTypeEnum GetCommandType( );
__declspec(property(get=GetCommandType,put=PutCommandType)) enum CommandTypeEnum CommandType;
VARIANT_BOOL GetPrepared( );
void PutPrepared( VARIANT_BOOL pfPrepared );
__declspec(property(get=GetPrepared,put=PutPrepared)) VARIANT_BOOL Prepared;
ParametersPtr GetParameters( );
__declspec(property(get=GetParameters)) ParametersPtr Parameters;
_bstr_t GetName( );
void PutName( _bstr_t pbstrName );
__declspec(property(get=GetName,put=PutName)) _bstr_t Name;
long GetState( );
__declspec(property(get=GetState)) long State;
*/
/************************************************************************/

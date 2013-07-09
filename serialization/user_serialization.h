
#pragma once

#include <WTypes.h>
#include <string>
#include <assert.h>


class UserSerialization
{
public:
	UserSerialization();
	~UserSerialization();

	static void	func();

	const	BOOL	IsLoading( )	const	{	return ( m_nMode & UserSerialization::load ) != 0;	}
	const	BOOL	IsStoring( )		const	{	return ( m_nMode & UserSerialization::load ) == 0;	}
	void	Read( PVOID lpBuf, int nSize );
	void	Write( LPCVOID lpBuf, int nSize );
//	void	Reserve( UINT nSize );
	virtual	void	Flush( );
//	void	Rewind( UINT uOffset );
	void	WriteString(LPCTSTR szBuffer );
	void	ReadString( LPTSTR szBuffer, int nBufSize );
	void	WriteString( const std::string & str )	{	WriteString( str.c_str( ) );	}
	template <int nSize>	void	ReadString( std::string & str );
	LPBYTE	GetBuffer( int* pnBufSize );
	LPBYTE	GetBuffer( )	const	{	assert( IsStoring( ) );	return m_lpBufStart;	}
	UINT	GetBufferSize( )	const	{	assert( IsStoring( ) );	return m_lpBufCur - m_lpBufStart;	}
	UINT	GetOffset( )	const	{	return( m_lpBufCur - m_lpBufStart );	}
	template <typename T>	T	Read( )	{	T t;	*this >> t;	return t;		}
	template <typename T>	UserSerialization& operator<<( const T& t )	{	Write( &t, sizeof(T) );	return *this;	}
	template <typename T>	UserSerialization& operator>>( T& t )	{	Read( &t, sizeof(T) );	return *this;	}

private:
//	void	Test( UINT nSize );

public:
	enum	{	store	= 0, load	= 1	};

private:
	enum	{	nGrowSize		= 16384	};
	BYTE	m_nMode;
	UINT	m_nBufSize;
	LPBYTE	m_lpBufCur;
	LPBYTE	m_lpBufMax;
	LPBYTE	m_lpBufStart;
	BYTE	m_lpBuf[nGrowSize];
};


template <int nSize>
void UserSerialization::ReadString( std::string & str )
{
	char szStr[nSize+1] = {0,};
	ReadString( szStr, nSize+1 );
	str = szStr;
}

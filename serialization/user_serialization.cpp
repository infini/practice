// String format:
//      UNICODE strings are always prefixed by 0xff, 0xfffe
//      if < 0xff chars: len:BYTE, TCHAR chars
//      if >= 0xff characters: 0xff, len:WORD, TCHAR chars
//      if >= 0xfffe characters: 0xff, 0xffff, len:DWORD, TCHARs

#include "stdafx.h"
#include "user_serialization.h"
#include "stop_watch.h"
#include <iostream>
#include <exception>


UserSerialization::UserSerialization()
{
	m_lpBufStart = new BYTE[ nGrowSize ];
	m_lpBufMax	= m_lpBufStart + nGrowSize;
	m_lpBufCur	= m_lpBufStart;
	m_nMode	= store;
	m_nBufSize	= nGrowSize;
}

UserSerialization::~UserSerialization( )
{
	delete m_lpBufStart;
}

void	UserSerialization::func()
{
	int n = 10;

	StopWatch sw;
	
	

	for( int nth = 0; nth < 1; ++nth ) {

		UserSerialization ar;

		// Serialize it.
		ar << n;

		//	std::cout << "packed buffer size : " << buffer.size() << ", sizeof : " << sizeof( buffer ) << std::endl;

		std::cout << sizeof( ar ) << std::endl;

		int nn = 0;
		ar >> nn;

		// Deserialize the serialized data.

	}

	std::cout << "user : " << sw.now() << std::endl;
}

void UserSerialization::Read( void* lpBuf, int nSize )
{
	return;
	assert( 0 <= nSize );
	if( nSize == 0 )
		return;

	assert( IsLoading( ) );
	assert( lpBuf != NULL );

	if( m_lpBufCur + nSize <= m_lpBufMax )	{
		memcpy( lpBuf, m_lpBufCur, nSize );
		m_lpBufCur	+= nSize;
	}
	else	{
#ifdef __DO_THROW
		throw std::exception( );
#else	// __DO_THROW
		memset( lpBuf, 0, nSize );
		m_lpBufCur	= m_lpBufMax;
#endif	// __DO_THROW
	}
}

void UserSerialization::Write( const void* lpBuf, int nSize )
{
	assert( IsStoring( ) );
	assert( lpBuf != NULL );

	if( nSize <= 0 )
		return;
	
	memcpy( m_lpBufCur, lpBuf, nSize );
	m_lpBufCur	+= nSize;
}

// special functions for text file input and output
void UserSerialization::WriteString( LPCTSTR szBuffer )
{
	int nLen	= ::_tcslen( szBuffer );
	*this << nLen;
	Write( szBuffer, sizeof(TCHAR) * nLen );
}

void UserSerialization::ReadString( LPTSTR szBuffer, int nBufSize )
{
	// if nMax is negative (such a large number doesn't make sense given today's
	// 2gb address space), then assume it to mean "keep the newline".
	int nLen;
	*this >> nLen;

	int nReadable	= nBufSize - 1;
	if( nReadable < nLen || nLen < 0 )	{
#ifdef __DO_THROW
		throw std::exception( );
#else	// __DO_THROW
		memset( (void*)szBuffer, 0, nBufSize );
		m_lpBufCur	= m_lpBufMax;
#endif	// __DO_THROW
	}
	else	{
		Read( szBuffer, sizeof(TCHAR) * nLen );
		szBuffer[nLen]		= '\0';
	}
}

// void UserSerialization::Reserve( UINT nSize )
// {
// 	assert( IsStoring( ) );
// 	assert( m_lpBufCur == m_lpBufStart );
// 	if( nSize <= nGrowSize )
// 		return;
// 
// 	LPBYTE lpBuf	= (LPBYTE)UserSerialization::m_Heap.Alloc( nSize );
// 	m_lpBufStart	= lpBuf;
// 
// 	assert( m_lpBufStart != NULL );
// 	m_nBufSize	= nSize;
// 	m_lpBufCur	= m_lpBufStart;
// 	m_lpBufMax	= m_lpBufStart + m_nBufSize;
// }

// void UserSerialization::Test( UINT nSize )
// {
// 	if( m_lpBufCur + nSize > m_lpBufMax )	{
// 		UINT uOffset	= m_lpBufCur - m_lpBufStart;
// 		UINT nExtension	= m_nBufSize * 2;
// 		if( m_nBufSize > nGrowSize )	{
// 			m_lpBufStart	= (LPBYTE)UserSerialization::m_Heap.Realloc( m_lpBufStart, m_nBufSize + nExtension );
// 		}
// 		else	{
// 			LPBYTE lpBuf	= (LPBYTE)UserSerialization::m_Heap.Alloc( m_nBufSize + nExtension );
// 			memcpy( lpBuf, m_lpBufStart, m_nBufSize );
// 			m_lpBufStart	= lpBuf;
// 		}
// 
// 		assert( m_lpBufStart != NULL );
// 
// 		m_nBufSize	+= nExtension;
// 		m_lpBufCur	= m_lpBufStart + uOffset;
// 		m_lpBufMax	= m_lpBufStart + m_nBufSize;
// 	}
// }

LPBYTE UserSerialization::GetBuffer( int* pnBufSize )
{
	assert( IsStoring( ) );
	assert( pnBufSize != NULL );

	*pnBufSize	= m_lpBufCur - m_lpBufStart;
	return m_lpBufStart;
}

void UserSerialization::Flush( )
{
	assert( IsStoring( ) );

	m_lpBufCur	= m_lpBufStart;
}

// void UserSerialization::Rewind( UINT uOffset )
// {
// 	assert( IsStoring( ) );
// 	assert( m_lpBufStart + uOffset <= m_lpBufCur );
// 
// 	if( m_nBufSize > nGrowSize )	{
// 		UserSerialization::m_Heap.Free( m_lpBufStart );
// 		m_lpBufStart	= m_lpBuf;
// 		m_nBufSize	= nGrowSize;
// 		m_lpBufMax	= m_lpBufStart + m_nBufSize;
// 	}
// 	m_lpBufCur	= m_lpBufStart + uOffset;
// }

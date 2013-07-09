
#pragma once


template< bool >
struct CompileTimeChecker	{	CompileTimeChecker(...);	};

template<>
struct CompileTimeChecker< false >	{};


#define STATIC_CHECK( expr, msg )\
{\
class _##msg {}; \
	( void )sizeof( ( CompileTimeChecker< ( expr ) >( _##msg() ) ) );\
}

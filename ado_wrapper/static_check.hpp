
#pragma once


template< bool >
struct CompileTimeChecker
{
	CompileTimeChecker(...);
};
template<> struct CompileTimeChecker<false> {};


#define STATIC_CHECK( expr, msg )\
{\
class __error__##msg {}; \
	( void )sizeof( ( CompileTimeChecker< ( expr ) >( __error__##msg() ) ) );\
}

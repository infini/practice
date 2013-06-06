
#pragma once


template< bool >
struct CompileTimeChecker
{
	CompileTimeChecker(...);
};
template<> struct CompileTimeChecker<false> {};


#define STATIC_CHECK( expr, msg )\
{\
class ERROR_##msg {}; \
	( void )sizeof( ( CompileTimeChecker< ( expr ) >( ERROR_##msg() ) ) );\
}

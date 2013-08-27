
#pragma once


#define LINE1(x) #x
#define LINE(x) LINE1(x)
#define TODO(msg) message ( __FILE__ "(" LINE(__LINE__) "): [TODO] " #msg )



template< bool >
struct CompileTimeChecker	{	CompileTimeChecker(...);	};

template<>
struct CompileTimeChecker< false >	{};


#define STATIC_CHECK( expr, msg )\
{\
class _##msg {}; \
	( void )sizeof( ( CompileTimeChecker< ( expr ) >( _##msg() ) ) );\
}

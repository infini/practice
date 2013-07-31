
#include "stdafx.h"
#include "stdlib.h"

#include <stdio.h>
#include <iostream>
#include <vector>

#include "exception.h"


class _A
{
	int nA;
};

class _B
{
	int nB;
};

class _C : public _A
{
	int nC;
};

template< class T >
class SmartPtr
{
public:
	explicit SmartPtr( T* pointee ) : pointee_( pointee ) {}
	SmartPtr& operator=( const SmartPtr& other )	{	pointee_ = other.pointee_;	return *this;	}
	~SmartPtr() {}

	T* get() const {	return pointee_;	}

	T& operator * () const	{	return *pointee_;	}

	T* operator -> () const	{	return pointee_;	}

 	operator T* ()	{	return pointee_;	}
// 
// 	operator void* () {	return pointee_;	}
	/*

	bool operator ! () const	{	return pointee_ == 0;	}


	inline	friend bool operator == ( const SmartPtr& lhs, const T* rhs )
	{
		return lhs.pointee_ == rhs;
	}

	inline	friend bool operator == ( const T* lhs, const SmartPtr& rhs )
	{
		return lhs == rhs.pointee_;
	}

	inline	friend bool operator != ( const SmartPtr& lhs, const T* rhs )
	{
		return lhs.pointee_ != rhs;
	}

	inline	friend bool operator != ( const T* lhs, const SmartPtr& rhs )
	{
		return lhs != rhs.pointee_;
	}

//  	template< class U >
// 	inline friend bool operator == ( const SmartPtr& lhs, const U* rhs )
// 	{
// 		return lhs.pointee_ == rhs;
// 	}

	template< class U >
	inline friend bool operator == ( const U* lhs, const SmartPtr& rhs )
	{
		return (void*)lhs == (void*)rhs.pointee_;
	}

	template< class U >
	inline friend bool operator != ( const SmartPtr& lhs, const U* rhs )
	{
		return lhs.pointee_ != rhs;
	}

	template< class U >
	inline friend bool operator != ( const U* lhs, const SmartPtr& rhs )
	{
		return lhs != rhs.pointee_;
	}


 	template< class U >
 	bool operator == ( const SmartPtr< U >& rhs )	const
 	{	
 		return pointee_ == rhs;
 	}

 	template< class U >
 	bool operator != ( const SmartPtr< U >& rhs ) 		{	return pointee_ != rhs.get();	}
*/
private:
	T* pointee_;

};

class Base
{
public:
	Base()	{}
	virtual ~Base()	{}
	int		get()	{	return 0;	}
	int		get( int i )	{	return i;	}
};

class Derived : public Base
{
public:
	int		get()	{	return 0;	}

	int		set( int i )	{	Base::get( i );	}
};

template< typename C >
class A
{
public:
	typedef typename C::iterator iter;
	typedef C cont;
};

template< typename C >
void f( const C& con )
{
	C::iterator it;
	/*
	if( con.size() >= 2 )
	{
		std::vector<_T>::const_iterator itr( con.begin() );

		++itr;

		int v = *itr;

		std::cout << v;
	}
	*/
}


template< typename T >
class Rational
{
public:
	Rational( const T & numerator = 0, const T & denominator = 1 )	{}

	const T numerator() const	{	return _numerator;	}
	const T denominator() const	{	return _denominator;	}

	friend Rational operator * ( const Rational & lhs, const Rational & rhs )
	{
		return Rational( lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator() );
	}

private:
	T	_numerator;
	T	_denominator;
};

template< typename T >
//template< typename Rational >
const Rational< T > operator * ( const Rational< T > & lhs, const Rational< T > & rhs )
{
	return Rational< T >( lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator() );
}


// class _Construct
// {
// public:
// 	_Construct() : nnnnn( 0 ), _temp( 0 ), _temp2( 0 )	{}
// 	/*explicit */_Construct( const int temp/*, const int temp2*/ ) : _temp( temp )/*, _temp2( temp2 )*/	{}
// 
// 	bool	operator == ( const _Construct & /*lhs*/ )	{	return true;	}
// 
// 	int nnnnn;
// 	const int _temp;
// 	int _temp2;
// 
// // private:
// // 	_Construct( const _Construct& a );
// };

#include <list>
#include <fstream>
#include <set>
#include <map>

using namespace std;

struct _data
{
	_data() {}

	int n;
	float b;
// 	_data( const int k ) : m_key( k ), m_data( 0 ) {}
// 	const int m_key;
// 	int m_data;
// 
// 	bool	operator < (  const _data & rhs ) const
// 	{
// 		return m_key < rhs.m_key;
// 	}
// 
// 	_data & operator = ( const _data & rhs )
// 	{
// 		m_data	= rhs.m_data;
// 		return *this;
// 	}

};

class _test
{
public:
	int		get() const	{	return n;	}

private:
	int n;
};

struct predicate : public unary_function< _test, bool >
{
	bool	operator()( const _test & v )
	{
		return v.get() > 0;
	}
};

#include <algorithm>

#include <omp.h>

static const int MAX_COUNT = 100000000;

struct _tt
{
	int n;
	int nn;



	
};

// struct _ttt
// {
// 	_tt* p;
// 
// 	_ttt( _tt* _p )
// 	{
// 		p( _p );
// 	}
// };

void f(int x)
{
	int i;
	if (x == 0)
	{
		i = 0;
	}
}

class Ref
{
public:
	int m_ref;

	Ref() : m_ref( 1 ) {}
	~Ref() {  }
};

void modify( const int & ref )
{
	const int n = ref;

	n;
	n;
	n;
	n;
	n;
	n;

	int nn = 0;
	nn = 2;
}

#include <boost/any.hpp>
#include <Windows.h>


int	_tmain( int /*argc*/, _TCHAR* /*argv[]*/ )
{
	const size_t sizePage = ::GetLargePageMinimum() / ( 1024 /** 1024*/ );

	std::cout << "GetLargePageMinimum : " << sizePage << "kb" << std::endl;

// 	boost::any var_any = 0;
// 	var_any = 3.14;
// 	var_any = std::string( "test" );
// 
// 	auto var_auto = 0;
// 	var_auto = 3.14;
// 	//var_auto = std::string( "test" );
// 
// 	ExceptionDerived derived;
// 	derived.func();

// 	Ref* p = new Ref;
// 
// 	p->m_ref = 10;
// 
// 	modify( p->m_ref + 20 );
// 
// 	p->Ref::~Ref();
// 
// 	int* leak = new int[10];
// 
// 	std::string abcde = "abcd" + 'e';
// 
// 	const int n = 100;
// 	char overflow[100];
// 
// 	overflow[n] = 0;
// 
// 	delete [] leak;


// 	_tt* original = new _tt( 1, 2 );
// 
// 	_ttt* p = new _ttt( original );
// 	::omp_set_num_threads( 2 );
// 	::omp_set_nested( 10 );
// 
// 	const int n = ::omp_get_nested();
// 
// #pragma omp parallel for
// 	for( int nth = 0; nth < MAX_COUNT; ++nth ) {
// 		__noop;
// 	}

// 	set<_data> container;
// 	set<_data> container2;
// 	for( int nth = 0; nth < 5; ++nth )
// 		container.insert( _data( nth ) );
// 
// 	set<_data>::iterator itr = container.find( 2 );
// 
// 	(*itr).m_data = 10;
// 
// 	container = container2;

// 	Base* pBase = new Base;
// 	Derived* pDerived	= dynamic_cast<Derived*>( pBase );
// 	Derived& rDerived	= dynamic_cast<Derived&>( *pBase );
// 	//_Construct _array[10] = { 0 };
// 
// 	float a = 2;
// 	_Construct c = (_Construct)a;
// 
// 	if( c == 1 ){ __noop;}
// 
// 	std::vector<_Construct> _vec;
// 	std::vector<_Construct>* p = new std::vector<_Construct>( 100, 2 );
// 
// 	const int n1 = p->front().nnnnn;
// 	const int n2 = p->front()._temp;
// 	const int n3 = p->front()._temp2;

	__noop;

// 	Rational< int > _f( 1, 2 );
// 	Rational< int > result = _f * 2;

// 	SmartPtr< _A > sp1( new _A );
// 	SmartPtr< _A > sp2( new _A );
// 	_A* pA	= NULL;
// 	_B* pB	= NULL;
// 	_C* pC	= NULL;
// 
// 	_A* newA	= new _A;
// 
// 	SmartPtr< _A > sp3( newA );
// 	SmartPtr< _B > sp4( (_B*)newA );
// 
// //	delete sp1;
// 
// 	if( sp1 == sp2 )
// 	{
// 		return;
// 	}
// 
// //	if( sp3 == sp4 )
// 	{
// 		return;
// 	}
// 
// 	if( !sp1 )
// 	{
// 		return;
// 	}
// 
// 	if( !!sp1 )
// 	{
// 		return;
// 	}
// 
// 	if( sp1 == pA )
// 	{
// 		return;
// 	}

// 	std::vector<int> con;
// 	std::vector<int>::iterator it;
// 
// 	
// 	for( int nth = 2; nth < 5; ++nth )
// 		con.push_back( nth );
// 
// 	f( con );
// 
// 	A<std::vector<int> >::iter i;

	return 0;
}


#pragma once

//#include <exception>


class ExceptionBase
{
public:
	virtual void	func() throw();
};


class ExceptionDerived : public ExceptionBase
{
public:
	virtual void	func() throw();
};

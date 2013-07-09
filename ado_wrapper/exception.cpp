
#include "stdafx.h"
#include "exception.h"


namespace exceptions {

	const char* commaon_error::what() const throw()
	{
		return "common error";
	}
}

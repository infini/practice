
#pragma once

#include <exception>


namespace exceptions {

	struct exception : std::exception
	{
		virtual const char* what() const throw() = 0;
	};

	struct commaon_error : exception
	{
		virtual const char* what() const;
	};
}

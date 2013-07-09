
#include "stdafx.h"
#include "json_serialization.h"
#include <json/json.h>
#include <vector>
#include <iostream>
#include "stop_watch.h"

#ifdef _DEBUG
#pragma comment( lib, "jsond.lib" )
#else
#pragma comment( lib, "json.lib" )
#endif


JSONSerialization::JSONSerialization()
{
}

JSONSerialization::~JSONSerialization()
{
}

void	JSONSerialization::func()
{
	std::vector<int> container;
	for( int nth = 0; nth < 1000; ++nth ) {
		container.push_back( nth );
	}

	std::cout << "container size : " << container.size() << std::endl;

	StopWatch sw;

	for( int nth = 0; nth < 1000; ++nth ) {
		// Serialize it.
		// Deserialize the serialized data.
	}

	std::cout << "json : " << sw.now() << std::endl;
}

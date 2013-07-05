// msgpack.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include ".\include\msgpack.hpp"
#ifdef _DEBUG
#pragma comment( lib, "msgpackd.lib" )
#else
#pragma comment( lib, "msgpack.lib" )
#endif

#include <vector>
#include <iostream>


int _tmain()
{
	std::vector<int> containerInt;
	for( int nth = 0; nth < 1000; ++nth ) {
		containerInt.push_back( nth );
	}

	std::vector<std::string> target;
	target.push_back("Hello,");
	target.push_back("World!");

	// Serialize it.
	msgpack::sbuffer buffer;  // simple buffer
	msgpack::pack(&buffer, containerInt);

	std::cout << "packed buffer size : " << buffer.size() << std::endl;

	// Deserialize the serialized data.
 	msgpack::unpacked msg;    // includes memory pool and deserialized object
 	msgpack::unpack(&msg, buffer.data(), buffer.size());
 	msgpack::object obj = msg.get();

	std::cout << "unpacked msg size : " << sizeof( msg ) << std::endl;
 
 	// Print the deserialized object to stdout.
	std::cout << "msg obj : " << obj << std::endl;    // ["Hello," "World!"]
 
 	// Convert the deserialized object to staticaly typed object.
  	std::vector<int> result;
  	obj.convert(&result);
  
  	// If the type is mismatched, it throws msgpack::type_error.
  	std::vector<int> temp = obj.as< std::vector<int> >();

	std::cout << temp.size() << std::endl;

	return 0;
}

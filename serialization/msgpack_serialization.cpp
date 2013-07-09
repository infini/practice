
#include "stdafx.h"
#include "msgpack_serialization.h"
#include <msgpack.hpp>
#include <vector>
#include <iostream>
#include "stop_watch.h"

#ifdef _DEBUG
#pragma comment( lib, "msgpackd.lib" )
#else
#pragma comment( lib, "msgpack.lib" )
#endif


MsgPackSerialization::MsgPackSerialization()
{
}

MsgPackSerialization::~MsgPackSerialization()
{
}

void	MsgPackSerialization::func()
{
	std::vector<int> container;
	for( int nth = 0; nth < 1000; ++nth ) {
		container.push_back( nth );
	}

	std::cout << "container size : " << container.size() << std::endl;

	StopWatch sw;

	for( int nth = 0; nth < 1000; ++nth ) {
		// Serialize it.
		msgpack::sbuffer buffer;  // simple buffer
		msgpack::pack( &buffer, container );

		std::cout << "packed buffer size : " << buffer.size() << ", sizeof : " << sizeof( buffer ) << std::endl;

		// Deserialize the serialized data.
		msgpack::unpacked msg;    // includes memory pool and deserialized object
		msgpack::unpack( &msg, buffer.data(), buffer.size() );
		msgpack::object obj = msg.get();
	}

	std::cout << "msgpack : " << sw.now() << std::endl;

//	std::cout << "unpacked obj sizeof : " << sizeof( obj ) << ", unpacked msg sizeof : " << sizeof( msg ) << std::endl;

	// Print the deserialized object to stdout.
	//std::cout << "msg obj : " << obj << std::endl;    // ["Hello," "World!"]

	// Convert the deserialized object to staticaly typed object.
//	std::vector<int> result;
//	obj.convert(&result);

	// If the type is mismatched, it throws msgpack::type_error.
//	std::vector<int> temp = obj.as< std::vector<int> >();
}

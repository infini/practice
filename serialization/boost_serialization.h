
#pragma once

#include <boost\serialization\serialization.hpp>
#include <vector>


class BoostSerialization
{
public:
	BoostSerialization();
	~BoostSerialization();

	static void	func();


private:
	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & container_;
	}


private:
	std::vector<int> container_;
};

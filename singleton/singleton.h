
#pragma once


class Singleton
{
public:
	Singleton();
	~Singleton();

	static	Singleton*	getInstance()
	{
		static Singleton singleton;

		return &singleton;
	}

};

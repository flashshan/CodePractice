#pragma once

#include <typeinfo>

class ITest {
public:
	const char* GetName()
	{
		return typeid(this).name();
	}

	virtual bool RunTest() = 0;

	virtual ~ITest() {}
};

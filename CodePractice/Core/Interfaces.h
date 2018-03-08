#pragma once


class ITest {
public:
	virtual bool RunTest() = 0;

	virtual ~ITest() {}
};

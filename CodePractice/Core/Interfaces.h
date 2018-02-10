#pragma once

#include <vector>

using namespace std;

class ITest {
public:
	virtual bool RunTest() = 0;

	virtual ~ITest() {}
};


class TestCases {
public:
	virtual ~TestCases() 
	{
		for (unsigned int i = 0; i < testCases_.size(); ++i)
			delete testCases_[i];
	}

	virtual bool RunAllTests()
	{
		bool res = true;
		for (unsigned int i = 0; i < testCases_.size(); ++i)
		{
			if (!testCases_[i]->RunTest())
			{
				res = false;
				break;
			}
		}
		return res;
	}

	void AddTestCase(ITest *i_testCase)
	{
		testCases_.push_back(i_testCase);
	}

private:
	std::vector<ITest *> testCases_;
};
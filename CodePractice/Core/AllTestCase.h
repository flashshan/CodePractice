#pragma once

#include "Interfaces.h"
#include <vector>

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

	virtual void AddEasyTestCases() = 0;
	virtual void AddMediumTestCases() = 0;
	virtual void AddHardTestCases() = 0;

private:
	std::vector<ITest *> testCases_;
};


class ArrayTestCases : public TestCases
{
public:
	ArrayTestCases()
	{
		AddEasyTestCases();
		AddMediumTestCases();
		AddHardTestCases();
	}

	virtual void AddEasyTestCases() override;
	virtual void AddMediumTestCases() override;
	virtual void AddHardTestCases() override;
};

class DPTestCases : public TestCases
{
public:
	DPTestCases()
	{
		AddEasyTestCases();
		AddMediumTestCases();
		AddHardTestCases();
	}

	virtual void AddEasyTestCases() override;
	virtual void AddMediumTestCases() override;
	virtual void AddHardTestCases() override;
};

class GraphTestCases : public TestCases
{
public:
	GraphTestCases()
	{
		AddEasyTestCases();
		AddMediumTestCases();
		AddHardTestCases();
	}

	virtual void AddEasyTestCases() override;
	virtual void AddMediumTestCases() override;
	virtual void AddHardTestCases() override;
};

class ListTestCases : public TestCases
{
public:
	ListTestCases()
	{
		AddEasyTestCases();
		AddMediumTestCases();
		AddHardTestCases();
	}

	virtual void AddEasyTestCases() override;
	virtual void AddMediumTestCases() override;
	virtual void AddHardTestCases() override;
};

class MathTestCases : public TestCases
{
public:
	MathTestCases()
	{
		AddEasyTestCases();
		AddMediumTestCases();
		AddHardTestCases();
	}

	virtual void AddEasyTestCases() override;
	virtual void AddMediumTestCases() override;
	virtual void AddHardTestCases() override;
};

class StringTestCases : public TestCases
{
public:
	StringTestCases()
	{
		AddEasyTestCases();
		AddMediumTestCases();
		AddHardTestCases();
	}

	virtual void AddEasyTestCases() override;
	virtual void AddMediumTestCases() override;
	virtual void AddHardTestCases() override;
};

class TreeTestCases : public TestCases
{
public:
	TreeTestCases()
	{
		AddEasyTestCases();
		AddMediumTestCases();
		AddHardTestCases();
	}

	virtual void AddEasyTestCases() override;
	virtual void AddMediumTestCases() override;
	virtual void AddHardTestCases() override;
};

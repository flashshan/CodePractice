#pragma once

#include "Interfaces.h"
#include "ConfigMgr.h"

#include <vector>


template<typename T>
const char* GetClassName(T) 
{
	return typeid(T).name();
}


class TestCases {
public:
	TestCases(ProblemClassConfig *i_config)
	{
		classConfig_ = i_config;
	}

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

	void TryAddTestCase(ITest *i_testCase)
	{
		if (classConfig_->ProblemSet.find(string(i_testCase->GetName())) != classConfig_->ProblemSet.end())
		{
			testCases_.push_back(i_testCase);
		}
		else
		{
			delete i_testCase;		    // if it is not needed, delete it
		}
	}

	virtual void AddEasyTestCases() = 0;
	virtual void AddMediumTestCases() = 0;
	virtual void AddHardTestCases() = 0;

protected:
	ProblemClassConfig* classConfig_;

private:		
	std::vector<ITest *> testCases_;
};


class ArrayTestCases : public TestCases
{
public:
	ArrayTestCases(ProblemClassConfig *i_config) : TestCases(i_config)
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
	DPTestCases(ProblemClassConfig *i_config) : TestCases(i_config)
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
	GraphTestCases(ProblemClassConfig *i_config) : TestCases(i_config)
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
	ListTestCases(ProblemClassConfig *i_config) : TestCases(i_config)
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
	MathTestCases(ProblemClassConfig *i_config) : TestCases(i_config)
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
	StringTestCases(ProblemClassConfig *i_config) : TestCases(i_config)
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
	TreeTestCases(ProblemClassConfig *i_config) : TestCases(i_config)
	{
		AddEasyTestCases();
		AddMediumTestCases();
		AddHardTestCases();
	}

	virtual void AddEasyTestCases() override;
	virtual void AddMediumTestCases() override;
	virtual void AddHardTestCases() override;
};

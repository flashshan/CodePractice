#include <iostream>

#include "Core\AllTestCase.h"

using namespace std;


void ExecuteProblem()
{
	ConfigMgr* configMgr = new ConfigMgr();
	configMgr->LoadConfigFromXml();

	// TestArray
	{
		ProblemClassConfig *tempClassConfig = configMgr->GetTypeConfig("Array");
		if (tempClassConfig != nullptr)
		{
			ArrayTestCases *arrayTestCases = new ArrayTestCases(tempClassConfig);
			if (!arrayTestCases->RunAllTests())
			{
				cout << "Test array failed!";
				return;
			}
			delete arrayTestCases;
		}		
	}

	// TestString
	{
		ProblemClassConfig *tempClassConfig = configMgr->GetTypeConfig("String");
		if (tempClassConfig != nullptr)
		{
			StringTestCases *stringTestCases = new StringTestCases(tempClassConfig);
			if (!stringTestCases->RunAllTests())
			{
				cout << "Test string failed!";
				return;
			}
			delete stringTestCases;
		}		
	}

	// TestMath
	{
		ProblemClassConfig *tempClassConfig = configMgr->GetTypeConfig("Math");
		if (tempClassConfig != nullptr)
		{
			MathTestCases *mathTestCases = new MathTestCases(tempClassConfig);
			if (!mathTestCases->RunAllTests())
			{
				cout << "Test math failed!";
				return;
			}
			delete mathTestCases;
		}		
	}

	// TestList
	{
		ProblemClassConfig *tempClassConfig = configMgr->GetTypeConfig("List");
		if (tempClassConfig != nullptr)
		{
			ListTestCases *listTestCases = new ListTestCases(tempClassConfig);
			if (!listTestCases->RunAllTests())
			{
				cout << "Test list failed!";
				return;
			}
			delete listTestCases;
		}		
	}

	// TestTree
	{
		ProblemClassConfig *tempClassConfig = configMgr->GetTypeConfig("Tree");
		if (tempClassConfig != nullptr)
		{
			TreeTestCases *treeTestCases = new TreeTestCases(tempClassConfig);
			if (!treeTestCases->RunAllTests())
			{
				cout << "Test tree failed!";
				return;
			}
			delete treeTestCases;
		}		
	}

	// TestDP
	{
		ProblemClassConfig *tempClassConfig = configMgr->GetTypeConfig("DP");
		if (tempClassConfig != nullptr)
		{
			DPTestCases *dpTestCases = new DPTestCases(tempClassConfig);
			if (!dpTestCases->RunAllTests())
			{
				cout << "Test DP failed!";
				return;
			}
			delete dpTestCases;
		}		
	}

	// TestGraph
	{
		ProblemClassConfig *tempClassConfig = configMgr->GetTypeConfig("Graph");
		if (tempClassConfig != nullptr)
		{
			DPTestCases *graphTestCases = new DPTestCases(tempClassConfig);
			if (!graphTestCases->RunAllTests())
			{
				cout << "Test Graph failed!";
				return;
			}
			delete graphTestCases;
		}		
	}

	cout << "Past all tests!";
	configMgr->ClearConfig();
	delete configMgr;
}



int main()
{	
	ExecuteProblem();

#if defined _DEBUG
	_CrtDumpMemoryLeaks();		   // 2 byte for singletons
#endif // _DEBUG

	system("pause");
	return 0;
}
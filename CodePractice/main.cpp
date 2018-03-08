#include <iostream>

#include "Core\AllTestCase.h"

using namespace std;

#define TestArray
#define TestString
#define TestMath

#define TestList
#define TestTree
#define TestDP
#define TestGraph


int main()
{
#ifdef TestArray
	{
		ArrayTestCases arrayTestCases;
		if (!arrayTestCases.RunAllTests())
		{
			cout << "Test array failed!";
			return -1;
		}
	}
#endif // TestArray

#ifdef TestString
	{
		StringTestCases stringTestCases;
		if (!stringTestCases.RunAllTests())
		{
			cout << "Test string failed!";
			return -1;
		}
	}
#endif // TestString

#ifdef TestMath
	{
		MathTestCases mathTestCases;
		if (!mathTestCases.RunAllTests())
		{
			cout << "Test string failed!";
			return -1;
		}
	}
#endif // TestString

#ifdef TestList
	{
		ListTestCases listTestCases;
		if (!listTestCases.RunAllTests())
		{
			cout << "Test list failed!";
			return -1;
		}
	}
#endif // TestList

#ifdef TestTree
	{
		TreeTestCases treeTestCases;
		if (!treeTestCases.RunAllTests())
		{
			cout << "Test tree failed!";
			return -1;
		}
	}
#endif // TestTree

#ifdef TestDP
	{
		DPTestCases dpTestCases;
		if (!dpTestCases.RunAllTests())
		{
			cout << "Test DP failed!";
			return -1;
		}
	}
#endif // TestDP

#ifdef TestGraph
	{
		GraphTestCases graphTestCases;
		if (!graphTestCases.RunAllTests())
		{
			cout << "Test Graph failed!";
			return -1;
		}
	}
#endif // TestGraph

	cout << "Past all tests!";

#if defined _DEBUG
	_CrtDumpMemoryLeaks();		   // 2 byte for singletons
#endif // _DEBUG

	return 0;
}
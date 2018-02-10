#include "Type/Array/AllTestCase.h"
#include "Type/List/AllTestCase.h"


int main()
{
	ArrayTestCases arrayTestCases;
	if (!arrayTestCases.RunAllTests())
	{
		cout << "Test array failed!";
		return -1;
	}

	ListTestCases listTestCases;
	if (!listTestCases.RunAllTests())
	{
		cout << "Test list failed!";
		return -1;
	}




	return 0;
}
#pragma once

#include "Core/CoreMinimal.h"

using namespace std;
/// Leetcode No.
/*

*/

class T : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test ." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			int m;
			cin >> m;
			vector<int> res = twoSum(nums, m);

			Output::OutputArray(res);
		}

		cout << "End test ." << endl << endl;
		return true;
	}

private:
	
};
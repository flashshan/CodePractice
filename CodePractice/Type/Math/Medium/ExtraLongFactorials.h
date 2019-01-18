#pragma once

#include "Core/CoreMinimal.h"

#include <string>


using namespace std;
/// HackerRank
/*
https://www.hackerrank.com/challenges/non-divisible-subset/problem
*/

class NonDivisibleSubset : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Non-Divisible Subset." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			int m;
			cin >> m;
			int res = nonDivisibleSubset(n, nums);

			cout << res << endl;
		}

		cout << "End test Non-Divisible Subset." << endl << endl;
		return true;
	}

private:
	int nonDivisibleSubset(int k, vector <int> arr) {
		// Complete this function
		vector<int> states(k, 0);

		for (unsigned int i = 0; i < arr.size(); ++i)
		{
			++states[((arr[i] % k) + k) % k];
		}
		int res = 0;
		if (states[0] != 0)
			++res;
		if (k % 2 == 0 && states[k / 2] != 0)
			++res;
		for (int i = 1; i < k - i; ++i)
		{
			res += states[i] > states[k - i] ? states[i] : states[k - i];
		}
		return res;
	}
};
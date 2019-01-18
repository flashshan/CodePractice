#pragma once

#include "Core/CoreMinimal.h"

#include <string>

#include <algorithm>
#include <set>
#include <assert.h>

using namespace std;
/// HackerRank
/*
https://www.hackerrank.com/challenges/lilys-homework/problem
*/

class LilyHomework : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Lily's Homework." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			int res = lilysHomework(nums);

			cout << res << endl;
		}

		cout << "End test Lily's Homework." << endl << endl;
		return true;
	}

private:
	int lilysHomework(vector <int> arr) {
		// Complete this function
		int numCount = (int)arr.size();
		vector<pair<int, int>> numAndOrder;
		numAndOrder.reserve(numCount);
		for (int i = 0; i < numCount; ++i)
		{
			numAndOrder.push_back(make_pair(arr[i], i));
		}
		sort(numAndOrder.begin(), numAndOrder.end(), [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
		vector<bool> states(numCount, false);
		int res = 0, equal = 0, rings = 0;
		for (int i = 0; i < numCount; ++i)
		{
			if (!states[i])
			{
				if (numAndOrder[i].second != i)
				{
					int count = 1;
					int tempI = numAndOrder[i].second;
					states[tempI] = true;
					while (numAndOrder[tempI].second != i)
					{
						++count;
						tempI = numAndOrder[tempI].second;
						states[tempI] = true;
					}
					res += count;
					++rings;
				}
				else
					++equal;
				states[i] = true;
			}
		}
		assert(equal + rings + res == numCount);
		return res;
	}
};
#pragma once

#include "Core/CoreMinimal.h"

#include <algorithm>
#include <map>

using namespace std;
/// Leetcode No.1
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class TwoSum : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Two Sum." << endl;

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

		cout << "End test Two Sum." << endl << endl;
		return true;
	}

private:
	vector<int> twoSum(vector<int> &numbers, int target) {
		map<int, int> hmap;
		map<int, int>::iterator it;
		vector<int> res;
		int n = numbers.size();
		if (n < 2) return res;

		for (int i = 0; i < n; i++)
		{
			it = hmap.find(target - numbers[i]);
			if (it != hmap.end() && it->second != i)
			{
				res.push_back(i < it->second ? i + 1 : it->second + 1);
				res.push_back(i < it->second ? it->second + 1 : i + 1);
				break;
			}
			else
			{
				hmap[numbers[i]] = i;
			}
		}
		return res;
	}
};
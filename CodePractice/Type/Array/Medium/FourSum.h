#pragma once

#include "Core/CoreMinimal.h"

#include <algorithm>

using namespace std;
/// Leetcode No.19
/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
*/

class FourSum : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test 4 Sum." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			int m;
			cin >> m;
			vector<vector<int>> res = fourSum(nums, m);

			Output::Output2DArray(res);
		}

		cout << "End test 4 Sum." << endl << endl;
		return true;
	}

private:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());

		int size = nums.size();

		vector<vector<int>> res;
		int i = 0;
		while (i < size - 3)
		{
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) 
				break;
			if (nums[i] + nums[size - 3] + nums[size - 2] + nums[size - 1] < target)
			{
				do {
					++i;
				} while (i < size - 3 && nums[i] == nums[i - 1]);
				continue;
			}
			int j = i + 1;
			while (j < size - 2)
			{
				int begin = j + 1, end = size - 1;
				int targetValue = target - nums[i] - nums[j];
				while (begin < end)
				{
					if (nums[begin] + nums[end] < targetValue)
					{
						do {
							++begin;
						} while (begin < end && nums[begin] == nums[begin - 1]);
					}
					else if (nums[begin] + nums[end] > targetValue)
					{
						do {
							--end;
						} while (begin < end && nums[end] == nums[end + 1]);
					}
					else
					{
						res.push_back(vector<int>{nums[i], nums[j], nums[begin], nums[end]});
						do {
							++begin;
						} while (begin < end && nums[begin] == nums[begin - 1]);
						do {
							--end;
						} while (begin < end && nums[end] == nums[end + 1]);
					}
				}
				do {
					++j;
				} while (j < size - 2 && nums[j] == nums[j - 1]);
			}
			do {
				++i;
			} while (i < size - 3 && nums[i] == nums[i - 1]);

		}
		return res;
	}
};
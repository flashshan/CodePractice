#pragma once

#include "Core/CoreMinimal.h"

#include <algorithm>

using namespace std;
/// Leetcode No.15
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]

contain duplicates, can not return duplicate triplets
*/

class ThreeSum : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test 3 Sum." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			vector<vector<int>> res = threeSum(nums);

			Output::Output2DArray(res);
		}

		cout << "End test 3 Sum." << endl << endl;
		return true;
	}

private:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		int size = nums.size();

		vector<vector<int>> res;
		int i = 0;
		while(i < size - 2)
		{
			int begin = i + 1, end = size - 1;
			while (begin < end)
			{
				if (nums[i] + nums[begin] + nums[end] < 0)
				{
					do {
						++begin;
					} while (begin < end && nums[begin] == nums[begin - 1]);
				}
				else if (nums[i] + nums[begin] + nums[end] > 0)
				{
					do {
						--end;
					} while (begin < end && nums[end] == nums[end + 1]);
				}
				else
				{
					res.push_back(vector<int>{nums[i], nums[begin], nums[end]});
					do {
						++begin;
					} while (begin < end && nums[begin] == nums[begin - 1]);
					do {
						--end;
					} while (begin < end && nums[end] == nums[end + 1]);
				}
			}
			do {
				++i;
			} while (i < size - 2 && nums[i] == nums[i - 1]);
		}
		return res;
	}
};
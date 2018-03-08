#pragma once

#include "Core/CoreMinimal.h"

#include <algorithm>

using namespace std;
/// Leetcode No.16
/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class ThreeSumCloest : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test 3 Sum closet." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			int m;
			cin >> m;
			int res = threeSumClosest(nums, m);

			cout << res << endl;
		}

		cout << "End test 3 Sum closet." << endl << endl;
		return true;
	}

private:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());

		int size = nums.size();
		int res, minDistance = INT_MAX;
		
		int i = 0;
		while(i < size - 2)
		{
			int begin = i + 1, end = size - 1;
			while (begin < end)
			{
				int distance = nums[i] + nums[begin] + nums[end] - target;
				distance = distance > 0 ? distance : -distance;
				if (distance < minDistance)
				{
					minDistance = distance;
					res = nums[i] + nums[begin] + nums[end];
				}

				if (nums[i] + nums[begin] + nums[end] <= target)
				{		
					do {
						++begin;
					} while (begin < end && nums[begin] == nums[begin - 1]);
				}
				else
				{
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
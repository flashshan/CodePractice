#pragma once

#include "Core/CoreMinimal.h"

using namespace std;
/// Leetcode No.27
/*
Given an array and a value, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.
*/

class RemoveElement : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Remove Element." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			int m;
			cin >> m;
			int res = removeElement(nums, m);

			cout << res << endl;
		}

		cout << "End test Remove Element." << endl << endl;
		return true;
	}

private:
	int removeElement(vector<int>& nums, int val) {
		int size = nums.size();
		if (size == 0)
			return 0;

		int begin = 0;
		for (int i = 0; i < size; ++i)
		{
			if (nums[i] != val)
			{
				nums[begin++] = nums[i];
			}
		}
		return begin;
	}
};
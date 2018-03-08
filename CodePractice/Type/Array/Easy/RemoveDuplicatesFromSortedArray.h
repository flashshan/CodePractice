#pragma once

#include "Core/CoreMinimal.h"


using namespace std;
/// Leetcode No.26
/*
Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/

class RemoveDuplicatesFromSortedArray : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Remove Duplicates from Sorted Array." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			int m;
			cin >> m;
			int res = removeDuplicates(nums);

			cout << res << endl;
		}

		cout << "End test Remove Duplicates from Sorted Array." << endl << endl;
		return true;
	}

private:
	int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		if (size == 0)
			return 0;
		
		int begin = 0;
		for (int i = 1; i < size; ++i)
		{
			if (nums[i] != nums[begin])
			{
				nums[++begin] = nums[i];
			}
		}
		return begin + 1;
	}
};
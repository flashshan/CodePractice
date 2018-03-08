#pragma once

#include "Core/CoreMinimal.h"


using namespace std;
/// Leetcode No.4
/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

class MedianofTwoSortedArrays : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Median of Two Sorted Arrays." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			int m;
			vector<int> nums1, nums2;
			Input::InputArray(nums1, n);
			
			cin >> m;
			Input::InputArray(nums2, m);

			double res = findMedianSortedArrays(nums1, nums2);

			cout << res << endl;
		}

		cout << "End test Median of Two Sorted Arrays." << endl << endl;
		return true;
	}

private:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size1 = static_cast<int>(nums1.size()), size2 = static_cast<int>(nums2.size());
		if (size1 == 0 && size2 == 0) 
			return 0.0;

		if ((size1 + size2) % 2 == 1)
			return halfSearch(nums1, 0, nums2, 0, (size1 + size2 + 1) / 2);
		else
		{
			return halfSearch(nums1, 0, nums2, 0, (size1 + size2) / 2) / 2 + halfSearch(nums1, 0, nums2, 0, (size1 + size2) / 2 + 1) / 2;
		}
	}

	double halfSearch(vector<int> &nums1, int index1, vector<int> &nums2, int index2, int k)
	{
		int size1 = static_cast<int>(nums1.size()) - index1, size2 = static_cast<int>(nums2.size()) - index2;

		if (size1 > size2)
			return halfSearch(nums2, index2, nums1, index1, k);
		if (size1 == 0)
			return nums2[index2 + k - 1];
		if (k == 1) 
			return(nums1[index1] < nums2[index2]) ? nums1[index1] : nums2[index2];

		int pa = (k / 2 < size1) ? k / 2 : size1;
		int pb = k - pa;
		if (nums1[index1 + pa - 1] < nums2[index2 + pb - 1])
			return halfSearch(nums1, index1 + pa, nums2, index2, k - pa);
		else if (nums1[index1 + pa - 1] > nums2[index2 + pb - 1])
			return halfSearch(nums1, index1, nums2, index2 + pb, k - pb);
		else
			return nums1[index1 + pa - 1];
	}
};
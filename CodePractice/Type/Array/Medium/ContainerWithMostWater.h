#pragma once

#include "Core/CoreMinimal.h"

#include <algorithm>
#include <map>

using namespace std;
/// Leetcode No.11
/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

class ContainerWithMostWater : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Container With Most Water." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			int res = maxArea(nums);

			cout << res << endl;
		}

		cout << "End test Container With Most Water." << endl << endl;
		return true;
	}

private:
	int maxArea(vector<int> &height) {
		int begin = 0, end = height.size() - 1;
		int actTotal = 0, res = 0;
		int min1 = height[begin], min2 = height[end];
		bool mark = true;
		while (begin < end)
		{
			mark = (height[begin] < height[end]) ? true : false;
			actTotal = ((mark) ? height[begin] : height[end]) * (end - begin);
			res = actTotal > res ? actTotal : res;
			if (mark)
			{
				while (min1 >= height[begin + 1])
					begin++;
				begin++;
				min1 = height[begin];
			}
			else
			{
				while (min2 >= height[end - 1])
					end--;
				end--;
				min2 = height[end];
			}
		}
		return res;
	}
};
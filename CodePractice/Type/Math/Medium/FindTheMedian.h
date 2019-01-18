#pragma once

#include "Core/CoreMinimal.h"

#include <string>


using namespace std;
/// HackerRank
/*
https://www.hackerrank.com/challenges/find-the-median/problem
*/

class FindMedian : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Find the Median." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			int res = findMedian(nums);

			cout << res << endl;
		}

		cout << "End test Find the Median." << endl << endl;
		return true;
	}

private:
	int findMedian(vector <int> arr) {
		// Complete this function

		int numCount = (int)arr.size(), median = numCount / 2;

		int begin = 0, end = numCount - 1, target = median;
		while (begin <= end)
		{
			if (begin == end)
				return arr[begin];
			if (begin + 1 == end)
				return target == 0 ? arr[begin] : arr[end];

			int cmp = arr[begin], pos = begin;
			for (int i = begin + 1; i <= end; ++i)
			{
				if (arr[i] < cmp)
					swap(arr[++pos], arr[i]);
			}
			swap(arr[begin], arr[pos]);
			if (pos - begin == target)
			{
				return arr[pos];
			}
			else if (pos - begin > target)
			{
				end = pos - 1;
			}
			else
			{
				target -= pos - begin + 1;
				begin = pos + 1;
			}
		}
		return -1;
	}
};
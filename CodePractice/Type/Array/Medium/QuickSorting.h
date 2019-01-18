#pragma once

#include "Core/CoreMinimal.h"

#include <algorithm>

using namespace std;
/// HackerRank
/*
https://www.hackerrank.com/challenges/quicksort2/problem
*/

class QuickSorting : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Quick Sorting." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			quickSort(nums);
		}

		cout << "End test Quick Sorting." << endl << endl;
		return true;
	}

private:
	void quickSort(vector <int> &arr) {
		// Complete this function

		if (arr.size() == 2)
		{
			if (arr[0] > arr[1])
				swap(arr[0], arr[1]);
			cout << arr[0] << " " << arr[1] << endl;
			return;
		}

		vector<int> smaller, larger;
		int cmp = arr[0];
		for (unsigned int i = 1; i < arr.size(); ++i)
		{
			if (arr[i] < cmp)
				smaller.push_back(arr[i]);
			else if (arr[i] > cmp)
				larger.push_back(arr[i]);
		}
		if (smaller.size() > 1)
			quickSort(smaller);
		if (larger.size() > 1)
			quickSort(larger);

		for (unsigned int i = 0; i < smaller.size(); ++i)
		{
			arr[i] = smaller[i];
			cout << smaller[i] << " ";
		}
		arr[smaller.size()] = cmp;
		cout << cmp;
		for (unsigned int i = 0; i < larger.size(); ++i)
		{
			arr[i + smaller.size() + 1] = larger[i];
			cout << " " << larger[i];
		}
		cout << endl;
	}
};
#pragma once

#include "Core/CoreMinimal.h"

#include <string>

#include <algorithm>
#include <set>
#include <assert.h>

using namespace std;
/// HackerRank
/*
https://www.hackerrank.com/challenges/ctci-merge-sort/problem
*/

class CountingInversions : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Counting Inversions." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			long res = countInversions(nums);

			cout << res << endl;
		}

		cout << "End test Counting Inversions." << endl << endl;
		return true;
	}

private:
	// method 1 O(n ^ 2)
	/*long countInversions(vector<int> arr) {
		// Complete this function
		int numCount = arr.size();

		long res = 0;
		for (int i = 1; i < numCount; ++i)
		{
			auto it = upper_bound(arr.begin(), arr.begin() + i, arr[i]);
			int index = it - arr.begin();

			int store = arr[i];
			for (int j = i; j > index; --j)
				arr[j] = arr[j - 1];
			arr[index] = store;
			res += long(i - index);
		}
		return res;
	}*/

	// method 2	 O(n log n)
	long countInversions(vector<int> arr) {
		return mergeSort(arr, 0, int(arr.size() - 1));
	}

	long mergeSort(vector<int> &arr, int start, int end) {
		if (start == end)
			return 0;
		int mid = (start + end) / 2;
		long count = 0;
		count += mergeSort(arr, start, mid);   //left inversions
		count += mergeSort(arr, mid + 1, end);  //right inversions
		count += merge(arr, start, end);   // split inversions.
		return count;
	}

	long merge(vector<int> &arr, int start, int end) {
		int mid = (start + end) / 2;
		vector<int> newArr(end - start + 1, 0);
		int curr = 0;
		int i = start;
		int j = mid + 1;
		long count = 0;
		while (i <= mid && j <= end) {
			if (arr[i] > arr[j]) {
				newArr[curr++] = arr[j++];
				count += mid - i + 1;      // Tricky part.
			}
			else
				newArr[curr++] = arr[i++];
		}
		
		while (i <= mid) {
			newArr[curr++] = arr[i++];
		}

		while (j <= end) {
			newArr[curr++] = arr[j++];
		}
	    
		for (int i = 0; i < end - start + 1; ++i)
		{
			arr[start + i] = newArr[i];
		}
		return count;
	}
};
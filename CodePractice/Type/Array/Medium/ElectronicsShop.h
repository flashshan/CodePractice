#pragma once

#include "Core/CoreMinimal.h"

#include <algorithm>

using namespace std;
/// HackerRank
/*
Monica wants to buy exactly one keyboard and one USB drive from her favorite electronics store. The store sells different brands of keyboards and  different brands of USB drives. Monica has exactly  dollars to spend, and she wants to spend as much of it as possible (i.e., the total cost of her purchase must be maximal).

Given the price lists for the store's keyboards and USB drives, find and print the amount of money Monica will spend. If she doesn't have enough money to buy one keyboard and one USB drive, print -1 instead.

Note: She will never buy more than one keyboard and one USB drive even if she has the leftover money to do so.

Input Format

The first line contains three space-separated integers describing the respective values of  (the amount of money Monica has),  (the number of keyboard brands) and  (the number of USB drive brands).
The second line contains  space-separated integers denoting the prices of each keyboard brand.
The third line contains  space-separated integers denoting the prices of each USB drive brand.

Constraints

The price of each item is in the inclusive range .
Output Format

Print a single integer denoting the amount of money Monica will spend. If she doesn't have enough money to buy one keyboard and one USB drive, print -1 instead.

Sample Input 0

10 2 3
3 1
5 2 8

Sample Output 0
9
*/

class ElectronicsShop : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Electronics Shop." << endl;

		int target;
		while (cin >> target)
		{
			if (target == 0)
				break;

			int n, m;
			cin >> n >> m;
			vector<int> nums1;
			Input::InputArray(nums1, n);
			vector<int>	nums2;
			Input::InputArray(nums2, m);

			int res = getMoneySpent(nums1, nums2, target);

			cout << res << endl;
		}

		cout << "End test Electronics Shop." << endl << endl;
		return true;
	}

private:
	int getMoneySpent(vector < int > keyboards, vector < int > drives, int s) {
		// Complete this function
		int keyboardCount = (int)keyboards.size();
		int driveCount = (int)drives.size();

		sort(keyboards.begin(), keyboards.end());
		sort(drives.begin(), drives.end());

		int it1 = 0;
		int it2 = (int)(lower_bound(drives.begin(), drives.end(), s - keyboards[0]) - drives.begin()) - 1;
		if (it2 == -1)
			return -1;

		int maxValue = keyboards[it1] + drives[it2];
		while (it1 < keyboardCount - 1 && it2 >= 0)
		{
			++it1;
			while (drives[it2] > s - keyboards[it1] && it2 >= 0)
			{
				--it2;
			}
			if (it2 < 0)
				break;
			maxValue = maxValue > keyboards[it1] + drives[it2] ? maxValue : keyboards[it1] + drives[it2];
		}
		return maxValue;
	}
};
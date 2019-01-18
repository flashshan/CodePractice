#pragma once

#include "Core/CoreMinimal.h"

#include <string>

#include <algorithm>
#include <set>

using namespace std;
/// HackerRank
/*
https://www.hackerrank.com/challenges/mark-and-toys/problem
*/

class MarkAndToys : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Mark and Toys." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			int k;
			cin >> k;
			int res = maximumToys(nums, k);

			cout << res << endl;
		}

		cout << "End test Mark and Toys." << endl << endl;
		return true;
	}

private:
	// method 1		 O(n log n)
	//int maximumToys(vector <int> prices, int k) {
	//	// Complete this function
	//	sort(prices.begin(), prices.end());

	//	int res = 0;
	//	for (int i = 0; i < prices.size(); ++i)
	//	{
	//		if (k > prices[i])
	//		{
	//			k -= prices[i];
	//			++res;
	//		}
	//		else
	//			return res;
	//	}
	//	return res;
	//}

	// method 2		   O(n log k)
	int maximumToys(vector <int> prices, int k) {
		// Complete this function
		multiset<int> items;
		int totalCost = 0, priceCount = (int)prices.size();

		for (int i = 0; i < priceCount; ++i)
		{
			if (totalCost + prices[i] <= k)
			{
				totalCost += prices[i];
				items.insert(prices[i]);
			}
			else if(!items.empty())
			{
				auto it = items.end();
				--it;
				if (prices[i] < *(it))
				{
					totalCost += prices[i] - (*it);
					items.erase(it);
					items.insert(prices[i]);
				}
			}
		}
		return (int)items.size();
	}
};
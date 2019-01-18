#pragma once

#include "Core/CoreMinimal.h"

#include <string>

#include <algorithm>
#include <set>
#include <assert.h>

using namespace std;
/// HackerRank
/*
https://www.hackerrank.com/challenges/minimum-loss/problem
*/

class MinimumLoss : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Minimum Loss." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<long long> nums;
			Input::InputLongLongArray(nums, n);

			int res = minimumLoss(nums);

			cout << res << endl;
		}

		cout << "End test Minimum Loss." << endl << endl;
		return true;
	}

private:
	int minimumLoss(vector <long long> price) {
		vector<pair<long long, int>> housePrice;
		int priceCount = (int)price.size();
		for (int i = 0; i < priceCount; ++i)
		{
			housePrice.push_back(make_pair(price[i], i));
		}
		sort(housePrice.begin(), housePrice.end(), [](pair<long long, int> a, pair<long long, int> b) {return a.first > b.first; });
		long long minLoss = LLONG_MAX;
		for (int i = 0; i < priceCount - 1; ++i)
		{
			if (housePrice[i].second < housePrice[i + 1].second)
			{
				minLoss = housePrice[i].first - housePrice[i + 1].first < minLoss ? housePrice[i].first - housePrice[i + 1].first : minLoss;
			}
		}
		return (int)minLoss;
	}
};
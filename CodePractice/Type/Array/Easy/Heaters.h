#pragma once

#include "Core/CoreMinimal.h"
#include "Core/Functions.h"

#include <algorithm>

using namespace std;
/// Leetcode No.475
/*
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:
Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.
Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can b
*/

class Heaters : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Heaters." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			vector<int> heaters;
			int m;
			cin >> m;
			Input::InputArray(heaters, m);

			int res = findRadius(nums, heaters);

			cout << res << endl;
		}

		cout << "End test Heaters." << endl << endl;
		return true;
	}

private:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());

		int length1 = (int)houses.size(), length2 = (int)heaters.size();
		if (length1 == 0)
			return 0;
		if (length2 == 0)
			return -1;

		int begin = 0, res = 0;
		for (unsigned int i = 0; i < houses.size(); ++i)
		{
			while (houses[i] > heaters[begin] && begin < length2)
			{
				++begin;
			}

			if (begin == 0)
			{
				res = Math::Max<int>(res, heaters[begin] - houses[i]);
			}
			else if (begin == length2)
			{
				res = Math::Max<int>(res, houses[i] - heaters.back());
			}
			else
			{
				res = Math::Max<int>(res, Math::Min<int>(heaters[begin] - houses[i], houses[i] - heaters[begin - 1]));
			}
		}
		return res;
	}
};
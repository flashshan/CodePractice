#pragma once

#include "Core/CoreMinimal.h"

#include <string>

#include <algorithm>
#include <set>

using namespace std;
/// HackerRank
/*
https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem
*/

class FraudulentActivityNotifications : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Fraudulent Activity Notifications." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			int d;
			cin >> d;

			vector<int> nums;
			Input::InputArray(nums, n);
			
			int res = activityNotifications(nums, d);

			cout << res << endl;
		}

		cout << "End test Fraudulent Activity Notifications." << endl << endl;
		return true;
	}

private:
	int activityNotifications(vector <int> expenditure, int d) {
		// Complete this function
		int res = 0, numCount = (int)expenditure.size();
		vector<int> states(201, 0);
		for (int i = 0; i < d; ++i)
		{
			++states[expenditure[i]];
		}
		int first, second, value1, value2;
		if (d % 2 == 1)
		{
			first = d / 2;
			second = d / 2;
		}
		else
		{
			first = d / 2 - 1;
			second = d / 2;
		}

		for (int i = d; i < numCount; ++i)
		{
			int curPos = 0;
			for (int j = 0; j < 201; ++j)
			{
				if (states[j] != 0)
				{
					if (curPos <= first && curPos + states[j] > first)
						value1 = j;
					if (curPos <= second && curPos + states[j] > second)
					{
						value2 = j;
						break;
					}
					curPos += states[j];
				}
			}
			if (expenditure[i] >= value1 + value2)
				++res;
			++states[expenditure[i]];
			--states[expenditure[i - d]];
		}
		return res;
	}
};
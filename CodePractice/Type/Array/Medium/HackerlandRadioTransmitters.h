#pragma once

#include "Core/CoreMinimal.h"

#include <algorithm>

using namespace std;
/// HackerRank
/*
https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem
*/

class HackerlandRadioTransmitters : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Hackerland Radio Transmitters." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			int k;
			cin >> k;

			vector<int> nums;
			Input::InputArray(nums, n);

			int res = hackerlandRadioTransmitters(nums, k);
			cout << res << endl;
		}

		cout << "End test Hackerland Radio Transmitters." << endl << endl;
		return true;
	}

private:
	int hackerlandRadioTransmitters(vector <int> x, int k) {
		// Complete this function
		int houseCount = (int)x.size();
		int res = 0;
		sort(x.begin(), x.end());
		int start;
		vector<int>::iterator it = x.begin();
		do {
			start = *it;
			auto it2 = upper_bound(it, x.end(), start + k);
			--it2;
			it = upper_bound(it2, x.end(), *it2 + k);
			++res;
		} while (it != x.end());
		return res;
	}
};
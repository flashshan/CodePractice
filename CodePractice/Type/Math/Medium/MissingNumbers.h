#pragma once

#include "Core/CoreMinimal.h"
#include "Core/DataStructure.h"

using namespace std;

/// Leetcode No.24
/*
https://www.hackerrank.com/challenges/missing-numbers/problem
*/

class MissingNumbers : public ITest {
public:
	virtual bool RunTest() override
	{
		cout << "Start test Missing Numbers." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> arr;
			Input::InputArray(arr, n);

			int m;
			cin >> m;
			vector<int> brr;
			Input::InputArray(brr, m);

			missingNumbers(arr, brr);
		}

		cout << "End test Missing Numbers." << endl << endl;
		return true;
	}

private:
	void missingNumbers(vector <int> arr, vector <int> brr) {
		// Complete this function
		vector<int> states(201, 0);
		int original = brr[0] - 100, arrCount = (int)arr.size(), brrCount = (int)brr.size();

		for (int i = 0; i < brrCount; ++i)
		{
			++states[brr[i] - original];
		}
		for (int i = 0; i < arrCount; ++i)
		{
			--states[arr[i] - original];
		}

		for (int i = 0; i <= 200; ++i)
		{
			if (states[i] > 0)
			{
				cout << i + original << " ";
			}
		}
	}

};
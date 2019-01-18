#pragma once

#include "Core/CoreMinimal.h"

using namespace std;
/// HackerRank
/*
https://www.hackerrank.com/challenges/linkedin-practice-bitwise-and/problem
*/

class BitwiseAND : public ITest {
public:
	virtual bool RunTest() override
	{
		cout << "Start test Bitwise AND." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			int k;
			cin >> k;
			int res = GetMaxAnd(n, k);

			cout << res << endl;
		}

		cout << "End test Bitwise AND." << endl << endl;
		return true;
	}

private:
	int GetMaxAnd(int n, int k)
	{
		--k;
		if (k % 2 == 0)
			return k;
		else
		{
			int level = 2;

			int tempK = k;
			while ((tempK / 2) % 2 == 1)
			{
				level *= 2;
				tempK /= 2;
			}
			if (n >= level + k)
				return k;
			else
				return k - 1;
		}
	}
};
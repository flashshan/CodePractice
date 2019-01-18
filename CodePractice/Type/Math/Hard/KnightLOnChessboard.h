#pragma once

#include "Core/CoreMinimal.h"

#include <string>

#include <algorithm>
#include <stack>
#include <assert.h>

using namespace std;
/// Leetcode
/*
https://www.hackerrank.com/challenges/knightl-on-chessboard/problem
*/

class KnightLOnChessboard : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test KnightL on a Chessboard." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			PrintKnightL(n);
		}

		cout << "End test KnightL on a Chessboard." << endl << endl;
		return true;
	}

private:

	// wrong answer
	void PrintKnightL(int n)
	{
		vector<vector<int>> res;
		res.resize(n);
		for (int i = 0; i < n; ++i)
			res[i].resize(n);

		int targetDis = n - 1;

		for (int i = 1; i < n; ++i)
		{
			for (int j = 1; j <= i; ++j)
			{
				if (i == j)
				{
					if (targetDis % i == 0)
						res[i][j] = targetDis / i;
					else
						res[i][j] = -1;
				}
				else
				{
					int min = INT_MAX;
					for (int k = 0; k * i <= targetDis; ++k)
					{
						int targetDisForJ = targetDis - k * i;
						if (targetDisForJ % j == 0 && (targetDisForJ / j - k) % 2 == 0)
						{
							int m = targetDisForJ / j;
							min = 2 * (m > k ? m : k);
						}
					}
					if (min == INT_MAX)
					{
						res[i][j] = -1; res[j][i] = -1;
					}
					else
					{
						res[i][j] = min; res[j][i] = min;
					}
				}
			}
		}

		for (int i = 1; i < n; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

};


/* test cases:
1 + 2
1 ?2 + 3
1 + 2 / 3
1 + 2 ?- 5 / 2
(1 + 2) / -2 + 5 / -10 * (2 + -1)
*/
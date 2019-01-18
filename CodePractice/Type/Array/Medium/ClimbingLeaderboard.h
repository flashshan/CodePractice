#pragma once

#include "Core/CoreMinimal.h"

#include <algorithm>

using namespace std;
/// HackerRank
/*
https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
*/

class ClimbingLeaderboard : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Climbing the Leader board." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			int m;
			cin >> m;
			vector<int> alices;
			Input::InputArray(alices, m);
			vector<int> res = climbingLeaderboard(nums, alices);

			Output::OutputArray(res);
		}

		cout << "End test Climbing the Leader board." << endl << endl;
		return true;
	}

private:
	vector <int> climbingLeaderboard(vector <int> scores, vector <int> alice) {
		// Complete this function
		int n = (int)scores.size(), m = (int)alice.size();
		vector<int> rank(n, 0);
		rank[0] = 1;

		int currentRank = 1;
		for (int i = 1; i < n; ++i)
		{
			if (scores[i] != scores[i - 1])
				++currentRank;
			rank[i] = currentRank;
		}

		vector<int> res(m, 0);
		int currentRankPos = n - 1;
		for (int i = 0; i < m; ++i)
		{
			while (scores[currentRankPos] <= alice[i] && currentRankPos >= 0)
				--currentRankPos;
			if (currentRankPos != -1)
				res[i] = rank[currentRankPos] + 1;
			else
				res[i] = 1;
		}
		return res;
	}
};
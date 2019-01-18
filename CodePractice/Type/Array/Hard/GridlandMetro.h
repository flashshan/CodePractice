#pragma once

#include "Core/CoreMinimal.h"

#include <map>
#include <algorithm>

using namespace std;
/// HackerRank
/*
https://www.hackerrank.com/challenges/gridland-metro/problem
*/		 

class GridlandMetro : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Gridland Metro." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			int m, k;
			cin >> m >> k;

			vector<vector<int>> matrix;
			Input::Input2DArray(matrix, k, 3);
			
			long long res = gridlandMetro(n, m, k, matrix);

			cout << res << endl;
		}

		cout << "End test Gridland Metro." << endl << endl;
		return true;

		
	}

private:
	long long gridlandMetro(int n, int m, int k, vector < vector<int> > track) {
		// Complete this function
		map<int, vector<pair<int, int>>> rowTracks;
		for (int i = 0; i < k; ++i)
		{
			auto it = rowTracks.find(track[i][0]);
			if (it == rowTracks.end())
			{
				it = rowTracks.insert(make_pair(track[i][0], vector<pair<int, int>>())).first;
			}
			it->second.push_back(make_pair(track[i][1], track[i][2]));
		}
		
		long long res = (long long)m * (long long)n;
		for (auto it = rowTracks.begin(); it != rowTracks.end(); ++it)
		{
			sort(it->second.begin(), it->second.end(), [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
			int curMax = 0, totalFreeSpace = 0;
			for (unsigned int i = 0; i < it->second.size(); ++i)
			{
				if (it->second[i].first > curMax)
					totalFreeSpace += it->second[i].first - curMax - 1;
				curMax = it->second[i].second > curMax ? it->second[i].second : curMax;
			}
			totalFreeSpace += m - curMax;
			res += (long long)(totalFreeSpace - m);
		}
		return res;
	
	}
};




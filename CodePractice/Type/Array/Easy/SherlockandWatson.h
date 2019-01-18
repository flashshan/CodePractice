#pragma once

#include "Core/CoreMinimal.h"

#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
/// from hackerRank
/*

*/		 

class SherlockAndWatson : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Sherlock and Watson." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			int k, m;
			cin >> k >> m;
			
			vector<int> nums;
			Input::InputArray(nums, n);
			
			vector<int> queries;
			Input::InputArray(queries, m);
			
			vector<int> res = circularArrayRotation(nums, k, queries);

			Output::OutputArray(res);
		}

		cout << "End test Sherlock and Watson." << endl << endl;
		return true;

	}

private:
	vector <int> circularArrayRotation(vector<int> a, int k, vector<int> m) {
		// Complete this function
		int sizeA = (int)a.size(), sizeM = (int)m.size();
		vector<int> res;
		res.reserve(sizeM);
		for (int i = 0; i < sizeM; ++i)
		{
			res.push_back(a[((m[i] - k) % sizeA + sizeA) % sizeA]);
		}
		return res;
	}
};

// Conclusion: I haven't found a type of container which support random access (which I need this feature to binary search) 
// and insert and erase within O(1) time (which I need this feature to update my intervals)

// So in the worst case, this algorithm will took O(n ^ 2) time.. 



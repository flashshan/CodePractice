#pragma once

#include "Core/CoreMinimal.h"

#include <algorithm>

using namespace std;


class LongestIncreasingSubsequence : public ITest {
public:
	virtual bool RunTest() override
	{
		cout << "Start test Longest Increasing Subsequence." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			int res = longestIncreasingSubsequence(nums);

			cout << res << endl;
		}

		cout << "End test Longest Increasing Subsequence." << endl << endl;
		return true;
	}

private:
	int longestIncreasingSubsequence(vector<int> &nums) {
		if (nums.size() == 0) return 0;
		vector<int> state;
		state.push_back(nums[0]);

		for (unsigned int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] > state[state.size() - 1])
			{
				state.push_back(nums[i]);
			}
			else
			{
				auto it = upper_bound(state.begin(), state.end(), nums[i], [](int a, int b) { return a <= b; });
				state[it - state.begin()] = nums[i];
			}
		}
		return state.size();
	}
};
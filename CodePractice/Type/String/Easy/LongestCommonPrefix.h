#pragma once

#include "Core/CoreMinimal.h"

#include <string>

using namespace std;
/// Leetcode No.14
/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class LongestCommonPrefix : public ITest {
public:
	virtual bool RunTest() override
	{
		cout << "Start test Longest Common Prefix." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<string> strs;
			Input::InputStringArray(strs, n);
			string res = longestCommonPrefix(strs);

			cout << res << endl;
		}

		cout << "End test Longest Common Prefix." << endl << endl;
		return true;
	}

private:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		if (strs.size() == 1)
			return strs[0];
		
		string res = "";

		for (int i = 0; i < INT_MAX; ++i)
		{
			char tempChar = strs[0][i];
			for (unsigned int j = 1; j < strs.size(); ++j)
			{
				if (strs[j].length() == i || strs[j][i] != tempChar)
				{
					return res;
				}
			}
			res.push_back(tempChar);
		}
		return res;
	}
};
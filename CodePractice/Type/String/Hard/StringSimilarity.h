#pragma once

#include "Core/CoreMinimal.h"

#include <string>

using namespace std;
/// Leetcode No.10
/*
https://www.hackerrank.com/challenges/string-similarity/problem
*/

class StringSimilarity : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test String Similarity." << endl;

		string str;
		while (cin >> str)
		{
			if (str == "0")
				break;

			int res = stringSimilarity(str);

			cout << res << endl;
		}

		cout << "End test String Similarity." << endl << endl;
		return true;
	}

private:
	int stringSimilarity(string s) {
		// Complete this function
		int strLen = (int)s.length();
		vector<int> states(strLen, 0);

		states[0] = strLen;

		int L = 0, R = 0;
		for (int i = 1; i < strLen; i++) {
			if (i > R) {
				L = R = i;
				while (R < strLen && s[R - L] == s[R]) R++;
				states[i] = R - L; R--;
			}
			else {
				int k = i - L;
				if (states[k] < R - i + 1) 
					states[i] = states[k];
				else {
					L = i;
					while (R < strLen && s[R - L] == s[R]) R++;
					states[i] = R - L; R--;
				}
			}
		}

		int res = 0;
		for (int i = 0; i < strLen; ++i)
		{
			res += states[i];
		}
		return res;
	}
};
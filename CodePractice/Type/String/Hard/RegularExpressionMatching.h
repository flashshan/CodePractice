#pragma once

#include "Core/CoreMinimal.h"

#include <string>

using namespace std;
/// Leetcode No.10
/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a")  false
isMatch("aa","aa")  true
isMatch("aaa","aa")  false
isMatch("aa", "a*")  true
isMatch("aa", ".*")  true
isMatch("ab", ".*")  true
isMatch("aab", "c*a*b")  true
*/

class RegularExpressionMatching : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Regular Expression Matching." << endl;

		string str;
		while (cin >> str)
		{
			if (str == "0")
				break;

			string str2;
			cin >> str2;
			bool res = isMatch(str, str2);

			cout << res << endl;
		}

		cout << "End test Regular Expression Matching." << endl << endl;
		return true;
	}

private:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));

		f[0][0] = true;
		for (int i = 1; i <= m; i++)
			f[i][0] = false;
		
		for (int j = 1; j <= n; j++)
			f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (p[j - 1] != '*')
					f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
				else
					f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];

		return f[m][n];
	}
};
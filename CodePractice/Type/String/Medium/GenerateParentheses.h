#pragma once

#include "Core/CoreMinimal.h"

#include <string>

using namespace std;
/// Leetcode No.22
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
*/

class GenerateParentheses : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Generate Parentheses." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<string> res = generateParenthesis(n);

			Output::OutputStringArray(res);
		}

		cout << "End test Generate Parentheses." << endl << endl;
		return true;
	}

private:
	vector<string> generateParenthesis(int n) {
		res.clear();
		if (n > 0)
		{
			unguarded_generate("", n, n);
		}
		return res;
	}

	void unguarded_generate(string curr, int m, int n)
	{
		if (m == 0 && n == 0)
		{
			res.push_back(curr);
		}
		else
		{
			if (m != 0)
			{
				unguarded_generate(curr + "(", m - 1, n);
			}

			if (m < n && n != 0)
			{
				unguarded_generate(curr + ")", m, n - 1);
			}
		}
	}

	vector<string> res;
};
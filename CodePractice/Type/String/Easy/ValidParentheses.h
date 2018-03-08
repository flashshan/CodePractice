#pragma once

#include "Core/CoreMinimal.h"

#include <string>
#include <stack>

using namespace std;
/// Leetcode No.20
/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class ValidParentheses : public ITest {
public:
	virtual bool RunTest() override
	{
		cout << "Start test Valid Parentheses." << endl;

		string str;
		while (cin >> str)
		{
			if (str == "0")
				break;

			bool res = isValid(str);

			cout << res << endl;
		}

		cout << "End test Valid Parentheses." << endl << endl;
		return true;
	}

private:
	bool isValid(string s) {
		stack<char> record;
		int length = s.length();

		for (int i = 0; i < length; ++i)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				record.push(s[i]);
			else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
			{
				if (s[i] == ')')
				{
					if (!record.empty() && record.top() == '(')
						record.pop();
					else
						return false;
				}
				if (s[i] == ']')
				{
					if (!record.empty() && record.top() == '[')
						record.pop();
					else
						return false;
				}
				if (s[i] == '}')
				{
					if (!record.empty() && record.top() == '{')
						record.pop();
					else
						return false;
				}
			}
			else
				return false;
		}

		return record.empty();
	}
};
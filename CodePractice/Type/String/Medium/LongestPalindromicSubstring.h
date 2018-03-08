#pragma once

#include "Core/CoreMinimal.h"

#include <string>

using namespace std;
/// Leetcode No.5
/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.


Example:

Input: "cbbd"

Output: "bb"
*/

class LongestPalindromicSubstring : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Longest Palindromic Substring." << endl;

		string str;
		while (cin >> str)
		{
			if (str == "0")
				break;

			string res = longestPalindrome(str);

			cout << res << endl;
		}

		cout << "End test Longest Palindromic Substring." << endl << endl;
		return true;
	}

private:
	string longestPalindrome(string s) {
		int length = static_cast<int>(s.length());
		int maxLen = 0, start = 0, end = 0, n;
		string res = "";
		if (length == 0) return res;

		for (int i = 0; i < length - 1; i++)
		{
			if (s[i] == s[i + 1])
			{
				n = 1;
				while (i - n >= 0 && i + 1 + n < length)
				{
					if (s[i - n] != s[i + 1 + n])
					{
						break;
					}
					else n++;
				}
				if (2 * n > maxLen)
				{
					maxLen = 2 * n;
					start = i - n + 1;
					end = i + n;
				}
			}
			if (i < length - 2 && s[i] == s[i + 2])
			{
				n = 1;
				while (i - n >= 0 && i + 2 + n < length)
				{
					if (s[i - n] != s[i + 2 + n])
					{
						break;
					}
					else n++;
				}
				if (2 * n + 1 > maxLen)
				{
					maxLen = 2 * n + 1;
					start = i - n + 1;
					end = i + n + 1;
				}
			}
		}
		
		res.reserve(end - start + 1);
		for (int i = start; i <= end; i++)
		{
			res.push_back(s[i]);
		}
		return res;
	}
};
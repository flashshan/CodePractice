#pragma once

#include "Core/CoreMinimal.h"

#include <string>

using namespace std;

/// Leetcode No 3.
/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class LongestSubstringWithoutRepeating : public ITest {
public:
	virtual bool RunTest() override
	{
		cout << "Start test Longest Substring Without Repeating." << endl;

		string str;
		while (cin >> str)
		{
			if (str == "0")
				break;

			int res = lengthOfLongestSubstring(str);

			cout << res << endl;
		}

		cout << "End test Longest Substring Without Repeating." << endl << endl;
		return true;
	}

private:
	int lengthOfLongestSubstring(string s) {
		vector<bool> state(256, false);
		int length = static_cast<int>(s.length());

		int left = 0, right = 0;
		int maxLength = 0, currentLength = 0;
		
		while (right < length)
		{
			++currentLength;
			if (!state[s[right]])
			{
				state[s[right]] = true;
			}
			else
			{
				maxLength = maxLength > currentLength - 1 ? maxLength : currentLength - 1;
				while (left < right)
				{
					--currentLength;
					++left;
					if (s[left - 1] == s[right])
					{
						break;
					}
					else
					{
						state[s[left - 1]] = false;
					}
				}
			}
			++right;
		}
		return maxLength > currentLength ? maxLength : currentLength;
	}
};
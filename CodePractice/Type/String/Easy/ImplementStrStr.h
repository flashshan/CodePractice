#pragma once

#include "Core/CoreMinimal.h"

#include <string>
#include <stack>

using namespace std;
/// Leetcode No.20
/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/

class ImplementStrStr : public ITest {
public:
	virtual bool RunTest() override
	{
		cout << "Start test Implement StrStr." << endl;

		string str;
		while (cin >> str)
		{
			if (str == "0")
				break;

			string str2;
			cin >> str2;
			int res = strStr(str, str2);

			cout << res << endl;
		}

		cout << "End test Implement StrStr." << endl << endl;
		return true;
	}

private:
	int strStr(string haystack, string needle) {
		int length1 = (int)haystack.length();
		int length2 = (int)needle.length();
		if (length2 == 0)
			return 0;
		if (length1 == 0)
			return -1;

		vector<int> next(length2 + 1, 0);
		getNext(needle, next);

		int i = 0, j = 0;
		while (i != length1)
		{
			while (j >= 0 && haystack[i] != needle[j])
				j = next[j];
			i++; 
			j++;
			if (j == length2)
				return i - j;
		}
		return -1;
	}

	void getNext(string needle, vector<int> &next)
	{
		int i = 0, j = -1;
		next[i] = j;
		while (i != needle.length())
		{
			while (j >= 0 && needle[j] != needle[i])
				j = next[j];
			i++;
			j++;
			next[i] = j;
		}
	}
};
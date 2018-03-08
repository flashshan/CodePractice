#pragma once

#include "Core/CoreMinimal.h"

#include <string>

using namespace std;
/// Leetcode No.17
/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

class LetterCombinationsPhoneNumber : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Letter Combinations of a Phone Number." << endl;

		string str;
		while (cin >> str)
		{
			if (str == "0")
				break;

			vector<string> res = letterCombinations(str);

			Output::OutputStringArray(res);
		}

		cout << "End test Letter Combinations of a Phone Number." << endl << endl;
		return true;
	}

private:
	vector<string> letterCombinations(string digits) {
		count[0] = 0; count[1] = 0; count[2] = 3; count[3] = 3; count[4] = 3;
		count[5] = 3; count[6] = 3; count[7] = 4; count[8] = 3; count[9] = 4;
		chars[0] = ""; chars[1] = ""; chars[2] = "abc"; chars[3] = "def"; chars[4] = "ghi";
		chars[5] = "jkl"; chars[6] = "mno"; chars[7] = "pqrs"; chars[8] = "tuv"; chars[9] = "wxyz";
		digit = digits;

		res.clear();
		n = digits.length();
		if (n == 0) return res;

		nextChar("", 0);
		return res;
	}
	void nextChar(string st, int temp)
	{
		for (int i = 0; i < count[digit[temp] - '0']; i++)
		{
			if (temp == n - 1)
				res.push_back(st + chars[digit[temp] - '0'][i]);
			else
				nextChar(st + chars[digit[temp] - '0'][i], temp + 1);
		}
	}

	int count[10];
	string chars[10];
	vector<string> res;
	int n;
	string digit;
};
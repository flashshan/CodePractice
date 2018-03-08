#pragma once

#include "Core/CoreMinimal.h"

#include <string>

using namespace std;
/// Leetcode No.12
/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

class IntegerToRoman : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Integer to Roman." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			string res = intToRoman(n);

			cout << res << endl;
		}

		cout << "End test Integer to Roman." << endl << endl;
		return true;
	}

private:
	string intToRoman(int num) {
		string res = "";
		int divisor[3] = { 100,10,1 };
		char sym[7] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };

		int digit = num / 1000;
		num -= digit * 1000;
		while (digit--)
			res.push_back('M');

		for (int i = 0; i <= 2; i++)
		{
			digit = num / divisor[i];
			num -= digit * divisor[i];
			if (digit == 9)
			{
				res.push_back(sym[i * 2 + 2]);
				res.push_back(sym[i * 2]);
			}
			else if (digit == 4)
			{
				res.push_back(sym[i * 2 + 2]);
				res.push_back(sym[i * 2 + 1]);
			}
			else
			{
				if (digit > 4)
				{
					res.push_back(sym[i * 2 + 1]);
					digit -= 5;
				}
				while (digit--)
					res.push_back(sym[i * 2 + 2]);
			}
		}
		return res;
	}
};
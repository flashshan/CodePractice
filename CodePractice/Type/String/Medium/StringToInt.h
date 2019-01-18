#pragma once

#include "Core/CoreMinimal.h"

#include <string>

using namespace std;
/// Leetcode No.8
/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.



Requirements for atoi:

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

class StringToInteger : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test String to Integer." << endl;

		string str;
		while (cin >> str)
		{
			if (str == "0")
				break;

			int res = myAtoi(str);

			cout << res << endl;
		}

		cout << "End test String to Integer." << endl << endl;
		return true;
	}

private:
	int myAtoi(string str) {
		int mode = 0, length = (int)str.length();
		bool mark = true;
		int markCount = 0;
		int res = 0;

		for (int i = 0; i < length; i++)
		{
			if (mode == 0)
			{
				if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')
				{
					mode = 1;
					if (str[i] == '-')
					{
						mark = false;
					}
					else if (str[i] >= '0' && str[i] <= '9')
					{
						res += str[i] - '0';
					}
				}
				else if (str[i] != ' ') return 0;
			}
			else if (mode == 1)
			{
				if (str[i] >= '0' && str[i] <= '9')
				{
					if (mark && (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' >= INT_MAX % 10)))
					{
						return INT_MAX;
					}
					else if (!mark && (-res < INT_MIN / 10 || (-res == INT_MIN / 10 && -(str[i] - '0') <= INT_MIN % 10)))
					{
						return INT_MIN;
					}
					else
					{
						res = res * 10 + str[i] - '0';
					}
				}
				else
				{
					mode = 2;
				}
			}
		}
		return mark ? res : -res;
	}
};
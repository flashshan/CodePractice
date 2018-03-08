#pragma once

#include "Core/CoreMinimal.h"

using namespace std;
/// Leetcode No.9
/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

class PalindromeNumber : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Palindrome Number." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			bool res = isPalindrome(n);

			cout << res << endl;
		}

		cout << "End test Palindrome Number." << endl << endl;
		return true;
	}

private:
	bool isPalindrome(int x) {
		if (x < 0 || x == INT_MIN)
			return false;

		int divider = 1;
		while (x / 10 >= divider)
		{
			divider *= 10;
		}
		while (divider >= 10)
		{
			if (x / divider != x % 10)
			{
				return false;
				break;
			}
			else
			{
				x = (x - (x % 10)*divider - x % 10) / 10;
				divider /= 100;
			}
		}
		return true;
	}
};
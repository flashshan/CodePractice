#pragma once

#include "Core/CoreMinimal.h"

using namespace std;
/// Leetcode No.7
/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output:  321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

class ReverseInteger : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Reverse Integer." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			int res = reverse(n);

			cout << res << endl;
		}

		cout << "End test Reverse Integer." << endl << endl;
		return true;
	}

private:
	int reverse(int x) {
		long long rev = 0;
		while (x != 0) {
			rev = rev * 10 + x % 10;
			x = x / 10;
			if (rev > INT_MAX || rev < INT_MIN)
				return 0;
		}
		return static_cast<int>(rev);
	}
};
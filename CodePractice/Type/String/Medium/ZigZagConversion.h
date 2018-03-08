#pragma once

#include "Core/CoreMinimal.h"
#include "Core/Functions.h"

#include <string>

using namespace std;
/// Leetcode No.6
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class ZigZagConversion : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test ZigZag Conversion." << endl;

		string str;
		while (cin >> str)
		{
			if (str == "0")
				break;

			int m;
			cin >> m;
			string res = convert(str, m);

			cout << res << endl;
		}

		cout << "End test ZigZag Conversion." << endl << endl;
		return true;
	}

private:
	string convert(string s, int nRows) {
		int length = static_cast<int>(s.length());
		string res = "";
		res.reserve(length);

		for (int i = 1; i <= nRows; ++i)
		{
			if (i == 1 || i == nRows)
			{
				int j = i - 1;
				if (j < length)
				{
					res.push_back(s[j]);
					j += Math::Max<int>((nRows - 1) * 2, 1);
				}
				while (j < length)
				{
					res.push_back(s[j]);
					j += Math::Max<int>((nRows - 1) * 2, 1);
				}
			}
			else
			{
				int j = i - 1;
				if (j < length)
				{
					res.push_back(s[j]);
					j += (nRows - i) * 2;
				}
				while (j < length)
				{
					res.push_back(s[j]);
					j += (i - 1) * 2;
					if (j < length)
					{
						res.push_back(s[j]);
						j += (nRows - i) * 2;
					}
				}
			}
		}
		return res;
	}
};
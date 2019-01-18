#pragma once

#include "Core/CoreMinimal.h"
#include "Core/Functions.h"

#include <string>

using namespace std;
/// HackerRank
/*
https://www.hackerrank.com/challenges/the-time-in-words/problem
*/

class TimeInWords : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test The Time in Words." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			int m;
			cin >> m;
			string res = timeInWords(n, m);

			cout << res << endl;
		}

		cout << "End test The Time in Words." << endl << endl;
		return true;
	}

private:
	string timeInWords(int h, int m) {
		// Complete this function
		vector<string> numberName{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
			"eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eighteen", "nineteen",                                "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six",
			"twenty seven", "twenty eight", "twenty nine", "half" };

		if (m == 0)
			return numberName[h] + " o' clock";
		if (m < 30)
		{
			if(m == 15)
				return "quarter past " + numberName[h];
			else
				return numberName[m] + ((m == 1) ? " minute " : " minutes ") + "past " + numberName[h];
		}
		else if (m > 30)
		{
			if (m == 45)
				return "quarter to " + numberName[(h + 1) % 12];
			else
				return numberName[60 - m] + ((m == 59) ? " minute " : " minutes ") + "to " + numberName[(h + 1) % 12];
		}
		else
			return "half past " + numberName[h];
	}
};
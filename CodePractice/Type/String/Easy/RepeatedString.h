#pragma once

#include "Core/CoreMinimal.h"

#include <string>

using namespace std;
/// HackerRank
/*

*/

class RepeatedString : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Repeated String." << endl;

		string str;
		while (cin >> str)
		{
			if (str == "0")
				break;

			long long n;
			cin >> n;
			long long res = repeatedString(str, n);

			cout << res << endl;
		}

		cout << "End test Repeated String." << endl << endl;
		return true;
	}

private:
	long long repeatedString(string s, long long n) {
		// Complete this function
		long long sLen = s.length();
		int res = 0, total = 0;
		bool goOnce = n >= sLen ? true : false;
		int tempN = int(n % sLen);

		for (int i = 0; i < tempN; ++i)
		{
			if (s[i] == 'a')
				++res;
		}
		if (!goOnce)
			return res;

		total = res;
		for (int i = tempN; i < sLen; ++i)
		{
			if (s[i] == 'a')
				++total;
		}
		return res + n / sLen * total;
	}
};
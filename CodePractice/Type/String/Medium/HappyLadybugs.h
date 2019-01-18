#pragma once

#include "Core/CoreMinimal.h"
#include "Core/Functions.h"

#include <string>

using namespace std;
/// HackerRank
/*
https://www.hackerrank.com/challenges/happy-ladybugs/problem
*/

class HappyLadybugs : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Happy Ladybugs." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			string str;
			cin >> str;
			bool res = HappyLady(n, str);

			cout << res << endl;
		}

		cout << "End test Happy Ladybugs." << endl << endl;
		return true;
	}

private:
	bool HappyLady(int n, string str)
	{
		vector<int> states(26, 0);
		bool hasEmpty = false, needMove = false;
		if (n == 1) 
			return str[0] == '_';

		for (int i = 0; i < n; ++i)
		{
			if (str[i] == '_')
				hasEmpty = true;
			else
				++states[str[i] - 'A'];

			if (!hasEmpty)
			{
				if(i == 0 && str[i] != str[i + 1])
					needMove = true;
				else if(i == n - 1 && str[i] != str[i - 1])
					needMove = true;
				else if(i != 0 && i != n - 1)
					if(str[i] != str[i - 1] && str[i] != str[i + 1])
						needMove = true;
			}
		}
		if (!hasEmpty)
		{
			return !needMove;
		}
		else
		{
			for (int i = 0; i < 26; ++i)
			{
				if (states[i] == 1)
					return false;
			}
			return true;
		}
	}
};
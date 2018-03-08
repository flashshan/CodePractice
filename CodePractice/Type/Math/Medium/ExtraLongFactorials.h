#pragma once

#include "Core/CoreMinimal.h"

#include <string>

#include <unordered_map>

using namespace std;
/// HackerRank
/*
Implement n!. n < 100
*/

class ExtraLongFactorials : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Extra Long Factorials." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			extraLongFactorials(n);
		}

		cout << "End test Extra Long Factorials." << endl << endl;
		return true;
	}

private:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") 
			return "0";
		vector<int> res(num1.length() + num2.length(), 0);

		for (int i = num1.length() - 1; i >= 0; i--)
		{
			for (int j = num2.length() - 1; j >= 0; j--)
			{
				res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
				if ( res[i + j + 1] < 0)
				{
					int a = 1;
					++a;
					cout << "error";
				}
			}
		}
		int flag = 0;
		for (int i = num1.length() + num2.length() - 1; i >= 0; --i)
		{
			res[i] += flag;
			flag = res[i] / 10;
			res[i] = res[i] % 10;
			
		}
		string ans = "";
		if (res[0] != 0) ans.push_back((char)(res[0] + '0'));
		for (unsigned int i = 1; i < num1.length() + num2.length(); ++i)
		{
			
			ans.push_back((char)(res[i] + '0'));
		}
		return ans;
	}

	string longToString(long long n)
	{
		if (n == 0)
			return "0";
		int i = 0;
		long long level = 1;
		while (n >= level)
		{
			++i;
			level *= 10;
		}
		string res;
		res.resize(i);

		level /= 10;
		int pos = 0;
		while (level)
		{
			res[pos++] = int(n % (level * 10) / level) + '0';
			level /= 10;
		}
		return res;
	}

	void extraLongFactorials(int n) {
		// Complete this function
		string currentResult = "1";

		long long largeNumber = (long long)2147483647 * (long long)2000000L;
		long long value = 1;
		for (int i = 1; i <= n; ++i)
		{
			value *= i;
			if (value > largeNumber || i == n)
			{
				currentResult = multiply(currentResult, longToString(value));
				value = 1;
			}
		}
		cout << currentResult << endl;
	}

	int minimumDistances(vector <int> a) {
		// Complete this function
		unordered_map<int, int> record;

		
		for (int i = 0; i < a.size(); ++i)
		{
			auto it = record.find(a[i]);
			if (it != record.end())
			{
				it->second = i;
			}
			else
			{
				record.insert(make_pair(a[i], i));
			}
		}
	}
};
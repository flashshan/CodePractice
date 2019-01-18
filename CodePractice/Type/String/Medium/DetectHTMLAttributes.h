#pragma once

#include "Core/CoreMinimal.h"
#include "Core/Functions.h"

#include <string>
#include <map>
#include <set>

using namespace std;
/// HackerRank
/*
https://www.hackerrank.com/challenges/html-attributes/problem
*/

class DetectHTMLAttributes : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Detect HTML Attributes." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			string tempStr;
			getline(cin, tempStr);
			vector<string> strs;
			strs.reserve(n);
			for (int i = 0; i < n; ++i)
			{
				tempStr.clear();
				getline(cin, tempStr);
				strs.push_back(tempStr);
			}

			GetTagsAndAttribute(strs);
		}

		cout << "End test Detect HTML Attributes." << endl << endl;
		return true;
	}

private:
	void GetTagsAndAttribute(vector<string> resource)
	{
		map<string, set<string>> res;
		map<string, set<string>>::iterator it;
		for (unsigned int i = 0; i < resource.size(); ++i)
		{
			for (unsigned int j = 0; j < resource[i].length(); ++j)
			{
				if (resource[i][j] == '<' && resource[i][j + 1] != '/')
				{
					string tempKey;
					int start = j + 1;
					while (resource[i][start] != '>' && resource[i][start] != ' ')
					{
						tempKey.push_back(resource[i][start]);
						++start;
					}

					it = res.find(tempKey);
					if (it == res.end())
					{
						it = res.insert(make_pair(tempKey, set<string>())).first;
					}
					j = (unsigned int)(start - 1) > j ? (unsigned int)(start - 1) : j;
				}
				else if (resource[i][j] == ' ')
				{
					unsigned int start = j + 1;
					while (resource[i][start] != ' ' && resource[i][start] != '=' && resource[i][start] != '<' && resource[i][start] != '>' && resource[i][start] != '?' && start < resource[i].length())
					{
						++start;
					}
					if (start != resource[i].length() && resource[i][start] == '=')
					{
						string tempKey;
						start = j + 1;
						while (resource[i][start] != '=')
						{
							tempKey.push_back(resource[i][start]);
							++start;
						}

						it->second.insert(tempKey);
					}
					j = (unsigned int)(start - 1) > j ? (unsigned int)(start - 1) : j;
				}
			}
		}

		for (auto i = res.begin(); i != res.end(); ++i)
		{
			cout << i->first << ':' ;
			for (auto j = i->second.begin(); j != i->second.end(); ++j)
			{
				if (j != i->second.begin())
					cout << ',';
				cout << *j;
			}
			cout << endl;
		}
	}
};
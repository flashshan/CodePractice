#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		res.clear();
		num = candidates;
		sort(num.begin(), num.end());
		vector<int> temp;
		backTrace(temp, 0, target);
		return res;
	}
private:
	void backTrace(vector<int> temp, int n, int target)
	{
		int max = target / num[n];
		for (int i = 0; i <= max; i++)
		{
			if (i == 0)
			{
				if (n < num.size() - 1 && target >= num[n + 1])
					backTrace(temp, n + 1, target);
			}
			else
			{
				temp.push_back(num[n]);
				target -= num[n];
				if (target == 0)
					res.push_back(temp);
				else if (n < num.size() - 1 && target >= num[n + 1])
					backTrace(temp, n + 1, target);
			}
		}
	}

	void QuickSort(vector<int> &num, int begin, int end)
	{
		if (begin >= end) return;
		if (begin + 1 == end)
		{
			if (num[begin] > num[end])
				swap(num[begin], num[end]);
			return;
		}
		int random = begin + rand() % (end + 1 - begin);
		swap(num[begin], num[random]);
		int comp = num[begin];
		int count = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (num[i] < comp)
			{
				count++;
				swap(num[count], num[i]);
			}
		}
		swap(num[count], num[begin]);
		QuickSort(num, begin, count - 1);
		QuickSort(num, count + 1, end);
	}

	vector<vector<int> > res;
	vector<int> num;
};


int main()
{
	Solution s;
	int n;
	while (cin >> n)
	{
		vector<vector<int> > ma;
		vector<int> temp;
		int tempInt;
		for (int i = 0; i < n; i++)
		{
			cin >> tempInt;
			temp.push_back(tempInt);
		}
		int m;
		cin >> m;
		ma = s.combinationSum(temp, m);

		for (int i = 0; i < ma.size(); i++)
		{
			for (int j = 0; j < ma[i].size(); j++)
			{
				cout << ma[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}
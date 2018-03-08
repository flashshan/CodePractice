#pragma once

#include "Core/CoreMinimal.h"

#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
/// this is google test question 2.
/*

*/		 

class RoseGrowQuestion : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test rose grow question." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			int m;
			cin >> m;
			int res = solution(nums, m);

			/*cout << res << endl;*/
		}

		cout << "End test rose grow question." << endl << endl;
		return true;

		
	}

private:
	struct Interval {
	public:
		int first;
		int second;
		Interval(int i_first, int i_second) : first(i_first), second(i_second) {}
	};

	int solution(vector<int> &P, int K) {
		// write your code in C++14 (g++ 6.2.0)

		int days = P.size();
		if (K > days)
			return -1;
		if (K == days)
			return days;

		auto cmp = [](const Interval& i_a, const Interval& i_b) { return i_a.first < i_b.first; };
		set < Interval, decltype(cmp) > intervals(cmp);
		intervals.insert(Interval(1, days));

		// search from the end to the front
		for (int i = days - 1; i >= 0; --i)
		{
			set<Interval>::iterator it = lower_bound(intervals.begin(), intervals.end(), P[i], [](const Interval& i_a, int i_value) {return i_a.first <= i_value; });
			it--;
			// it will always exist, get a ref of this interval so we can make changes

			if (it->first == it->second)  // interval only has 1 element
			{
				intervals.erase(it);		// erase will took O(log N)
			}
			else
			{
				Interval* unconstIt = const_cast<Interval *>(&(*it));
				if (P[i] == unconstIt->first)
				{

					++(unconstIt->first);
					if (unconstIt->second - unconstIt->first + 1 == K)
						return i;
				}
				else if (P[i] == unconstIt->second)
				{
					--(unconstIt->first);
					if (unconstIt->second - unconstIt->first + 1 == K)
						return i;
				}
				else
				{
					if (P[i] - unconstIt->first == K || unconstIt->second - P[i] == K)
						return i;

					int recordFirst = unconstIt->first;
					unconstIt->first = P[i] + 1;
					intervals.insert(Interval(recordFirst, P[i] - 1));			// insert ahead of current interval, this will cost O(n)
				}
			}
		}
		return -1;
	}
};




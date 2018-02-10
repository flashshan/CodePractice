#pragma once

#include <iostream>
#include <vector>

using namespace std;


namespace Array
{
	// quick sort
	template<typename T> void QuickSort(vector<T> &num, int begin, int end);   // begin index and end index are inclusive


}

namespace Math
{

}
















// implementation

namespace Array
{
	template<typename T>void QuickSort(vector<T> &num, int begin, int end)
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
}
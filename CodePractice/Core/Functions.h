#pragma once

#include <iostream>
#include <vector>


namespace Array
{
	// quick sort
	template<typename T> void QuickSort(std::vector<T> &num, int begin, int end);   // begin index and end index are inclusive


}

namespace Math
{
	template<typename T> T Max(const T &a, const T &b)
	{
		return a > b ? a : b;
	}
	template<typename T> T Min(const T &a, const T &b)
	{
		return a < b ? a : b;
	}
}
















// implementation

namespace Array
{
	template<typename T>void QuickSort(std::vector<T> &num, int begin, int end)
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
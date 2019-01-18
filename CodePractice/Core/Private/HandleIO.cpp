#include "Core/HandleIO.h"

#include <string>

using namespace std;

namespace Input
{
	void InputArray(vector<int> &nums, int n)
	{
		nums.reserve(n);
		for (int i = 0; i < n; ++i)
		{
			int tempNum;
			cin >> tempNum;
			nums.push_back(tempNum);
		}
	}

	void InputLongLongArray(vector<long long> &nums, int n)
	{
		nums.reserve(n);
		for (int i = 0; i < n; ++i)
		{
			long long tempNum;
			cin >> tempNum;
			nums.push_back(tempNum);
		}
	}

	void Input2DArray(std::vector<std::vector<int>> &matrix, int n, int m)
	{
		matrix.resize(n);
		for (int i = 0; i < n; ++i)
		{
			matrix[i].resize(m);
			for (int j = 0; j < m; ++j)
			{
				cin >> matrix[i][j];
			}
		}
	}

	void InputStringArray(vector<string> &strs, int n)
	{
		strs.reserve(n);
		for (int i = 0; i < n; ++i)
		{
			string tempStr;
			cin >> tempStr;
			strs.push_back(tempStr);
		}
	}

	void InputList(ListNode *&node, int n)
	{
		ListNode *tail = nullptr;
		while (n--)
		{
			int tempInt;
			cin >> tempInt;

			ListNode *tempNode = new ListNode(tempInt);
			tempNode->next = nullptr;
			if (node == nullptr)
			{
				node = tempNode;
				tail = node;
			}
			else
			{
				tail->next = tempNode;
				tail = tempNode;
			}
		}
	}

	void InputTree()
	{

	}

	void InputGraph()
	{

	}

}


namespace Output
{
	void OutputArray(vector<int> &nums)
	{
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << " ";
		}
		cout << endl;
	}


	void Output2DArray(vector<vector<int>> &matrix)
	{
		for (unsigned int i = 0; i < matrix.size(); ++i)
		{
			for (unsigned int j = 0; j < matrix[0].size(); ++j)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	void OutputStringArray(vector<string> &strs)
	{
		for (unsigned int i = 0; i < strs.size(); i++)
		{
			cout << strs[i] << endl;
		}
	}

	void OutputList(ListNode *&node)
	{
		ListNode *tempNode = node;
		while (tempNode)
		{
			cout << tempNode->val << " ";
			tempNode = tempNode->next;
		}
		cout << endl;
	}

	void OutputTree()
	{

	}

	void OutputGraph()
	{

	}
}

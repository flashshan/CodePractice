#include "HandleIO.h"


namespace Input
{
	void InputArray(vector<int> &nums, int n)
	{
		for (int i = 0; i < n; ++i)
		{
			int tempNum;
			cin >> tempNum;
			nums.push_back(tempNum);
		}
	}

	void InputMatrix()
	{

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

	void OutputMatrix()
	{

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

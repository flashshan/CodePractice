#pragma once

#include "Core/CoreMinimal.h"
#include "Core/DataStructure.h"

using namespace std;

/// Leetcode No.24
/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

class SwapNodesinPairs : public ITest {
public:
	virtual bool RunTest() override
	{
		cout << "Start test Swap Nodes in Pairs." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			ListNode *list = nullptr;
			Input::InputList(list, n);

			ListNode *res = swapPairs(list);

			Output::OutputList(res);
		}

		cout << "End test Swap Nodes in Pairs." << endl << endl;
		return true;
	}

private:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr || head->next == nullptr) 
			return head;

		ListNode *pre, *temp, *first, *second;
		temp = head->next->next;
		first = head;
		second = head->next;
		first->next = nullptr;
		second->next = first;
		first->next = temp;
		head = second;
		pre = head->next;

		while (pre->next)
		{
			if (pre->next->next)
			{
				temp = pre->next->next->next;
				first = pre->next;
				second = pre->next->next;
				first->next = nullptr;
				second->next = first;
				first->next = temp;
				pre->next = second;
				pre = pre->next->next;
			}
			else
			{
				pre = pre->next;
			}
		}
		return head;
	}
};
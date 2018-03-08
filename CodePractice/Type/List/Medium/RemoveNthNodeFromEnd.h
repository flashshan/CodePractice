#pragma once

#include "Core/CoreMinimal.h"
#include "Core/DataStructure.h"

using namespace std;
/// Leetcode No.19
/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

class RemoveNthNodeFromEnd : public ITest {
public:
	virtual bool RunTest() override
	{
		cout << "Start test Remove Nth Node From End of List." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			ListNode *list = nullptr;
			Input::InputList(list, n);

			int m;
			cin >> m;
			ListNode *res = removeNthFromEnd(list, m);

			Output::OutputList(res);
		}

		cout << "End test Remove Nth Node From End of List." << endl << endl;
		return true;
	}

private:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr || head->next == nullptr)
		{
			return nullptr;
		}
		ListNode *front = head, *later = head;
		int pos = 1;
		for (int i = 1; i <= n; i++)
		{
			front = front->next;
		}
		bool mark = true;
		while (front)
		{
			mark = false;
			if (front->next != nullptr)
			{
				later = later->next;
			}
			front = front->next;
		}
		if (later == head && mark)
		{
			return head->next;
		}
		else
		{
			later->next = later->next->next;
		}
		return head;
	}
};
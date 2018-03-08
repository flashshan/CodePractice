#pragma once

#include "Core/CoreMinimal.h"

#include <queue>

using namespace std;
/// Leetcode No.25
/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/
				
class ReverseNodesinKGroup : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Reverse Nodes in k-Group." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			ListNode *list;
			Input::InputList(list, n);

			int m;
			cin >> m;
			ListNode *res = reverseKGroup(list, m);

			Output::OutputList(res);
		}

		cout << "End test Reverse Nodes in k-Group." << endl << endl;
		return true;
	}

private:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 1) 
			return head;

		ListNode *h = new ListNode(-1), *hp = h, *headPre = head, *headLater = head;
		ListNode *tempH = new ListNode(-1), *tempNode;
		int count = 0;
		while (headLater)
		{
			count++;
			headLater = headLater->next;
			if (count == k)
			{
				count = 0;
				for (int i = 0; i < k; i++)
				{
					tempNode = tempH->next;
					tempH->next = headPre;
					headPre = headPre->next;
					tempH->next->next = tempNode;
				}
				hp->next = tempH->next;
				tempH->next = nullptr;
				while (hp->next)
				{
					hp = hp->next;
				}
			}
		}
		if (count != 0)
			hp->next = headPre;
		return h->next;
	}
};

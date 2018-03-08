#pragma once

#include "Core/CoreMinimal.h"

using namespace std;
/// Leetcode No.21
/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/
				
class MergeTwoSortedLists : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Merge Two Sorted Lists." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			ListNode *a = nullptr;
			Input::InputList(a, n);

			int m;
			cin >> m;
			ListNode *b = nullptr;
			Input::InputList(b, m);

			ListNode *res = mergeTwoLists(a, b);

			Output::OutputList(res);
		}

		cout << "End test Merge Two Sorted Lists." << endl << endl;
		return true;
	}

private:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;

		ListNode *temp;
		if (l1->val > l2->val)
		{
			temp = l1;
			l1 = l2;
			l2 = temp;
		}
		ListNode *temp1 = l1, *temp2 = l2;
		while (temp1->next && temp2)
		{
			if (temp2->val < temp1->next->val)
			{
				temp = temp1->next;
				temp1->next = temp2;
				while (temp2->next && temp2->next->val < temp->val)
				{
					temp2 = temp2->next;
				}
				ListNode *tempp = temp2;
				temp2 = temp2->next;
				tempp->next = temp;
			}
			else
			{
				temp1 = temp1->next;
			}
		}
		if (temp2)
			temp1->next = temp2;
		return l1;
	}
};

#pragma once

#include "Core/CoreMinimal.h"

/// No.2
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
				
class AddTwoNumbers1 : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Add Two Numbers1." << endl;

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

			ListNode *res = addTwoNumbers(a, b);

			Output::OutputList(res);
		}

		cout << "End test Add Two Numbers1." << endl << endl;
		return true;
	}

private:
	ListNode * addTwoNumbers(ListNode *l1, ListNode *l2) {
		int mark = 0;
		ListNode *head = nullptr;
		ListNode *tail = nullptr;
		while (l1 != nullptr || l2 != nullptr || mark)
		{
			int val = 0;
			if (l1 != nullptr)
			{
				val += l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr)
			{
				val += l2->val;
				l2 = l2->next;
			}
			val += mark;
			mark = val / 10;
			val = val % 10;

			if (head == nullptr)
			{
				head = new ListNode(val);
				tail = head;
			}
			else
			{
				tail->next = new ListNode(val);
				tail = tail->next;
			}
		}
		return head;
	}
};

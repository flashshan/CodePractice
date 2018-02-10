#pragma once

#include "Core/CoreMinimal.h"

/// No.445
/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/

class AddTwoNumbers2 : public ITest {
public:
	virtual bool RunTest() override
	{
		cout << "Start test Add Two Numbers2." << endl;

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

		cout << "End test Add Two Numbers2." << endl << endl;
		return true;
	}

private:
	ListNode * addTwoNumbers(ListNode *l1, ListNode *l2) {
		if (l1 == nullptr && l2 == nullptr)
			return nullptr;
		int length1 = 0, length2 = 0;
		ListNode *temp1 = l1, *temp2 = l2;
		while (temp1)
		{
			++length1;
			temp1 = temp1->next;
		}
		while (temp2)
		{
			++length2;
			temp2 = temp2->next;
		}

		if (length1 >= length2)
		{
			temp1 = l1;
			temp2 = l2;
		}
		else
		{
			temp1 = l2;
			temp2 = l1;
			swap(length1, length2);
		}

		ListNode *tempHead = new ListNode(-1), *tempNext;
		for (int i = 0; i < length1; ++i)
		{
			tempNext = tempHead->next;
			if (i < length1 - length2)
			{
				tempHead->next = new ListNode(temp1->val);
			}
			else
			{
				tempHead->next = new ListNode(temp1->val + temp2->val);
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
			tempHead->next->next = tempNext;
		}

		temp1 = tempHead->next;
		bool marker = temp1->val > 9;
		temp1->val %= 10;
		while (temp1->next)
		{
			if (marker)
				++temp1->next->val;
			marker = temp1->next->val > 9;
			temp1->next->val %= 10;
			tempNext = temp1->next->next;
			temp1->next->next = tempHead->next;
			tempHead->next = temp1->next;
			temp1->next = tempNext;
		}
		if (marker)
		{
			tempNext = tempHead->next;
			tempHead->next = new ListNode(1);
			tempHead->next->next = tempNext;
		}
		tempNext = tempHead->next;
		delete tempHead;
		return tempNext;
	}
};



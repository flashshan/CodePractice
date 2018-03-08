#pragma once

#include "Core/CoreMinimal.h"

#include <queue>

using namespace std;
/// Leetcode No.23
/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
				
class MergekSortedLists : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Merge k Sorted Lists." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<ListNode *> lists(n);

			int m;
			for (int i = 0; i < n; ++i)
			{
				cin >> m;
				Input::InputList(lists[i], m);
			}

			ListNode *res = mergeKLists(lists);

			Output::OutputList(res);
		}

		cout << "End test Merge k Sorted Lists." << endl << endl;
		return true;
	}

private:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) 
			return nullptr;
		
		
		if (lists.size() == 1) 
			return lists[0];

		auto cmp = [](ListNode *i_a, ListNode *i_b) {return i_a->val > i_b->val; };
		priority_queue < ListNode*, vector<ListNode*>, decltype(cmp)> que(cmp);
		
		ListNode *h = nullptr, *hp = nullptr;
		for (unsigned int i = 0; i < lists.size(); i++)
		{
			if (lists[i] != nullptr)
				que.push(lists[i]);
		}
		while (!que.empty())
		{
			if (h == nullptr)
			{
				h = que.top();
				hp = h;
			}
			else
			{
				hp->next = que.top();
				hp = hp->next;
			}
			
			que.pop();	
			if (hp->next != nullptr)
				que.push(hp->next);
		}
		return h;
	}
};

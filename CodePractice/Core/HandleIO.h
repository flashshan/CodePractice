#pragma once

#include <iostream>
#include <vector>

#include "DataStructure.h"

using namespace std;


namespace Input
{
	void InputArray(vector<int> &nums, int n);  

	void InputMatrix();

	void InputList(ListNode *&node, int n);
	
	void InputTree();

	void InputGraph();



}


namespace Output
{
	void OutputArray(vector<int> &nums);   

	void OutputMatrix();

	void OutputList(ListNode *&node);

	void OutputTree();

	void OutputGraph();
}








#pragma once

#include <iostream>
#include <vector>

#include "DataStructure.h"


namespace Input
{
	void InputArray(std::vector<int> &nums, int n);  

	void Input2DArray(std::vector<std::vector<int>> &matrix, int n, int m);

	void InputStringArray(std::vector<std::string> &strs, int n);

	void InputList(ListNode *&node, int n);
	
	void InputTree();

	void InputGraph();



}


namespace Output
{
	void OutputArray(std::vector<int> &nums);   

	void Output2DArray(std::vector<std::vector<int>> &matrix);

	void OutputStringArray(std::vector<std::string> &strs);

	void OutputList(ListNode *&node);

	void OutputTree();

	void OutputGraph();
}








#pragma once

#include "Core/CoreMinimal.h"

#include <string>

#include <algorithm>
#include <stack>
#include <assert.h>

using namespace std;
/// Leetcode
/*
handle + - * / ( ) 
*/

class BasicOperator: public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Basic Calculator." << endl;

		string str;
		while (getline(std::cin, str))
		{
			if (str == "0")
				break;

			float res = calculate(str);

			cout << res << endl;
		}

		cout << "End test Basic Calculator." << endl << endl;
		return true;
	}

private:
	enum ValueType {
		Operator,
		Num,
	};
	float calculate(string s) {
		int strLen = (int)s.length();
		
		vector<char> operators;
		vector<pair<ValueType, int>> characters;

		int curPos = 0;

		while (curPos < strLen)
		{
			if (s[curPos] >= '0' && s[curPos] <= '9' || (s[curPos] == '-' && s[curPos + 1] >= '0' && s[curPos + 1] <= '9'))
			{
				bool negativeMark = false;
				if (s[curPos] == '-')
				{
					negativeMark = true;
					++curPos;
				}
				int tempValue = 0;
				while (curPos < strLen && s[curPos] != ' ' && s[curPos] != ')')
				{
					tempValue = tempValue * 10 + s[curPos] - '0';
					++curPos;
				}
				--curPos;
				if (negativeMark)
					tempValue = -tempValue;

				characters.push_back(make_pair(ValueType::Num, tempValue));
			}
			else if (s[curPos] == '+' || s[curPos] == '-')
			{
				while (!operators.empty() && operators.back() != '(')
				{
					characters.push_back(make_pair(ValueType::Operator, operators.back()));
					operators.pop_back();
				}
				operators.push_back(s[curPos]);
			}
			else if (s[curPos] == '*' || s[curPos] == '/')
			{
				while (!operators.empty() && (operators.back() == '*' || operators.back() == '/'))
				{
					characters.push_back(make_pair(ValueType::Operator, operators.back()));
					operators.pop_back();
				}
				operators.push_back(s[curPos]);
			}
			else if (s[curPos] == '(')
			{
				operators.push_back(s[curPos]);
			}
			else if (s[curPos] == ')')
			{
				while (operators.back() != '(')
				{
					characters.push_back(make_pair(ValueType::Operator, operators.back()));
					operators.pop_back();
				}
				operators.pop_back();
			}
			++curPos;
		}

		while (!operators.empty())
		{
			characters.push_back(make_pair(ValueType::Operator, operators.back()));
			operators.pop_back();
		}

		int characterCount = (int)characters.size();
		stack<float> values;
		for (int i = 0; i < characterCount; ++i)
		{
			if (characters[i].first == ValueType::Num)
			{
				values.push((float)(characters[i].second));
			}
			else
			{
				float num2 = values.top();
				values.pop();
				float num1 = values.top();
				values.pop();
				switch (characters[i].second)
				{
				case '+':
					values.push(num1 + num2);
					break;
				case '-':
					values.push(num1 - num2);
					break;
				case '*':
					values.push(num1 * num2);
					break;
				case '/':
					values.push(num1 / num2);
					break;
				default:
					break;
				}
			}
		}
		assert(values.size() == 1);
		return values.top();
	}

	/*float calculate(string s) {
		int strLen = s.length();

		vector<char> operators;
		vector<float> nums;

		int curPos = 0;

		while (curPos < strLen)
		{
			if (s[curPos] >= '0' && s[curPos] <= '9' || (s[curPos] == '-' && s[curPos + 1] >= '0' && s[curPos + 1] <= '9'))
			{
				bool negativeMark = false;
				if (s[curPos] == '-')
				{
					negativeMark = true;
					++curPos;
				}
				int tempValue = 0;
				while (curPos < strLen && s[curPos] != ' ' && s[curPos] != ')')
				{
					tempValue = tempValue * 10 + s[curPos] - '0';
					++curPos;
				}
				--curPos;
				if (negativeMark)
					tempValue = -tempValue;

				if (!operators.empty() && (operators.back() == '*' || operators.back() == '/'))
				{
					float previousNum = nums.back();
					nums.pop_back();
					if (operators.back() == '*')
						nums.push_back(previousNum * float(tempValue));
					else
						nums.push_back(previousNum / float(tempValue));
					operators.pop_back();
				}
				else
					nums.push_back(float(tempValue));
			}
			else if (s[curPos] == '+' || s[curPos] == '-' || s[curPos] == '*' || s[curPos] == '/' || s[curPos] == '(')
			{
				operators.push_back(s[curPos]);
			}
			else if (s[curPos] == ')')
			{
				while (operators.back() != '(')
				{
					float num2 = nums.back();
					nums.pop_back();
					float num1 = nums.back();
					nums.pop_back();
					if (operators.back() == '+')
						nums.push_back(num1 + num2);
					else if (operators.back() == '-')
						nums.push_back(num1 - num2);
					else
						assert(0);
					operators.pop_back();
				}
				operators.pop_back();
				if(!operators.empty() && (operators.back() == '*' || operators.back() == '/'))
				{
					float num2 = nums.back();
					nums.pop_back();
					float num1 = nums.back();
					nums.pop_back();
					if (operators.back() == '*')
						nums.push_back(num1 * num2);
					else
						nums.push_back(num1 / num2);
					operators.pop_back();
				}
			}
			++curPos;
		}

		assert(operators.size() + 1 == nums.size());
		int curNumIndex = 0, curOperatorIndex = 0, operatorCount = operators.size();
		float res = nums[curNumIndex++];
		while (curOperatorIndex < operatorCount)
		{
			float nextNumber = nums[curNumIndex++];
			char nextOperator = operators[curOperatorIndex++];
			if (nextOperator == '+')
				res += nextNumber;
			else if (nextOperator == '-')
				res -= nextNumber;
			else
				assert(0);
		}
		return res;
	}*/

	/*int calculate(string s) {
			stack <int> nums, ops;
			int num = 0;
			int rst = 0;
			int sign = 1;
			for (char c : s) {
				if (isdigit(c)) {
					num = num * 10 + c - '0';
				}
				else {
					rst += sign * num;
					num = 0;
					if (c == '+') sign = 1;
					if (c == '-') sign = -1;
					if (c == '(') {
						nums.push(rst);
						ops.push(sign);
						rst = 0;
						sign = 1;
					}
					if (c == ')' && ops.size()) {
						rst = ops.top() * rst + nums.top();
						ops.pop(); nums.pop();
					}
				}
			}
			rst += sign * num;
			return rst;
		}
	};*/
};


/* test cases:
1 + 2
1 ?2 + 3
1 + 2 / 3
1 + 2 ?- 5 / 2
(1 + 2) / -2 + 5 / -10 * (2 + -1)
*/
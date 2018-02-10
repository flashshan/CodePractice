#pragma once

#include "Easy/AAInclude.h"
#include "Medium/AAInclude.h"
#include "Hard/AAInclude.h"

class ListTestCases : public TestCases
{
public:
	ListTestCases();
 };


inline ListTestCases::ListTestCases()
{
	AddTestCase(new AddTwoNumbers1());
	AddTestCase(new AddTwoNumbers2());
}
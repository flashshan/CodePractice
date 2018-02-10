#pragma once

#include "Interfaces.h"

#include "Easy/AAInclude.h"
#include "Medium/AAInclude.h"
#include "Hard/AAInclude.h"

class ArrayTestCases : public TestCases
{
public:
	ArrayTestCases();
 };


inline ArrayTestCases::ArrayTestCases()
{
	AddTestCase(new TwoSum());
}
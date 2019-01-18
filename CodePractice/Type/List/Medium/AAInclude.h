#pragma once

#include "Core/AllTestCase.h"

#include "AddTwoNumbers1.h"
#include "AddTwoNumbers2.h"
#include "RemoveNthNodeFromEnd.h"
#include "SwapNodesinPairs.h"

void ListTestCases::AddMediumTestCases()
{
	TryAddTestCase(new AddTwoNumbers1());
	TryAddTestCase(new AddTwoNumbers2());
	TryAddTestCase(new RemoveNthNodeFromEnd());
	TryAddTestCase(new SwapNodesinPairs());
}
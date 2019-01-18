#pragma once

#include "Core/AllTestCase.h"

#include "ImplementStrStr.h"
#include "LongestCommonPrefix.h"
#include "ValidParentheses.h"
#include "RepeatedString.h"


void StringTestCases::AddEasyTestCases()
{
	TryAddTestCase(new ImplementStrStr());
	TryAddTestCase(new LongestCommonPrefix());
	TryAddTestCase(new ValidParentheses());
	TryAddTestCase(new RepeatedString());
}
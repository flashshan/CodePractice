#pragma once

#include "Core/AllTestCase.h"

#include "RegularExpressionMatching.h"
#include "StringSimilarity.h"

void StringTestCases::AddHardTestCases()
{
	TryAddTestCase(new RegularExpressionMatching());
	TryAddTestCase(new StringSimilarity());
}
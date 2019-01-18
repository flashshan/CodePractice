#pragma once

#include "Core/AllTestCase.h"

#include "LongestIncreasingSubsequence.h"


void DPTestCases::AddMediumTestCases()
{
	TryAddTestCase(new LongestIncreasingSubsequence());
}
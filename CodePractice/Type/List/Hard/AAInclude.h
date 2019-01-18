#pragma once

#include "Core/AllTestCase.h"

#include "MergekSortedLists.h"
#include "ReverseNodesinkGroup.h"

void ListTestCases::AddHardTestCases()
{
	TryAddTestCase(new MergekSortedLists());
	TryAddTestCase(new ReverseNodesinKGroup());
}
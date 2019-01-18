#pragma once

#include "Core\AllTestCase.h"

#include "MedianofTwoSortedArrays.h"
#include "RoseGrowQuestion.h"
#include "GridlandMetro.h"


void ArrayTestCases::AddMediumTestCases()
{
	TryAddTestCase(new MedianofTwoSortedArrays());
	TryAddTestCase(new RoseGrowQuestion());
	TryAddTestCase(new GridlandMetro());
}
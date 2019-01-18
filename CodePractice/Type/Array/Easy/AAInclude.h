#pragma once

#include "Core\AllTestCase.h"

#include "Heaters.h"
#include "MigratoryBirds.h"
#include "RemoveElement.h"
#include "RemoveDuplicatesFromSortedArray.h"
#include "TwoSum.h"
#include "SherlockandWatson.h"



void ArrayTestCases::AddEasyTestCases()
{
	TryAddTestCase(new Heaters());
	TryAddTestCase(new MigratoryBirds());
	TryAddTestCase(new RemoveElement());
	TryAddTestCase(new RemoveDuplicatesFromSortedArray());
	TryAddTestCase(new TwoSum());
	TryAddTestCase(new SherlockAndWatson());
}
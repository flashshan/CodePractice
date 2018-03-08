#pragma once

#include "Core/AllTestCase.h"

#include "ExtraLongFactorials.h"

void MathTestCases::AddMediumTestCases()
{
	AddTestCase(new ExtraLongFactorials());
}
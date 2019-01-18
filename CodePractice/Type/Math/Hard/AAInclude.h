#pragma once

#include "Core/AllTestCase.h"

#include "BasicCalculator.h"
#include "KnightLOnChessboard.h"

void MathTestCases::AddHardTestCases()
{
	TryAddTestCase(new BasicOperator());
	TryAddTestCase(new KnightLOnChessboard());
}
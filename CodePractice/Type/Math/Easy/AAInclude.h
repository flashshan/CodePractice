#pragma once

#include "Core/AllTestCase.h"

#include "PalindromeNumber.h"
#include "ReverseInteger.h"

void MathTestCases::AddEasyTestCases()
{
	TryAddTestCase(new PalindromeNumber());
	TryAddTestCase(new ReverseInteger());
}
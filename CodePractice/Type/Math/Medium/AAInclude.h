#pragma once

#include "Core/AllTestCase.h"

#include "ExtraLongFactorials.h"
#include "NonDivisibleSubset.h"
#include "BitwiseAND.h"
#include "FindTheMedian.h"
#include "MarkandToys.h"
#include "FraudulentActivityNotifications.h"
#include "LilyHomework.h"
#include "CountingInversions.h"
#include "MinimumLoss.h"
#include "MissingNumbers.h"


void MathTestCases::AddMediumTestCases()
{
	TryAddTestCase(new BitwiseAND());
	TryAddTestCase(new ExtraLongFactorials());
	TryAddTestCase(new NonDivisibleSubset());
	TryAddTestCase(new FindMedian());
	TryAddTestCase(new MarkAndToys());
	TryAddTestCase(new FraudulentActivityNotifications());
	TryAddTestCase(new LilyHomework());
	TryAddTestCase(new CountingInversions());
	TryAddTestCase(new MinimumLoss());
	TryAddTestCase(new MissingNumbers());
}
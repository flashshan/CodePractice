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
	//AddTestCase(new BitwiseAND());
	//AddTestCase(new ExtraLongFactorials());
	//AddTestCase(new NonDivisibleSubset());
	//AddTestCase(new FindMedian());
	//AddTestCase(new MarkAndToys());
	//AddTestCase(new FraudulentActivityNotifications());
	//AddTestCase(new LilyHomework());
	//AddTestCase(new CountingInversions());
	//AddTestCase(new MinimumLoss());
	AddTestCase(new MissingNumbers());
}
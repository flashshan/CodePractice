#pragma once

#include "Core\AllTestCase.h"

#include "FourSum.h"
#include "ElectronicsShop.h"
#include "ThreeSum.h"
#include "ThreeSumClosest.h"
#include "ContainerWithMostWater.h"
#include "ClimbingLeaderboard.h"
#include "QuickSorting.h"
#include "HackerlandRadioTransmitters.h"


void ArrayTestCases::AddHardTestCases()
{
	TryAddTestCase(new FourSum());
	TryAddTestCase(new ThreeSum());
	TryAddTestCase(new ThreeSumCloest());
	TryAddTestCase(new ContainerWithMostWater());
	TryAddTestCase(new ElectronicsShop());
	TryAddTestCase(new ClimbingLeaderboard());
	TryAddTestCase(new QuickSorting());
	TryAddTestCase(new HackerlandRadioTransmitters());
}
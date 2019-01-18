#pragma once

#include "Core/AllTestCase.h"

#include "GenerateParentheses.h"
#include "IntegerToRoman.h"
#include "LongestPalindromicSubstring.h"
#include "LongestSubstringWithoutRepeating.h"
#include "StringToInt.h"
#include "ZigZagConversion.h"
#include "LetterCombinationsPhoneNumber.h"
#include "TimeInWords.h"
#include "HappyLadybugs.h"
#include "DetectHTMLAttributes.h"


void StringTestCases::AddMediumTestCases()
{
	TryAddTestCase(new GenerateParentheses());
	TryAddTestCase(new IntegerToRoman());
	TryAddTestCase(new LongestPalindromicSubstring());
	TryAddTestCase(new LongestSubstringWithoutRepeating());
	TryAddTestCase(new StringToInteger());
	TryAddTestCase(new ZigZagConversion());
	TryAddTestCase(new LetterCombinationsPhoneNumber());
	TryAddTestCase(new TimeInWords());
	TryAddTestCase(new HappyLadybugs());
	TryAddTestCase(new DetectHTMLAttributes());
}
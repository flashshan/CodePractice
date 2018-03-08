#pragma once

#include "Core/CoreMinimal.h"

#include <algorithm>
#include <map>

using namespace std;
/// HackerRank 
/*
You have been asked to help study the population of birds migrating across the continent. Each type of bird you are interested in will be identified by an integer value. Each time a particular kind of bird is spotted, its id number will be added to your array of sightings. You would like to be able to find out which type of bird is most common given a list of sightings. Your task is to print the type number of that bird and if two or more types of birds are equally common, choose the type with the smallest ID number.

Input Format

The first line contains an integer denoting , the number of birds sighted and reported in the array .
The second line describes  as  space-separated integers representing the type numbers of each bird sighted.

Constraints

It is guaranteed that each type is , , , , or .
Output Format

Print the type number of the most common bird; if two or more types of birds are equally common, choose the type with the smallest ID number.

Sample Input 0

6
1 4 4 4 5 3
Sample Output 0

4
*/

class MigratoryBirds : public ITest{
public:
	virtual bool RunTest() override
	{
		cout << "Start test Migratory Birds." << endl;

		int n;
		while (cin >> n)
		{
			if (n == 0)
				break;

			vector<int> nums;
			Input::InputArray(nums, n);

			int res = migratoryBirds(n, nums);

			cout << res << endl;
		}

		cout << "End test Migratory Birds." << endl << endl;
		return true;
	}

private:
	int migratoryBirds(int n, vector <int> ar) {
		// Complete this function
		int count[5];
		memset(count, 0, 20);

		for (int i = 0; i < n; ++i)
		{
			++count[ar[i] - 1];
		}
		int index = 0, maxCount = count[0];

		for (int i = 1; i < 5; ++i)
		{
			if (count[i] > maxCount)
			{
				index = i;
				maxCount = count[i];
			}
		}
		return index + 1;
		
	}
};
/*
You are given an array of integers nums. You are also given an integer original which is the first number that needs to be searched for in nums.

You then do the following steps:

If original is found in nums, multiply it by two (i.e., set original = 2 * original).
Otherwise, stop the process.
Repeat this process with the new number as long as you keep finding the number.
Return the final value of original.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1000;

bool numExists(vector<int> &nums, int Findnum)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == Findnum)
            return true;
    }
    return false;
}

int findFinalValue(vector<int> &nums, int original)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (numExists(nums, original))
            original *= 2;
    }
    return original;
}

int main()
{
    vector<int> nums;
    int original;
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(1);
    nums.push_back(12);
    original = 3;
    cout << findFinalValue(nums, original);
    return 0;
}

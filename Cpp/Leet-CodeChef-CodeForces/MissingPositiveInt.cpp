/*
Optimum Approach - 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool contains1 = false;

        // Replace negative numbers, zeros,
        // and numbers larger than n with 1s.
        // After this nums contains only positive numbers.
        for (int i = 0; i < n; i++) {
            // Check whether 1 is in the original array
            if (nums[i] == 1) {
                contains1 = true;
            }
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }      
        }

        if (!contains1) return 1;

        // Mark whether integers 1 to n are in nums
        // Use index as a hash key and negative sign as a presence detector.
        for (int i = 0; i < n; i++) {
            int a = abs(nums[i]);
            if (a == n) {
                nums[0] = -abs(nums[0]);
            } else {
                nums[a] = -abs(nums[a]);
            }       
        }

        // First positive in nums is smallest missing positive integer
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0)
                return i;
        }

        // nums[0] stores whether n is in nums
        if (nums[0] > 0) {
            return n;
        }

        // If nums contained all elements 1 to n
        // the smallest missing positive number is n + 1
        return n + 1;
    }
};

*/


#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <string>
#include <climits>
#include <set>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
const int N = 1e3 + 2, MOD = 1e9 + 7;

// int firstMissingPositive(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());

//     int count = 1;
//     for (int i = 0; i < nums.size() - 1; i++)
//     {
//         if(nums[i] >= 0 && nums[i] == count){
//             count++;
//         }
//     }
//     return count;
// }


int firstMissingPositive(vector<int> &nums){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int c = 1;

    // n = 1
    if(n == 1){
        if(nums[0] == 1)
            return 2;
        else if(nums[0] != 1 && nums[0] > 0){
            return 1;            
        }
        else if(nums[0] <= 0)
            return 1;
    }

    // for not n = 1 and 1st element 1 or -ve 
    for (int i = 0; i < n; i++)
    {
        if(nums[i] == c and nums[i] != 0)
            c++;
    }
    return c;
}


int main()
{
    int n; // Length of the vectors
    cout << "Enter the length of the vectors: ";
    cin >> n;

    vector<int> vector1(n);

    cout << "Enter elements for vector: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> vector1[i];
    }

    cout << firstMissingPositive(vector1) << endl;
    return 0;
}
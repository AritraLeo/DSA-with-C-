#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    int smallestRangeII(vector<int> &nums, int k)
    {

        /*
        // get the min ele and max in nums
        // 1st ele initial max and min
        // max - k & min + k is score
        if(nums.size() == 1) return 0;
        int max = nums[0];
        int min = nums[0];
        for(int i=0; i < nums.size(); i++){
            if(nums[i] > max) max=nums[i];

            if(nums[i] < min) min = nums[i];
        }

        int score = (max - k) - (min + k);

        return score;

        */

        // sort nums
        // split btw nums calc max and min initially nums[0]
        // score inital max - min
        // calc score = min(score, high - low)
        // int high = max(nums[n-1] - k, nums[i] + k);
        // int low = min(nums[0] + k, nums[i+1] - k);

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int initial_diff = nums[n - 1] - nums[0];
        int min_score = initial_diff;

        for (int i = 0; i < n - 1; ++i)
        {
            int high = max(nums[n - 1] - k, nums[i] + k);
            int low = min(nums[0] + k, nums[i + 1] - k);
            min_score = min(min_score, high - low);
        }

        return min_score;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 3, 6};
    int k1 = 3;
    cout << "Minimum score for nums1: " << sol.smallestRangeII(nums1, k1) << endl;

    vector<int> nums2 = {4, 7, 8, 10};
    int k2 = 2;
    cout << "Minimum score for nums2: " << sol.smallestRangeII(nums2, k2) << endl;

    return 0;
}

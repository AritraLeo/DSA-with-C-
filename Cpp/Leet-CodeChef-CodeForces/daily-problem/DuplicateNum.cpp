/*

Better approach - 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ret = 0;
        for (int i=0; i < nums.size(); ++i) {
            int curr = abs(nums[i]);
            if (nums[curr] < 0) {
                ret = curr;
                break;
            }
            nums[curr] = -nums[curr];
        }

        for (auto&& n: nums) {
            n = abs(n);
        }
        return ret;
    }
};

*/


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                return nums[i];
        }
        return -1;
    }
};

int main()
{
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 3, 4, 2, 2};
    int result1 = sol.findDuplicate(nums1);
    cout << "Test case 1 result: " << result1 << endl;

    // Test case 2
    vector<int> nums2 = {3, 1, 3, 4, 2};
    int result2 = sol.findDuplicate(nums2);
    cout << "Test case 2 result: " << result2 << endl;

    // Test case 3
    vector<int> nums3 = {1, 1};
    int result3 = sol.findDuplicate(nums3);
    cout << "Test case 3 result: " << result3 << endl;

    return 0;
}

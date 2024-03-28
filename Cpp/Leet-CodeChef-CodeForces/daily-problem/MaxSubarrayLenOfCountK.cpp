/*

Optimized approach - 

Initialize variables:
n as the size of the input array nums.
left and right pointers, both starting at index 0.
product as the initial product, set to 1.
count to store the number of valid subarrays.
Loop through the array with the right pointer:
Update product by multiplying it with the value at nums[right].
While product is greater than or equal to k, move the left pointer and update product by dividing it by nums[left].
For each valid subarray found (right - left + 1), update count.
Return count.

class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int product = 1;
        int count = 0;

        while (right < n) {
            product *= nums[right];

            // Shrink the window from the left until product is less than k
            while (left <= right && product >= k) {
                product /= nums[left];
                left++;
            }

            // Count the valid subarrays
            count += (right - left + 1);

            // Move the right pointer to the next element
            right++;
        }

        return count;
    }
};


*/



#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        // create map m, iterate, if(ele in m) get count if(count < k) insert to map
        // iterate m -> count ele's with count same as k return ele's count x k;

        unordered_map<int, int> m;
        int c = 0;
        int ele, mCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ele = nums[i];
            if (m.find(ele) != m.end())
            {
                mCount = m[ele];
                if (mCount < k)
                {
                    m[ele]++;
                }
            }
            else
            {
                m[ele]++;
            }
        }

        for (const auto &pair : m)
        {
            if (pair.second == k)
                c++;
        }

        return c * k;
    }
};

int main()
{
    // Test case
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    int k = 2;

    Solution sol;
    int result = sol.maxSubarrayLength(nums, k);

    cout << "Maximum subarray length with elements occurring less than " << k << " times: " << result << endl;

    return 0;
}
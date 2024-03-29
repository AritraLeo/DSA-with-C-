/*

Algorithm
Find the Maximum Element:

Find the maximum element (max_num) in the array nums.
Initialize Variables:

Initialize left, right to 0, count to 0, and ans to 0.
Sliding Window Technique:

Use a sliding window approach to iterate through nums.
Move right pointer from left to right.
Increment count if nums[right] equals max_num.
Count Subarrays:

If count >= k, calculate subarrays count:
Add nums.size() - right to ans.
This accounts for all subarrays ending at right with at least k occurrences of max_num.
Adjusting Window:

Shrink window from left if necessary:
Move left pointer rightwards.
Decrement count if nums[left] equals max_num.
Move Right Pointer:

Move right pointer to continue expanding the window.
Return Answer:

Return ans as the total count of subarrays satisfying the condition.

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <valarray>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int max_num = *max_element(nums.begin(),nums.end()),count = 0;
        long long int left = 0,right = 0,ans = 0;
        while(right<nums.size()){
            if(nums[right] == max_num)count++;
            
            while(count>=k){
                if(nums[left]==max_num)count--;
                left++;
                ans += nums.size()-right;
            }    
            right++;
        }


        return ans;
        
    }
};


int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 3, 2, 3, 3};
    int k1 = 2;
    std::cout << "Example 1: " << solution.countSubarrays(nums1, k1) << std::endl;

    std::vector<int> nums2 = {1, 4, 2, 1};
    int k2 = 3;
    std::cout << "Example 2: " << solution.countSubarrays(nums2, k2) << std::endl;

    return 0;
}

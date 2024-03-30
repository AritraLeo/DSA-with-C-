/*
Overall Approach:

The solution utilizes a sliding window technique to count the number of subarrays with exactly k distinct integers.
Counting Subarrays with k Distinct Integers:

The subarraysWithKDistinct function computes the difference between the count of subarrays with at most k distinct integers and the count of subarrays with at most k-1 distinct integers.
Counting Subarrays with At Most k Distinct Integers:

The subarray_with_atmost_k helper function calculates the count of subarrays with at most k distinct integers.
It initializes a sliding window with left and right pointers.
It maintains a hashmap map to track the frequency of integers within the window.
The right pointer moves to the right, updating the frequency of the current element in map.
If the count of distinct integers exceeds k, the left pointer is adjusted to shrink the window until the count becomes at most k.
The size of each valid subarray ending at the current position (right) is added to the answer.

*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysWithKDistinct(std::vector<int>& nums, int k) {
        int sub_with_max_element_k = subarray_with_atmost_k(nums, k);
        int reduced_sub_with_max_k = subarray_with_atmost_k(nums, k - 1);
        return (sub_with_max_element_k - reduced_sub_with_max_k);
    }
    
    int subarray_with_atmost_k(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        int left = 0, right = 0, ans = 0;
        
        while (right < nums.size()) {
            map[nums[right]]++;
            
            while (map.size() > k) {
                map[nums[left]]--;
                if (map[nums[left]] == 0) map.erase(nums[left]);
                left++;
            }
            
            ans += right - left + 1; // size of subarray
            right++;
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    std::vector<int> nums1 = {1, 2, 1, 2, 3};
    int k1 = 2;
    std::cout << "Example 1: " << solution.subarraysWithKDistinct(nums1, k1) << std::endl;

    std::vector<int> nums2 = {1, 2, 1, 3, 4};
    int k2 = 3;
    std::cout << "Example 2: " << solution.subarraysWithKDistinct(nums2, k2) << std::endl;

    return 0;
}

/*

Iterate over the array using the right pointer:
Multiply the current element with the product.
If the product is greater than or equal to k, move the left pointer to the right until the product becomes less than k.
Add the length of the subarray (right - left + 1) to the count.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, product = 1, count = 0;
        
        for (int right = 0; right < n; ++right) {
            product *= nums[right];
            
            while (left <= right && product >= k) {
                product /= nums[left++];
            }
            
            count += right - left + 1;
        }
        
        return count;
    }
};


int main() {
    // Test case
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    
    // Create an instance of the Solution class
    Solution sol;
    
    // Call the numSubarrayProductLessThanK function
    int result = sol.numSubarrayProductLessThanK(nums, k);
    
    // Display the result
    cout << "Number of subarrays with product less than " << k << ": " << result << endl;

    return 0;
}

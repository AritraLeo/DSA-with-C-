/*
Logic Explanation:

-> To solve the problem without using the division operation and in linear time complexity (O(n)), we utilize the concept of prefix and suffix products.
-> We initialize an output vector output of size n with all elements set to 1. This vector will store the final result.
-> We iterate through the array to calculate the prefix products. At each iteration, we update the corresponding element in the output vector with the prefix product up to that point.
-> We then iterate through the array in reverse order to calculate the suffix products. Again, at each iteration, we update the corresponding element in the output vector with the suffix product up to that point.
-> Finally, we return the output vector containing the product of all elements except self.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1); // Initialize output vector with 1s
        int prefix = 1, suffix = 1; // Initialize prefix and suffix products
        
        // Calculate prefix products
        for (int i = 0; i < n; ++i) {
            output[i] *= prefix; // Update output with prefix product
            prefix *= nums[i]; // Update prefix product
        }
        
        // Calculate suffix products
        for (int i = n - 1; i >= 0; --i) {
            output[i] *= suffix; // Update output with suffix product
            suffix *= nums[i]; // Update suffix product
        }
        
        return output;
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {4, 5, 6, 7};

    // Test the function with test cases
    vector<int> result1 = sol.productExceptSelf(nums1);
    vector<int> result2 = sol.productExceptSelf(nums2);

    // Print the results
    cout << "Result 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Result 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

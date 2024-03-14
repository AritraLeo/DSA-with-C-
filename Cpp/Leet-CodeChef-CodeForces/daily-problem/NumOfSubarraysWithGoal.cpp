#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0; // Initialize count of subarrays
        int prefixSum = 0; // Initialize prefix sum
        unordered_map<int, int> prefixSumCount; // Map to store prefix sum count
        
        // Initialize the count of prefix sum 0 as 1
        prefixSumCount[0] = 1;
        
        // Iterate through the array
        for (int num : nums) {
            prefixSum += num; // Calculate prefix sum
            
            // Check if prefix sum - goal exists in the map
            if (prefixSumCount.find(prefixSum - goal) != prefixSumCount.end()) {
                count += prefixSumCount[prefixSum - goal]; // Add the count to the total
            }
            
            // Increment the count of the current prefix sum
            prefixSumCount[prefixSum]++;
        }
        
        return count;
    }
};

int main() {
    // Test cases
    Solution sol;
    vector<int> nums1 = {1, 0, 1, 0, 1};
    int goal1 = 2;
    cout << "Test Case 1: nums = [1, 0, 1, 0, 1], goal = 2" << endl;
    cout << "Expected Output: 4" << endl;
    cout << "Output: " << sol.numSubarraysWithSum(nums1, goal1) << endl;
    
    vector<int> nums2 = {0, 0, 0, 0, 0};
    int goal2 = 0;
    cout << "Test Case 2: nums = [0, 0, 0, 0, 0], goal = 0" << endl;
    cout << "Expected Output: 15" << endl;
    cout << "Output: " << sol.numSubarraysWithSum(nums2, goal2) << endl;

    return 0;
}

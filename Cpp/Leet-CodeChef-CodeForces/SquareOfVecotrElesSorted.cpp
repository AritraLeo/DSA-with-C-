/*

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].


Initialize two pointers, one at the beginning of the array (pointing to the smallest element) and the other at the end of the array (pointing to the largest element).
Compare the absolute values of the elements pointed to by the two pointers.
Square the larger absolute value and insert it at the end of the result array.
Move the pointer of the larger absolute value towards the center of the array.
Repeat steps 2-4 until both pointers meet in the center of the array.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        int left = 0, right = n - 1;
        int idx = n - 1; // Index to insert squared elements into the result array
        
        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[idx--] = nums[left] * nums[left];
                left++;
            } else {
                result[idx--] = nums[right] * nums[right];
                right--;
            }
        }
        
        return result;
    }
};

int main() {
    // Test case
    vector<int> nums = {-4, -1, 0, 3, 10};
    Solution sol;
    vector<int> result = sol.sortedSquares(nums);
    
    // Print the result
    cout << "Sorted Squares: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

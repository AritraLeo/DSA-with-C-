#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int c=0;
//         for(int i=0; i < nums.size()-1; i++){
//             if(nums[i] == nums[i+1]){
//                 checkDuplicate(nums, i+1);
//             }
//         }

//         for(int i=0; i < nums.size(); i++){
//             if(nums[i] == 101){
//                 c++;
//                 shift_left_array(nums, i);
//             }
//         }

//         return (nums.size()-c);
//     }
// public: 
//     void checkDuplicate(vector<int>& nums, int i){
//         if(i < nums.size() -1 && nums[i] == nums[i+1]){
//             nums[i] = 101;
//             checkDuplicate(nums, i+2);
//         }
//         return;
//     }
// public:
//     void shift_left_array(vector<int>& nums, int i){
//         nums.push_back(101);
//         for(int k=i; k < nums.size(); k++){
//             nums[k] = nums[k+1];
//         }
//         return;
//     }
// };

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};


int main() {
    Solution sol;
    
    // Test cases
    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    cout << "Length after removing duplicates in nums1: " << sol.removeDuplicates(nums1) << endl; // Expected output: 2
    cout << "Length after removing duplicates in nums2: " << sol.removeDuplicates(nums2) << endl; // Expected output: 5
    
    return 0;
}

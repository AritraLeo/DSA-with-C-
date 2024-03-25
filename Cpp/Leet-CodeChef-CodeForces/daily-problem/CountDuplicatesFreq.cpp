#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                res.push_back(nums[i]);
                /*
                
                if(c == 0){
                    res.push_back(nums[i]);
                    c++;
                }
                else if(res[c] != nums[i]){
                    res.push_back(nums[i]);
                    c++;
                }
                */
            }
        }
        return res;
    }
};

int main() {
    // Test case
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    
    // Create an instance of the Solution class
    Solution sol;
    
    // Call the findDuplicates function
    vector<int> result = sol.findDuplicates(nums);
    
    // Display the result
    cout << "Duplicates: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

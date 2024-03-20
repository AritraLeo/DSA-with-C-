/*
Not proper soln
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> v1 = nums;
        vector<int> v2 = nums;

        sort(v1.begin(),v1.end());
        sort(v2.rbegin(),v2.rend());
        
        for(int i=0; i<=nums.size()/2+2; i+=2){

            if(v2[i/2] > v1[i/2]){
            nums[i] = v1[i/2];
            nums[i+1] = v2[i/2];
            }
            else{
                nums[i] = nums[0];
                nums[0] = v1[i/2];
                nums[i+1] = v2[i/2];
            }
            cout << "i = " << i  << "V1: " << v1[i] << " V2: " << nums[i+1] << endl;
    }
//       for(int i=0; i<v1.size(); i++)
//           cout << v1[i] << " ";
        
//         for(int i=0; i<v2.size(); i++)
//           cout << v2[i] << " ";
    }
};

int main() {
    // Test case
    vector<int> nums = {1, 3, 2, 2, 3, 1};
    /*
    Output: [2,3,1,3,1,2]
    v1 = 1,1,2,2,3,3
    v2 = 3,3,2,2,1,1
    nums = 1 3 1 3 2 2
    */
    
    Solution sol;
    sol.wiggleSort(nums);

    cout << "Output: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

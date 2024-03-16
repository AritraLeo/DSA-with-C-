/*
Initial Wrong Idea

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        // count 1's and 0's 
        // calc min (c1, c0) + 1 return this
        int count1 = 0, count0 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                count1++;
            else
                count0++;
        }
        int minCount = min(count1, count0) * 2 + 1;
        return count1 == count0      ? count0 * 2
               : (minCount % 2 == 0) ? minCount
                                     : minCount - 1;
    }
};

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = -1;
        int maxLen = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            count += nums[i] == 1 ? 1 : -1;
            if (prefixSum.find(count) != prefixSum.end()) {
                maxLen = max(maxLen, i - prefixSum[count]);
            } else {
                prefixSum[count] = i;
            }
        }

        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,1,1,0,1,1,1,0};
    int result = sol.findMaxLength(nums);
    cout << "Longest contiguous subarray with an equal number of 0's and 1's: " << result << endl;
    return 0;
}



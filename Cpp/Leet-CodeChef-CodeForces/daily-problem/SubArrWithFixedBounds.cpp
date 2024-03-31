/*
Brute approach - 

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        for(int i=0; i < nums.size() - 1; i++){
            for(int j=i+1; j < nums.size(); j++){
                if(checkForMinMax(nums, i, j, minK, maxK)) ans++;
            }
        }

        return ans;
    }

public:
    bool checkForMinMax(vector<int>& nums, int& i, int& j, int minK, int maxK){
        int cMin = 0, cMax = 0;
        for(int k=i; k <= j; k++){
            if(nums[k] > maxK) return false;

            if(nums[k] == minK) cMin++;
            else if(nums[k] == maxK) cMax++;
        }
        if(cMin >=1 && cMax >=1) return true;

        return false;
    }
};


Optimized Apporach - 

Although sliding window, but the pattern in Leetcode 992. Subarrays with K Different Integers
must be modified a lot.

Set maxi=-1, mini=-1 to track the positions for the indices for ocurrences of maxK & minK.
Set l=0. Use a loop from r=0 to nums.size()-1:
x=nums[r]
if x exceeds the bounds, move l to r+1 & goto the next iteration
set maxi=r if x==maxK; or mini=r if x==minK
increment=max((min(maxi, mini)-l+1),0), which is the number of subarrays ending with index=r with all values in [minK, maxK]. Add it to ans


*/

#include <iostream>
#include <vector>

using namespace std;

#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int maxi=-1, mini=-1;
        int s=nums.size();
        for(int r=0, l=0; r<s; r++){
            int x=nums[r];
            if (x<minK ||x>maxK){// x exceeds the bound
                l=r+1; // move l to r+1
                continue;
            }
            if (x==maxK) maxi=r; // position for maxK
            if (x==minK) mini=r; // position for minK
            ans+=max((min(maxi, mini)-l+1),0);
        }
        return ans;
    }
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main() {
    Solution solution;

    // Test cases
    vector<int> nums1 = {3, 1, 1, 2, 1, 2, 2, 3};
    int minK1 = 2, maxK1 = 3;
    cout << "Example 1: " << solution.countSubarrays(nums1, minK1, maxK1) << endl;

    vector<int> nums2 = {2, 2, 1, 1, 3, 3};
    int minK2 = 1, maxK2 = 3;
    cout << "Example 2: " << solution.countSubarrays(nums2, minK2, maxK2) << endl;

    return 0;
}

/*
Best soln - 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size(),l2=nums2.size(),i=0,j=0;
        vector<int>ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while(i<l1&&j<l2)
        {
            if(nums1[i]<nums2[j]) i++;
            else if(nums1[i]==nums2[j]) 
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]>nums2[j]) j++;
        }
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
        
    }
};

*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int, int> vectorToMap(const vector<int>& vec) {
    unordered_map<int, int> frequencyMap;
    for (int num : vec) {
        frequencyMap[num]++;
    }
    return frequencyMap;
}

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int> res;
        if (nums1.size() == 0 || nums2.size() == 0)
        {
            return res;
        }

        unordered_map<int, int> frequencyMap;
        vector<int> v;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // Check size -> iterate over smaller array and -> check in map of larger if item present -> check if item was already inserted -> store item in vector -> return res
        if(nums1.size() > nums2.size()){
            frequencyMap = vectorToMap(nums1);
            v = nums2;
        }else{
            frequencyMap = vectorToMap(nums2);
            v = nums1;
        }
        for (size_t i = 0; i < v.size(); i++)
        {
            if(i!= 0 && v[i] != v[i-1]){
                    res.push_back(v[i]);
                }
                if(res.size() == 0)
                    res.push_back(v[i]);
        }
        return res;
    }
};

int main() {
    // Test case
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    
    // Create a Solution object
    Solution sol;

    // Call the intersection function and print the result
    vector<int> result = sol.intersection(nums1, nums2);
    cout << "Intersection: [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>

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
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int, int> frequencyMap;
        vector<int> v;

        if (n > m) {
            frequencyMap = vectorToMap(nums1);
            v = nums2;
        } else {
            frequencyMap = vectorToMap(nums2);
            v = nums1;
        }

        // Check if elements of v are present in frequencyMap
        for (int i = 0; i < v.size(); ++i) {
            if (frequencyMap.find(v[i]) != frequencyMap.end()) {
                return v[i];
            } 
        }
        // return nums1[0] > nums2[0] ? nums2[0] : nums1[0];
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 2, 3};
    vector<int> nums2 = {2, 3, 4};

    int commonElement = solution.getCommon(nums1, nums2);
    if (commonElement != -1) {
        cout << "Common element found: " << commonElement << endl;
    } else {
        cout << "No common element found" << endl;
    }

    return 0;
}

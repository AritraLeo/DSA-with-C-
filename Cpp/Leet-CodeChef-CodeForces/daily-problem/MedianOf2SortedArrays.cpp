/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // merge -> calc median -> return
        double median;
        int n = nums1.size() - 1;
        int m = nums2.size() - 1;
        vector<int> v = merge(nums1, nums2, n, m);
        displayVector(v);

        int vSize = v.size();
        cout << vSize << endl;
        if (vSize % 2 == 0)
        {
            // even
            median = (v[vSize / 2 - 1] + v[vSize / 2]) / 2.0;
        }
        else
        {
            // odd
            median = v[vSize / 2];
        }

        return median;
    }

    void displayVector(const vector<int> &vec)
    {
        cout << "[";
        for (size_t i = 0; i < vec.size(); ++i)
        {
            cout << vec[i];
            if (i < vec.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    vector<int> merge(vector<int> nums1, vector<int> nums2, int n, int m)
    {
        vector<int> merged;
        int left = 0, right = 0;

        while (left <= n && right <= m)
        {
            if (nums1[left] <= nums2[right])
            {
                merged.push_back(nums1[left]);
                left++;
            }
            else
            {
                merged.push_back(nums2[right]);
                right++;
            }
        }

        while (left <= n)
        {
            merged.push_back(nums1[left]);
            left++;
        }

        while (right <= m)
        {
            merged.push_back(nums2[right]);
            right++;
        }

        return merged;
    }
};

int main()
{
    // Test case
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4};

    // Create a Solution object
    Solution sol;

    // Call the findMedianSortedArrays function and print the result
    double result = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << result << endl;

    return 0;
}

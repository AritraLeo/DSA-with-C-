#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
Approach:
Initial Observation:

The difference between corresponding elements in nums1 and nums2 is what we want to minimize.
k1 and k2 can be treated as a combined total number of operations, say k = k1 + k2.
Since we want to minimize the sum of squared differences, we should try to reduce the largest differences first, because the square of a larger number has a more significant impact on the total sum.
Greedy Reduction:

Compute the absolute differences between corresponding elements in nums1 and nums2.
Use a max-heap (priority queue) to keep track of the largest differences.
While you have operations left (k > 0), reduce the largest difference by 1, and push the new value back into the heap.
If the difference is already 0, it means further reductions aren't beneficial.
Final Computation:

After performing the operations, compute the sum of squares of the remaining differences.


Optimized Approach:
Calculate Differences:

First, compute the absolute differences between corresponding elements in nums1 and nums2.
Sort Differences:

Sort these differences in descending order.
Bulk Adjustment:

Rather than reducing one element at a time, we'll determine how much we can reduce groups of identical differences in bulk, which is much more efficient.
Sum of Squares:

After adjusting the differences, compute the sum of squares of the final differences.

*/

class Solution
{
public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
    {
        int n = nums1.size();
        int k = k1 + k2;
        vector<int> diffs(n);

        for (int i = 0; i < n; ++i)
        {
            diffs[i] = abs(nums1[i] - nums2[i]);
        }

        // Sort differences in descending order
        sort(diffs.begin(), diffs.end(), greater<int>());

        for (int i = 0; i < n && k > 0; ++i)
        {
            int current_diff = diffs[i];
            int next_diff = (i + 1 < n) ? diffs[i + 1] : 0;
            int count = i + 1;

            // The maximum we can reduce the current set of differences
            int total_reduction = (current_diff - next_diff) * count;

            if (k >= total_reduction)
            {
                k -= total_reduction;
                // Reduce the current difference level to the next difference level
                fill(diffs.begin(), diffs.begin() + count, next_diff);
            }
            else
            {
                int reduction_per_diff = k / count;
                int remainder = k % count;

                // Reduce as much as possible
                for (int j = 0; j < count; ++j)
                {
                    diffs[j] -= reduction_per_diff;
                }

                // Handle remainder by reducing a few more
                for (int j = 0; j < remainder; ++j)
                {
                    diffs[j]--;
                }

                k = 0; // No more reductions left
            }
        }

        // Calculate the sum of squares of the final differences
        long long result = 0;
        for (int diff : diffs)
        {
            result += static_cast<long long>(diff) * diff;
        }

        return result;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1_1 = {1, 2, 3, 4};
    vector<int> nums2_1 = {2, 10, 20, 19};
    int k1_1 = 0, k2_1 = 0;
    cout << "Example 1: " << sol.minSumSquareDiff(nums1_1, nums2_1, k1_1, k2_1) << endl; // Output: 579

    vector<int> nums1_2 = {1, 4, 10, 12};
    vector<int> nums2_2 = {5, 8, 6, 9};
    int k1_2 = 1, k2_2 = 1;
    cout << "Example 2: " << sol.minSumSquareDiff(nums1_2, nums2_2, k1_2, k2_2) << endl; // Output: 43

    return 0;
}

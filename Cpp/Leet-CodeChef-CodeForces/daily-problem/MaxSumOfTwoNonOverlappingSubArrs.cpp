#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen)
    {
        // Calculate prefix sums
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Helper function to get sum of subarray nums[i:j] using prefix sums
        auto getSum = [&](int i, int j) -> int
        {
            return prefix[j + 1] - prefix[i];
        };

        int maxSum = 0;

        // Iterate for the firstLen window and then for secondLen window in remaining parts
        for (int i = 0; i <= n - firstLen; ++i)
        {
            int sumFirst = getSum(i, i + firstLen - 1);

            // Left side of first window
            for (int j = 0; j <= i - secondLen; ++j)
            {
                int sumSecond = getSum(j, j + secondLen - 1);
                maxSum = max(maxSum, sumFirst + sumSecond);
            }

            // Right side of first window
            for (int j = i + firstLen; j <= n - secondLen; ++j)
            {
                int sumSecond = getSum(j, j + secondLen - 1);
                maxSum = max(maxSum, sumFirst + sumSecond);
            }
        }

        // Iterate for the secondLen window and then for firstLen window in remaining parts
        for (int i = 0; i <= n - secondLen; ++i)
        {
            int sumSecond = getSum(i, i + secondLen - 1);

            // Left side of second window
            for (int j = 0; j <= i - firstLen; ++j)
            {
                int sumFirst = getSum(j, j + firstLen - 1);
                maxSum = max(maxSum, sumFirst + sumSecond);
            }

            // Right side of second window
            for (int j = i + secondLen; j <= n - firstLen; ++j)
            {
                int sumFirst = getSum(j, j + firstLen - 1);
                maxSum = max(maxSum, sumFirst + sumSecond);
            }
        }

        return maxSum;
    }
};

// Example usage:
int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 1, 2, 6, 7, 5, 1};
    int firstLen = 2;
    int secondLen = 3;
    int result = solution.maxSumTwoNoOverlap(nums, firstLen, secondLen);
    // Expected output: 23 (subarrays are [6, 7] and [1, 2, 1])
    cout << "Max sum of two non-overlapping subarrays: " << result << "\n";

    return 0;
}

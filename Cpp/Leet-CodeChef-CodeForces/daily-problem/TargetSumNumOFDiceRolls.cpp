#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        // Create a dp array to store the number of ways to reach each target sum
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Base case: when rolling 0 dice, there is only 1 way to reach sum 0
        dp[0][0] = 1;

        // Iterate through each dice
        for (int i = 1; i <= n; ++i) {
            // Iterate through each possible target sum
            for (int j = 1; j <= target; ++j) {
                // Iterate through each face of the current dice
                for (int f = 1; f <= k; ++f) {
                    // If the current face value is less than or equal to the current target sum
                    // Add the number of ways to reach the previous sum (j - f) with (i - 1) dice
                    if (f <= j) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - f]) % MOD;
                    }
                }
            }
        }

        return dp[n][target];
    }

private:
    const int MOD = 1e9 + 7;
};

int main() {
    Solution sol;

    // Test cases
    cout << "Test Case 1: " << sol.numRollsToTarget(1, 6, 3) << endl; // Output: 1
    cout << "Test Case 2: " << sol.numRollsToTarget(2, 6, 7) << endl; // Output: 6
    cout << "Test Case 3: " << sol.numRollsToTarget(2, 5, 10) << endl; // Output: 1
    cout << "Test Case 4: " << sol.numRollsToTarget(1, 2, 3) << endl; // Output: 0
    cout << "Test Case 5: " << sol.numRollsToTarget(30, 30, 500) << endl; // Output: 222616187

    return 0;
}

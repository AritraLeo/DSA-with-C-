/*


1. **Initialization**: We initialize a 2D dynamic programming (DP) array `dp` of size `n x n` where `n` is the size of the grid. We set all values in `dp` to `INT_MAX` except for the first row, which is initialized with the values from the first row of the grid.

   ```cpp
   vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
   dp[0] = grid[0];
   ```

2. **Iterating through Rows**: We iterate through each row of the grid starting from the second row (`i = 1`).

   ```cpp
   for (int i = 1; i < n; ++i) {
       // Calculate the minimum falling path sum for each element in the current row
       for (int j = 0; j < n; ++j) {
           // Find the minimum element in the previous row excluding the current column
           int minPrev = INT_MAX;
           for (int k = 0; k < n; ++k) {
               if (k != j) {
                   minPrev = min(minPrev, dp[i - 1][k]);
               }
           }
           // Update the dp array with the minimum falling path sum for the current element
           dp[i][j] = grid[i][j] + minPrev;
       }
   }
   ```

3. **Updating DP Array**: For each element in the current row, we calculate the minimum falling path sum considering all possible choices from the previous row. We exclude the current column and find the minimum value from the previous row.

4. **Finding Minimum Sum**: After calculating the minimum falling path sum for each element in the last row, we find the minimum sum among them, which represents the minimum falling path sum with non-zero shifts.

   ```cpp
   int minSum = INT_MAX;
   for (int j = 0; j < n; ++j) {
       minSum = min(minSum, dp[n - 1][j]);
   }
   ```

5. **Return**: We return the minimum sum found.

*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Initialize the dp array with the first row of the grid
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dp[0] = grid[0];
        
        // Iterate through the rows of the grid starting from the second row
        for (int i = 1; i < n; ++i) {
            // Calculate the minimum falling path sum for each element in the current row
            for (int j = 0; j < n; ++j) {
                // Find the minimum element in the previous row excluding the current column
                int minPrev = INT_MAX;
                for (int k = 0; k < n; ++k) {
                    if (k != j) {
                        minPrev = min(minPrev, dp[i - 1][k]);
                    }
                }
                // Update the dp array with the minimum falling path sum for the current element
                dp[i][j] = grid[i][j] + minPrev;
            }
        }
        
        // Find the minimum falling path sum in the last row
        int minSum = INT_MAX;
        for (int j = 0; j < n; ++j) {
            minSum = min(minSum, dp[n - 1][j]);
        }
        
        return minSum;
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<vector<int>> grid1 = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << "Test Case 1: " << sol.minFallingPathSum(grid1) << endl; // Output: 13

    vector<vector<int>> grid2 = {{-19, 57}, {-40, -5}};
    cout << "Test Case 2: " << sol.minFallingPathSum(grid2) << endl; // Output: -24

    vector<vector<int>> grid3 = {{-48}};
    cout << "Test Case 3: " << sol.minFallingPathSum(grid3) << endl; // Output: -48

    return 0;
}

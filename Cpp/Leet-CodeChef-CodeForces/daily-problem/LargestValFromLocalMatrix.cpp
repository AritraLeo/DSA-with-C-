#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<int>> maxLocal(n - 2, std::vector<int>(n - 2));

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                int maxVal = INT_MIN;
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        maxVal = std::max(maxVal, grid[x][y]);
                    }
                }
                maxLocal[i][j] = maxVal;
            }
        }

        return maxLocal;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid = {
        {9, 9, 8, 1},
        {5, 6, 2, 6},
        {8, 2, 6, 4},
        {6, 2, 2, 2}
    };

    std::vector<std::vector<int>> result = solution.largestLocal(grid);

    // Output the result
    for (const auto& row : result) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

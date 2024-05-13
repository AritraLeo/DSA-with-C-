
#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    int matrixScore(std::vector<std::vector<int>>& grid) {
        int m = grid[0].size(), n = grid.size();
        if (m == 0 || n == 0) return 0;

        for (int i = 0; i < n; i++) {
            if (grid[i][0] != 1) {
                rflip(grid, i, m);
            }
        }

        for (int i = 0; i < m; i++) {
            int c1 = 0, c0 = 0;
            for (int j = 0; j < n; j++) {
                if (grid[j][i] == 0) c0++;
                else c1++;
            }

            if (c0 > c1) {
                cflip(grid, i, n);
            }
        }

        int maxlen = 0;
        for (int i = 0; i < n; i++) {
            std::string s = "";
            for (int j = 0; j < m; j++) {
                s += std::to_string(grid[i][j]);
            }
            maxlen += std::stoi(s, nullptr, 2);
        }

        return maxlen;
    }

    void rflip(std::vector<std::vector<int>>& grid, int i, int m) {
        for (int k = 0; k < m; k++) {
            grid[i][k] = 1 - grid[i][k];
        }
    }

    void cflip(std::vector<std::vector<int>>& grid, int i, int n) {
        for (int k = 0; k < n; k++) {
            grid[k][i] = 1 - grid[k][i];
        }
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid = {
        {0, 0, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 0}
    };

    std::cout << solution.matrixScore(grid) << std::endl;

    return 0;
}

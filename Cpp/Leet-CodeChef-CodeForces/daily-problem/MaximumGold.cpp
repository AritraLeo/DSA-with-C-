/*
// iterate for every ele in grid
// if not 0 / empty -> create visited matrix and 
// maxlen = max(maxlen, traversal(grid, i, j, vis, 0: maxlen))
// traversal -> recursive checks node not visited (mark it visited) then adds to maxlenlocal
// checks for left right up down exits and not zero 

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxlen = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    vector<vector<int>> vis(m, vector<int>(n, 0));
                    maxlen = std::max(maxlen, traversal(grid, i, j, vis));
                }
            }
        }

        return maxlen;
    }

    int traversal(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vis) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || vis[i][j] == 1) {
            return 0;
        }

        vis[i][j] = 1;
        int currentGold = grid[i][j];
        int up = traversal(grid, i - 1, j, vis);
        int down = traversal(grid, i + 1, j, vis);
        int left = traversal(grid, i, j - 1, vis);
        int right = traversal(grid, i, j + 1, vis);

        vis[i][j] = 0; // Backtrack

        return currentGold + max({up, down, left, right});
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {1, 0, 7},
        {2, 0, 6},
        {3, 4, 5},
        {0, 3, 0},
        {9, 0, 20}
    };

    cout << solution.getMaximumGold(grid) << std::endl;

    return 0;
}

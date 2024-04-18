#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    perimeter += 4;
                    if (i > 0 && grid[i - 1][j] == 1) perimeter -= 2;
                    if (j > 0 && grid[i][j - 1] == 1) perimeter -= 2;
                }
            }
        }

        return perimeter;
    }
};

int main() {
    // Test cases
    Solution sol;
    vector<vector<int>> grid1 = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    vector<vector<int>> grid2 = {{1}};
    vector<vector<int>> grid3 = {{1,0}};
    
    cout << "Perimeter of island in grid1: " << sol.islandPerimeter(grid1) << endl; // Expected output: 16
    cout << "Perimeter of island in grid2: " << sol.islandPerimeter(grid2) << endl; // Expected output: 4
    cout << "Perimeter of island in grid3: " << sol.islandPerimeter(grid3) << endl; // Expected output: 4
    
    return 0;
}

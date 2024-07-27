#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;

        // Initialize the queue with all the rotten oranges
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    freshOranges++;
                }
            }
        }

        if (freshOranges == 0)
            return 0; // No fresh oranges to begin with

        int minutes = -1; // Start at -1 to account for the first level in BFS
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Perform BFS
        while (!q.empty())
        {
            int size = q.size();
            ++minutes;
            for (int i = 0; i < size; ++i)
            {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : directions)
                {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        freshOranges--;
                    }
                }
            }
        }

        return freshOranges == 0 ? minutes : -1;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> grid1 = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << "Test Case 1: " << sol.orangesRotting(grid1) << endl; // Expected output: 4

    vector<vector<int>> grid2 = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    cout << "Test Case 2: " << sol.orangesRotting(grid2) << endl; // Expected output: -1

    vector<vector<int>> grid3 = {{0, 2}};
    cout << "Test Case 3: " << sol.orangesRotting(grid3) << endl; // Expected output: 0

    return 0;
}

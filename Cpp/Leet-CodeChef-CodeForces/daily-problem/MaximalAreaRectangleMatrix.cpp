#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<vector<int>> heights(rows, vector<int>(cols, 0));
        
        // Calculate heights matrix
        for (int j = 0; j < cols; ++j) {
            heights[0][j] = matrix[0][j] - '0';
            for (int i = 1; i < rows; ++i) {
                if (matrix[i][j] == '1') {
                    heights[i][j] = heights[i - 1][j] + 1;
                }
            }
        }
        
        int maxArea = 0;
        // Find maximal rectangle using largest rectangle in histogram algorithm
        for (int i = 0; i < rows; ++i) {
            maxArea = max(maxArea, largestRectangleArea(heights[i]));
        }
        
        return maxArea;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        heights.push_back(0); // Append 0 to the end to ensure all bars are processed
        
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int h = heights[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            stk.push(i);
        }
        
        return maxArea;
    }
};

int main() {
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    Solution sol;
    cout << "Maximal Rectangle Area: " << sol.maximalRectangle(matrix) << endl;

    return 0;
}

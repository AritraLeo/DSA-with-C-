/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Soln - 

Create an empty stack to store the indices of the histogram bars.

Iterate through each bar of the histogram:

If the stack is empty or the current bar's height is greater than or equal to the height of the bar at the top of the stack, push the index of the current bar onto the stack.
If the current bar's height is less than the height of the bar at the top of the stack, it means we've found the right boundary of a rectangle. Pop the index from the stack and calculate the area of the rectangle with the popped index as the right boundary. Repeat this process until the stack is empty or the height of the bar at the top of the stack is less than the height of the current bar.
For each rectangle, calculate its area by multiplying the height of the popped bar by the width (index difference) between the current bar and the bar at the top of the stack. Update the maximum area found so far.
After iterating through all bars, if there are bars remaining in the stack, repeat the above process for each remaining bar to calculate the area of the corresponding rectangle.

Return the maximum area found.
*/

#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int maxArea = 0;
        
        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && (i == n || heights[s.top()] > heights[i])) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            s.push(i);
        }
        
        return maxArea;
    }
};

int main() {
    // Test case
    vector<int> heights = {2,0,2};
    Solution sol;
    int result = sol.largestRectangleArea(heights);
    cout << "Largest rectangle area: " << result << endl;
    return 0;
}

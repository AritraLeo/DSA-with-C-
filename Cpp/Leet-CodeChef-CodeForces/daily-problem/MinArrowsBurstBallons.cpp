/*

Sort by End Points: First, we sort the balloons based on their end points. This helps us identify which balloons are overlapping, as they will have common end points.

Count Arrows: We initialize a variable arrows to keep track of the number of arrows needed. We then iterate through the sorted balloons:

If the current balloon's start point is greater than or equal to the previous balloon's end point, it means that these two balloons do not overlap. Therefore, we need another arrow to burst the current balloon, and we increment the arrows count.
If the current balloon's start point is less than the previous balloon's end point, it means that these two balloons overlap. In this case, we do not need an additional arrow, as one arrow can burst both balloons. We continue to the next balloon without incrementing the arrows count.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Sort by end points
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int arrows = 1; // Initial arrow count
        
        // Iterate through balloons
        int n = points.size();
        int prevEnd = points[0][1];
        for (int i = 1; i < n; ++i) {
            if (points[i][0] > prevEnd) {
                arrows++; // Need another arrow
                prevEnd = points[i][1]; // Update end point
            }
        }
        
        return arrows;
    }
};

int main() {
    // Test cases
    vector<vector<int>> points1 = {{10,16},{2,8},{1,6},{7,12}};
    vector<vector<int>> points2 = {{1,2},{3,4},{5,6},{7,8}};
    
    Solution sol;
    cout << "Minimum arrows needed for points1: " << sol.findMinArrowShots(points1) << endl;
    cout << "Minimum arrows needed for points2: " << sol.findMinArrowShots(points2) << endl;
    
    return 0;
}

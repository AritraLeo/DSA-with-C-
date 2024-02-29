/*
Iterating through each pair of points:

We iterate through each pair of points in the points array. To ensure that we don't count the same pair twice and avoid duplicate calculations, we start the inner loop from i + 1, where i is the index of the outer loop.
Calculating the slope between each pair of points:

For each pair of points (points[i], points[j]), we calculate the slope of the line passing through these two points. The slope between two points (x1, y1) and (x2, y2) is given by (y2 - y1) / (x2 - x1).
If the two points have the same x-coordinate, we handle this as a special case to avoid division by zero. In this case, we return positive infinity as the slope.
Storing the count of points with the same slope:

We maintain a hashmap called slopeCount, where the key is the slope between two points, and the value is the count of points that share that slope with the current pair of points (points[i], points[j]).
Calculating the maximum number of points on the same line for each point:

For each point points[i], we iterate through all pairs of points excluding points[i] itself.
We calculate the slope between points[i] and every other point and store the count of points that share the same slope in slopeCount.
We then update the maximum number of points on the same line passing through points[i] by finding the maximum count of points with the same slope (count + 1, where count is the value in slopeCount) and adding 1 to account for points[i] itself.
Updating the overall maximum number of points on the same line:

After processing all points, we update the overall maximum number of points on the same line (maxPointsOnLine) by taking the maximum of maxPointsOnLine and the maximum number of points on the same line for each individual point.
Returning the result:

Finally, we return maxPointsOnLine as the result, which represents the maximum number of points that lie on the same straight line.

*/

#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n <= 2)
            return n; // If there are 0, 1, or 2 points, return the number of points

        int maxPointsOnLine = 0; // Initialize the maximum number of points on the same line

        for (int i = 0; i < n; ++i)
        {
            unordered_map<double, int> slopeCount; // Store the count of points with the same slope

            for (int j = i + 1; j < n; ++j)
            {
                double slope = calculateSlope(points[i], points[j]); // Calculate the slope between points[i] and points[j]
                slopeCount[slope]++;                                 // Increment the count of points with the same slope
            }

            int currentMaxPointsOnLine = 1; // Initialize the maximum number of points on the same line for the current point

            // for (auto& [slope, counter] : slopeCount) {
            //     currentMaxPointsOnLine = max(currentMaxPointsOnLine, counter + 1); // Update the maximum number of points on the same line
            // }

            // above is the modern way C++ 17
            for (auto it = slopeCount.begin(); it != slopeCount.end(); ++it)
            {
                double slope = it->first;
                int counter = it->second;
                currentMaxPointsOnLine = max(currentMaxPointsOnLine, counter + 1);
            }

            maxPointsOnLine = max(maxPointsOnLine, currentMaxPointsOnLine); // Update the overall maximum number of points on the same line
        }

        return maxPointsOnLine;
    }

private:
    double calculateSlope(const vector<int> &p1, const vector<int> &p2)
    {
        if (p1[0] == p2[0])                            // If the points are vertically aligned
            return numeric_limits<double>::infinity(); // Return positive infinity as the slope

        return static_cast<double>(p2[1] - p1[1]) / (p2[0] - p1[0]); // Calculate the slope using the formula (y2 - y1) / (x2 - x1)
    }
};

int main()
{
    // Test case
    vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
    Solution sol;
    cout << "Maximum number of points on the same line: " << sol.maxPoints(points) << endl;

    return 0;
}

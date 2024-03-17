/*
Logic - 

Initialize an empty vector to store the merged intervals.
Iterate through the given intervals.
For each interval in the given intervals, do the following:
If the current interval ends before the new interval starts, add it to the merged intervals vector as it is.
If the current interval starts after the new interval ends, add the new interval to the merged intervals vector and update the new interval to the current interval.
If there is an overlap between the current interval and the new interval, update the new interval to merge both intervals.
Add the remaining new interval to the merged intervals vector.
Return the merged intervals vector.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> mergedIntervals;
        int n = intervals.size();
        int i = 0;

        // Add all intervals that end before the new interval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            mergedIntervals.push_back(intervals[i++]);
        }

        // Merge intervals that overlap with the new interval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        mergedIntervals.push_back(newInterval);

        // Add remaining intervals
        while (i < n) {
            mergedIntervals.push_back(intervals[i++]);
        }

        return mergedIntervals;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};

    Solution sol;
    vector<vector<int>> result = sol.insert(intervals, newInterval);

    cout << "Result after insertion:" << endl;
    for (const auto& interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}

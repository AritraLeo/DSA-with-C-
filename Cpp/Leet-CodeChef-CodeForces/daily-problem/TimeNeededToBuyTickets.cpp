/*
Explanation:

We define a class Solution that contains the method timeRequiredToBuy.
Inside the timeRequiredToBuy method, we calculate the total time required for each person to buy tickets.
We iterate over each person in the queue and check their position relative to the target position k.
For persons before k, we add the minimum of their ticket count and the ticket count of person k to the totalTime.
For persons after k, we add the minimum of their ticket count and (ticket count of person k - 1) to account for the tickets already bought by person k.
Finally, we add the time needed for the person at position k to the totalTime.
If k is out of range (less than 0 or greater than or equal to the size of the ticket queue), we return -1.
In the main function, we create test cases with different ticket counts and target positions.
We instantiate the Solution class and call the timeRequiredToBuy method for each test case, printing the result.
This implementation correctly calculates the time required for the person at position k to finish buying tickets according to the given rules.

*/

#include <iostream>
#include <vector>
#include <algorithm> // Included for min function
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int totalTime = 0;

        // Calculate the total time needed for each person to buy tickets
        for (int i = 0; i < n; ++i) {
            // If the person is before the target position k
            if (i < k) {
                // Add the minimum of their ticket count and the ticket count of person k
                totalTime += min(tickets[i], tickets[k]);
            } 
            // If the person is after the target position k
            else if (i > k) {
                // Add the minimum of their ticket count and (ticket count of person k - 1)
                // (Minus 1 to account for the tickets already bought by the person at position k)
                totalTime += min(tickets[i], tickets[k] - 1);
            }
        }

        // Add the time needed for the person at position k
        totalTime += tickets[k];

        // If k is out of range, return -1
        return (k >= 0 && k < n) ? totalTime : -1;
    }
};

int main() {
    // Test cases
    vector<vector<int>> ticketsList = {{2, 3, 2}, {5, 1, 1, 1}};
    vector<int> kList = {2, 0};

    Solution sol;

    // Iterate over test cases
    for (int i = 0; i < ticketsList.size(); ++i) {
        int result = sol.timeRequiredToBuy(ticketsList[i], kList[i]);
        cout << "For test case " << i + 1 << ", time required for person at position " << kList[i] << " is: " << result << endl;
    }

    return 0;
}

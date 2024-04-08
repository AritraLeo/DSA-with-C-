/*
class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        // circular - 0 and square - 1
        // students - queue
        // sandwiches - stack
        queue<int> q;
        stack<int> st;
        for (int i = 0; i < students.size(); i++)
        {
            q.push(students[i]);
        }
        for (int i = sandwiches.size() - 1; i >= 0; i--)
        {
            st.push(sandwiches[i]);
        }
        // none want the top sandwich
        while (checkTopSandwichTypePresentInQueue(q, st.top()))
        {
            if (q.front() == st.top())
            {
                st.pop();
                q.pop();
            }
            else
            {
                int e = q.front();
                q.pop();
                q.push(e);
            }
        }
        return q.size();
    }

    bool checkTopSandwichTypePresentInQueue(queue<int> q, int stackTop)
    {
        
        while (!q.empty())
        {
            if (q.front() == stackTop)
            {
                return true; // Element found, return true
            }
            q.pop(); // Remove the front element and continue searching
        }
        return false;
    }
};

*/

/*
    // Copy the elements of the queue to a vector
    vector<int> vec;
    while (!q.empty()) {
        vec.push_back(q.front());
        q.pop();
    }

    // Search for the stackTop in the vector
    auto it = find(vec.begin(), vec.end(), stackTop);

    // If the element is found, return true
    if (it != vec.end()) {
        return true;
    }
    return false;
        */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// optimized soln
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentQueue;
        stack<int> sandwichStack;
        
        // Initialize the queues
        for (int i = 0; i < students.size(); ++i) {
            studentQueue.push(students[i]);
        }
        for (int i = sandwiches.size() - 1; i >= 0; --i) {
            sandwichStack.push(sandwiches[i]);
        }
        
        // Keep track of the number of consecutive iterations without changes
        int noChangeCount = 0;
        
        // Loop until all students have had lunch or no one can eat anymore
        while (!sandwichStack.empty()) {
            // If the student at the front of the queue prefers the current sandwich
            if (studentQueue.front() == sandwichStack.top()) {
                studentQueue.pop();
                sandwichStack.pop();
                noChangeCount = 0; // Reset the count
            } else {
                // If the student doesn't prefer the current sandwich, move them to the end of the queue
                int student = studentQueue.front();
                studentQueue.pop();
                studentQueue.push(student);
                noChangeCount++;
            }
            // If no changes happen for a full iteration, break out of the loop
            if (noChangeCount == studentQueue.size()) {
                break;
            }
        }
        
        // Return the number of students unable to eat
        return studentQueue.size();
    }
};


int main()
{
    Solution sol;

    // Test cases
    vector<int> students1 = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches1 = {1, 0, 0, 0, 1, 1};
    cout << "Result: " << sol.countStudents(students1, sandwiches1) << endl;
    // Add more test cases

    return 0;
}

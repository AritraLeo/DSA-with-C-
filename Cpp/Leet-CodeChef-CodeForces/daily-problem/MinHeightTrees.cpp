/*
Explanation:

We define a Solution class with the findMinHeightTrees method to find the roots of minimum height trees.
In the testMinimumHeightTrees function, we create test cases and call the findMinHeightTrees method to get the roots of minimum height trees for each test case.
We print the results of each test case to verify the correctness of the solution.

*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // If there is only one node, it's already a minimum height tree
        
        vector<unordered_set<int>> adjList(n);
        vector<int> degrees(n, 0);
        
        // Build adjacency list and calculate degrees of nodes
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].insert(v);
            adjList[v].insert(u);
            degrees[u]++;
            degrees[v]++;
        }
        
        queue<int> leaves;
        
        // Add leaves (nodes with degree 1) to the queue
        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 1) {
                leaves.push(i);
            }
        }
        
        // Continue until there are <= 2 nodes left
        while (n > 2) {
            int numLeaves = leaves.size();
            n -= numLeaves;
            for (int i = 0; i < numLeaves; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbor : adjList[leaf]) {
                    adjList[neighbor].erase(leaf);
                    degrees[neighbor]--;
                    if (degrees[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }
        
        vector<int> mhtRoots;
        while (!leaves.empty()) {
            mhtRoots.push_back(leaves.front());
            leaves.pop();
        }
        
        return mhtRoots;
    }
};

void testMinimumHeightTrees() {
    Solution solution;
    vector<vector<int>> edges1 = {{1, 0}, {1, 2}, {1, 3}};
    vector<int> result1 = solution.findMinHeightTrees(4, edges1);
    cout << "Test Case 1: ";
    for (int root : result1) {
        cout << root << " ";
    }
    cout << endl;

    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {0, 3}, {3, 4}, {4, 5}};
    vector<int> result2 = solution.findMinHeightTrees(6, edges2);
    cout << "Test Case 2: ";
    for (int root : result2) {
        cout << root << " ";
    }
    cout << endl;

    vector<vector<int>> edges3 = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    vector<int> result3 = solution.findMinHeightTrees(6, edges3);
    cout << "Test Case 3: ";
    for (int root : result3) {
        cout << root << " ";
    }
    cout << endl;
}

int main() {
    testMinimumHeightTrees();
    return 0;
}

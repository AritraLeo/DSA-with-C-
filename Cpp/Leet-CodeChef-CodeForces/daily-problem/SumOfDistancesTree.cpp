/*
Explanation of Modifications:
Construction of the Graph:
We construct the adjacency list representation of the tree using the edges vector.
First DFS Traversal (dfs1):
We perform the first DFS traversal to calculate counts and partial answers.
The function dfs1 takes five arguments: current node, parent node, graph, ans, and count.
We iterate through the children of the current node, excluding the parent.
For each child, we recursively visit it and update the count and partial answer of the parent node.
Second DFS Traversal (dfs2):
We perform the second DFS traversal to calculate final answers.
The function dfs2 also takes five arguments: current node, parent node, graph, ans, and count.
We iterate through the children of the current node, excluding the parent.
For each child, we update its answer based on the parent node and recursively visit its children.
Main Function:
In the main function sumOfDistancesInTree, we call dfs1 with the root node 0 and -1 as the parent.
This is because there is no parent for the root node, so we pass -1.
After both DFS traversals, we return the ans vector containing the sum of distances for each node.

*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // Initialize the graph
        vector<vector<int>> graph(n);
        // Construct the adjacency list representation of the tree
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Initialize vectors to store the result and count of nodes in each subtree
        vector<int> ans(n), count(n, 1);
        
        // Perform the first DFS traversal
        dfs1(0, -1, graph, ans, count);
        
        // Perform the second DFS traversal
        dfs2(0, -1, graph, ans, count);
        
        return ans;
    }

    // First DFS traversal to calculate counts and partial answers
    void dfs1(int node, int parent, const vector<vector<int>>& graph, vector<int>& ans, vector<int>& count) {
        for (int child : graph[node]) {
            if (child != parent) {
                // Recursively visit child nodes
                dfs1(child, node, graph, ans, count);
                // Update the count and partial answer of the parent node
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }

    // Second DFS traversal to calculate final answers
    void dfs2(int node, int parent, const vector<vector<int>>& graph, vector<int>& ans, vector<int>& count) {
        for (int child : graph[node]) {
            if (child != parent) {
                // Update the answer of the child node based on the parent node
                ans[child] = ans[node] - count[child] + (count.size() - count[child]);
                // Recursively visit child nodes
                dfs2(child, node, graph, ans, count);
            }
        }
    }
};

int main() {
    Solution solution;
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
    
    vector<int> result = solution.sumOfDistancesInTree(n, edges);

    cout << "Output: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

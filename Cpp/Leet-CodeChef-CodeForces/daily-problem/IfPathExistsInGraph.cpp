// class Solution {
// public:
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//        return dfs(n, edges, source, destination);
//     }
// public:
//     bool dfs(int n, vector<vector<int>>& e, int s, int t){

//         if(s == t) return true;

//         for(int i=0; i < e.size(); i++){
//             if(e[i][0] == s){
//                 if(e[i][1] == t) return true;

//                 else {
//                     if(dfs(n, e, e[i][1], t)) return true;

//                     else{
//                         continue;
//                     }
//                 }
//             }
//         }

//         // when s at 2nd poz in edges and d at 1st poz
//         for(int i=0; i < e.size(); i++){
//             if(e[i][1] == s){
//                 if(e[i][0] == t) return true;

//                 else {
//                     if(dfs(n, e, e[i][0], t)) return true;

//                     else{
//                         continue;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        // Build the graph
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> visited(n, false);
        return dfs(graph, visited, source, destination);
    }

    bool dfs(const vector<vector<int>>& graph, vector<bool>& visited, int s, int t) {
        if (s == t) return true;
        visited[s] = true;
        for (int neighbor : graph[s]) {
            if (!visited[neighbor]) {
                if (dfs(graph, visited, neighbor, t)) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    // Test cases
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {2, 4}, {3, 4}};
    cout << "Test Case 1: " << sol.validPath(5, edges1, 0, 4) << endl; // Output: 1 (true)

    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {2, 4}, {3, 4}};
    cout << "Test Case 2: " << sol.validPath(5, edges2, 0, 3) << endl; // Output: 1 (true)

    vector<vector<int>> edges3 = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {2, 4}, {3, 4}};
    cout << "Test Case 3: " << sol.validPath(5, edges3, 2, 3) << endl; // Output: 0 (false)

    vector<vector<int>> edges4 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << "Test Case 4: " << sol.validPath(6, edges4, 0, 5) << endl; // Output: 1 (true)

    vector<vector<int>> edges5 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << "Test Case 5: " << sol.validPath(6, edges5, 0, 4) << endl; // Output: 1 (true)

    vector<vector<int>> edges6 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << "Test Case 6: " << sol.validPath(6, edges6, 0, 3) << endl; // Output: 0 (false)

    return 0;
}

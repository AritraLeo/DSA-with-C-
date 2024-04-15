#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*

We'll define a recursive function to perform DFS traversal of the binary tree.
During the traversal, at each node, we'll update the current number formed by concatenating the digits encountered so far.
If we reach a leaf node, we'll add the current number to the total sum.
We'll recursively traverse the left and right subtrees, updating the current number accordingly.
Once the traversal is complete, we'll return the total sum.
*/


class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int currentSum) {
        if (node == nullptr) {
            return 0;
        }
        
        // Update the current sum by adding the current node's value
        currentSum = currentSum * 10 + node->val;
        
        // If it's a leaf node, return the current sum
        if (node->left == nullptr && node->right == nullptr) {
            return currentSum;
        }
        
        // Recursively traverse the left and right subtrees
        int leftSum = dfs(node->left, currentSum);
        int rightSum = dfs(node->right, currentSum);
        
        // Return the sum of both left and right subtree sums
        return leftSum + rightSum;
    }
};

// Function to build a binary tree from level order traversal
TreeNode* buildTree(const vector<int>& nodes, int n, int index) {
    TreeNode* root = nullptr;

    if (index < n && nodes[index] != -1) {
        root = new TreeNode(nodes[index]);
        root->left = buildTree(nodes, n, 2 * index + 1);
        root->right = buildTree(nodes, n, 2 * index + 2);
    }

    return root;
}

// Function to print the binary tree in level order
void printTree(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                cout << "null ";
                continue;
            }
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
        cout << endl;
    }
}

int main() {
    // Test case
    vector<int> nodes = {4,9,0,5,1}; // -1 represents null node // ans - 1026
    int n = nodes.size();
    TreeNode* root = buildTree(nodes, n, 0);

    Solution sol;
    cout << "Sum of left leaves: " << sol.sumNumbers(root) << endl;

    return 0;
}

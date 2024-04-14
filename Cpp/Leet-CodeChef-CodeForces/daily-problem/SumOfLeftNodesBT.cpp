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
We'll perform a depth-first traversal (DFS) of the binary tree.
During the traversal, we'll keep track of whether each node is a left child or a right child.
If we encounter a leaf node (a node with no children), we'll check if it's a left leaf. If it is, we'll add its value to the sum.
We'll recursively traverse the left and right subtrees, passing the information about whether each node is a left child or a right child.
*/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0; // Base case: empty tree
        }

        return dfs(root, false); // Start DFS traversal from the root
    }

private:
    int dfs(TreeNode* node, bool isLeft) {
        if (node == nullptr) {
            return 0; // Base case: empty node
        }

        if (node->left == nullptr && node->right == nullptr && isLeft) {
            return node->val; // Return the value if it's a left leaf
        }

        // Recursively traverse the left and right subtrees
        int leftSum = dfs(node->left, true); // Pass true if the current node is a left child
        int rightSum = dfs(node->right, false); // Pass false if the current node is a right child

        return leftSum + rightSum; // Return the sum of left leaves
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
    vector<int> nodes = {3, 9, 20, -1, -1, 15, 7}; // -1 represents null node
    int n = nodes.size();
    TreeNode* root = buildTree(nodes, n, 0);

    Solution sol;
    cout << "Sum of left leaves: " << sol.sumOfLeftLeaves(root) << endl;

    return 0;
}

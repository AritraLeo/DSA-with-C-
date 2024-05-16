#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool evaluateTree(TreeNode *root)
    {
        if (root->val == 0 || root->val == 1)
        {
            return root->val;
        }

        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);

        if (root->val == 2)
        {
            return left || right;
        }
        else
        {
            return left && right;
        }
    }
};

// Function to create a binary tree from a vector representation
TreeNode *createTree(const vector<int> &nodes, int idx)
{
    if (idx >= nodes.size() || nodes[idx] == -1)
    {
        return nullptr;
    }
    TreeNode *node = new TreeNode(nodes[idx]);
    node->left = createTree(nodes, 2 * idx + 1);
    node->right = createTree(nodes, 2 * idx + 2);
    return node;
}

// Function to delete a binary tree
void deleteTree(TreeNode *root)
{
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    Solution sol;

    // Test cases
    vector<vector<int>> trees = {
        {2, 1, 3, -1, -1, 0, 1}, // Result: true
        {0},                     // Result: false
        {3, 1, 3, 0, 1, 2, 3}    // Result: true
    };

    for (const auto &tree : trees)
    {
        TreeNode *root = createTree(tree, 0);
        bool result = sol.evaluateTree(root);
        cout << "Result: " << (result ? "true" : "false") << endl;
        deleteTree(root);
    }

    return 0;
}

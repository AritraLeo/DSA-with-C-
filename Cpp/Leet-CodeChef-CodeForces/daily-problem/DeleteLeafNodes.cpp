#include <iostream>
#include <vector>
#include <queue>
#include <memory>

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
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if (root->left == nullptr && root->right == nullptr && root->val == target)
        {
            delete root;
            return nullptr;
        }

        return root;
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

// Function to print the tree level by level (for debugging purposes)
void printTree(TreeNode *root)
{
    if (!root)
    {
        cout << "Empty tree" << endl;
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node)
        {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
        else
        {
            cout << "null ";
        }
    }
    cout << endl;
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

    // Test case
    vector<int> tree = {1, 2, 3, 2, -1, 2, 4};
    int target = 2;

    TreeNode *root = createTree(tree, 0);
    cout << "Original tree: ";
    printTree(root);

    root = sol.removeLeafNodes(root, target);
    cout << "Tree after removing target leaves: ";
    printTree(root);

    deleteTree(root);

    return 0;
}

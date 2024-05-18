#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <cmath>

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
    int distributeCoins(TreeNode *root)
    {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }

private:
    // Helper function to perform DFS traversal
    int dfs(TreeNode *node, int &moves)
    {
        // Base case: if the node is null, return 0
        if (!node)
            return 0;

        // Recursively calculate the balance of coins for the left and right subtrees
        int leftBalance = dfs(node->left, moves);
        int rightBalance = dfs(node->right, moves);

        // The total balance for the current node
        int balance = node->val + leftBalance + rightBalance - 1;

        // The number of moves needed is the absolute value of the balance
        moves += abs(balance);

        // Return the balance of coins for the current node
        return balance;
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

    // Test case 1
    vector<int> tree1 = {3, 0, 0};
    TreeNode *root1 = createTree(tree1, 0);
    cout << "Original tree 1: ";
    printTree(root1);
    cout << "Minimum moves required: " << sol.distributeCoins(root1) << endl;
    deleteTree(root1);

    // Test case 2
    vector<int> tree2 = {0, 3, 0};
    TreeNode *root2 = createTree(tree2, 0);
    cout << "Original tree 2: ";
    printTree(root2);
    cout << "Minimum moves required: " << sol.distributeCoins(root2) << endl;
    deleteTree(root2);

    // Test case 3
    vector<int> tree3 = {1, 0, 2};
    TreeNode *root3 = createTree(tree3, 0);
    cout << "Original tree 3: ";
    printTree(root3);
    cout << "Minimum moves required: " << sol.distributeCoins(root3) << endl;
    deleteTree(root3);

    return 0;
}

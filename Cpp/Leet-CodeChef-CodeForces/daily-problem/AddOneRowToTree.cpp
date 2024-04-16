/*
Initial attempt - 

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* ansRoot = dfs(root, depth, 1);

        TreeNode* newNode = new TreeNode(val);

        if(ansRoot->left == nullptr){
            ansRoot->left = newNode;
        }
        if(ansRoot->left == nullptr){
            ansRoot->right = newNode; 
        }
        else{
            TreeNode* tempLeft = ansRoot->left;
            TreeNode* tempRight = ansRoot->right;

            ansRoot->left = newNode;
            newNode->left = tempLeft;

            ansRoot->right = newNode;
            newNode->right = tempRight;

        }

        return root;
    }
    private:
    TreeNode* dfs(TreeNode* node, int depth, int cur) {
        if (node == nullptr) {
            return 0;
        }
        cur = cur + 1;

        if(depth == cur){
            return node;
        }
        
        // Recursively traverse the left and right subtrees
        if(node->left != nullptr)
            dfs(node->left, depth, cur);
        if(node->right != nullptr)
            dfs(node->right, depth, cur);
        
        // Return the sum of both left and right subtree sums
        return node;
    }
};

*/

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            // Create a new node with val as the new root
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        // Use level-order traversal to find nodes at depth depth-1
        queue<TreeNode*> q;
        q.push(root);

        int currentDepth = 1;
        while (!q.empty() && currentDepth < depth - 1) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();

                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
            currentDepth++;
        }

        // Add new nodes with val as children of nodes at depth depth-1
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            TreeNode* leftChild = new TreeNode(val);
            leftChild->left = current->left;
            current->left = leftChild;

            TreeNode* rightChild = new TreeNode(val);
            rightChild->right = current->right;
            current->right = rightChild;
        }

        return root;
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
    vector<int> nodes = {4,2,6,3,1,5}; // -1 represents null node // ans - 1026
    int n = nodes.size();
    TreeNode* root = buildTree(nodes, n, 0);
    int val = 1, depth = 2;

    Solution sol;
    cout << "New Tree - " << endl;
    printTree(sol.addOneRow(root, val, depth));

    return 0;
}

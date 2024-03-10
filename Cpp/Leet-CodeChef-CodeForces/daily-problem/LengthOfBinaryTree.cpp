#include <iostream>
#include <algorithm>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0; // Initialize diameter to 0

        // Helper function to find both diameter and height
        calculateDiameter(root, diameter); // Call helper function to find diameter

        return diameter;
    }

private:
    int calculateDiameter(TreeNode* root, int& diameter) {
        if (root == nullptr) {
            return 0; // Base case: empty tree has height and diameter 0
        }

        int leftHeight = calculateDiameter(root->left, diameter); // Height of left subtree
        int rightHeight = calculateDiameter(root->right, diameter); // Height of right subtree

        // Update the overall diameter if the current diameter is larger
        diameter = std::max(diameter, leftHeight + rightHeight);

        // Return the maximum height of the current node + 1 (for its edge)
        return std::max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    // Test case 1: [1,2]
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    std::cout << "Test Case 1: " << Solution().diameterOfBinaryTree(root1) << std::endl;

    // Test case 2: [1,2,3,4,5]
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    std::cout << "Test Case 2: " << Solution().diameterOfBinaryTree(root2) << std::endl;

    return 0;
}

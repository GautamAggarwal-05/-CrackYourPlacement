/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to find the rightmost node of a given subtree
    void findRightmostNode(TreeNode* root, TreeNode*& rightmostNode) {
        if (root == NULL)
             return;

        rightmostNode = root;

        // Traverse the right subtree first
        findRightmostNode(root->right, rightmostNode);
        
    }

    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        // Flatten the left and right subtrees
        flatten(root->left);
        flatten(root->right);

        // If there is a left subtree, we need to attach it to the right
        if (root->left) {
            TreeNode* rightmost = NULL;
            findRightmostNode(root->left, rightmost);

            // Temporarily store the right subtree
            TreeNode* temp = root->right;
            
            // Attach the left subtree to the right
            root->right = root->left;
            root->left = NULL;

            // Attach the stored right subtree to the end of the new right subtree
            if (rightmost) {
                rightmost->right = temp;
            }
        }
    }
};

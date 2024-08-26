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
    bool helper(TreeNode* root, TreeNode* subRoot){
        if(root==NULL && subRoot==NULL)
            return true;
        if(root==NULL || subRoot == NULL)
            return false;
        if(root->val==subRoot->val){
        int left = helper(root->left,subRoot->left);
        int right = helper(root->right,subRoot->right);
        return left && right;
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL)
            return true;
        
        if(root==NULL)
            return false;

        if(helper(root,subRoot))
            return true;
        
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
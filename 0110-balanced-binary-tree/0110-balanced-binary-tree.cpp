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
    int helper(TreeNode* root,bool &flag){
        if(root==NULL){
            return 0;
        }
        int left =  helper(root->left,flag);
        int right = helper(root->right,flag);
        if(abs(left-right)>1){
            flag=false;
        }

        return 1+max(left,right);

    }
    bool isBalanced(TreeNode* root) {
        bool flag=true;
        helper(root,flag);
        return flag;
    }
};
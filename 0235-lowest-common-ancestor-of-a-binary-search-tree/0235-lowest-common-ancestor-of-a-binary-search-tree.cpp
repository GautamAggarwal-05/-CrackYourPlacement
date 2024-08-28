/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode*q){
        if(root==NULL)
            return root;

        if((root->val >=p->val && root->val<=q->val) ||(root->val <=p->val && root->val>=q->val)){
            return root;
        }
        else if(root->val>p->val && root->val>q->val){
            return helper(root->left,p,q);
        }
        else{
            return helper(root->right,p,q);
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
    }
};
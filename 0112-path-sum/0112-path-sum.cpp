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
    bool helper(TreeNode* root,int target,int sum){
        if(root==NULL)
            return false;
        // if(sum==target)
        //     return true;
        if(root->left==NULL && root->right==NULL){
            sum +=root->val;
            return target==sum;
        }
        sum += root->val;
        return helper(root->left,target,sum) || helper(root->right,target,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
       return  helper(root,targetSum,0);
    }
};
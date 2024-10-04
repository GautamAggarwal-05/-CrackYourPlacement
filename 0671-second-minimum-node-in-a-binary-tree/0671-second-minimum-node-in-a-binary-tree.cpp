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
    void solve(TreeNode* root,long long &maxi,int mini){
        if(root==NULL)
            return ;
        
        solve(root->left,maxi,mini);
            if(root->val > mini && root->val<maxi){
                maxi=root->val;
            }
        solve(root->right,maxi,mini);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
            return -1;
        long long maxi=LONG_MAX;
        solve(root,maxi,root->val);
        return maxi==LONG_MAX?-1:maxi;
    }
};
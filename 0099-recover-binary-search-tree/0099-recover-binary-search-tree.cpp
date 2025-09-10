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
    void solve(TreeNode* root){
        if(root == NULL)
            return ;
        
        solve(root->left);
        if(prev!=NULL && prev->val > root->val){
            if(first==NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        solve(root->right);
    }
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev ;
    void recoverTree(TreeNode* root) {
        first=middle=last=prev=NULL;
    solve(root);
    if(first && last)
        swap(first->val,last->val);
    else if(first && middle)
        swap(first->val,middle->val);
    } 
};
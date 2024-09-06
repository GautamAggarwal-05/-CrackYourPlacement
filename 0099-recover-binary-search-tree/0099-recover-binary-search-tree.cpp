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
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    void helper(TreeNode* root){
        if(root==NULL)
            return ;

        helper(root->left);
        if(prev!=NULL && root->val < prev->val){
            //if this is the first violation mark these two nodes first and middle
            if(first == NULL){
                first=prev;
                middle=root;
            }
            //if this is the second violation then mark last
            else{
                last=root;
            }
        }
        //mark this node as previous
        prev=root;
        helper(root->right);

    }
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        helper(root);
        if(first && last)
            swap(first->val,last->val);
        else if(first && middle)
            swap(first->val,middle->val);
    }
};
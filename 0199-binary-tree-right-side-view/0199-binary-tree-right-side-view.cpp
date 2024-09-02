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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        deque<TreeNode*>q;
        if(root==NULL){
            return {};
        }
        q.push_back(root);
        q.push_back(NULL);
        res.push_back(root->val);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop_front();
            if(node==NULL){
                if(!q.empty()){
                    TreeNode* ans = q.back();
                    res.push_back(ans->val);
                    q.push_back(NULL);
                }
            }
            else{
            if(node->left){
                q.push_back(node->left);
            }
            if(node->right){
                q.push_back(node->right);
            }
            }
        }
        return res;
    }
};
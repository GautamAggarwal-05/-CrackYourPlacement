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
    map<pair<int,int>,vector<TreeNode*>>mp;
    vector<TreeNode*> solve(int s,int e){
        if(s>e){
            return {NULL};
        }
        if(s==e){
            return {new TreeNode(s)};
        }
        if(mp.find({s,e})!=mp.end()){
            return mp[{s,e}];
        }
        vector<TreeNode*>result;
        for(int i=s;i<=e;i++){
            vector<TreeNode*> leftBst= solve(s,i-1);
            vector<TreeNode*> rightBst = solve(i+1,e);

            for(TreeNode* leftRoot:leftBst){
                for(TreeNode* rightRoot:rightBst){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;

                    result.push_back(root);
                }
            }
        }
        return mp[{s,e}] = result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};
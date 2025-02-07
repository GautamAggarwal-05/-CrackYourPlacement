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
    vector<int>solve(TreeNode* root,int& distance,int& goodleaf){
        if(root==NULL)
            return {0};
        
        if(root->left==NULL && root->right == NULL){
            return {1};
        }

        vector<int> left_ans = solve(root->left,distance,goodleaf);
        vector<int> right_ans = solve(root->right,distance,goodleaf);

        for(auto& l:left_ans){
            for(auto& r:right_ans){
                if(l!=0 && r!=0 && l+r<=distance)
                    goodleaf++;
            }
        }

        vector<int>currdist;
        for(auto& l:left_ans){
            if(l!=0 && l+1<=distance)
                currdist.push_back(l+1);
        }
        for(auto& r:right_ans){
            if(r!=0 && r+1<=distance)
                currdist.push_back(r+1);
        }
        return currdist;
    }
    int countPairs(TreeNode* root, int distance) {
        int goodleaf=0;
        solve(root,distance,goodleaf);
        return goodleaf;
    }
};
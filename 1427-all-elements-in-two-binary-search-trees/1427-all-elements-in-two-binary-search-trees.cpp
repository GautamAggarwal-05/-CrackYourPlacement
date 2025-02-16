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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode* > st1,st2;
        vector<int> ans;

        while(root1 || !st1.empty() || root2 || !st2.empty()){
            while(root1){
                st1.push(root1);
                root1=root1->left;
            }
             while(root2){
                st2.push(root2);
                root2=root2->left;
            }
            // foucs on tree1 and hold trav. for tree 2
            if(st2.empty() || (!st1.empty() &&st1.top()->val<= st2.top()->val)){
                root1=st1.top();
                st1.pop();
                ans.push_back(root1->val);
                root1=root1->right;
            }
            // hold trav. for tree1 and focus on tree 2
            else{
                 root2=st2.top();
                st2.pop();
                ans.push_back(root2->val);
                root2=root2->right;

            }
        }
         
       return ans;

    }
};
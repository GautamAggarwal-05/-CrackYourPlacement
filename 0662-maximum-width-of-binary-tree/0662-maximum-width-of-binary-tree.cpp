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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;  // Handle edge case where root is null
        unsigned long long ans = 1;
        deque<pair<TreeNode*, unsigned long long>> q;
        q.push_back({root, 0});
        q.push_back({NULL, -1});
        
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            unsigned long long indx = q.front().second;
            q.pop_front();
            
            if (node == NULL) {
                if (!q.empty()) {
                    unsigned long long a = q.front().second;
                    unsigned long long b = q.back().second;
                    ans = max(ans, b - a + 1);
                    q.push_back({NULL, -1});
                }
            } else {
                if (node->left) {
                    q.push_back({node->left, 2 * indx + 1});
                }
                if (node->right) {
                    q.push_back({node->right, 2 * indx + 2});
                }
            }
        }
        return ans;
    }
};

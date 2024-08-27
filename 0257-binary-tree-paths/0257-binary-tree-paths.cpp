class Solution {
public:
    void helper(TreeNode* root, string &temp, vector<string>& ans) {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL) {
            temp += to_string(root->val);  // Add the leaf node value
            ans.push_back(temp);  // Add the complete path to the result
            temp.erase(temp.end() - to_string(root->val).length(), temp.end());  // Remove the leaf node value
            return;
        }

        temp += to_string(root->val) + "->";  // Add the current node value and "->"
        helper(root->left, temp, ans);  // Recur to the left child
        helper(root->right, temp, ans);  // Recur to the right child

        // Backtrack by removing the current node value and the arrow "->"
        temp.erase(temp.end() - (to_string(root->val).length() + 2), temp.end());
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = "";
        helper(root, temp, ans);
        return ans;
    }
};

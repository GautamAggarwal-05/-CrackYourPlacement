class Solution {
public:
    int helper(TreeNode* root, long long target) {
        if (root == NULL)
            return 0;

        long long count = 0;
        
        // If current node value matches the target, it's a valid path
        if (root->val == target)
            count++;

        // Recursively check the left and right subtrees for paths that sum to target - root->val
        count += helper(root->left, target - root->val);
        count += helper(root->right, target - root->val);

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return 0;

        // Count paths starting from the current node
        int count = helper(root, targetSum);

        // Recursively count paths in the left and right subtrees
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
};

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;

        sort(nums.rbegin(), nums.rend());
        vector<bool> visited(nums.size(), false);
        return solve(nums, visited, k, 0, 0, sum / k);
    }

private:
    bool solve(vector<int>& nums, vector<bool>& visited, int k, int startIdx, int currSum, int target) {
        if (k == 1) return true;
        if (currSum > target) return false;
        if (currSum == target) {
            return solve(nums, visited, k-1, 0, 0, target);
        }

        for (int i = startIdx; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (nums[i] > target) return false; // Case: [6, 4]; k = 2

            visited[i] = true;
            if (solve(nums, visited, k, i + 1, currSum + nums[i], target)) return true;
            visited[i] = false;//backtrack
        }

        return false;
    }
};
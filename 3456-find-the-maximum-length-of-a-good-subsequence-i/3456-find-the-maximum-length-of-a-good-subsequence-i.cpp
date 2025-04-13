class Solution {
public:
    int solve(int i, int prev, int k, vector<int>& nums, vector<vector<vector<int>>>&dp) {
        if (i == nums.size())
            return 0;
        
        if(dp[i][prev][k]!=-1)
            return dp[i][prev][k];
        int ans = 0;

        ans = max(ans, solve(i + 1, prev, k, nums,dp)); //exclude
        if (prev == nums.size()) {
            ans = max(ans, 1 + solve(i + 1, i, k, nums,dp));
        }
        else {
            if (nums[i] == nums[prev]) {
                ans = max(ans, 1 + solve(i + 1, i, k, nums,dp));
            }
            else if (k > 0) {
                ans = max(ans, 1 + solve(i + 1, i, k - 1, nums,dp));
            }
        }
        
        return dp[i][prev][k]= ans;
    }
    
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1,vector<int>(k+2,-1)));
        return solve(0,n, k, nums,dp);
    }
};

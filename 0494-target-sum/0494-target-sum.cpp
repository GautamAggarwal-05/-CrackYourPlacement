class Solution {
public:
    int totalsum;
    int solve(int i,int sum,int n,vector<int>& nums, int target,vector<vector<int>>& dp){
        if(i==n){
            return sum==target;
        }
        // sum can go negative so we have to take sum+totalsum to avoid runtime error
        if(dp[i][totalsum+sum]!=-1)
            return dp[i][totalsum + sum];

        int add = solve(i+1,sum+nums[i],n,nums,target,dp);
        int sub = solve(i+1,sum-nums[i],n,nums,target,dp);

        return dp[i][totalsum+sum]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
         totalsum = accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(2*totalsum+1,-1));
        return solve(0,0,n,nums,target,dp);
    }
};
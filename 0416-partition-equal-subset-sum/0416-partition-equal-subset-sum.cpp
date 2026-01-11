class Solution {
public:
    bool solve(int i,int curr,int totalsum,vector<int>&nums,vector<vector<int>>&dp){
        if(i>=nums.size())
            return false;
        if(curr == totalsum - curr){
            return true;
        }
        if(curr > abs(totalsum-curr)){
            return false;
        }
        if(dp[i][curr]!=-1)
            return dp[i][curr];
        int include = solve(i+1,curr + nums[i],totalsum,nums,dp);
        int exclude = solve(i+1,curr,totalsum,nums,dp);
        return dp[i][curr] =  include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0,n;
        n = nums.size();
        for(int num:nums){
            sum += num;
        }
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return sum%2!=0?false:solve(0,0,sum,nums,dp);
    }
};
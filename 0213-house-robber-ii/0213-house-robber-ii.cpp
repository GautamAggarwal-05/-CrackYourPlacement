class Solution {
public:
int solve(int ind,vector<int>&nums,int n,vector<int>&dp)
{
    if(ind>=n)
        return 0;
    if(dp[ind]!=-1)
        return dp[ind];
   
        int include=nums[ind]+ solve(ind+2,nums,n,dp);
        int exclude=solve(ind+1,nums,n,dp);
       
        dp[ind]=max(include,exclude);
        return dp[ind];

}
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        return max(solve(0,nums,nums.size()-1,dp1),solve(1,nums,nums.size(),dp2));
        
    }
};
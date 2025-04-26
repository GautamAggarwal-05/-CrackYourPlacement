class Solution {
public:
    int solve(int indx,vector<int>& nums,vector<int>& dp){
        if(indx>=nums.size()-1)
            return 0;
        if(nums[indx]==0)
            return 1e9+7;
        if(dp[indx]!=-1)
            return dp[indx];
        int power=nums[indx];
        int ans=0;
        int result=1e9+7;
        for(int i=1;i<=power;i++){
           ans = 1 +  solve(indx+i,nums,dp);
           result=min(result,ans);
        }
        return dp[indx] = result;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,nums,dp);
    }
};
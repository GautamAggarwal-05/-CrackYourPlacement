class Solution {
public:
    bool solve(int indx,vector<int>& nums,vector<int>& dp){
        if(indx>=nums.size()-1)
            return true;
        if(nums[indx]==0)
            return false;
        if(dp[indx]!=-1)
            return dp[indx];
        int power=nums[indx];
        bool ans=false;
        for(int i=1;i<=power;i++){
           ans = ans | solve(indx+i,nums,dp);
           if(ans)
            break;
        }
        return dp[indx] = ans;
    }
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]==0 && n==1)
            return true;
        vector<int>dp(n+1,-1);
        return solve(0,nums,dp);
    }
};
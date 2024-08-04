class Solution {
public:
    int solve(int i,int j,vector<int>& nums,vector<vector<int>>&dp){
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MIN;
        for(int indx=i;indx<=j;indx++){
            int cost = nums[i-1]*nums[indx]*nums[j+1] + solve(i,indx-1,nums,dp)+solve(indx+1,j,nums,dp);
            ans = max(ans,cost);
        }
        return dp[i][j]=ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return solve(1,n,nums,dp);
    }
};
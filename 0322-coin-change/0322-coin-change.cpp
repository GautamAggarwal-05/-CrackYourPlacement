class Solution {
public:
    int solve(int i,vector<int>& coins,int amount,vector<vector<int>>&dp){
        if(amount ==0)
            return 0;
        if(i>=coins.size() || amount<0)
            return INT_MAX - 1;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        int include=INT_MAX;
        if(amount >= coins[i])
            include = 1+solve(i,coins,amount-coins[i],dp);
        int exclude = solve(i+1,coins,amount,dp);

        return dp[i][amount] = min(include,exclude);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans = solve(0,coins,amount,dp);
        if(ans>=INT_MAX-1)
            return -1;
        return ans;
    }
};
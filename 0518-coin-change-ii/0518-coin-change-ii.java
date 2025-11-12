class Solution {
    public int solve(int i,int target,int[] coins,int[][] dp){
        if(i>=coins.length){
            return target == 0 ? 1:0; 
        }
        if(target==0)
            return 1;
        if(target < 0)
            return 0;
        
        if(dp[i][target]!=-1)
            return dp[i][target];
        int take=0,nottake=0;
        if(target >= coins[i]){
            take = solve(i,target-coins[i],coins,dp);
        }
        nottake = solve(i+1,target,coins,dp);
        return dp[i][target] = take + nottake;
    }
    public int change(int amount, int[] coins) {
        int n=coins.length;
        int[][] dp = new int[n+1][amount+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                dp[i][j]=-1;
            }
        }
        return solve(0,amount,coins,dp);
    }
}
class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>& dungeon,vector<vector<int>>&dp){
        if(i>=n || j>=m)
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==n-1 && j==m-1){
            return dungeon[i][j]>0?1:1-dungeon[i][j];
        }
        int right = solve(i,j+1,n,m,dungeon,dp);
        int down = solve(i+1,j,n,m,dungeon,dp);
        int ans = min(right,down)-dungeon[i][j];
        return  dp[i][j] = ans>0?ans:1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n= dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,dungeon.size(),dungeon[0].size(),dungeon,dp);

    }
};
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&matrix,int n,vector<vector<int>>&dp){
        if(i<0 || i>=n || j<0 || j>=n){
            return 1e8;
        }
        if (i == n - 1) 
            return matrix[i][j];
        if(dp[i][j]!=1e9)
            return dp[i][j];
        int left = matrix[i][j] + solve(i+1,j-1,matrix,n,dp);
        int right = matrix[i][j] + solve(i+1,j+1,matrix,n,dp);
        int down = matrix[i][j] + solve(i+1,j,matrix,n,dp);
        return dp[i][j] = min(left,min(right,down));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int n = matrix.size();
        vector<vector<int>>dp(n+1,(vector<int>(n+1,1e9)));
        for(int j=0;j<n;j++){
            ans=min(ans,solve(0,j,matrix,n,dp));
        }
        return ans;
    }
    
};
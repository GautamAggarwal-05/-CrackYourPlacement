class Solution {
public:
    int mod=1000000007;
    int solve(int i,int absent,int late,int n,vector<vector<vector<int>>>&dp){
        if (absent>=2 || late>=3){
            return 0;
        }
        if(i>=n)
            return 1;
        if(dp[i][absent][late]!=-1)
            return dp[i][absent][late];
        long long p=solve(i+1,absent,0,n,dp);
        long long a=solve(i+1,absent+1,0,n,dp);
        long long l=solve(i+1,absent,late+1,n,dp);
        return dp[i][absent][late] = (p+a+l)%mod;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,0,0,n,dp);
    }
};
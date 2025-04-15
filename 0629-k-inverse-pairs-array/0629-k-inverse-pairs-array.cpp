class Solution {
public:
    int mod=1000000007;
    int dp[1001][1001];
    int kInversePairs(int n, int k) {
        // vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                for(int inv=0;inv<=min(j,i-1);inv++){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-inv])%mod;
                }
            }
        }
        return dp[n][k];
    }
};
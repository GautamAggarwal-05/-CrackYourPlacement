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
            long long cumsum=1;
            for(int j=1;j<=k;j++){
                    cumsum = (cumsum + dp[i-1][j]);
                    if(j-i>=0){
                        cumsum = cumsum - dp[i-1][j-i];
                    }
                    dp[i][j]=cumsum % mod;
            }
        }
        return dp[n][k];
    }
};
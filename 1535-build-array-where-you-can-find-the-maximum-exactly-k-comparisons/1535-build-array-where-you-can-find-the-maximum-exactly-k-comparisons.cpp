class Solution {
public:
    int mod=1e9+7;
    int solve(int i,int maxtillnow,int cost,int k,int m,int n,vector<vector<vector<int>>>& dp){
        if(cost>k)
            return 0;
        if(i==n)
            return cost==k?1:0;
        
        if(dp[i][maxtillnow][cost]!=-1){
            return dp[i][maxtillnow][cost];
        }
        int ans=0;
        for(int j=1;j<=m;j++){
            if(maxtillnow<j){
                ans = (ans + solve(i+1,j,cost+1,k,m,n,dp))%mod;
            }else{
                ans =  (ans + solve(i+1,maxtillnow,cost,k,m,n,dp))%mod;
            }
        }
        return dp[i][maxtillnow][cost]=ans;
    }
    int numOfArrays(int n, int m, int k) {
        if(m<k)
            return 0;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,0,0,k,m,n,dp);
    }
};
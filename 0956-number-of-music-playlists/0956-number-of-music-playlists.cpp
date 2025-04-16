class Solution {
public:
    int mod=1e9+7;
    int solve(int i,int used,int n,int goal,int k,vector<vector<long long>>& dp){
        if(i==goal)
            return used==n;
        if(dp[i][used]!=-1)
            return dp[i][used];
        long long usedsong=(solve(i+1,used,n,goal,k,dp)* 1LL * max(used-k,0))%mod;
        long long unique=(solve(i+1,used+1,n,goal,k,dp) * 1LL * (n-used))%mod;

        return dp[i][used] = (usedsong+unique)%mod;
    }
    unordered_map<int,int>prevused;
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>>dp(goal+1,vector<long long>(goal+1,-1));
        return solve(0,0,n,goal,k,dp);
    }
};
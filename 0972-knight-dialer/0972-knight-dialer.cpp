class Solution {
    int mod = 1e9 + 7;
public: 
    int solve(int square,int n,vector<vector<int>> &jumps,vector<vector<int>>&dp){
        if(n==0){
            return 1;
        }
        if(dp[square][n]!=-1)
            return dp[square][n];
        int ans=0;
        for(auto &next:jumps[square]){
            ans=(ans+solve(next,n-1,jumps,dp))%mod;
        }
        return dp[square][n] = ans;
    }
public:
    int knightDialer(int n) {
        vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    vector<vector<int>>dp(11,vector<int>(n+1,-1));
    int ans=0;
    for(int i=0;i<=9;i++){
        ans = (ans+solve(i,n-1,jumps,dp))%mod;
    }
    return ans;
    }
};
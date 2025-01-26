class Solution {
public:
    int solve(int i, string s, unordered_set<string>st, int n, vector<int>&dp){
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        // taking curr char as extra character
        int result = 1 + solve(i+1,s,st,n,dp);

        //not taking as extra character
        for(int j=i;j<n;j++){
            string curr = s.substr(i,j-i+1);
            if(st.count(curr)>0){
                result = min (result,solve(j+1,s,st,n,dp));
            }
        }
        return dp[i] = result;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>st(begin(dictionary),end(dictionary));
        int n = s.length();
        vector<int>dp(n+1,-1);
        return solve(0,s,st,n,dp);
    }
};
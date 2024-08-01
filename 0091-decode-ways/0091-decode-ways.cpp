class Solution {
public:
    int solve(int i,string &s,vector<int>&dp){
        if(i>=s.length())
            return 1;
        if(s[i]=='0')
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int op2=0;
        int op1 = solve(i+1,s,dp);
        if(i+1<s.length()){
        if(s[i]=='1'||(s[i]=='2'&&s[i+1]<='6')){
            op2 = solve(i+2,s,dp);
        }
        }
        return dp[i] = op1+op2;
    }
    int numDecodings(string s) {
        vector<int>dp(s.length(),-1);
        return solve(0,s,dp);
    }
};
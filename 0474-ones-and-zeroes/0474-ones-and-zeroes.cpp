class Solution {
public:
    int solve(int i,vector<string>&strs,int m,int n,vector<vector<vector<int>>> &dp){
        if(i>=strs.size())
            return 0 ;
        if (dp[i][m][n] != -1)
         return dp[i][m][n];
        string temp = strs[i];
        int onecount=0;
        int zerocount=0;
        for(int count=0;count<temp.size();count++){
            if(temp[count]=='1')
                onecount++;
            else
                zerocount++;
        }
        int include=0;
        if(onecount <= n && zerocount <= m){
            include = 1+solve(i+1,strs,m-zerocount,n-onecount,dp);
        }
        int exclude = solve(i+1,strs,m,n,dp);

        return dp[i][m][n] = max(include,exclude);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
         vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(0, strs, m, n, dp);
    }
};
class Solution {
public:
    int mod = 1e9 + 7;
    int n, m;

    bool hasApple(int row1, int col1, int row2, int col2, vector<string>& pizza) {
        for (int i = row1; i < row2; ++i) {
            for (int j = col1; j < col2; ++j) {
                if (pizza[i][j] == 'A') return true;
            }
        }
        return false;
    }

    int solve(int row, int col, int cutsLeft, vector<string>& pizza,vector<vector<vector<int>>>& dp) {
        if (!hasApple(row, col, pizza.size(), pizza[0].size(), pizza))
            return 0;
        if (cutsLeft == 0) return 1;
        if(dp[row][col][cutsLeft]!=-1){
            return dp[row][col][cutsLeft];
        }
        int ans = 0;

        //Horizontal
        for (int i = row + 1; i < pizza.size(); ++i) {
            if (hasApple(row, col, i, pizza[0].size(), pizza)) {
                ans = (ans + solve(i, col, cutsLeft - 1, pizza,dp)) % mod;
            }
        }

        // Vertical 
        for (int j = col + 1; j < pizza[0].size(); ++j) {
            if (hasApple(row, col, pizza.size(), j, pizza)) {
                ans = (ans + solve(row, j, cutsLeft - 1, pizza,dp)) % mod;
            }
        }

        return dp[row][col][cutsLeft]=ans;
    }

    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return solve(0, 0, k - 1, pizza,dp);
    }
};

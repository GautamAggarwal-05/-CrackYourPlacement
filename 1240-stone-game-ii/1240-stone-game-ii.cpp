class Solution {
public:
    int solve(int i, int M, vector<int>& piles, bool flag, vector<int>& pre, vector<vector<vector<int>>>& dp) {
        if (i >= piles.size())
            return 0;
        if (dp[i][M][flag] != -1) 
            return dp[i][M][flag];

        int sum = 0;
        int maxi = 0;
        int mini = INT_MAX;

        if (flag) { // Alice's turn
            for (int X = 0; X < 2 * M; X++) {
                if (i + X >= piles.size()) break;
                if (i > 0)
                    sum = pre[i + X] - pre[i - 1];
                else
                    sum = pre[i + X];
                maxi = max(maxi, sum + solve(i + X + 1, max(M, X + 1), piles, false, pre, dp));
            }
            dp[i][M][flag] = maxi; 
        } else { //BOB turn
            for (int X = 0; X < 2 * M; X++) {
                if (i + X >= piles.size()) break;
                mini = min(mini, solve(i + X + 1, max(M, X + 1), piles, true, pre, dp));
            }
            dp[i][M][flag] = mini; 
        }   
        return dp[i][M][flag];
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> pre(n);
        pre[0] = piles[0];
        for (int i = 1; i < n; i++) {
            pre[i] = piles[i] + pre[i - 1];
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(2, -1)));

        return solve(0, 1, piles, true, pre, dp);
    }
};

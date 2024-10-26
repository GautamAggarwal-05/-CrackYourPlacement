class Solution {
public:
    double solve(int i, int j, int k, int n, vector<vector<vector<double>>>& dp) {
        if (k == 0) return 1.0;
        
        if (dp[i][j][k] != -1.0) return dp[i][j][k];

        int dx[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
        int dy[8] = {-1, 1, -1, 1, -2, 2, -2, 2};

        double probability = 0.0;

        for (int m = 0; m < 8; m++) {
            int ni = i + dx[m];
            int nj = j + dy[m];

            if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                probability += solve(ni, nj, k - 1, n, dp) / 8.0;
            }
        }

        dp[i][j][k] = probability;
        return probability;
    }

    double knightProbability(int n, int k, int row, int column) {
        if (k == 0) return 1.0;
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));
        
        return solve(row, column, k, n, dp);
    }
};

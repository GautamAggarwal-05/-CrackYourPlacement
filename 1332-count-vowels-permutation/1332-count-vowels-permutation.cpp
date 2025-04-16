class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int i, int prev, int n, vector<vector<int>>& dp) {
        if (i == n)
            return 1;
        if (dp[i][prev] != -1)
            return dp[i][prev];

        int ans = 0;

        // a-0, e-1, i-2, o-3, u-4
        if (prev == 0) {
            ans = (ans + solve(i + 1, 1, n, dp)) % mod;
        }
        if (prev == 1) {
            ans = (ans + solve(i + 1, 0, n, dp)) % mod;
            ans = (ans + solve(i + 1, 2, n, dp)) % mod;
        }
        if (prev == 2) {
            ans = (ans + solve(i + 1, 0, n, dp)) % mod;
            ans = (ans + solve(i + 1, 1, n, dp)) % mod;
            ans = (ans + solve(i + 1, 3, n, dp)) % mod;
            ans = (ans + solve(i + 1, 4, n, dp)) % mod;
        }
        if (prev == 3) {
            ans = (ans + solve(i + 1, 2, n, dp)) % mod;
            ans = (ans + solve(i + 1, 4, n, dp)) % mod;
        }
        if (prev == 4) {
            ans = (ans + solve(i + 1, 0, n, dp)) % mod;
        }

        return dp[i][prev] = ans;
    }

    int countVowelPermutation(int n) {
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(5, -1));
        for (int i = 0; i < 5; i++) {
            ans = (ans + solve(1, i, n, dp)) % mod;
        }
        return ans;
    }
};

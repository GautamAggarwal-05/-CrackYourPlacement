class Solution {
public:
    int totalStrength(vector<int>& strength) {
        constexpr int MOD = 1'000'000'007;
        int n = strength.size();
        vector<long> prefixSum(n + 1, 0), doublePrefixSum(n + 1, 0);
        vector<int> left(n, -1), right(n, n);
        stack<int> monoStack;

        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = (prefixSum[i] + strength[i]) % MOD;
        }
        for (int i = 0; i < n; ++i) {
            doublePrefixSum[i + 1] = (doublePrefixSum[i] + prefixSum[i + 1]) % MOD;
        }

        // left smallest element
        for (int i = 0; i < n; ++i) {
            while (!monoStack.empty() && strength[monoStack.top()] >= strength[i]) {
                monoStack.pop();
            }
            if (!monoStack.empty()) {
                left[i] = monoStack.top();
            }
            monoStack.push(i);
        }
        // right smallest element
        while (!monoStack.empty()) monoStack.pop();

        
        for (int i = n - 1; i >= 0; --i) {
            while (!monoStack.empty() && strength[monoStack.top()] > strength[i]) {
                monoStack.pop();
            }
            if (!monoStack.empty()) {
                right[i] = monoStack.top();
            }
            monoStack.push(i);
        }

        long ans = 0;

        
        for (int i = 0; i < n; ++i) {
            int l = left[i];
            int r = right[i];
            long leftSum = (doublePrefixSum[i] - doublePrefixSum[max(0, l)] + MOD) % MOD;
            long rightSum = (doublePrefixSum[r] - doublePrefixSum[i] + MOD) % MOD;
            int leftLen = i - l;
            int rightLen = r - i;
            ans = (ans + strength[i] * ((rightSum * leftLen % MOD - leftSum * rightLen % MOD + MOD) % MOD)) % MOD;
        }

        return ans;
    }
};

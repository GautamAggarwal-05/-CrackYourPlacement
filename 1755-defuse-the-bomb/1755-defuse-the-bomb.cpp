class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        vector<int> ans(n, 0);

        if (k == 0) 
            return ans;

        prefix[0] = code[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = code[i] + prefix[i - 1];
        }

        suffix[n - 1] = code[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = code[i] + suffix[i + 1];
        }

        if (k > 0) {
            for (int i = 0; i < n; i++) {
                if (i + k < n) {
                    ans[i] = prefix[i + k] - prefix[i];
                } else {
                    ans[i] = prefix[n - 1] - prefix[i] + prefix[(i + k) % n];
                }
            }
        } else {
            k = -k; 
            for (int i = 0; i < n; i++) {
                if (i - k >= 0) {
                    ans[i] = suffix[i - k] - suffix[i];
                } else {
                    ans[i] = suffix[0] - suffix[i] + suffix[n + (i - k) % n];
                }
            }
        }

        return ans;
    }
};

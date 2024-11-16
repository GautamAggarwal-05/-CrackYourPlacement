class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mod = 1e9+7;
        vector<int> power(n, 1);
        
        for (int k = 1; k < n; ++k) {
            power[k] = (power[k - 1] * 2) % mod;
        }

        int i = 0;
        int j = n - 1;
        int ans = 0;

        while (i <= j) {
            if (nums[i] + nums[j] > target) {
                j--;
            } else {
                ans = (ans + power[j - i]) % mod;
                i++;
            }
        }

        return ans;
    }
};

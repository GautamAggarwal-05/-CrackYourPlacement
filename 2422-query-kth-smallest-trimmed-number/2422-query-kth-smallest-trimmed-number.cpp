class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums[0].length();

        for (auto& query : queries) {
            int k = query[0];
            int trim = query[1];
            vector<pair<string, int>> trimmedNums;
            for (int i = 0; i < nums.size(); i++) {
                string trimmed = nums[i].substr(n - trim, trim);
                trimmedNums.push_back({trimmed, i});
            }
            sort(trimmedNums.begin(), trimmedNums.end());
            ans.push_back(trimmedNums[k - 1].second);
        }

        return ans;
    }
};

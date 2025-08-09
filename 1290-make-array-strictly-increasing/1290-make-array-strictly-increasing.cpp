class Solution {
public:
    map<pair<int,int>, int> dp; // memoization 

    int solve(int i, int prev, vector<int>& arr1, vector<int>& arr2) {
        if (i >= arr1.size()) return 0;

        auto key = make_pair(i, prev);
        if (dp.count(key)) return dp[key];

        int cost = 2001;

        // keep arr1[i]
        if (arr1[i] > prev) {
            cost = solve(i + 1, arr1[i], arr1, arr2);
        }

        //replace arr1[i] with a number from arr2
        int idx = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if (idx != arr2.size()) { // if no valid upperbound exist in arr2 for val then it gives arr2.size()
            cost = min(cost, 1 + solve(i + 1, arr2[idx], arr1, arr2));
        }

        return dp[key] = cost;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int ans = solve(0, -1, arr1, arr2);
        return (ans >= 2001 ? -1 : ans);
    }
};

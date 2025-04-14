class Solution {
public:
    int solve(int i, bool same, int k, vector<int>& nums, vector<vector<vector<int>>>&dp,unordered_map<int,vector<int>>& mp) {
        if (i == nums.size())
            return 0;
        
        if(dp[i][same][k]!=-1)
            return dp[i][same][k];

        int include=0;
        vector<int>& vec=mp[nums[i]];
        int nexti=upper_bound(vec.begin(),vec.end(),i)-vec.begin(); // next index of same value
        if (nexti == vec.size()) {
            include=1+0;
        }
        else{
            include=1+solve(vec[nexti],true,k,nums,dp,mp);
        }
        if (k > 0) {
                include = max(include, 1 + solve(i + 1, false, k - 1, nums,dp,mp));
            }
        int exclude = 0;
        if(same==false)
            exclude = solve(i + 1, false, k, nums,dp,mp); //exclude
        return dp[i][same][k]= max(exclude,include);
    }
    
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        return solve(0,false, k, nums,dp,mp);
    }
};
